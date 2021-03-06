#include "NodeManager.h"
#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include "Graph.h"
NodeManager::NodeManager()
{
    nodeList = Graph::createGraph();
    
}

NodeManager::~NodeManager()
{
    /// <summary>
    /// destructor using lambda
    /// </summary>
    //deleting all node
    std::for_each(nodeList.begin(), nodeList.end(), [](node* node) {
        delete node;
        });
}

void NodeManager::addPoints(std::vector<node*>* actualPath)
{
    /// <summary>
    /// add points to all the node that deserves it this path
    /// </summary>
    /// <param name="allPath">the path between nodeA and nodeB</param>
    
    //begin + 1 and end -1  so the selected node by the user doens't have points
    std::for_each(actualPath->begin() + 1, actualPath->end() - 1, [](node* node) {
        node->points ++;
        });
}




void NodeManager::findPathUsingShortestDistance(node* startingNode, node* endingNode, std::vector<node*>* actualPath, std::vector<node*>* nodeVisited)
{
    /// <summary>
    /// find the path from starting node to ending node using the shortest distance between two nodes
    /// </summary>
    /// <param name="startingNode">in the first itération, containts de node starting node that the user selected, in the other, contains 
   /// the actual node </param>
   /// <param name="endingNode">the node that we are searching in the graph</param>
   /// <param name="allPath">we pass this list empty and after the function, it is filled with the list of all possible paths</param>
   /// <param name="actualPath">we pass an empty list and the function use it to know where we come from</param>
   /// <param name="nodeVisited">we pass an empty list and the function use it to know if we already visited a node so we do not enter in  
   /// a infinite loop</param>
   /// 
   
    //if it is the first time the function is called
    if (actualPath->size() == 0) {
        double shortestDistance = 1000;
        int tempIndex = -1;
        for (int i = 0; i < startingNode->adjacentNode.size(); i++) {
            if (Distance::calculateDistance(startingNode->posX, startingNode->posY, startingNode->adjacentNode.at(i)->posX, startingNode->adjacentNode.at(i)->posY) < shortestDistance) {
                shortestDistance = Distance::calculateDistance(startingNode->posX, startingNode->posY, startingNode->adjacentNode.at(i)->posX, startingNode->adjacentNode.at(i)->posY);
                tempIndex = i;
            }
        }
        actualPath->push_back(startingNode);
        if (Distance::calculateDistance(startingNode->posX, startingNode->posY, startingNode->adjacentNode.at(tempIndex)->posX, startingNode->adjacentNode.at(tempIndex)->posY) > maxDistance) {
            movePoints(startingNode, startingNode->adjacentNode.at(tempIndex));
            delete actualPath;
            actualPath = nullptr;
            return;
        }
        if (startingNode->adjacentNode.at(tempIndex) == endingNode) {
            actualPath->push_back(startingNode->adjacentNode.at(tempIndex));
            return;
        }
        else {
            std::vector<node*>* newNodeVisited = new std::vector<node*>;
            actualPath->push_back(startingNode->adjacentNode.at(tempIndex));
            newNodeVisited->push_back(startingNode);
            findPathUsingShortestDistance(startingNode->adjacentNode.at(tempIndex), endingNode, actualPath, newNodeVisited);
        }
    }
    else {
        double shortestDistance = 1000;
        int tempIndex = -1;
        for (int i = 0; i < startingNode->adjacentNode.size(); i++) {
            if (startingNode->adjacentNode.at(i) != actualPath->at(actualPath->size() - 2)) {
                if (Distance::calculateDistance<double>(startingNode->posX,startingNode->posY, startingNode->adjacentNode.at(i)->posX, startingNode->adjacentNode.at(i)->posY) < shortestDistance) {
                    shortestDistance = Distance::calculateDistance<double>(startingNode->posX, startingNode->posY, startingNode->adjacentNode.at(i)->posX, startingNode->adjacentNode.at(i)->posY);
                    tempIndex = i;
                }
            }
        }
        if (Distance::calculateDistance<double>(startingNode->posX, startingNode->posY, startingNode->adjacentNode.at(tempIndex)->posX, startingNode->adjacentNode.at(tempIndex)->posY)
                > maxDistance) {
            movePoints(startingNode, startingNode->adjacentNode.at(tempIndex));
            nodeTooFar = startingNode->adjacentNode.at(tempIndex);
            delete actualPath;
            actualPath = nullptr;
            return;
        }
        bool infinateLoop = false;
        //check if the node with the shortest distance is different from the node that we already visited(else we would enter in an infinite loop using lambda
        std::for_each(nodeVisited->begin(), nodeVisited->end(), [&](node* actualNode) {
            if (actualNode == startingNode->adjacentNode.at(tempIndex)) {
                delete actualPath;
                actualPath = nullptr;
                delete nodeVisited;
                infinateLoop = true;
                return;
            }});
        //check if we were in an infinate loop
        if (infinateLoop)
            return;
        if (startingNode->adjacentNode.at(tempIndex) == endingNode) {
            actualPath->push_back(startingNode->adjacentNode.at(tempIndex));
            delete nodeVisited;
            return;
        }

        actualPath->push_back(startingNode->adjacentNode.at(tempIndex));
        nodeVisited->push_back(startingNode);
        findPathUsingShortestDistance(startingNode->adjacentNode.at(tempIndex), endingNode, actualPath, nodeVisited);
    }
}

void NodeManager::movePoints(node* actualNode, node* nearestNode)
{  
    double ratio = maxDistance / Distance::calculateDistance<double>(actualNode->posX, actualNode->posY, nearestNode->posX, nearestNode->posY);
    double addX = ratio * (nearestNode->posX - actualNode->posX);
    double addY = ratio * (nearestNode->posY - actualNode->posY);
    nearestNode->changePos(actualNode->posX + addX, actualNode->posY + addY);
}
