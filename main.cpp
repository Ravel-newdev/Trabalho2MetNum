#include <iostream>
#include <vector>

#include "src/methods/cramer.h"
#include "src/output/table.h"

int main() {
    int n;
    double a;

    // entrada
    std::cout << "n a\n";
    std::cin >> n >> a;

    matriz C(n);
    std::vector<double> v(n);

    // como o enunciado pede para "Calibrar o sistema desenvolvido usando como padrão a=1, a matriz [C] e o vetor {v} do enunciado"
    // essa parte é necessaria
    char usar_padrao;
    std::cout << "Deseja seguir com os valores padrão do enunciado? (s/n): ";
    std::cin >> usar_padrao; 

    if (usar_padrao == 's') {
        if (n != 3) {
            std::cout << "Aviso: valores padrão definidos apenas para n = 3.\n";
            std::cout << "Ajustando n para 3.\n";
            n = 3;
            C = matriz(3);
            v.resize(3);
            a = 1.0;
        }

        // valores do enunciado
        C(0,0)=10; C(0,1)=1;  C(0,2)=1;
        C(1,0)=1;  C(1,1)=10; C(1,2)=1;
        C(2,0)=1;  C(2,1)=1;  C(2,2)=10;

        v[0]=12; v[1]=12; v[2]=12;
    } else {

        std::cout << "\nInforme os termos da matriz C (" 
                << n << "x" << n << "), linha a linha:\n";
        if(n <= 0){
            std::cout << "n inválido.\n";
            return 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cin >> C(i, j);
            }
        }

        std::cout << "\nInforme os termos do vetor v (" 
                << n << " valores, separados por espaco):\n";

        for (int i = 0; i < n; i++) {
            std::cin >> v[i];
        }
    }

    // calculo dos metodos
    CramerResultado r1 = cramer_gauss(C, v, a);
    CramerResultado r2 = cramer_gauss_jordan(C, v, a);

    // saída
    Table tabela(C, v, {r1, r2});
    tabela.print();

    return 0;
}
