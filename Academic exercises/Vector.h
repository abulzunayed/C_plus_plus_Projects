

#ifndef ASSIGNMENTSA_Vector_H
#define ASSIGNMENTSA_Vector_H

#include <iostream>
#include <cassert>
#include <math.h>

template <class T, std::size_t rows> class Vector
{
public:
    T *p_data;
    size_t _size, x, len_; //Dimensions: _size rows and cols_ = 1 columns

    Vector()
    { p_data = NULL;
    }

    //constructor
    Vector(T initValue)
    {   _size = rows;
        len_ = _size;
        x = 1;
        p_data = new T [_size];
        for (size_t i = 0; i < _size; ++i)
            p_data[i] = initValue;
    }

    //destructor
    ~Vector()
    { delete[] p_data; // = NULL;
    }

    //copy constructor
    Vector(const Vector &ob)
    {   _size = ob._size;
        p_data = new T[_size];
        for (size_t i = 0; i < _size; ++i)
            p_data[i] = ob.p_data[i];
    }

    //assignment operator
    Vector<T, rows>& operator=(const Vector<T, rows> &ob); //done
    T& operator=(const T& ob);

    T& operator()(std::size_t i); //done
    const T& operator()(std::size_t i) const; //done

    bool operator ==(const Vector<T, rows>&) const; //done
    bool operator !=(const Vector<T, rows>&) const; //done

    Vector<T, rows>& operator +=(const Vector<T, rows>&);
    Vector<T, rows> operator +(const Vector<T, rows>&) const;
    Vector<T, rows>& operator -=(const Vector<T, rows>&);
    Vector<T, rows> operator -(const Vector<T, rows>&) const;
    Vector<T, rows>& operator *=(const Vector<T, rows>&);
    Vector<T, rows> operator *(const Vector<T, rows>&) const;
    Vector<T, rows> operator* (const T ob) const;

    std::size_t size() const;

    double l2Norm() const;


};

template <class T, std::size_t rows> Vector<T, rows> Vector<T, rows>::operator* (const T ob) const
{
    Vector<T, rows> res(_size, 0);
    for (size_t i = 0; i < this->_size; ++i)
        res(i) = this->p_data[i] * ob;

    return res;
}

template <class T, std::size_t rows> double Vector<T, rows>::l2Norm() const
{
    double norm = 0.;
    for (size_t i = 0; i < this->_size; ++i)
        norm += this->p_data[i] * this->p_data[i];

    return sqrt(norm);
}

template <class T, std::size_t rows> T& Vector<T, rows>::operator=(const T& ob)
{
    return ob;
}

template <class T, std::size_t rows> T& Vector<T, rows>::operator()(std::size_t i)
{
    return this->p_data[i * x];
}

template <class T, std::size_t rows> const T& Vector<T, rows>::operator()(std::size_t i) const
{
    size_t j = 1;
    if (i <= _size)
        return p_data[i * x + j];
    else return p_data[0];
}

template <class T, std::size_t rows> Vector<T, rows>& Vector<T, rows>::operator= (const Vector<T, rows> &ob)
{
    if (_size * x != ob._size * ob.x)
    {
        delete[] p_data;
        p_data = new T[ob._size * ob.x];
    }
    _size = ob._size;
    x = ob.x;
    for (size_t i = 0; i < _size; ++i)
        for (size_t j = 0; j < x; ++j)
            p_data[i * x + j] = ob.p_data[i * x + j];

    return *this;
}

template <class T, std::size_t rows> bool Vector<T, rows>::operator== (const Vector<T, rows> &ob) const
{
    bool res = true;
    bool bre = false;

    if (this->_size != ob._size || this-> x != ob.x)
        res = false;
    if (res)
    {
        for (size_t i = 0; i < _size; ++i)
        {
            if (bre)
                break;
            for (size_t j = 0; j < x; ++j)
                if (p_data[i * x + j] != ob.p_data[i * x + j])
                {
                    res = false;
                    bre = true;
                    break;
                }
        }
    }

    return res;
}

template <class T, std::size_t rows> bool Vector<T, rows>::operator!= (const Vector<T, rows> &ob) const
{
    if (_size != ob._size || x != ob.x)
        return true;
    for (size_t i = 0; i < _size; ++i)
        for (size_t j = 0; j < x; ++j)
            if (p_data[i * x + j] != ob.p_data[i * x + j])
                return true;

    return false;
}

template <class T, std::size_t rows> Vector<T, rows>& Vector<T, rows>::operator+= (const Vector<T, rows>& ob)
{
    //same _size test
    assert(_size == ob._size);

    for (size_t i = 0; i < this->_size; ++i)
        this->p_data[i] += ob.p_data[i];

    return *this;
}

template <class T, std::size_t rows> Vector<T, rows> Vector<T, rows>::operator+ (const Vector<T, rows>&ob) const
{
    assert(this->_size == ob._size && this-> x == ob.x);
    Vector res(this->_size, this->x, 0);

    for (size_t i = 0; i < this->_size; ++i)
        for (size_t j = 0; j < this->x; ++j)
            res.p_data[i * x + j] = this->p_data[i * x + j] + ob(i, j);

    return res;
}

template <class T, std::size_t rows> Vector<T, rows>& Vector<T, rows>::operator-= (const Vector<T, rows>&ob)
{
    assert(_size == ob._size && x == ob.x);

    for (size_t i = 0; i < _size; ++i)
        for (size_t j = 0; j < x; ++j)
            p_data[i * x + j] = p_data[i * x + j] - ob.p_data[i * x + j];

    return *this;

}

template <class T, std::size_t rows> Vector<T, rows> Vector<T, rows>::operator- (const Vector<T, rows>&ob) const
{
    assert(this->_size == ob._size);
    Vector<T, rows> res(0.);

    for (size_t i = 0; i < this->size(); ++i)
        res.p_data[i] = this->p_data[i] - ob.p_data[i];

    return res;
}

template <class T, std::size_t rows> Vector<T, rows>& Vector<T, rows>::operator *=(const Vector<T, rows>& ob)
{
    assert(this->x == ob._size);
    Vector res(this->_size, ob.x, 0);

    for (size_t i = 0; i < res._size; ++i)
        for (size_t j = 0; j < res.x; ++j)
            for (size_t k = 0; k < this->x; ++k)
                res.p_data[i * res.x + j] += this->p_data[i * this->x + k] * ob.p_data[k * ob.x + j];

    _size = res._size;
    x = res.x;
    for (size_t i = 0; i < _size; ++i)
        for (size_t j = 0; j < ob.x; ++j)
            p_data[i * ob.x + j] = res.p_data[i * ob.x + j];

    return *this;
}

template <class T, std::size_t rows> Vector<T, rows> Vector<T, rows>::operator*(const Vector<T, rows>& ob) const
{
    assert(this->x == ob._size);
    Vector res(this->_size, ob.x, 0);

    for (size_t i = 0; i < res._size; ++i)
        for (size_t j = 0; j < res.x; ++j)
            for (size_t k = 0; k < this->x; ++k)
                res.p_data[i * res.x + j] += this->p_data[i * this->x + k] * ob.p_data[k * ob.x + j];

    return res;
}

template <class T, std::size_t rows> size_t Vector<T, rows>::size() const
{
    return _size;
}


template <class T, std::size_t rows> std::ostream& operator << (std::ostream &out, const Vector<T, rows> &ob)
{
    for (size_t i = 0; i < ob._size; ++i)
    {
        for (size_t j = 0; j < ob.x; ++j)
            out << ob.p_data[i * ob.x + j] << " ";

        out << "\n";
    }
    return out;
}

template <class T, std::size_t rows> std::istream& operator >> (std::istream &in, Vector<T, rows> &ob)
{
    for (size_t i = 0; i < ob._size; ++i)
    {
        for (size_t j = 0; j < ob.x; ++j)
            in >> ob.p_data[i * ob.x + j];

        std::cout << "\n";
    }

    return in;
}


#endif
