//
// Created by hgokse on 2/27/18.
//

#include "Node.h"

/**
 * Initializes the data members appropriately
 */
Node::Node():data(0), next(nullptr), prev(nullptr) {}

/**
 * A personalized constructor that will create a node and assign its data and pointers
   to the given values passed as arguments
 * @param data
 * @param next
 * @param prev
 */
Node::Node(int data, Node *next, Node *prev):data(data), next(next), prev(prev) {}

/**
 * A destructor that makes sure all dynamically allocated memory was appropriately deleted (if any)
 */
Node::~Node()
{

}

int Node::getData()
{
    return this->data;
}

Node* Node::getNext()
{
    return this->next;
}

Node* Node::getPrev()
{
    return this->prev;
}

void Node::setData(int data)
{
    this->data = data;
}

void Node::setNext(Node *next)
{
    this->next = next;
}

void Node::setPrev(Node *prev)
{
    this->prev = prev;
}