#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
            "vertices " + to_string(num_vertices) + " nao eh invalido!"));
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    listas_adj_.resize(num_vertices); // a lista já vai possuir o número de vértices
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

void Grafo::insere_aresta(Aresta e) {
    // preciso fazer a verificação se a aresta já existe
    if (e.v1 == e.v2){
        return; // os vertices sao iguais
    }
    
    for(auto i : listas_adj_[e.v1]){
        if (i == e.v2){
            return; //Já existe aresta
        }
    }
    // do contrário só inserir
    listas_adj_[e.v1].insert(listas_adj_[e.v1].end(), e.v2); // incluindo na posição v1 o vértice v2
    listas_adj_[e.v2].insert(listas_adj_[e.v2].end(), e.v1); // incluindo na posição v2 o vértice v1

    num_arestas_++;
}

void Grafo::remove_aresta(Aresta e) {

    auto i = find(listas_adj_[e.v1].begin(), listas_adj_[e.v1].end(), e.v2);
    if(i != listas_adj_[e.v1].end()){
        listas_adj_[e.v1].erase(i);
    } else{
        return;
    }

    auto j = find(listas_adj_[e.v2].begin(), listas_adj_[e.v2].end(), e.v1);
    if(j != listas_adj_[e.v2].end()){
        listas_adj_[e.v2].erase(j);
    }

    num_arestas_--;
}

// void Grafo::imprime(){
//     for(int k = 0; k < listas_adj_.size(); k++){
//         cout << "Lista de adjacencias do vertice " << k << endl;
//         cout << "Cabeca";
//         for (auto l = listas_adj_[k].begin(); l!= listas_adj_[k].end(); l++){
//             cout << " -> " << *l;
//             cout << endl;
//         }
//     }
// }

bool Grafo::eh_clique(vector<int> vertices_clique){
    int num_max_arestas = (vertices_clique.size()*(vertices_clique.size()-1));    //n(n − 1)
    int contador = 0;
    for (auto u : vertices_clique){
        for (auto v : listas_adj_[u]){
            if(find(vertices_clique.begin(), vertices_clique.end(), v) != vertices_clique.end())
                contador++;
        }
    }
    if (num_max_arestas == contador)
        return true;
    
    return false;

}

void Grafo::busca_profundidade(int v, vector<int> &marcado){
    marcado[v] = 1;
    for(int u : listas_adj_[v]){
        if(marcado[u] == 0)
            busca_profundidade(u, marcado);
    }
}

bool Grafo::existe_caminho_restrito(int vertice_o, int vertice_d, Aresta e, vector<int> marcado){
    valida_vertice(vertice_o);
    valida_vertice(vertice_d);

    marcado[vertice_o] = 1;

    if(vertice_o == vertice_d)
        return true;

    for(int j : listas_adj_[vertice_o]){
        if (!((vertice_o == e.v1 && j == e.v2) || (vertice_o == e.v2 && j == e.v1)))
            if (marcado[j] == 0)
                if (existe_caminho_restrito(j, vertice_d, e, marcado))
                    return true;
    }
    return false;   
}

void Grafo::imprime_graus(){
    for (int i = 0; i < num_vertices_; i++){
        cout << i << ": " << listas_adj_[i].size() << endl;
    }
}

void Grafo::valida_vertice(int v) {
    if ((v < 0) || (v >= num_vertices_)) {
        throw out_of_range("Indice de vertice invalido: " + to_string(v));
    }
}

void Grafo::valida_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);
}
