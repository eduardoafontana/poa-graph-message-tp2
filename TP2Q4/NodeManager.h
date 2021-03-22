#pragma once
#include "Node.h"
#include <iostream>
class NodeManager
{
public:
	NodeManager();
	int findShortestPath(std::vector<std::vector<node*>>* allPath);
	void showPath(std::vector<node*>* path);
	void addNode(node* node1, node* node2, int distance);
	std::vector<std::vector<node*>>* allPath(node* startingNode, node* endingNode);
	void sortPath(std::vector<std::vector<node*>> *allPath);

};

