#include "Parser.h"

bool Parser::isNumber(string s)
{
    int state = 0;
    for(char c : s)
    {
        if(!isdigit(c))
            return false;
    }
    return true;
}

void Parser::getLexeme()
{
    if(i >= input.size())
    {
        lexeme = "#";
        return;
    }
    lexeme = "";
    if(input[i] == '+')
    {
        lexeme += input[i];
        ++i;
    }
    else
    {
        while(i < input.size() && !(input[i] == '+'))
        {
            lexeme += input[i];
            ++i;
        }
    }
}

void Parser::S(Node& n)
{
    if(isNumber(lexeme))
    {
        // S -> TS1
        n.addSon("T");
        T(n.children[0]);
        n.addSon("S1");
        S1(n.children[1]);
    }
    else throw exception("Wrong input");
}

void Parser::S1(Node& n)
{
    if(lexeme == "+")
    {
        // S1 -> +TS1
        n.addSon("+");
        getLexeme();
        n.addSon("T");
        T(n.children[1]);
        n.addSon("S1");
        S1(n.children[2]);
    }
    else if(lexeme == "#")
    {
        // S1 -> eps
        n.addSon("eps");
    }
    else throw exception("Wrong input");
}

void Parser::T(Node& n)
{
    if(isNumber(lexeme))
    {
        // T -> num
        n.addSon(lexeme);
        getLexeme();
    }
    else throw exception("Wrong input");
}

Node Parser::parse()
{
    Node root("S");
    getLexeme();
    S(root);
    if(lexeme != "#")
        throw exception("Wrong input");
    return root;
}
