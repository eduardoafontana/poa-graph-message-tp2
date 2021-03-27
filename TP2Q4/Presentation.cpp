#include "Presentation.h"

void Presentation::showPath(std::vector<node*>* path)
{
    /// <summary>
    /// shows the pass passed in arguement using lambda
    /// </summary>
    /// <param name="path">a vector containing the path that we want to show</param>
    

    std::cout << "This is the path between the two nodes you selected" << std::endl;
    std::for_each(path->begin(), path->end(), [](const node* node) {
        std::cout << node->nodeName << "-";
        });
    std::cout << std::endl;
}

void Presentation::showWinningNode(std::vector<node*> nodeList)
{
    /// <summary>
    /// show the node that has more points
    /// </summary>
   
    int maxPoints = 0;
    //using lambda to sort the nodeList 
    std::sort(nodeList.begin(), nodeList.end(), [](const node* node1, const node* node2) {
        return node1->points > node2->points; });
    maxPoints = nodeList.at(0)->points;
    std::cout << "The winning node(s) -> " << std::endl;
    //unsing lambda to show the winning points
    std::for_each(nodeList.begin(), nodeList.end(), [&](node* node) {
        if (node->points == maxPoints)
            std::cout << node->nodeName << " with : " << node->points << " points" << std::endl;
        });
}

int Presentation::getStartingNode()
{
    std::string tempStartingNode;
    std::cout << "Please select a starting node" << std::endl;
    std::cin >> tempStartingNode;
    try {
        int nodeName = std::stoi(tempStartingNode);
        return nodeName;
    }
    catch (std::exception& e) {
        std::cout << "You didn't entered a number ! " << std::endl;
    }
    
}

int Presentation::getEndingNode()
{
    std::string tempEndingNode;
    std::cout << "Please select an ending node" << std::endl;
    std::cin >> tempEndingNode;
    try {
        int nodeName = std::stoi(tempEndingNode);
        return nodeName;
    }
    catch (std::exception& e) {
        std::cout << "You didn't entered a number ! " << std::endl;
    }
    
}

double Presentation::getMaxDistance()
{
    std::cout << "Please enter the max distance between 2 nodes : " << std::endl;
    std::string tempMaxDistance;
    std::cin >> tempMaxDistance;
    double maxDistance = 0;
    try {
        maxDistance = std::stod(tempMaxDistance);
        return maxDistance;
    }
    catch(std::exception &e){
        std::cout << "You didn't entered a number ! " << std::endl;
    }
    
}

void Presentation::noPathFound()
{
    std::cout << "Cannot find a path between the two node you selected" << std::endl;
}

void Presentation::nodeDidntFound()
{
    std::cout << "The node you entered is not in our node list ! "<<std::endl;
}

bool Presentation::continuePlaying()
{
    std::string continuePlaying;
    std::cout << "Do you want to continue playing ? continuer ? (Y/N) :" << std::endl;
    std::cin >> continuePlaying;
    if (continuePlaying == "N" || continuePlaying == "n") {
        return false;
    }
    else
        return true;
}

void Presentation::showNodeList(std::vector<node*> nodeList)
{
    std::cout << "This is the list of possible nodes : " << std::endl;
    for (int i = 0; i < nodeList.size(); i++) {
        std::cout << i << " -> Node" << nodeList.at(i)->nodeName << std::endl;
    }
}