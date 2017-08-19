#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    Node();
    Node(Node *next, string the_string);
    string getData();
    void setData(string the_data);
    Node *getLink();
    void setLink(Node *next);
private:
    string data;
    Node *link;
};
typedef Node* NodePtr;

Node::Node() : link(NULL), data("empty")
{}

Node::Node(Node *next, string the_string) : link(next), data(the_string)
{}

string Node::getData()
{
    return data;
}

void Node::setData(string the_data)
{
    data = the_data;
}

Node* Node::getLink()
{
    return link;
}

void Node::setLink(Node* next)
{
    link = next;
}

void head_insert(NodePtr& head, string data);

void head_insert(NodePtr& head, string data)
{
    NodePtr temp;
    temp = new Node(head, data);//temp now points to the old head, next newest
    head = temp;//head now points to the newest item in the list.
}

int main()
{
    NodePtr head = NULL;
    head_insert(head, "Something 1");
    head_insert(head, "Another thing 2");
    head_insert(head, "Top of list 3");

    NodePtr iter;
    for (iter = head; iter != NULL; iter = iter->getLink())
    {
        cout << iter->getData() << endl;
    }

    return 0;
}
