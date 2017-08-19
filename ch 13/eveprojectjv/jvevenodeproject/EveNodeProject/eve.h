#ifndef EVE_H_INCLUDED
#define EVE_H_INCLUDED

namespace villegaseve
{
    #include <iostream>
    using namespace std;

    class Node
    {
    public:
        Node();
        Node(int the_data, Node *the_link);
        void setData(int the_data);
        void setLink(Node *the_link);
        int getData();
        Node *getLink();
        void getSuitor(int numOfSuitors);
    private:
        int data;
        Node *link;
    };
    typedef Node* NodePtr;
    void head_insert(NodePtr& head, int data);
}


#endif // EVE_H_INCLUDED
