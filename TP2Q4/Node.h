#pragma once
#include <vector>



class node {


public:
	// contains the list off Node that this node can reach
	std::vector<node*> adjacentNode;
	int points = 0;
	double posX = 0;
	double posY = 0;
	//contains the distance from this node to the other node. Same pos same node ex. distanceList.at(0) is the distance for the node adjacentNode.at(0)
	int nodeName;
	int actualDistance = 0;
public:
	//constructor give a name for the node
	node(int nodeName, double posX, double posY);
	void addAdjacentNode(node* node);
	
};