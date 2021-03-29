#include "Node.h"



node::node(int nodeName, double posX, double posY)
{
	/// <summary>
	/// constructor 
	/// </summary>
	/// <param name="nodeName">just a number so we can identifiate the node</param>
	/// <param name="posX">its pos in the graph</param>
	/// <param name="posY">its pos in the graph</param>
	this->nodeName = nodeName;
	this->posX = posX;
	this->posY = posY;
}

void node::addAdjacentNode(node* node)
{
	this->adjacentNode.push_back(node);
}

