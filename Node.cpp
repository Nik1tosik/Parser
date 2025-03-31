#include "Node.h"

void Node::print(int lvl)
{
    for(int i = 0; i < lvl; ++i)
        cout << ' ';
    cout << data << endl;
    for(Node n : children)
        n.print(lvl + 1);
}

double Node::evaluate(double x)
{
    if(data == "S")
    {
        return children[0].evaluate(x) + children[1].evaluate(x);
    }
    else if(data == "S1")
    {
        if(children[0].data == "+")
            return children[1].evaluate(x) + children[2].evaluate(x);
        else
            return 0;
    }
    else if(data == "T")
    {
        return stod(children[0].data);
    }
}
