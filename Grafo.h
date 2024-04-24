#ifndef GRAFO_H
#define GRAFO_H

#include "Aresta.h"
#include <vector>
#include <list>

class Grafo {
public:

    Grafo(int num_vertices);

    int num_vertices();
    int num_arestas();

    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);

    bool eh_clique(std::vector<int> vertices_clique);
    bool existe_caminho_restrito(int v1, int v2, Aresta e, std::vector<int> marcado);
    void imprime_graus();

private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::list<int>> listas_adj_;

    void valida_vertice(int v);
    void valida_aresta(Aresta e);
    void busca_profundidade(int v, std::vector<int> &marcado);

};

#endif 
