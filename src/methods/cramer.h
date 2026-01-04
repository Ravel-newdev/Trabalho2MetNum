#ifndef CRAMER_H
#define CRAMER_H

#include <cmath>
#include <vector>
#include <string> 

#include "matriz.h"
#include "gauss.h"
#include "gauss_jordan.h"
#include "cramer_resultado.h"

inline matriz montar_Ci(const matriz& C, const std::vector<double>& v, int col) {
    int n = C.n;
    matriz Ci(C);

    for (int i = 0; i < n; i++) {
        Ci(i, col) = v[i];
    }

    return Ci;
}

inline CramerResultado cramer_gauss(const matriz& C, const std::vector<double>& v, double a) {
    int n = C.n;
    CramerResultado R;

    R.method = "Gauss";
    R.d.resize(n);
    R.amplitude.resize(n);
    R.rompeu.resize(n);

    double detC = determinante_gauss(C);
    R.detC = detC;

    if (std::fabs(detC) < 1e-9) {
        R.solucao_unica = false;
        return R;
    }

    R.solucao_unica = true;

    for (int i = 0; i < n; i++) {
        matriz Ci = montar_Ci(C, v, i);
        double detCi = determinante_gauss(Ci);

        double di = detCi / detC;
        double amp = a * di;

        R.d[i] = di;
        R.amplitude[i] = amp;
        R.rompeu[i] = (std::fabs(amp) > 3.0);
    }

    return R;
}

inline CramerResultado cramer_gauss_jordan(const matriz& C, const std::vector<double>& v, double a) {
    int n = C.n;
    CramerResultado R;

    R.method = "Gauss-Jordan";
    R.d.resize(n);
    R.amplitude.resize(n);
    R.rompeu.resize(n);

    double detC = determinante_gauss_jordan(C);
    R.detC = detC;

    if (std::fabs(detC) < 1e-9) {
        R.solucao_unica = false;
        return R;
    }

    R.solucao_unica = true;

    for (int i = 0; i < n; i++) {
        matriz Ci = montar_Ci(C, v, i);
        double detCi = determinante_gauss_jordan(Ci);

        double di = detCi / detC;
        double amp = a * di;

        R.d[i] = di;
        R.amplitude[i] = amp;
        R.rompeu[i] = (std::fabs(amp) > 3.0);
    }

    return R;
}

#endif