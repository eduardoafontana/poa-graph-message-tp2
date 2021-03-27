#include "Graph.h"

std::vector<node*> Graph::createGraph()
{
    /// <summary>
    /// create a static graph so we can use it
    /// </summary>
    
    std::vector<node*> nodeList;
    node* node0 = new node(0, 0, 4);
    node* node1 = new node(1, 4, 4);
    node* node2 = new node(2, 5, 5);
    node* node3 = new node(3, 5, 3);
    node* node4 = new node(4, 8, 4);
    addNode(node0, node1);
    addNode(node1, node2);
    addNode(node1, node3);
    addNode(node2, node3);
    addNode(node2, node4);
    addNode(node3, node4);
    nodeList.push_back(node0);
    nodeList.push_back(node1);
    nodeList.push_back(node2);
    nodeList.push_back(node3);
    nodeList.push_back(node4);
    return nodeList;
}

void Graph::addNode(node* node1, node* node2)
{
    {
        /// <summary>
        /// create a link in a graph between two nodes
        /// </summary>
        /// <param name="node1">the pointer of the node1</param>
        /// <param name="node2">the pointer of the node2</param>
        node1->addAdjacentNode(node2);
        node2->addAdjacentNode(node1);
    }
}
