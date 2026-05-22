#include "bfs.hpp"
#include <map>

vector<pair<Elem, Elem>> bfs(const Graph &G, const Node &s)
{
    Graph g = G;
    vector<pair<Elem, Elem>> res; // parent, elem

    // Mappa di supporto per salvare le relazioni: chiave = FIGLIO, valore = PADRE
    std::map<Elem, Elem> parent;

    for (auto &&elem : g)
    {
        elem.isVisited = false;
    }

    queue<Node> Q;
    Q.push(s);

    while (!Q.empty())
    {
        Node u = Q.front();
        Q.pop();

        for (auto &&edge : u.adjList)
        {
            Node *v = findNode(g, edge.elem);
            if (!v->isVisited)
            {
                v->isVisited = true;
                Q.push(*v);

                parent[v->elem] = u.elem; // parent[v] = u
            }
        }
        u.isVisited = true;
        res.push_back({parent[u.elem], u.elem});
    }

    return res;
}