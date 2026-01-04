#ifndef GAUSS_JORDAN_H
#define GAUSS_JORDAN_H

#include "matriz.h"

#include <cmath>
#include "matriz.h"

double determinante_gauss_jordan(const matriz& A) {
    int n = A.n;
    matriz M(A);
    double det = 1.0;

    for (int i = 0; i < n; i++) {

        // pivoteamento parcial
        int pivot = i;
        for (int k = i + 1; k < n; k++) {
            if (std::fabs(M(k, i)) > std::fabs(M(pivot, i))) {
                pivot = k;
            }
        }

        // se o pivô for zero, determinante é zero
        if (std::fabs(M(pivot, i)) < 1e-9)
            return 0.0;

        // troca de linhas
        if (pivot != i) {
            for (int j = 0; j < n; j++)
                std::swap(M(i, j), M(pivot, j));
            det *= -1.0;
        }

        double p = M(i, i);
        det *= p;

        // normaliza a linha do pivô
        for (int j = 0; j < n; j++)
            M(i, j) /= p;

        // zera a coluna i nas outras linhas
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double fator = M(k, i);
                for (int j = 0; j < n; j++) {
                    M(k, j) -= fator * M(i, j);
                }
            }
        }
    }

    return det;
}

#endif