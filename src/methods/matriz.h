#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <cmath>

class matriz {
    public:
        int n;
        double* m;

        // construtor
        matriz(int n_) : n(n_) {
            m = new double[n * n];
            for (int i = 0; i < n * n; i++)
                m[i] = 0.0;
        }

        // construtor de cópia
        matriz(const matriz& other) : n(other.n) {
            m = new double[n * n];
            for (int i = 0; i < n * n; i++)
                m[i] = other.m[i];
        }

        // destrutor
        ~matriz() {
            delete[] m;
        }

        // atribuição
        matriz& operator=(const matriz& other) {
            if (this != &other) {
                delete[] m;
                n = other.n;
                m = new double[n * n];
                for (int i = 0; i < n * n; i++)
                    m[i] = other.m[i];
            }
            return *this;
        }

        // acesso (linha, coluna)
        double& operator()(int i, int j) {
            return m[i * n + j];
        }

        const double& operator()(int i, int j) const {
            return m[i * n + j];
        }

        // matriz identidade
        static matriz identidade(int n) {
            matriz I(n);
            for (int i = 0; i < n; i++)
                I(i, i) = 1.0;
            return I;
        }

        void print() const {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    std::cout << (*this)(i, j) << " ";
                std::cout << std::endl;
            }
        }
};

#endif