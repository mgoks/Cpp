//
// Created by Murat Goksel on 2/27/18.
//

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

class Node
{
private:
    int data;   // to hold the data​ in each element
    Node* next; // to hold the pointer to the ​ next element
    Node* prev; // to hold the pointer to the ​ previous element

public:
    /**
     * Initializes the data members appropriately
     */
    Node();

    /**
     * A personalized constructor that will create a node and assign its data and pointers
       to the given values passed as arguments
     * @param data
     * @param next
     * @param prev
     */
    Node(int data, Node* next, Node* prev);

    /**
     * A destructor that makes sure all dynamically allocated memory was appropriately deleted (if any)
     */
    ~Node();

    /**
     * Swaps the data of this node with the data of another node
     * @param n the node to swap values with
     */
    void swapValues(Node* n);

    /*
     * Accessor methods for private members
     */
    void setData(int data);
    void setNext(Node* next);
    void setPrev(Node* prev);
    int getData();
    Node* getNext();
    Node* getPrev();
};

#endif //LINKED_LIST_NODE_H
