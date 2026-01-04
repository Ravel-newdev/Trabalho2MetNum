#include <cmath>
#include "matriz.h"
#include "cramer.h"

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

bool cramer_gauss(double **C, double *v, double *d, int n) {
    double detC = determinante_gauss(C, n);

    if (fabs(detC) < 1e-9)
        return false;

    for (int i = 0; i < n; i++) {
        double **Ci = montar_Ci(C, v, n, i);
        double detCi = determinante_gauss(Ci, n);
        d[i] = detCi / detC;
        liberar_matriz(Ci, n);
    }

    return true;
}
