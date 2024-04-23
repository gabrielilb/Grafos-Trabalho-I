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
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "insere_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    // preciso fazer a verificação se a aresta já existe
    for(auto i : listas_adj_[e.v1]){
        if (i == e.v2){
            return; //Já existe aresta
        }

    }

    // do contrário só inserir
    listas_adj_[e.v1].insert(listas_adj_[e.v1].end(), e.v2); // incluindo na posição v1 o vértice v2
    listas_adj_[e.v2].insert(listas_adj_[e.v2].end(), e.v1); // incluindo na posição v2 o vértice v1

    num_arestas_++;
    // }
}

void Grafo::remove_aresta(Aresta e) {
    try {
        valida_aresta(e);
    } catch (...) {
        throw_with_nested(runtime_error("Erro na operacao "
            "remove_aresta(Aresta): a aresta " + e.to_string() + " eh "
            "invalida!"));
    }

    auto i = find(listas_adj_[e.v1].begin(), listas_adj_[e.v1].end(), e.v2);
    if(i != listas_adj_[e.v1].end()){
        listas_adj_[e.v1].erase(i);
    } else{
        cout << "\nA aresta nao existe\n";
        return;
    }

    auto j = find(listas_adj_[e.v2].begin(), listas_adj_[e.v2].end(), e.v1);
    if(j != listas_adj_[e.v2].end()){
        listas_adj_[e.v2].erase(j);
    }

    num_arestas_--;
}

void Grafo::imprime(){
    for(int k = 0; k < listas_adj_.size(); k++){
        cout << "Lista de adjacencias do vertice " << k << endl;
        cout << "Cabeca";
        for (auto l = listas_adj_[k].begin(); l!= listas_adj_[k].end(); l++){
            cout << " -> " << *l;
            cout << endl;
        }
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
