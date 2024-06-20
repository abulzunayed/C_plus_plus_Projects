
#ifndef Matrix_hpp
#define Matrix_hpp
#include <stdio.h>
#include <iostream>
#include <ostream>
#include <iomanip>
# include <assert.h>
#include <cstdlib>
#include <stdexcept>
#endif /* matrix_hpp */

using namespace std;

class Matrix
{
        private:
            // double **vals;
            const size_t ROWS;
            const size_t COLS;
            double *vals;
            inline double& at(size_t r, size_t c) const
            {
                return vals[COLS * r + c];
            }

        public:
            Matrix(size_t rows, size_t cols, double initValue);
            ~Matrix();
            inline size_t rows(void) const {return ROWS;}
            inline size_t cols(void) const {return COLS;}
            double getValueAt(size_t r, size_t c) const;
            void setValueAt(double v, size_t r, size_t c);

            Matrix(const Matrix &m);
            void display();
            void accept();
            size_t rows();
            size_t cols();
            void fillRandom(void);
            double& operator()(size_t r, size_t c);
            double operator()(size_t r, size_t c) const;

            Matrix operator =(const Matrix &m2)
            {
                if (this != &m2) {
                    if (ROWS != m2.ROWS or COLS != m2.COLS){
                        throw std::out_of_range("Cannot assign matrix with different dimensions");
                    }
                    for (int i = 0; i < ROWS * COLS; ++i){
                        vals[i] = m2.vals[i];
                    }
                }
                return *this; //we return reference not a pointer.
            }
            Matrix sum(const Matrix &m2);
            Matrix diff(const Matrix &m2);
            Matrix operator +(const Matrix &m2);
            Matrix operator -(const Matrix &m2);
            Matrix operator *(const Matrix &m2);
            Matrix operator +=(const Matrix &m2);
            Matrix operator -=(const Matrix &m2);
            Matrix operator *=(const Matrix &m2);
            bool operator ==(const Matrix &m2);
            bool operator !=(const Matrix &m2);

};

Matrix::Matrix(size_t rows, size_t cols, double initValue) :
    ROWS(rows), COLS(cols)
{
    vals = new double[ROWS*COLS];
    for (int i = 0; i < ROWS*COLS; i++)
        vals[i] = initValue;
}

Matrix::~Matrix()
{
    delete[] vals;
}

Matrix::Matrix(const Matrix &m) : ROWS(m.ROWS), COLS(m.COLS)
{ // copy constructor
    vals = new double[ROWS*COLS];
    for (int i = 0; i < ROWS*COLS; i++)
    {
        vals[i] = m.vals[i];
    }
}

void Matrix::fillRandom(void)
{
    for(int r=0; r<ROWS; ++r){
        for (int c = 0; c<COLS; ++c){
            at(r,c) = (rand() % 100) / 10.0; // set vals[COLS * r + c]
        }
    }
}

double Matrix::getValueAt(size_t r, size_t c) const
{
    if(r >= ROWS or c >= COLS){
        throw std::out_of_range("Out of range at Matrix::getValueAt");
    }
    return at(r, c);
}
void Matrix::setValueAt(double v, size_t r, size_t c)
{
    if(r >= ROWS or c >= COLS){
        throw std::out_of_range("Out of range at Matrix::getValueAt");
    }
    at(r, c) = v;
}


// use the reference for modification of the cell value.
double& Matrix::operator()(size_t r, size_t c)
{
    return at(r,c);
}
// copy the value for the const operator.
double Matrix::operator()(size_t r, size_t c) const
{
    return at(r,c);
}

void Matrix::display()
{
    //cout <<"The matrix is:";
    for(int i = 0; i < ROWS; i++)
    {
        cout <<endl;
        for(int j = 0; j < COLS; j++)
        {
            //ideal cout << vals[i][j] <<" ";
            //1D transformation: vals[i][j] is vals[i*COLS + j]
            cout << vals[i*COLS + j] <<" ";
        }
    }
    std::cout<<'\n'<< endl;
}

void print(const Matrix& m)
{
std:cout<<std::fixed <<std::setprecision(1);
    for (size_t r = 0; r < m.rows(); ++r){
        for (size_t c = 0; c < m.cols(); ++c){
            std::cout<<(c > 0 ? " ": "") <<std::setw(4);
            std::cout<<m.getValueAt(r, c);
        }
        std::cout<< std::endl;
    }
}

size_t Matrix::rows()
{
    return ROWS;
}

size_t Matrix::cols()
{
    return COLS;
}

Matrix Matrix::sum(const Matrix &m2)
{
    if (ROWS != m2.ROWS or COLS != m2.COLS)
    {
        throw std::invalid_argument("Matrix dimensions do not match at Matrix::sum");
    }
    Matrix ret(ROWS, COLS, 0);
    //for(int i = 0; i < ROWS*COLS; i++)
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            //std::cout<<m2.getValueAt(i,j)<<endl;
            ret.setValueAt((vals[i*COLS+j] + m2.getValueAt(i,j)), i, j);
        }
    }
    return ret;
}

Matrix Matrix::diff(const Matrix &m2)
{
    if (ROWS != m2.ROWS or COLS != m2.COLS)
    {
        throw std::invalid_argument("Matrix dimensions do not match at Matrix::sum");
    }
    Matrix ret(ROWS, COLS, 0);
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            ret.setValueAt((vals[i*COLS+j] - m2.getValueAt(i,j)), i, j);
        }
    }
    return ret;
}

// method definition for the matrix sum operation.
Matrix Matrix::operator +(const Matrix &m2)
{
    return sum(m2);
}

// method definition for the matrix subtraction operation.
Matrix Matrix::operator -(const Matrix &m2)
{

    return diff(m2);
}

// method definition for the matrix multiplication operation.
Matrix Matrix::operator *(const Matrix &m2)
{
    Matrix m3(rows(), m2.cols(), 0.0);
    for (int r=0; r < rows(); ++r){
        for (int c = 0; c < m2.cols(); ++c){
            m3(r,c)= 0.0;
            for (int k = 0; k < cols(); ++k){
                m3(r, c) += (*this)(r, k) * m2(k, c);
            }
        }
    }
    return m3;
}


Matrix Matrix::operator +=(const Matrix &m2)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            vals[i*COLS+j]=sum(m2).getValueAt(i,j);
        }
    }
    return sum(m2);
}

Matrix Matrix::operator -=(const Matrix &m2)
{
//    Matrix ret(ROWS, COLS, 0);
//    ret = diff(m2);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            vals[i*COLS+j]=diff(m2).getValueAt(i,j);
        }
    }
    return diff(m2);
}

Matrix Matrix::operator *=(const Matrix &m2)
{
    *this = *this * m2;

    return m2;
}

bool Matrix::operator ==(const Matrix &m2)
{
    // assert size of matrix 1 equals size of m2.
    // the size of a matrix is it's number of rows and columns.

    size_t num_rows;
    size_t num_cols;

    num_rows = m2.rows();
    num_cols = m2.cols();

    if (ROWS != num_rows)
    {
        return false;
    }
    if (COLS != num_cols)
    {
        return false;
    }

    // element wise comparison of matrix 1 and matrix 2.
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if (vals[i*COLS+j] != m2.getValueAt(i, j))
            {
                    return false;
            }
        }
    }
    return true;
}

bool Matrix::operator !=(const Matrix &m2)
{
    // assert size of matrix 1 equals size of m2.
    // the size of a matrix is it's number of rows and columns.

    size_t num_rows;
    size_t num_cols;

    num_rows = m2.rows();
    num_cols = m2.cols();

    if (ROWS != num_rows)
    {
        return true;
    }
    if (COLS != num_cols)
    {
        return true;
    }

    // element wise comparison of matrix 1 and matrix 2.
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            //ideal: if (vals[i][j] != m2.vals[i][j])
            //1D transformation: vals[1][i*COLS + j] != m2.vals[1][i*COLS + j]
            if (vals[i*COLS + j] != m2.vals[i*COLS + j])
            {
                return true;
            }
        }
    }
    return false;
}

std::ostream& operator<< (std::ostream& out, const Matrix& m);
std::ostream& operator<< (std::ostream& out, const Matrix& m)
{
    if (out) {
        out << std::fixed <<std::setprecision(1);
        for (int r = 0; r < m.rows(); ++r){
            for (int c = 0; c < m.cols(); ++c) {
                out << (c > 0 ? " " : "") << std::setw(4);
                out << m.getValueAt(r, c);
            }
            out << std::endl;
        }
    }
    return out;
}

//std::istream& operator>> (std::istream& out, const Matrix& m);
//std::istream& operator>> (std::istream& out, const Matrix& m)
//{
//    int rows, cols;
//    out >> rows >> cols;
//    if (!out)
//        return out;
//    Matrix tmp(rows, cols, 0.0);
//    if (rows*cols>0){
//        cout << "Enter " << cols*rows<<"values (top row, second row ... last row - left to right)" << endl;
//        for (int i=0; i<rows; i++)
//        {
//            for (int j=0; j<cols; j++)
//            {
//                out >> tmp.getValueAt(i, j);
//            }
//        }
//    }
//    if (out)
//        m = tmp;
//    m.swap(tmp);
//    return out;
//}
//

