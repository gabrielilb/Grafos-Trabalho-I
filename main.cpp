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
            cout << g.num_arestas() << "\n";

        } else if(opcao == 'Q'){
            int n, novo_vertice;
            cin >> n;
            vector<int> vertices_clique;
            for(int i = 0; i < n; i++){
                cin >> novo_vertice;
                vertices_clique.push_back(novo_vertice);
            }
            g.eh_clique(vertices_clique);
            if(g.eh_clique(vertices_clique)){
                cout << "SIM\n";
            } else{
                cout << "NAO\n";
            }

        } else if(opcao == 'C'){
            int v1, v2, r1, r2;
            cin >> v1 >> v2 >> r1 >> r2;
            if(g.existe_caminho_restrito(v1, v2, Aresta(r1, r2), vector<int>(g.num_vertices()))){
                cout << "SIM\n";
            } else{
                cout << "NAO\n";
            }

        } else if(opcao == 'G'){
            g.imprime_graus();
        }
    }
    return 0;
}
