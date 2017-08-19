#include <iostream>
#include <string>
using namespace std;

struct NodeType
{
    string data;
    NodeType *link;
};
typedef NodeType* PointerType;

void head_insert(PointerType& head, string data);

void head_insert(PointerType& head, string data)
{
    PointerType temp;
    temp = new NodeType;
    temp->data = data;
    temp->link = head;
    head = temp;
}

int main()
{
    PointerType head = NULL;
    head_insert(head, "Something 1");
    head_insert(head, "Another thing 2");
    head_insert(head, "Top of list 3");

    PointerType iter;
    for (iter = head; iter != NULL; iter = iter->link)
    {
        cout << iter->data << endl;
    }

    return 0;
}
