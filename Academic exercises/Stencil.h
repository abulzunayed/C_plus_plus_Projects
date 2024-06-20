#pragma once

#include <cassert>
#include <utility> //std::swap
#include <algorithm> // std::find_if
#include <vector>
#include "MatrixLike.h"

template<typename T>
using StencilEntry = std::pair<int, T>; // convenience type for stencil entries

template<typename T, size_t rows, size_t cols>
class Stencil :public MatrixLike<T, Stencil<T,rows,cols>,rows,cols>/* TODO: inherit MatrixLike */ {
public:
    Stencil(const std::vector<StencilEntry<T> >& boundaryEntries, const std::vector<StencilEntry<T> >& innerEntries)
            : boundaryStencil_(boundaryEntries), innerStencil_(innerEntries) { }
    Stencil(const std::vector<StencilEntry<T> >& innerEntries)	// c'tor for stencils w/o explicit boundary handling
            : boundaryStencil_(innerEntries), innerStencil_(innerEntries) { }

    Stencil(const Stencil & o);
    Stencil(Stencil && o) noexcept;

    ~Stencil( ) noexcept override {
        std::vector<StencilEntry<T>>().swap(boundaryStencil_);
        std::vector<StencilEntry<T>>().swap(innerStencil_);

    }

    Stencil& operator=(const Stencil & o);
    Stencil& operator=(Stencil && o) noexcept;

    T& operator() (int, int)override;
    const T& operator() (int, int)const override;

    // HINT: stencil entries are stored as offset/coefficient pair, that is the offset specifies which element of a
    // vector, relative to the current index, is to be regarded. It is then multiplied with the according coefficient.
    // All of these expressions are evaluated and then summed up to get the final result.

    Vector<T,rows> operator* (const Vector<T,rows> & o) const override;

    Stencil<T,rows,cols> inverseDiagonal( ) const override;

protected:
    // containers for the stencil entries -> boundary stencils represent the first and last rows of a corresponding
    // matrix and are to be applied to the first and last element of a target vector; inner stencils correspond to
    // the remaining rows of the matrix
    std::vector<StencilEntry<T> > boundaryStencil_;	// feel free to change the datatype if convenient
    std::vector<StencilEntry<T> > innerStencil_;	// feel free to change the datatype if convenient
    int size_;      //matrix size
    double rest_ =0;    //rest zeros;
};

template<typename T, size_t rows, size_t cols>
Stencil<T, rows, cols>::Stencil(const Stencil &o)
        :boundaryStencil_(o.boundaryStencil_),innerStencil_(o.innerStencil_){}

template<typename T, size_t rows, size_t cols>
Stencil<T, rows, cols>::Stencil(Stencil &&o)noexcept
        :boundaryStencil_(o.boundaryStencil_),innerStencil_(o.innerStencil_){}


template<typename T, size_t rows, size_t cols>        //operator ()
const T& Stencil<T, rows, cols>::operator() (int row, int col) const {
    if (row == 0 && col == 0) return boundaryStencil_[0].second;
    else if (row == size_-1 && col == size_-1) return boundaryStencil_[0].second;
    else if (row == col) return innerStencil_[1].second;
    else if (row == col+1) return innerStencil_[0].second;
    else if (row == col-1) return innerStencil_[2].second;
    else return rest_;
}


template<typename T, size_t rows, size_t cols>        //operator () #2
T& Stencil<T, rows, cols>::operator() (int row, int col) {

    if (row == 0 && col == 0) return boundaryStencil_[0].second;
    else if (row == size_-1 && col == size_-1) return boundaryStencil_[0].second;
    else if (row == col) return innerStencil_[1].second;
    else if (row == col+1) return innerStencil_[0].second;
    else if (row == col-1) return innerStencil_[2].second;

    else return rest_;
}

template <typename T, size_t rows, size_t cols>
Vector<T,rows> Stencil<T,rows,cols>::operator* (const Vector<T,rows> & obj) const
{

    Vector<T, rows> res(0.);
    res.p_data[0]=obj.p_data[0]*boundaryStencil_[0].second;
    res.p_data[obj.size()-1]=obj.p_data[obj.size()-1]*boundaryStencil_[0].second;
    auto inner0 = std::find_if(innerStencil_.begin(), innerStencil_.end(), [](const StencilEntry<T>& p){return p.first==-1;} );
    auto inner1 = std::find_if(innerStencil_.begin(), innerStencil_.end(), [](const StencilEntry<T>& p){return p.first==0;} );
    auto inner2 = std::find_if(innerStencil_.begin(), innerStencil_.end(), [](const StencilEntry<T>& p){return p.first==1;} );
    for (int i=1; i<obj.size()-1; i++){
        res.p_data[i]=obj.p_data[i-1]*inner0->second+obj.p_data[i]*inner1->second+obj.p_data[i+1]*inner2->second;
    }
    return res;
}

template<typename T, size_t rows, size_t cols>
Stencil<T, rows, cols> Stencil<T, rows, cols>:: inverseDiagonal( ) const {
    auto inner = std::find_if(innerStencil_.begin(), innerStencil_.end(), [](const StencilEntry<T>& p){return p.first==0;} );
    Stencil<T, rows, cols> res({ {0,1.} }, { {-1,0}, {0, 1.0 / inner->second} ,{1,0} });
    res.size_ = this->size_;

    return res;
}
