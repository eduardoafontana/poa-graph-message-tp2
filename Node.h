#pragma once
#include <vector>
#include <string>


class node {


public:
	// contains the list off Node that this node can reach
	std::vector<node*> adjacentNode;
	std::string name;
	int points = 0;
	double posX = 0;
	double posY = 0;
	int nodeName;
public:
	//constructor give a name and an Id for the node
	node(int nodeName,std::string name, double posX, double posY);
	void addAdjacentNode(node* node);
	
};