#ifndef BFS_HPP
#define BFS_HPP
#include <queue>
#include "graph.hpp"

using namespace graph;

vector<pair<Elem, Elem>>  bfs(const Graph &G, const Node &s); // Θ(1)

#endif