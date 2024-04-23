#include "Aresta.h"
#include "Grafo.h"
#include <exception>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void print_exception(const exception &e, int level = 0) {
    cerr << "exception: " << string(level, ' ') << e.what() << "\n";
    try {
        rethrow_if_nested(e);
    } catch(const std::exception& nested_exception) {
        print_exception(nested_exception, (level + 2));
    }
}

int main() {
    try {

        // Grafo g(10);

        // g.insere_aresta(Aresta(0, 2));
        // g.insere_aresta(Aresta(1, 2));
        // g.insere_aresta(Aresta(5, 7));
        // g.insere_aresta(Aresta(5, 1));
        // g.insere_aresta(Aresta(0, 4));
        // g.insere_aresta(Aresta(0, 2));

        // g.imprime();

        // g.remove_aresta(Aresta(0,2));
        // cout << "\nREMOVENDO ARESTA\n\n";
        // g.imprime();

        Grafo g(3);
        g.insere_aresta(Aresta(0,1));
        g.insere_aresta(Aresta(0,2));
        g.insere_aresta(Aresta(1,2));
        g.eh_clique();
        cout << "0 se nao for, 1 se for clique: " << g.eh_clique() << endl;

        std::vector<int> &marcado();
        cout << "0 se nao existe caminho restrito, 1 se sim: " << g.existe_caminho_restrito(0, 2, Aresta(1,2), vector<int>(g.num_vertices())) << endl;


    }
    catch (const exception &e) {
        print_exception(e);
    }

    return 0;
}
