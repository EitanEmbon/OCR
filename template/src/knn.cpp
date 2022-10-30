#include <algorithm>
// #include <eigen.h>
#include <iostream>
#include <vector>
#include "knn.h"

using namespace std;

KNNClassifier::KNNClassifier(unsigned int n_neighbors) : n_neighbors_(n_neighbors)
{
}

void KNNClassifier::fit(Matrix X, Matrix y)
{
   this->images_ = X;
   this->labels_ = y;
}

Label KNNClassifier::classifyimage(const Vector &image) const
{
    //Calculamos distancia Euclidea
    vector<double> distances(images_.rows(), 0);
    vector<unsigned int> indexes(images_.rows(), 0);
    for (unsigned int i = 0; i < images_.rows(); i++) {
        distances[i] = (image - Vector(images_.row(i))).norm();
        indexes[i] = i;
    }

    // Ordenamos los indices de las imagenes por distancia 
    sort(indexes.begin(), indexes.end(), [&distances](unsigned int a, unsigned int b){ return distances[a] < distances[b]; });
    sort(distances.begin(), distances.end());

    // Contamos la cantidad de apariciones (pesadas) de cada etiqueta dentro de los n_vecinos
    vector<Label> neighbor_label_count(10, 0);
    for (unsigned int i = 0; i < n_neighbors_; i++) {
        neighbor_label_count[labels_(indexes[i])] += (distances[i]);
    }

    // Buscamos la etiqueta con mayor cantidad de apariciones en los n_vecinos
    Label max_label = 0;
    for (size_t i = 0; i < neighbor_label_count.size(); i++) {
        if (neighbor_label_count[i] > neighbor_label_count[max_label]) {
            max_label = i;
        }
    }

    return max_label;
}

Vector KNNClassifier::predict(Matrix X)
{
    // Creamos vector columna a devolver
    auto ret = Vector(X.rows());
    for (unsigned int k = 0; k < X.rows(); k++)
    {
        ret(k) = this->classifyimage(X.row(k));
    }
    return ret;
}