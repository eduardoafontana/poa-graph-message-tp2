#pragma once
#include "Node.h"
#include <iostream>
#include "Distance.h"
#include "Presentation.h"
class NodeManager
{
public:
	NodeManager();
	~NodeManager();

	node* startingNode = nullptr;
	node* endingNode = nullptr;	
	void addPoints(std::vector<node*>* actualPath);
	void setMaxDistance(double maxDistance) {
		this->maxDistance = maxDistance;
	}
	std::vector<node*> getNodeList() {
		return nodeList;
	}
	void findPathUsingShortestDistance(node* startingNode, node* endingNode, std::vector<node*>* actualPath, std::vector<node*>* nodeVisited);
 
	std::vector<node*> nodeList;
	double maxDistance = 0;
	
};

