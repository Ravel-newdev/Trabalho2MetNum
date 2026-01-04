#ifndef GAUSS_H
#define GAUSS_H

#include <cmath>
#include "matriz.h"

double determinante_gauss(const matriz& A) {
    int n = A.n;

    // cópia da matriz (eliminação destrói os dados)
    matriz M(A);
    double det = 1.0;

    for (int k = 0; k < n - 1; k++) {

        // Se o pivô for zero, o determinante é zero
        if (M(k, k) == 0.0) {
            det = 0.0;
            break;
        }

        // Eliminação abaixo do pivô
        for (int i = k + 1; i < n; i++) {
            double fator = M(i, k) / M(k, k);

            for (int j = k; j < n; j++) {
                M(i, j) -= fator * M(k, j);
            }
        }
    }

    // Produto da diagonal principal
    if (det != 0.0) {
        for (int i = 0; i < n; i++) {
            det *= M(i, i);
        }
    }

    return det;
}

#endif