#include <algorithm>
#include <chrono>
#include <iostream>
#include "eigen.h"

using namespace std;


pair<double, Vector> power_iteration(const Matrix& X, unsigned num_iter, double eps)
{
    Vector b = Vector::Random(X.cols());
    b = b / b.norm();
    double lambda;
    
    for (unsigned int i = 0; i < num_iter; i++) {
        Vector old = b; 
        b = X * b;
        b = b / b.norm();
        /**
         *  Criterio de parada
         *  <a, b> = |a| |b| cos(angle)
         *  -1 < cos(angle) < 1
         *  IMPORTANTE - criterio de parada adicional a niter > acelero el corte del método.
         *  Otros criterios de convergencia: angulo A*x ~ w*x 
         * 
         */
         double cos_angle = b.dot(old);
        if (((1- eps) < cos_angle) && cos_angle <= 1 )
        {
            break;
        }
    }

    lambda = b.dot(X * b);
    return make_pair(lambda, b);  
}

pair<Vector, Matrix> get_first_eigenvalues(const Matrix& X, unsigned int num, unsigned num_iter, double epsilon)
{
    Matrix A(X);
    Vector eigvalues(num);
    Matrix eigvectors(A.rows(), num);

    double lambda;
    Vector v;
    for (unsigned int i = 0; i < num; i++) {
        // Se obtiene el maximo autovalor con un autovector asociado (lambda y v)
        pair<double, Vector> pi_res = power_iteration(A, num_iter, epsilon);
        lambda = pi_res.first;
        v = pi_res.second;

        eigvalues(i) = lambda;
        eigvectors.col(i) = v;
        
        // Deflacion
        A = A - lambda * v * v.transpose();
    }

    return make_pair(eigvalues, eigvectors);
}
