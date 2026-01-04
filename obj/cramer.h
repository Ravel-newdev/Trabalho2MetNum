#ifndef CRAMER_H
#define CRAMER_H

// Monta a matriz Ci (coluna i substituída por v)
double **montar_Ci(double **C, double *v, int n, int col);

// Resolve Cd = v pela Regra de Cramer usando Gauss normal
bool cramer_gauss(double **C, double *v, double *d, int n);

// (depois) usando Gauss-Jordan
bool cramer_gauss_jordan(double **C, double *v, double *d, int n);

#endif
