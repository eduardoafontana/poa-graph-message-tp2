#pragma once
#include <vector>



class node {


public:
	// contains the list off Node that this node can reach
	std::vector<node*> adjacentNode;
	//contains the distance from this node to the other node. Same pos same node ex. distanceList.at(0) is the distance for the node adjacentNode.at(0)
	std::vector<int> distanceList;
	int nodeName;
	int actualDistance = 0;
public:
	//constructor give a name for the node
	node(int nodeName);
	//add adjacent node to this node to create a graph
	void addAdjacentNode(node* node, int distance);
	std::vector<node*> getAdjacentNode() {
		return adjacentNode;
	};

	void findPath(int nodeToFind, std::vector<std::vector<node*>>* Allpath, std::vector<node*>* actualPath,std::vector<node*>* nodeVisited, int distance);
	
};