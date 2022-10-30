#pragma once

#include "types.h"


class KNNClassifier {
public:
    KNNClassifier(unsigned int n_neighbors);

    void fit(Matrix X, Matrix y);

    inline void setneighbors(unsigned int n_neigbors) { n_neighbors_ = n_neigbors; };

    Vector predict(Matrix X);


private:
    Label classifyimage(const Vector &image) const;
    
    // Numero de vecinos
    unsigned int n_neighbors_;
    // Base
    Matrix images_;
    Matrix labels_;
};
