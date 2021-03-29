#include "Graph.h"

std::vector<node*> Graph::createGraph()
{
    /// <summary>
    /// create a static graph so we can use it
    /// </summary>
    
    //std::vector<node*> nodeList;
    //node* node0 = new node(0, 0, 4);
    //node* node1 = new node(1, 4, 4);
    //node* node2 = new node(2, 5, 5);
    //node* node3 = new node(3, 5, 3);
    //node* node4 = new node(4, 8, 4);
    //addNode(node0, node1);
    //addNode(node1, node2);
    //addNode(node1, node3);
    //addNode(node2, node3);
    //addNode(node2, node4);
    //addNode(node3, node4);
    //nodeList.push_back(node0);
    //nodeList.push_back(node1);
    //nodeList.push_back(node2);
    //nodeList.push_back(node3);
    //nodeList.push_back(node4);
    //return nodeList;

	//-------------------------------------

	//std::vector<node*> nodeList;
	//node* nodeP1 = new node(0, 0.502, 1.957);
	//node* nodeP2 = new node(1, 1.192, 0.772);
	//node* nodeP3 = new node(2, 1.345, 2.157);
	//node* nodeP5 = new node(3, 2.076, 0.309);
	//node* nodeP4 = new node(4, 1.420, 1.306);
	//node* nodeP6 = new node(5, 4.237, 3.690);
	//node* nodeP7 = new node(6, 2.237, 1.424);
	//node* nodeP8 = new node(7, 3.314, 0.151);
	//node* nodeP9 = new node(8, 4.318, 1.456);
	//node* nodeP10 = new node(9, 3.180, 0.931);

	//addNode(nodeP1, nodeP3);
	//addNode(nodeP1, nodeP4);
	//addNode(nodeP1, nodeP2);

	//addNode(nodeP3, nodeP6);
	//addNode(nodeP3, nodeP7);
	//addNode(nodeP3, nodeP4);

	//addNode(nodeP4, nodeP7);
	//addNode(nodeP4, nodeP8);
	//addNode(nodeP4, nodeP5);

	//addNode(nodeP2, nodeP5);

	//addNode(nodeP7, nodeP6);
	//addNode(nodeP7, nodeP9);
	//addNode(nodeP7, nodeP10);
	//addNode(nodeP7, nodeP8);

	//addNode(nodeP5, nodeP8);

	//addNode(nodeP10, nodeP9);
	//addNode(nodeP10, nodeP8);

	//addNode(nodeP9, nodeP6);

	//nodeList.push_back(nodeP1);
	//nodeList.push_back(nodeP2);
	//nodeList.push_back(nodeP3);
	//nodeList.push_back(nodeP4);
	//nodeList.push_back(nodeP5);
	//nodeList.push_back(nodeP6);
	//nodeList.push_back(nodeP7);
	//nodeList.push_back(nodeP8);
	//nodeList.push_back(nodeP9);
	//nodeList.push_back(nodeP10);

//-------------------------------------
	//std::vector<node*> nodeList;
	//node* nodeP1 = new node(0, 1, 4);
	//node* nodeP2 = new node(1, 3, 5);
	//node* nodeP3 = new node(2, 5, 3);
	//node* nodeP4 = new node(3, 7, 4);
	//node* nodeP5 = new node(4, 8, 0);

	//addNode(nodeP1, nodeP2);
	//addNode(nodeP1, nodeP3);
	//addNode(nodeP1, nodeP5);

	//addNode(nodeP2, nodeP4);
	//addNode(nodeP3, nodeP4);
	//addNode(nodeP5, nodeP4);

	//nodeList.push_back(nodeP1);
	//nodeList.push_back(nodeP2);
	//nodeList.push_back(nodeP3);
	//nodeList.push_back(nodeP4);
	//nodeList.push_back(nodeP5);

	//-------------------------------------

	std::vector<node*> nodeList;
	node* nodeP1 = new node(0, 1, 6);
	node* nodeP2 = new node(1, 3, 4);
	node* nodeP3 = new node(2, 5, 6);
	node* nodeP4 = new node(3, 5, 4);
	node* nodeP5 = new node(4, 8, 9);
	node* nodeP6 = new node(5, 8, 4);
	node* nodeP7 = new node(6, 9, 1);
	node* nodeP8 = new node(7, 10, 5);
	node* nodeP9 = new node(8, 11, 3);
	node* nodeP10 = new node(9, 13, 9);
	node* nodeP11 = new node(10, 13, 5);
	node* nodeP12 = new node(11, 15, 5);

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
