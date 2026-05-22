#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>
#include "utils.hpp"

using namespace std;

namespace graph
{
    typedef unsigned int Elem; // etichetta dei vertici (int in questo caso)
    typedef double Weight;     // peso degli archi

    struct Edge
    {
        Elem elem;
        Weight weight;
    };

    struct Node
    {
        Elem elem;
        vector<Edge> adjList;
        bool isVisited;
    };

    typedef vector<Node> Graph;

    // Restituisce il grafo vuoto
    Graph createEmptyGraph(); // Θ(1)

    // Trova un puntatore al nodo data l'etichetta
    Node *findNode(Graph &g, Elem l); // Θ(V)

    // Aggiunge nuovo vertice con etichetta la stringa.
    // Se non e gia presente, ritorna true, altrimenti fallisce e ritorna false
    bool addNode(Elem, Graph &); // Θ(V)

    // Aggiunge nuovo arco tra i due vertici con etichette label e peso
    // l'intero. Fallisce se non sono presenti tutti e due i nodi o se l'arco
    // tra i due e' gia' presente. Se fallisce ritorna false,
    // altrimenti ritorna true
    bool addEdge(Elem, Elem, Weight, Graph &); // Θ(V + adj)

    // Ritorna il numero di vertici del grafo
    unsigned int numNodes(const Graph &); // Θ(1)

    // Ritorna il numero di archi del grafo
    unsigned int numEdges(const Graph &); // Θ(V + E)

    // Ritorna la lista di adiacenza di un vertice (vicini con peso dell'arco).
    // Se il vertice non esiste, ritorna una lista vuota.
    vector<Edge> adjacentList(Elem, const Graph &); // Θ(V)

    // Svuota un grafo
    void clear(Graph &g); // Θ(V + E)

    // Stampa il grafo
    // Per ogni vertice stampa su una riga l'etichetta del vertice seguito di ':'
    // poi le etichette dei vertici adiacenti con fra parentesi il peso associato,
    // separate da virgole
    void printGraph(const Graph &g); // Θ(V + E)
}

#endif