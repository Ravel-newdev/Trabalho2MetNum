#include <iostream>
#include "matriz.h"
#include "cramer.h"

#include <iostream>
#include "matriz.h"
#include "cramer.h"

int main() {
    int n;
    std::cin >> n;

    double **C = alocar_matriz(n);
    double *v = new double[n];
    double *d = new double[n];

    // leitura da matriz C
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> C[i][j];

    // leitura do vetor v
    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    // ITEM (a) ACONTECE AQUI ↓↓↓
    if (cramer_gauss(C, v, d, n)) {
        for (int i = 0; i < n; i++)
            std::cout << "d[" << i+1 << "] = " << d[i] << std::endl;
    } else {
        std::cout << "Sistema sem solução única\n";
    }

    liberar_matriz(C, n);
    delete[] v;
    delete[] d;

    return 0;
}
