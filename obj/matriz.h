#ifndef MATRIZ_H
#define MATRIZ_H

// Aloca matriz n x n
double **alocar_matriz(int n);

// Libera matriz n x n
void liberar_matriz(double **A, int n);

// Copia matriz n x n
double **copiar_matriz(double **A, int n);

// Calcula determinante pelo método de Gauss normal
double determinante_gauss(double **A, int n);

// Monta a matriz Ci (coluna i substituída por v)
double **montar_Ci(double **C, double *v, int n, int col);

// Resolve Cd = v pela Regra de Cramer usando Gauss normal
bool cramer_gauss(double **C, double *v, double *d, int n);

#endif
