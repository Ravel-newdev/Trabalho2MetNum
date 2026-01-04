#include "gauss.h"
#include "matriz.h"

double determinante_gauss(double **A, int n) {
    double **M = copia_matriz(A, n);
    double det = 1.0;

    for (int k = 0; k < n - 1; k++) {

        // Se o pivô for zero, o determinante é zero
        if (M[k][k] == 0.0) {
            det = 0.0;
            break;
        }

        // Eliminação abaixo do pivô
        for (int i = k + 1; i < n; i++) {
            double fator = M[i][k] / M[k][k];

            for (int j = k; j < n; j++) {
                M[i][j] -= fator * M[k][j];
            }
        }
    }

    // Produto da diagonal principal
    if (det != 0.0) {
        for (int i = 0; i < n; i++) {
            det *= M[i][i];
        }
    }

    libera_matriz(M, n);
    return det;
}
