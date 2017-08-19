#include <iostream>
using namespace std;

struct Node
{
    int coefficient;
    int power;
    Node *link;
};
typedef Node* nodePtr;

class Poly
{
public:
    Poly();
    Poly(Poly& a_poly);
    Poly(int the_num);
private:
    nodePtr top;
};


int main()
{
    return 0;
}
