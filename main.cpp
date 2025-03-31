#include <iostream>
#include <string>
#include "Parser.h"
#include "Node.h"


using namespace std;

int main()
{
	string code = "2+3+23+123";
	Parser parcer(code);

	Node root = parcer.parse();
	root.print(1);
}