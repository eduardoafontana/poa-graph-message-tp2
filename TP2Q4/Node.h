#pragma once
#include <vector>
#include <string>


class node {
//serve like a data strucutre of node (contains everything the node needs) and methods that are usefull for a nodes. 

public:
	// contains the list off Node that this node can reach
	std::vector<node*> adjacentNode;
	std::string name;
	int points = 0;
	double posX = 0;
	double posY = 0;
	int nodeName;

	//constructor give a name and an Id for the node and its pos in the graph
	node(int nodeName,std::string name, double posX, double posY);
	void addAdjacentNode(node* node);
	void changePos(double newX, double newY);
	
};