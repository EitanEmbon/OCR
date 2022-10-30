#pragma once
#include "types.h"

class PCA {
public:
    PCA(unsigned int n_components);

    void fit(Matrix X);

    inline void setalpha(unsigned int alpha) { n_components_ = alpha; };

    Eigen::MatrixXd transform(Matrix X);

    Matrix getEigenVectors(){return V_;};

private:
    unsigned int n_components_;
    Vector mean_vector_;
    Matrix V_;
};
