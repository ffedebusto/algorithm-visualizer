#include "graph.hpp" // Assumiamo che includa le definizioni di Graph, Node, Edge

namespace graph
{
    // Aggiunge un arco ORIENTATO da 'from' a 'to'
    bool addOrientedEdge(Elem from, Elem to, Weight w, Graph &g)
    {
        Node *fromNode = findNode(g, from);
        Node *toNode = findNode(g, to);

        if ((fromNode == nullptr) || (toNode == nullptr))
        {
            return false;
        }

        // Controllo se l'arco uscente da from esiste già
        for (const auto &edge : fromNode->adjList)
        {
            if (edge.elem == to)
            {
                return false;
            }
        }

        // Aggiungiamo solo l'arco uscente da from
        Edge newEdge;
        newEdge.elem = to;
        newEdge.weight = w;
        fromNode->adjList.push_back(newEdge);
        
        return true;
    }

    // Ritorna il numero di archi orientati
    // Ora non dobbiamo più dividere per 2
    unsigned int numEdgesOriented(const Graph &g)
    {
        unsigned int count = 0;
        for (const auto &node : g)
        {
            count += node.adjList.size();
        }
        return count; 
    }
}