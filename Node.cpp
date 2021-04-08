#include "Node.h"

node::node(int nodeName,std::string name, double posX, double posY)
{
	/// <summary>
	/// constructor 
	/// </summary>
	/// <param name="nodeName">just a number so we can identifiate the node</param>
	/// <param name="posX">its pos in the graph</param>
	/// <param name="posY">its pos in the graph</param>
	
	this->name = name;
	this->nodeName = nodeName;
	this->posX = posX;
	this->posY = posY;
}

void node::addAdjacentNode(node* node)
{
	this->adjacentNode.push_back(node);
}

void node::changePos(double newX, double newY)
{
	/// <summary>
	/// Change the pos of the node. 
	/// </summary>
	/// <param name="newX">new pos x in the graph</param>
	/// <param name="newY">new pos y in the graph</param>
	this->posX = newX;
	this->posY = newY;
}

