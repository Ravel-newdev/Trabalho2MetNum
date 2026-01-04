#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

#include "../methods/cramer_resultado.h"
#include "../methods/matriz.h"

#define COLOR_RESET  "\x1b[0m"
#define COLOR_CYAN   "\x1b[36m"
#define COLOR_GREEN  "\x1b[32m"
#define COLOR_RED    "\x1b[31m"
#define COLOR_YELLOW "\x1b[33m"

class Table {
    public:
        Table(
            const matriz& C_,
            const std::vector<double>& v_,
            const std::vector<CramerResultado>& r)
        : C(C_), v(v_), resultados(r) {}

        void print() const {
            using std::cout;
            using std::setw;
            using std::left;
            using std::right;
            using std::fixed;
            using std::setprecision;

            cout << "\n"
                << COLOR_CYAN
                << "==========================================================\n"
                << "           ANÁLISE DE CORDAS ELÁSTICAS (CRAMER)           \n"
                << "==========================================================\n\n"
                << COLOR_RESET;

            cout << "entrada [C]{d} = {v}:\n\n";

            int n = C.n;
            int meio = n / 2;

            for (int i = 0; i < n; i++) {
                // matriz C com uma pequnea moldura
                // eh pura estetica

                // borda esq
                cout << "  " << (i == 0 ? "/" : (i == n - 1 ? "\\" : "|"));
                
                for (int j = 0; j < n; j++) {
                    cout << right << setw(8) << fixed << setprecision(2) << C(i, j);
                }
                
                // bora dir
                cout << " " << (i == 0 ? "\\" : (i == n - 1 ? "/" : "|"));

                // sinal de igualdade ou multiplicação no meio
                if (i == meio) cout << "   =   ";
                else           cout << "       ";

                // vetor v tambem bonitinho
                cout << (i == 0 ? "/" : (i == n - 1 ? "\\" : "|"));
                cout << right << setw(10) << fixed << setprecision(2) << v[i];
                cout << " " << (i == 0 ? "\\" : (i == n - 1 ? "/" : "|"));
                
                cout << "\n";
            }
            cout << "\n" << COLOR_CYAN << "----------------------------------------------------------" << COLOR_RESET << "\n";

            // resultado por metodo
            for (const auto& R : resultados) {
                cout << "\n" 
                    << "metodo: " << COLOR_YELLOW << R.method << COLOR_RESET << "\n";

                if (!R.solucao_unica) {
                    cout << "status: " << COLOR_RED << "SINGULAR (Determinante = 0)" << COLOR_RESET << "\n"
                         << "Nao e possivel calcular os deslocamentos.\n";
                    cout << COLOR_CYAN << "----------------------------------------------------------" << COLOR_RESET << "\n";
                    continue;
                }

                // 4 casas decimais por padrao
                cout << "determinante: " << fixed << setprecision(4) << R.detC << "\n\n";

                // cabeçalho da tabela de resultados
                cout << left
                    << COLOR_CYAN
                    << setw(10) << "corda"
                    << setw(18) << "deslocamento (d)"
                    << setw(18) << "amplitude (a*d)"
                    << setw(15) << "condicao"
                    << COLOR_RESET << "\n";

                cout << "----------+------------------+------------------+----------\n";

                for (std::size_t i = 0; i < R.d.size(); ++i) {
                    cout << left
                        << setw(10) << (i + 1)
                        << setw(18) << fixed << setprecision(6) << R.d[i]
                        << setw(18) << fixed << setprecision(6) << R.amplitude[i];

                    if (R.rompeu[i]) {
                        cout << COLOR_RED << setw(15) << "PODE ROMPER (!)" << COLOR_RESET;
                    } else {
                        cout << COLOR_GREEN << setw(15) << "Seguro" << COLOR_RESET;
                    }
                    cout << "\n";
                }
                cout << "\n" << COLOR_CYAN << "----------------------------------------------------------" << COLOR_RESET << "\n";
            }
        }

    private:
        const matriz& C;
        const std::vector<double>& v;
        const std::vector<CramerResultado> resultados;
};

#endif