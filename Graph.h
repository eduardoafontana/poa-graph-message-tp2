#pragma once
#include "Node.h"
#include <vector>
class Graph
/// <summary>
/// Class that serves to create the graph ( create nodes and link between them)
/// </summary>
{
public:
	static std::vector<node*> createGraph();
	static void addNode(node* node1, node* node2);
};

