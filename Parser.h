#pragma once
#include "Node.h"

struct Parser
{
	string input, lexeme;
	int i;

	bool isNumber(string s);
	void getLexeme();

	void S(Node& n);
	void S1(Node& n);
	void T(Node& n);

	Parser(string inp) : input(inp), i(0) {}
	Node parse();
};

