#include <iostream>
#include <string>
#include "Parser.h"
#include "Node.h"


using namespace std;

int main()
{
	string code = "Function int function_name return_value";
	Parser parcer(code);

	Node root = parcer.parse();
	root.print(4);
}