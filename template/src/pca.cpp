#include <iostream>
#include <tuple>
#include "pca.h"
#include "eigen.h"

using namespace std;

PCA::PCA(unsigned int n_components) : n_components_(n_components)
{
}

void PCA::fit(Matrix images)
{
    /* Calculamos el valor medio de cada pixel
     *
     *     1xn             nxm         1x1                         1xm
     *
     * [1, ..., 1] * [i00, ..., i0m] * 1/n = [(i00 + ... + in0)/n, ..., (i0m + ... + inm)/n]
     *               [..., ..., ...]
     *               [in0, ..., inm]
     */
    unsigned int n = images.rows();
    unsigned int m = images.cols();
    mean_vector_ = (Vector::Ones(n).transpose() * images) / double(n);

    /* Calculamos la matriz de covarianzas
     * 
     * X = [images^(0) - mean_vector]
     *     [           ...          ]
     *     [images^(n) - mean_vector]
     * 
     * Mx = X^t * X / n - 1
     */
    Matrix X(n,m);
    for (unsigned int i = 0; i < n; i++) {
        X.row(i) = images.row(i) - mean_vector_;
    }
    Matrix Mx(m,m);
    Mx = X.transpose() * X / double(n - 1);
    // Obtenemos todos los autovectores
    // A la hora de transformar vamos a tomar los necesarios
    V_ = get_first_eigenvalues(Mx, n_components_, 5000, 1e-16).second;
}

Eigen::MatrixXd PCA::transform(Matrix X)
{
    return X * V_;
}