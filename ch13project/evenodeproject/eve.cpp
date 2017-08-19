//Name: Jonathan Villegas
//Assignment: Write a program that takes a list of suitors,
//makes them a circular linked list, and outputs the correct suitor
//after eliminating every third one.
//Date: 3/21/14
//Email: jonathan.e.villegas@gmail.com
//filename: eve.cpp

#include <iostream>
#include "eve.h"
using namespace std;

namespace villegaseve
{
    Node::Node() : data(0), link(NULL)
    {
        //Intentionally left blank.
    }

    Node::Node(int the_data, Node *the_link) : data(the_data), link(the_link)
    {
        //Intentionally left blank.
    }

    void Node::setData(int the_data)
    {
        data = the_data;
    }

    void Node::setLink(Node *the_link)
    {
        link = the_link;
    }

    int Node::getData()
    {
        return data;
    }

    Node* Node::getLink()
    {
        return link;
    }

    void Node::getSuitor(int numOfSuitors)
    {
        NodePtr head;

        cout << "Number of suitors: " << numOfSuitors << endl;
        cout << endl;
        cout << "Here are the suitors..." << endl;

        head = new Node(numOfSuitors, NULL);//start of the linked list
        for (int i = numOfSuitors - 1; i >= 1; i--)//inserts the rest of the linked list
        {
            head_insert(head, i);
        }

        NodePtr iter;
        for (iter = head; iter != NULL; iter = iter -> getLink())//print out the list
        {
            cout << iter->getData() << endl;
        }

        NodePtr temp = head;
        for (int j = numOfSuitors; j >= 1; j--)
        {
            if (temp->getLink() == NULL)
                temp->setLink(head);  //Sets the last link to point to the head. Circular loop.
            else
                temp = temp -> getLink();  //if it is not the last link, go to the next link that points to the next node.
        }

        int count = 1;
        int total = numOfSuitors;
        NodePtr before, discard;
        temp = head;

        while (total != 1)
        {
            if (count == 2)
            {
                before = temp;
            }
            else if (count == 3)
            {
                discard = temp;  //discard points to the current node
                before -> setLink(temp->getLink());//before's link points to where temp points
                cout << "Suitor #" << temp->getData() << " eliminated." << endl;
                temp = temp->getLink();//point to next node before we delete it

                delete discard;
                total--;
                count = 1;//The number we are now at is counted as 1 since we moved to the next number after the deletion.
            }
            count++;
            temp = temp -> getLink();//Next number is number 2.
        }
        cout << "Suitor #" << temp -> getData() << " wins Eve's heart." << endl;
    }

    void head_insert(NodePtr& head, int data)
    {
        NodePtr temp;
        temp = new Node(data, head);
        head = temp;
    }
}
