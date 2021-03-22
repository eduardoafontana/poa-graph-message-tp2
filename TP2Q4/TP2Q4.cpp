// TP2Q4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"



int findShortestPath(std::vector<std::vector<node*>>* allPath);
void addNode(node* node1, node* node2, int distance);
void showPath(std::vector<node*>* path);
int main()
{

    node* node0 = new node(0);
    node* node1 = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(4);
    /*node0->addAdjacentNode(node1, 10);
    node0->addAdjacentNode(node2, 20);
    node0->addAdjacentNode(node3, 10);
    node1->addAdjacentNode(node0, 10);
    node1->addAdjacentNode(node2, 20);
    node2->addAdjacentNode(node0, 10);
    node2->addAdjacentNode(node1, 20);
    node2->addAdjacentNode(node4, 15);
    node3->addAdjacentNode(node0, 10);
    node4->addAdjacentNode(node2, 15);*/
    /*node0->addAdjacentNode(node1, 10);
    node0->addAdjacentNode(node2, 20);
    node0->addAdjacentNode(node3, 30);
    node1->addAdjacentNode(node3, 200);
    node2->addAdjacentNode(node3, 20);
    node3->addAdjacentNode(node4, 20);*/
    addNode(node0, node1, 10);
    addNode(node0, node2, 20);
    addNode(node0, node3, 30);
    addNode(node1, node3, 100);
    addNode(node2, node3, 20);
    addNode(node3, node4, 10);
    //node4->addAdjacentNode(nullptr, -1);
    
    //int test = node0->findNode(4);
    //std::cout << test;
    std::vector<std::vector<node*>>* allPath = new std::vector<std::vector<node*>>;
    std::vector<node*>* temp = nullptr;
    std::vector<node*>* nodeVisited = nullptr;
    node0->findPath(2, allPath, temp, nodeVisited, 0);
    
    int index = findShortestPath(allPath);
    //showPath(&allPath->at(index));
    for (int j = 0; j < allPath->size(); j++) {
        for (int i = 0; i < allPath->at(j).size(); i++) {
            std::cout << allPath->at(j).at(i)->nodeName << "-";
        }
        std::cout << std::endl;
    }
    
    

    delete node0;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete allPath;
    delete temp;
    delete nodeVisited;
}
int findShortestPath(std::vector<std::vector<node*>>* allPath) {
    int tempo = 1000;
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
        if (shortest <= tempo) {
            tempo = shortest;
            index = i;
        }
    }
    return index;
}
void showPath(std::vector<node*>* path) {
    for (int i = 0; i < path->size(); i++) {
        std::cout << path->at(i)->nodeName << "-";
    }
}
void addNode(node* node1, node* node2, int distance) {
    node1->addAdjacentNode(node2, distance);
    node2->addAdjacentNode(node1, distance);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
