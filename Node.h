#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Node
{
	string data;
	vector<Node> children;

	Node(string data) : data(data) {};
	void addSon(string data) { children.push_back(Node(data)); }

	void print(int lvl);
	double evaluate(double x);
};
