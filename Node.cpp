#include "Node.h"

void Node::print(int lvl)
{
    for(int i = 0; i < lvl; ++i)
        cout << ' ';

    cout << data << endl;
    for(Node n : children)
        n.print(lvl + 2);
}
