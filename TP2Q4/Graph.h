#pragma once
#include "Node.h"
#include <vector>
class Graph
{
public:
	static std::vector<node*> createGraph();
	static void addNode(node* node1, node* node2);
};

