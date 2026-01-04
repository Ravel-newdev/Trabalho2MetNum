#include <iostream>
#include <cmath>
#include "./matriz.h"

double **alocar_matriz(int n) {
    double **A = new double*[n];
    for (int i = 0; i < n; i++)
        A[i] = new double[n];
    return A;
}

void liberar_matriz(double **A, int n) {
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;
}

double **copiar_matriz(double **A, int n) {
    double **B = alocar_matriz(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = A[i][j];
    return B;
}

double determinante_gauss(double **A, int n) {
    double **M = copiar_matriz(A, n);
    double det = 1.0;

    for (int k = 0; k < n - 1; k++) {
        if (fabs(M[k][k]) < 1e-9) {
            det = 0.0;
            break;
        }

        for (int i = k + 1; i < n; i++) {
            double m = M[i][k] / M[k][k];
            for (int j = k; j < n; j++) {
                M[i][j] -= m * M[k][j];
            }
        }
    }

    if (det != 0.0) {
        for (int i = 0; i < n; i++)
            det *= M[i][i];
    }

    liberar_matriz(M, n);
    return det;
}

double **montar_Ci(double **C, double *v, int n, int col) {
    double **Ci = alocar_matriz(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == col)
                Ci[i][j] = v[i];
            else
                Ci[i][j] = C[i][j];
        }
    }

    return Ci;
}
