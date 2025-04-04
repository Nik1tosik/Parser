#include "Parser.h"

bool Parser::isNumber(string s)
{
    if(!('1' <= s[0] && s[0] <= '9'))
    {
        return false;
    }
    for(int i = 1; i < s.size(); ++i)
    {
        if(!(('0' <= s[i] && s[i] <= '9')))
        {
            return false;
        }
    }
    return true;
}

bool Parser::isWord(string s)
{
    if('0' <= s[0] && s[0] <= '9')
    {
        return false;
    }
    for(int i = 1; i < s.size(); ++i)
    {
        if(!(('0' <= s[i] && s[i] <= '9')
           || ('a' <= s[i] && s[i] <= 'z')
           || ('A' <= s[i] && s[i] <= 'Z') || s[i] == '_'))
        {
            return false;
        }
    }
    return true;
}

void Parser::getLexeme()
{
    while(input[i] == ' ')
    {
        ++i;
    }
    if(i >= input.size())
    {
        lexeme = "#";
        return;
    }

    lexeme = "";
    while(i < input.size() && !(input[i] == ' '))
    {
        lexeme += input[i];
        ++i;
    }
}

void Parser::Function(Node& n)
{
    if(lexeme == "Function")
    {
        // Function -> Type Var Return
        n.addSon("Type");
        getLexeme();
        Type(n.children[0]);

        n.addSon("Var");
        Var(n.children[1]);

        n.addSon("Return");
        Return(n.children[2]);
    }
}

void Parser::Type(Node& n)
{
    if(lexeme == "int")
    {
        // Type -> int
        n.addSon("int");
        getLexeme();
    }
}

void Parser::Var(Node& n)
{
    if(isWord(lexeme))
    {
        // Var -> Id
        n.addSon("Id");
        Id(n.children[0]);
    }
}

void Parser::Return(Node& n)
{
    if(isWord(lexeme))
    {
        // Return -> Id
        n.addSon("Id");
        Id(n.children[0]);
    }
}

void Parser::Id(Node& n)
{
    if(isWord(lexeme))
    {
        // Id -> id_name
        n.addSon(lexeme);
        getLexeme();
    }
}

Node Parser::parse()
{
    Node root("Function");
    getLexeme();
    Function(root);
    if(lexeme != "#")
        throw exception("Wrong input");
    return root;
}
