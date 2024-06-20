#include <iostream>
#include <chrono>

#include "Vector.h"
#include "Matrix.h"
#include "Stencil.h"

#define PI 3.141592653589793

template<typename T, typename MatrixImpl, size_t numPoints>
void solve (
        const MatrixLike<T, MatrixImpl, numPoints, numPoints>& A,
        const Vector<T, numPoints>& b,
        Vector<T, numPoints>& u)
{

    double initRes = (b - A * u).l2Norm( ); // determine the initial residual
    double curRes = initRes;
    std::cout << "Initial residual:\t\t" << initRes << std::endl;

    unsigned int curIt = 0; // store the current iteration index

    while (curRes > 1.e-5 * initRes) { // solve until the residual is reduced by a certain amount
        ++curIt;

        u += A.inverseDiagonal( ) * (b - A * u); // Jacobi step

       // std::cout << u;
        //std::cout <<"--------";


        curRes = (b - A * u).l2Norm( ); // update the residual

        if (0 == curIt % 500) // print some info every few steps
            std::cout << "Residual after iteration " << curIt << ":\t" << curRes << std::endl;
    }

    std::cout << "Residual after iteration " << curIt << ":\t" << curRes << std::endl << std::endl; // print the final number of iterations and the final residual
}

template <size_t numGridPoints> void testFullMatrix (/*const int numGridPoints*/)
{
	const double hx = 1. / (numGridPoints - 1);
	const double hxSq = hx * hx;

	std::cout << "Starting full matrix solver for " << numGridPoints << " grid points" << std::endl;

	Matrix<double, numGridPoints, numGridPoints> A(0);
	Vector<double, numGridPoints> u(0.);
	Vector<double, numGridPoints> b(0.);

	A(0, 0) = 1.;
	for (int x = 1; x < numGridPoints - 1; ++x) {
		A(x, x-1) = 1. / hxSq;
		A(x, x) = -2. / hxSq;
		A(x, x + 1) = 1. / hxSq;
	}
	A(numGridPoints - 1, numGridPoints - 1) = 1.;

	for (int x = 0; x < numGridPoints; ++x) {
		b(x) = sin(2. * PI * (x / (double)(numGridPoints - 1)));
	}

	std::cout << "Initialization complete\n";

	// TODO: start timing
    auto start = std::chrono::system_clock::now();

	solve(A, b, u);

	// TODO: end timing and print elapsed time
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Normal elapsed time: " << elapsed_seconds.count() << "s\n";
}

template <size_t numGridPoints> void testStencil (/*const size_t numGridPoints*/)
{

    const double hx = 1. / (numGridPoints - 1);
    const double hxSq = hx * hx;
	// TODO: add stencil code
	//the stencil can be set up using
	    Stencil<double, numGridPoints, numGridPoints> ASten({ { 0, 1. } }, { { -1, 1. / hxSq },{ 0, -2. / hxSq },{ 1, 1. / hxSq } });

    Vector<double, numGridPoints> u(0.);
    Vector<double, numGridPoints> b(0.);
    for (int x = 0; x < numGridPoints; ++x)
    {
        b(x) = sin(2. * PI * (x / (double)(numGridPoints - 1)));
    }

    std::cout << "Stencil Initialization complete\n";

    // TODO: start timing
    auto start = std::chrono::system_clock::now();

    solve(ASten, b, u);

    // TODO: end timing and print elapsed time
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Stencil elapsed time: " << elapsed_seconds.count() << "s\n";

}

int main(int argc, char** argv)
{
	testFullMatrix<7>();
	//testStencil<4>();
}
