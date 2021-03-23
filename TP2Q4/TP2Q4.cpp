// TP2Q4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "NodeManager.h"



/*int findShortestPath(std::vector<std::vector<node*>>* allPath);
void addNode(node* node1, node* node2, int distance);
void showPath(std::vector<node*>* path);*/
int main()
{
    NodeManager manager;
    node* node0 = new node(0);
    node* node1 = new node(1);
    node* node2 = new node(2);
    node* node3 = new node(3);
    node* node4 = new node(4);
    node* node5 = new node(5);
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
    manager.addNode(node0, node1, 10);
    manager.addNode(node0, node2, 20);
    manager.addNode(node0, node3, 30);
    manager.addNode(node1, node3, 10);
    manager.addNode(node2, node3, 20);
    manager.addNode(node3, node4, 10);
    //node4->addAdjacentNode(nullptr, -1);
    //int test = node0->findNode(4);
    //std::cout << test;
    /*std::vector<std::vector<node*>>* allPath = new std::vector<std::vector<node*>>;
    std::vector<node*>* temp = nullptr;
    std::vector<node*>* nodeVisited = nullptr;
    node0->findPath(2, allPath, temp, nodeVisited, 0);*/
    std::vector<std::vector<node*>>* allPath = manager.allPath(node0, node4);
    manager.addPoints(allPath);
    //std::cout << node3->points << std::endl;
    //int index = manager.findShortestPath(allPath);
    std::cout << "before sort" << std::endl;
    for (int i = 0; i < allPath->size(); i++) {
        manager.showPath(&allPath->at(i));
        std::cout << std::endl;
    }
    std::cout << "after sort" << std::endl;
    manager.sortPath(allPath);
    for (int i = 0; i < allPath->size(); i++) {
        manager.showPath(&allPath->at(i));
        std::cout << std::endl;
    }
    /*int index = manager.findShortestPath(allPath);
    manager.showPath(&allPath->at(index));*/
    //manager.showPath(&allPath->at(index));

    /*for (int j = 0; j < allPath->size(); j++) {
        for (int i = 0; i < allPath->at(j).size(); i++) {
            std::cout << allPath->at(j).at(i)->nodeName << "-";
        }
        std::cout << std::endl;
    }*/
    
    

    delete node0;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete allPath;
    //delete temp;
    //delete nodeVisited;
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
