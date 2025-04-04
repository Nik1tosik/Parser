#pragma once
#include "Node.h"

struct Parser
{
	string input, lexeme;
	int i;

	bool isNumber(string s);
	bool isWord(string s);
	void getLexeme();

	void Function(Node& n);
	void Type(Node& n);
	void Var(Node& n);
	void Return(Node& n);
	void Id(Node& n);

	Parser(string inp) : input(inp), i(0) {}
	Node parse();
};

