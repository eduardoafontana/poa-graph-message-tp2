#pragma once
#include "Node.h"
#include <iostream>
#include "Distance.h"
#include "Presentation.h"
class NodeManager
/// <summary>
/// Class which contains the methods that we apply on the nodes. 
/// </summary>
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
	node* nodeTooFar = nullptr;
	std::vector<node*> getNodeList() {
		return nodeList;
	}
	void findPathUsingShortestDistance(node* startingNode, node* endingNode, std::vector<node*>* actualPath, std::vector<node*>* nodeVisited);
 
	void movePoints(node* actualNode, node* nearestNode);
	std::vector<node*> nodeList;
	double maxDistance = 0;
	
};

