#include <iostream>

#include "graph.hpp"

using namespace graph;

namespace graph
{

    // Restituisce il grafo vuoto
    Graph createEmptyGraph()
    {
        return Graph();
    }

    // Trova un puntatore al nodo data l'etichetta
    Node *findNode(Graph &g, Elem l)
    {
        for (unsigned int i = 0; i < g.size(); ++i)
        {

            if (g[i].elem == l)
            {
                return &g[i];
            }
        }
        return nullptr;
    }

    // Aggiunge nuovo vertice con etichetta: Elem (int da 0 a N-1).
    // Se non è gia presente, ritorna true, altrimenti fallisce e ritorna false
    bool addNode(Elem l, Graph &g)
    {
        if (findNode(g, l) != nullptr)
        {
            return false;
        }

        Node newNode;
        newNode.elem = l;

        g.push_back(newNode);
        return true;
    }

    // Aggiunge nuovo arco tra i due vertici con etichette elem e peso
    // Fallisce se non sono presenti tutti e due i nodi o se l'arco
    // tra i due e' gia' presente. Se fallisce ritorna false,
    // altrimenti ritorna true
    bool addEdge(Elem from, Elem to, Weight w, Graph &g)
    {

        Node *fromNode = findNode(g, from);
        Node *toNode = findNode(g, to);

        if ((fromNode == nullptr) || (toNode == nullptr))
        {
            return false;
        }

        // Controllo se esiste già un arco tra from e to
        for (unsigned int i = 0; i < fromNode->adjList.size(); ++i)
        {
            if (fromNode->adjList[i].elem == to)
            {
                return false;
            }
        }

        Edge newEdgeTo;
        newEdgeTo.elem = to;
        newEdgeTo.weight = w;
        fromNode->adjList.push_back(newEdgeTo);

        Edge newEdgeFrom;
        newEdgeFrom.elem = from;
        newEdgeFrom.weight = w;
        toNode->adjList.push_back(newEdgeFrom);
        return true;
    }

    // Ritorna il numero di vertici del grafo
    unsigned int numNodes(const Graph &g)
    {
        return g.size();
    }

    // Ritorna il numero di archi del grafo
    unsigned int numEdges(const Graph &g)
    {
        unsigned int count = 0;
        for (unsigned int i = 0; i < g.size(); ++i)
        {
            count += g[i].adjList.size();
        }
        return count / 2;
    }

    // Ritorna la lista di adiacenza di un vertice (vicini con peso dell'arco).
    // Se il vertice non esiste, ritorna una lista vuota.
    vector<Edge> adjacentList(Elem v, const Graph &g)
    {
        for (unsigned int i = 0; i < g.size(); ++i)
        {
            if (g[i].elem == v)
            {
                return g[i].adjList;
            }
        }
        return vector<Edge>();
    }

    // Svuota un grafo
    void clear(Graph &g)
    {
        g.clear();
    }

