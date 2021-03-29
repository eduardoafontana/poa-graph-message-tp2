#include "GameManager.h"

GameManager::GameManager() {
    /// <summary>
    /// the loop containing all the game
    /// </summary>
    
    NodeManager nodeManager;
    Presentation::showNodeList(nodeManager.nodeList);
    do {
        int startingNodeName = Presentation::getStartingNode();
        int endingNodeName = Presentation::getEndingNode();

        bool findStarting = false;
        bool findEnding = false;
        for (int i = 0; i < nodeManager.nodeList.size(); i++) {
            if (startingNodeName == nodeManager.nodeList.at(i)->nodeName) {
                nodeManager.startingNode = nodeManager.nodeList.at(i);
                findStarting = true;
            }
            if (endingNodeName == nodeManager.nodeList.at(i)->nodeName) {
                nodeManager.endingNode = nodeManager.nodeList.at(i);
                findEnding = true;
            }
        }
        if (findEnding && findStarting) {
            nodeManager.maxDistance = Presentation::getMaxDistance();
            std::vector<node*>* actualPath = new std::vector<node*>;
            std::vector<node*>* nodeVisited = nullptr;
            nodeManager.findPathUsingShortestDistance(nodeManager.startingNode, nodeManager.endingNode, actualPath, nodeVisited);

            if (actualPath->size() > 0) {
                nodeManager.addPoints(actualPath);
                Presentation::showPath(actualPath);
                delete actualPath;
            }
            else
                Presentation::showNoPathFound();


            delete nodeVisited;

        }
        else
            Presentation::nodeDidntFound();


    } while (Presentation::continuePlaying());
    Presentation::showWinningNode(nodeManager.nodeList);
}