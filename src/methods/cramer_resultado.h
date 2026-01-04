#ifndef CRAMER_RESULT_H
#define CRAMER_RESULT_H

#include <vector>
#include <string>

struct CramerResultado {
    std::string method;    // "Gauss" ou "Gauss-Jordan"
    double detC;
    std::vector<double> d;
    std::vector<double> amplitude;
    std::vector<bool> rompeu;
    bool solucao_unica;
};

#endif
