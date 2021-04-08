#pragma once
#include "Node.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
class Presentation
//this class is for all the presentation of the game and the interaction with the user
{
public:
	static void showPath(std::vector<node*>* path);
	static void showWinningNode(std::vector<node*> nodeList);
	static int getStartingNode();
	static int getEndingNode();
	static double getMaxDistance();
	static void nodeDidntFound();
	static bool continuePlaying();
	static void showNodeList(std::vector<node*> nodeList);
	static void showNoPathFound();
	static void showNodeTooFar(node* nodeTooFar);
};

