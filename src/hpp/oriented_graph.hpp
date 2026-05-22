#ifndef ORIENTED_GRAPH_HPP
#define ORIENTED_GRAPH_HPP

#include <vector>
#include "graph.hpp" // Riusiamo le struct Edge e Node

namespace graph
{
    // Aggiunge arco orientato: solo da 'from' a 'to'
    bool addOrientedEdge(Elem from, Elem to, Weight w, Graph &g);

    unsigned int numEdgesOriented(const Graph &g);

}

#endif