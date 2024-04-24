#include "Aresta.h"
#include "Grafo.h"
#include <exception>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {

    int num_vertices;
    int operacoes;
    int num_aresta1, num_aresta2;

    cin >> num_vertices >> operacoes;

    Grafo g(num_vertices);

    for(int i = 1; i <= operacoes; i++){
        char opcao;
        cin >> opcao; 
        if(opcao == 'I'){
            cin >> num_aresta1 >> num_aresta2;
            g.insere_aresta(Aresta(num_aresta1,num_aresta2));
        } else if(opcao == 'R'){
            cin >> num_aresta1 >> num_aresta2;
            g.remove_aresta(Aresta(num_aresta1,num_aresta2));
        } else if(opcao == 'E'){
            cout << g.num_arestas();
        } else if(opcao == 'Q'){
            // g.eh_clique();
        } else if(opcao == 'C'){
            // g.existe_caminho_restrito();
        } else if(opcao == 'G'){
            g.imprime_graus();
        }
    }
    return 0;
}
