#include "Graph.h"

std::vector<node*> Graph::createGraph()
{
    /// <summary>
    /// create a static graph so we can use it
    /// </summary>
    
    std::vector<node*> nodeList;
    
	////+++++++++++++++ Question 4 - la partie bonus +++++++++++++++
	////Pour exécuter la question bonus, décommentez cette partie et commentez celle ci-dessous.
    //node* nodeP1 = new node(1, "P1", 0, 0);
    //node* nodeP2 = new node(2, "P2", 0, 1);
    //node* nodeP3 = new node(3, "P3", 0, 3);
    //node* nodeP4 = new node(4, "P4", 0, 4);

    //addNode(nodeP1, nodeP2);
    //addNode(nodeP3, nodeP2);
    //addNode(nodeP3, nodeP4);
    //nodeList.push_back(nodeP1);
    //nodeList.push_back(nodeP2);
    //nodeList.push_back(nodeP3);
    //nodeList.push_back(nodeP4);
	////------------------------------------------------------------

	////--------------- Question 4 ------------------
	////Pour exécuter la question normale, décommentez cette partie et commentez la partie supérieure.
    node* nodeP1 = new node(1, "P1", 1, 6);
    node* nodeP2 = new node(2, "P2", 3, 4);
    node* nodeP3 = new node(3, "P3", 5, 6);
    node* nodeP4 = new node(4, "P4", 5, 4);
    node* nodeP5 = new node(5, "P5", 8, 9);
    node* nodeP6 = new node(6, "P6", 8, 4);
    node* nodeP7 = new node(7, "P7", 9, 1);
    node* nodeP8 = new node(8, "P8", 10, 5);
    node* nodeP9 = new node(9, "P9", 11, 3);
    node* nodeP10 = new node(10, "P10", 13, 9);
    node* nodeP11 = new node(11, "P11", 13, 5);
    node* nodeP12 = new node(12, "P12", 15, 5);

    addNode(nodeP1, nodeP5);
    addNode(nodeP1, nodeP3);
    addNode(nodeP1, nodeP2);

    addNode(nodeP2, nodeP4);

    addNode(nodeP3, nodeP5);
    addNode(nodeP3, nodeP8);
    addNode(nodeP3, nodeP6);

    addNode(nodeP4, nodeP6);
    addNode(nodeP4, nodeP7);

    addNode(nodeP5, nodeP10);
    addNode(nodeP5, nodeP11);

    addNode(nodeP6, nodeP8);
    addNode(nodeP6, nodeP9);

    addNode(nodeP7, nodeP9);

    addNode(nodeP8, nodeP11);

    addNode(nodeP9, nodeP12);

    addNode(nodeP10, nodeP11);
    addNode(nodeP10, nodeP12);

    addNode(nodeP11, nodeP12);

    nodeList.push_back(nodeP1);
    nodeList.push_back(nodeP2);
    nodeList.push_back(nodeP3);
    nodeList.push_back(nodeP4);
    nodeList.push_back(nodeP5);
    nodeList.push_back(nodeP6);
    nodeList.push_back(nodeP7);
    nodeList.push_back(nodeP8);
    nodeList.push_back(nodeP9);
    nodeList.push_back(nodeP10);
    nodeList.push_back(nodeP11);
    nodeList.push_back(nodeP12);
	////------------------------------------------------------------

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
