
#pragma once
#ifndef ASSIGNMENTB_MATRIX_H
#define ASSIGNMENTB_MATRIX_H
#include <iostream>
#include <cassert>
#include "MatrixLike.h"

template <typename T, size_t x, size_t y> class Matrix : public MatrixLike<T, Matrix<T, x, y>, x, y>
{
public:
    friend class Vector<T, x>;

    T *m_data;
    size_t rows_, cols_; //Dimensions: m rows and cols_ columns

    Matrix()
    {
        m_data = NULL;
    }

    //constructor
    Matrix(T initValue)
    {   this->rows_ = x;
        this->cols_ = y;
        m_data = new T [this->rows() * cols_];
        for (size_t i = 0; i < this->rows(); ++i)
            for (size_t j = 0; j < this->cols(); ++j)
                m_data[i * cols_ + j] = initValue;
    }

    //destructor
    ~Matrix()
    {
        delete[] m_data; // = NULL;
    }

    //copy constructor
    Matrix(const Matrix &ob)
    {
        this->rows_ = ob.rows_;
        this->cols_ = ob.cols_;
        m_data = new T[this->rows_ * cols_];
        for (size_t i = 0; i < this->rows_; ++i)
            for (size_t j = 0; j < this->cols_; ++j)
                m_data[i * cols_ + j] = ob.m_data[i * this->cols_ + j];
    }

    //assignment operator
    Matrix<T, x, y>& operator=(const Matrix<T, x, y> &ob); //done
    T& operator=(const T& ob);

    T& operator() (int i, int j) ; //done
    const T& operator() (int i, int j) const ; //done

    bool operator ==(const Matrix<T, x, y>&) const; //done
    bool operator !=(const Matrix<T, x, y>&) const; //done

    Matrix<T, x, y>& operator +=(const Matrix<T, x, y>&);
    Matrix<T, x, y> operator +(const Matrix<T, x, y>&) const;
    Matrix<T, x, y>& operator -=(const Matrix<T, x, y>&);
    Matrix<T, x, y> operator -(const Matrix<T, x, y>&) const;
    Matrix<T, x, y>& operator *=(const Matrix<T, x, y>&);
    Matrix<T, x, y> operator *(const Matrix<T, x, y>&) const;

    std::size_t rows() const;
    std::size_t cols() const;

    Matrix<T, x, y> inverseDiagonal() const;

    template <typename U, size_t x1, size_t y1> friend std::ostream& operator <<(std::ostream&, const Matrix<U, x1, y1>&);

    template <typename Y, size_t x2, size_t y2> friend std::istream& operator >>(std::istream&, Matrix<Y, x2, y2>&);

    Vector<T, x> operator* (const Vector<T, x> &) const;
};

template <typename T, size_t x, size_t y> Vector<T, x> Matrix<T, x, y>::operator* (const Vector<T, x> &ob) const
{
    size_t row = this->rows();
    Vector<T, x> res(0.);

    for (size_t i = 0; i < row; ++i)
        for (size_t k = 0; k < this->cols(); ++k)
            res.p_data[i] += this->m_data[i * this->cols() + k] * ob.p_data[k];

    return res;
}


template <typename T, size_t x, size_t y> Matrix<T, x, y> Matrix<T, x, y>::inverseDiagonal() const
{
    Matrix<T, x, y> res(0.);

    for (size_t i = 0; i < this->rows(); ++i)
        for (size_t j = 0; j < this->rows(); ++j)
            if (i == j) res.m_data[i*this->rows() + j] = 1/m_data[i*this->rows() + j];
            else res.m_data[i*this->rows() + j] = 0;

    return res;
}

template <typename T, size_t x, size_t y> T& Matrix<T, x, y>::operator()(int i, int j)
{
    return this->m_data[i*this->cols_ + j];
}

template <typename T, size_t x, size_t y> const T& Matrix<T, x, y>::operator()(int i, int j) const
{
    return this->m_data[i*this->cols() + j];
//    if (i<=this->rows() && j <= cols_)
//        return m_data[i * cols_ + j];
//    else return m_data[0];
}

template <typename T, size_t x, size_t y> Matrix<T, x, y>& Matrix<T, x, y>::operator= (const Matrix<T, x, y> &ob)
{
    if (this->rows() * cols_ != ob.x * ob.cols_)
    {
        delete[] m_data;
        m_data = new T[ob.x*ob.cols_];
    }
    this->rows_ = ob.rows_;
    cols_ = ob.cols_;
    for (size_t i = 0; i < this->rows(); ++i)
        for (size_t j = 0; j < cols_; ++j)
            m_data[i * cols_ + j] = ob.m_data[i * cols_ + j];

    return *this;
}

template <typename T, size_t x, size_t y> bool Matrix<T, x, y>::operator== (const Matrix<T, x, y> &ob) const
{
    bool res = true;
    bool bre = false;

    if (this->rows() != ob.rows() || this-> cols_ != ob.cols_)
        res = false;
    if (res)
    {
        for (size_t i = 0; i < this->rows(); ++i)
        {
            if (bre)
                break;
            for (size_t j = 0; j < cols_; ++j)
                if (m_data[i * cols_ + j] != ob.m_data[i * cols_ + j])
                {
                    res = false;
                    bre = true;
                    break;
                }
        }
    }

    return res;
}

template <typename T, size_t x, size_t y> bool Matrix<T, x, y>::operator!= (const Matrix<T, x, y> &ob) const
{
    if (this->rows() != ob.rows() || cols_ != ob.cols_)
        return true;
    for (size_t i = 0; i < this->rows(); ++i)
        for (size_t j = 0; j < cols_; ++j)
            if (m_data[i * cols_ + j] != ob.m_data[i * cols_ + j])
                return true;

    return false;
}

template <typename T, size_t x, size_t y> Matrix<T, x, y>& Matrix<T, x, y>::operator+= (const Matrix<T, x, y>&ob)
{
    //same _size test
    assert(this->rows()== ob.rows_ && cols_ == ob.cols_);
    for (size_t i = 0; i < ob.rows_; ++i)
        for (size_t j = 0; j < ob.cols_; ++j)
            m_data[i * this-> cols_ + j] += ob.m_data[i * ob.cols_ + j];

    return *this;
}

template <typename T, size_t x, size_t y> Matrix<T, x, y> Matrix<T, x, y>::operator+ (const Matrix<T, x, y>&ob) const
{
    assert(this->rows() == ob.rows() && this-> cols_ == ob.cols_);
    Matrix res(this->rows(), this->cols_, 0);

    for (size_t i = 0; i < this->rows(); ++i)
        for (size_t j = 0; j < this->cols(); ++j)
            res.m_data[i * this->cols() + j] = this->m_data[i * this->cols() + j] + ob(i, j);

    return res;
}

template <typename T, size_t x, size_t y> Matrix<T, x, y>& Matrix<T, x, y>::operator-= (const Matrix<T, x, y>&ob)
{
    assert(this->rows() == ob.rows() && cols_ == ob.cols_);

    for (size_t i = 0; i < this->rows(); ++i)
        for (size_t j = 0; j < cols_; ++j)
            m_data[i * cols_ + j] = m_data[i * cols_ + j] - ob.m_data[i * cols_ + j];

    return *this;

}

template <typename T, size_t x, size_t y> Matrix<T, x, y> Matrix<T, x, y>::operator- (const Matrix<T, x, y>&ob) const
{
    assert(this->x == ob.x && this->cols_ == ob.cols_);
    Matrix res(this->x, this->cols_, 0.0);

    for (size_t i = 0; i < this->rows(); ++i)
        for (size_t j = 0; j < cols_; ++j)
            res.m_data[i * cols_ + j] = this->m_data[i * cols_ + j] - ob(i, j);

    return res;
}

template <typename T, size_t x, size_t y> Matrix<T, x, y>& Matrix<T, x, y>::operator *=(const Matrix<T, x, y>& ob)
{
    assert(this->cols_ == ob.x);
    Matrix res(this->x, ob.cols_, 0);

    for (size_t i = 0; i < res.x; ++i)
        for (size_t j = 0; j < res.cols_; ++j)
            for (size_t k = 0; k < this->cols_; ++k)
                res.m_data[i * res.cols_ + j] += this->m_data[i * this->cols_ + k] * ob.m_data[k * ob.cols_ + j];

    this->rows_ = res.x;
    cols_ = res.cols_;
    for (size_t i = 0; i < this->rows(); ++i)
        for (size_t j = 0; j < ob.cols_; ++j)
            m_data[i*ob.cols_ + j] = res.m_data[i * ob.cols_ + j];

    return *this;
}

template <typename T, size_t x, size_t y> Matrix<T, x, y> Matrix<T, x, y>::operator*(const Matrix<T, x, y>& ob) const
{
    assert(this->cols_ == ob.x);
    Matrix res(this->x, ob.cols_, 0);

    for (size_t i = 0; i < res.x; ++i)
        for (size_t j = 0; j < res.cols_; ++j)
            for (size_t k = 0; k < this->cols_; ++k)
                res.m_data[i * res.cols_ + j] += this->m_data[i * this->cols_ + k] * ob.m_data[k * ob.cols_ + j];

    return res;
}

template <typename T, size_t x, size_t y> size_t Matrix<T, x, y>::rows() const
{
    return this->rows_;
}

template <typename T, size_t x, size_t y> size_t Matrix<T, x, y>::cols() const
{
    return this->cols_;
}

template <typename T, size_t x, size_t y> std::ostream& operator << (std::ostream &out, const Matrix<T, x, y> &ob)
{
    for (size_t i = 0; i < ob.rows(); ++i)
    {
        for (size_t j = 0; j < ob.cols_; ++j)
            out << ob.m_data[i * ob.cols_ + j] << " ";

        out << "\n";
    }

    return out;
}

template <typename T, size_t x, size_t y> std::istream& operator >> (std::istream &in, Matrix<T, x, y> &ob)
{
    for (size_t i = 0; i < ob.rows(); ++i)
    {
        for (size_t j = 0; j < ob.cols_; ++j)
            in >> ob.m_data[i * ob.cols_ + j];

        std::cout << "\n";
    }

    return in;
}

#endif
