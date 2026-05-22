#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include "hpp/graph.hpp"

// Stampa il grafo
// Per ogni vertice stampa su una riga l'etichetta del vertice seguito di ':'
// poi le etichette dei vertici adiacenti con fra parentesi il peso associato,
// separate da virgole
void printGraph(const graph::Graph &g); // Θ(V + E)

void printVector(const graph::Graph &g);

void printMatrix(vector<vector<int>>);

graph::Graph buildGraphFromInput(string &);

graph::Graph buildOrientedGraphFromInput(string &);

#endif