//Name: Jonathan Villegas
//Assignment: Write a program that takes a list of suitors,
//makes them a circular linked list, and outputs the correct suitor
//after eliminating every third one.
//Date: 3/21/14
//Email: jonathan.e.villegas@gmail.com
//filename: eve.h

#ifndef EVE_H_INCLUDED
#define EVE_H_INCLUDED

namespace villegaseve
{
    #include <iostream>
    using namespace std;

    class Node
    {
    public:
        //Constructors
        Node();
        Node(int the_data, Node *the_link);
        //Mutators
        void setData(int the_data);
        void setLink(Node *the_link);
        //Accessors
        int getData();
        Node *getLink();
        //Takes the number of suitors and displays the winner after eliminating every
        //third one.
        void getSuitor(int numOfSuitors);
    private:
        int data;
        Node *link;
    };
    typedef Node* NodePtr;
    void head_insert(NodePtr& head, int data);
}


#endif // EVE_H_INCLUDED
