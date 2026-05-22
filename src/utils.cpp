#include "utils.hpp"

void printGraph(const graph::Graph &g)
{
    for (unsigned int i = 0; i < g.size(); ++i)
    {
        cout << g[i].elem << ": ";
        for (unsigned int j = 0; j < g[i].adjList.size(); ++j)
        {
            cout << g[i].adjList[j].elem << "(" << g[i].adjList[j].weight << ")";
            if (j < g[i].adjList.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

void printVector(const graph::Graph &g)
{
    int i = 0;
    for (auto &&e : g)
    {
        cout << "Elemnto [" << i << "]: " << e.elem << endl;
    }
}

void printMatrix(vector<vector<int>> m)
{
}

graph::Graph buildGraphFromInput(string &input)
{
}