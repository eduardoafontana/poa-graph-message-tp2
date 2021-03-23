#include "Node.h"



node::node(int nodeName)
{
	this->nodeName = nodeName;
}

void node::addAdjacentNode(node* node, int distance)
{
	this->adjacentNode.push_back(node);
	this->distanceList.push_back(distance);
}


void node::findPath(int nodeToFind, std::vector<std::vector<node*>>* allPath, std::vector<node*>* actualPath,std::vector<node*>* nodeVisited, int distance)
{
	
	

	
	if (actualPath == nullptr) {
		for (int i = 0; i < adjacentNode.size(); i++) {
			std::vector<node*>* newPath = new std::vector<node*>;
			std::vector<node*>* newNodeVisited = new std::vector<node*>;
			newNodeVisited->push_back(this);
			newPath->push_back(this);
			adjacentNode.at(i)->findPath(nodeToFind, allPath, newPath,newNodeVisited,distanceList.at(i));
		}
	}
	else {
		for (int i = 0; i < adjacentNode.size(); i++) {
			bool visited = false;
			if (adjacentNode.at(i) != nullptr) {
				for (int j = 0; j < nodeVisited->size(); j++) {
					if (adjacentNode.at(i) == nodeVisited->at(j)) {
						visited = true;
					}
				}
				if (visited == false) {
					for (int i = 0; i < nodeVisited->size(); i++) {
						if (nodeVisited->at(i) == this)
							visited = true;
					}
					if (visited == false) {
						if (distance + distanceList.at(i) > 130) {
							delete actualPath;
							delete nodeVisited;
							return;
						}
						nodeVisited->push_back(this);
						actualPath->push_back(this);
					}
					//tcheck if ok. 
					
					
					if (adjacentNode.at(i)->nodeName == nodeToFind) {
						actualPath->push_back(adjacentNode.at(i));
						allPath->push_back((*actualPath));
						delete actualPath;
						delete nodeVisited;
						return;
					}
					adjacentNode.at(i)->findPath(nodeToFind, allPath, actualPath, nodeVisited, distance + distanceList.at(i));
				}
			}
			else {
				delete actualPath;
				delete nodeVisited;
				return;
			}
		}
	}
	
}
/*void node::findPath(int nodeToFind, std::vector<std::vector<node*>>* allPath, std::vector<node*>* actualPath, int distance)
{
	
	if (distance > 100) {
		delete actualPath;
		return;
	}

	if (nodeName == nodeToFind) {
		actualPath->push_back(this);
		allPath->push_back((*actualPath));
		delete actualPath;
		return;
	}
	if (actualPath == nullptr) {
		for (int i = 0; i < adjacentNode.size(); i++) {
			std::vector<node*>* newPath = new std::vector<node*>;
			newPath->push_back(this);
			adjacentNode.at(i)->findPath(nodeToFind, allPath, newPath,distanceList.at(i));
		}
	}
	else {
		for (int i = 0; i < adjacentNode.size(); i++) {
			actualPath->push_back(this);
			if (adjacentNode.at(i) != nullptr) {
				adjacentNode.at(i)->findPath(nodeToFind, allPath, actualPath,distance + distanceList.at(i));
			}
			else {
				delete actualPath;
				return;
			}
		}
	}
	
}*/
