#ifndef GAUSS_H
#define GAUSS_H

#include <cmath>
#include <algorithm>
#include "matriz.h"

double determinante_gauss(const matriz& A) {
    int n = A.n;
    matriz M(A);
    double det = 1.0;
    int trocas = 0;

    for (int k = 0; k < n - 1; k++) {

        // pivoteamento parcial
        int pivot = k;
        for (int i = k + 1; i < n; i++) {
            if (std::fabs(M(i, k)) > std::fabs(M(pivot, k)))
                pivot = i;
        }

        if (std::fabs(M(pivot, k)) < 1e-12)
            return 0.0;

        if (pivot != k) {
            for (int j = 0; j < n; j++)
                std::swap(M(k, j), M(pivot, j));
            trocas++;
        }

        for (int i = k + 1; i < n; i++) {
            double fator = M(i, k) / M(k, k);
            for (int j = k; j < n; j++)
                M(i, j) -= fator * M(k, j);
        }
    }

    for (int i = 0; i < n; i++)
        det *= M(i, i);

    if (trocas % 2 != 0)
        det *= -1.0;

    return det;
}

#endif
