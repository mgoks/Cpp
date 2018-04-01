//
// Created by mgoks on 2/27/18.
//

#include "Node.h"
#include <iostream>
using namespace std;

// Constructors
Node::Node():data(0), next(nullptr), prev(nullptr) {}
Node::Node(int data, Node *next, Node *prev):data(data), next(next), prev(prev) {}

// Destructor
Node::~Node() {}

void Node::swapValues(Node *n)
{
    int tmp = this->getData();
    this->setData(n->getData());
    n->setData(tmp);
}

// Accessor methods

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
