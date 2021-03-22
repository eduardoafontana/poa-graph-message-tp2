#include "NodeManager.h"
#include <algorithm>


NodeManager::NodeManager()
{

}

int NodeManager::findShortestPath(std::vector<std::vector<node*>>* allPath)
{
    int temp = 1000;
    int shortest = 0;
    int index = 0;
    for (int i = 0; i < allPath->size(); i++) {
        shortest = 0;
        for (int j = 0; j < allPath->at(i).size() - 1; j++) {
            for (int k = 0; k < allPath->at(i).at(j)->adjacentNode.size(); k++) {
                if (allPath->at(i).at(j + 1)->nodeName == allPath->at(i).at(j)->adjacentNode.at(k)->nodeName) {
                    shortest += allPath->at(i).at(j)->distanceList.at(k);
                }
            }
        }
        if (shortest <= temp) {
            temp = shortest;
            index = i;
        }
    }
    return index;
}

void NodeManager::showPath(std::vector<node*>* path)
{
    for (int i = 0; i < path->size(); i++) {
        std::cout << path->at(i)->nodeName << "-";
    }
}

void NodeManager::addNode(node* node1, node* node2, int distance)
{
    node1->addAdjacentNode(node2, distance);
    node2->addAdjacentNode(node1, distance);
}

std::vector<std::vector<node*>>* NodeManager::allPath(node* startingNode, node* endingNode)
{
    std::vector<std::vector<node*>>* allPath = new std::vector<std::vector<node*>>;
    std::vector<node*>* temp = nullptr;
    std::vector<node*>* nodeVisited = nullptr;
    startingNode->findPath(endingNode->nodeName, allPath, temp, nodeVisited, 0);
    return allPath;
}

void NodeManager::sortPath(std::vector<std::vector<node*>>* allPath)
{
    std::sort(allPath->begin(), allPath->end(), [](const std::vector<node*>A, const std::vector<node*>B) {
        return A.size() < B.size();
        });
}
