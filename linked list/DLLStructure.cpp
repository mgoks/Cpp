//
// Created by Murat Goksel on 2/27/18.
//

#include <iostream>
#include <climits>
#include "DLLStructure.h"
using namespace std;


// Constructors

DLLStructure::DLLStructure()
{
    // Dummy nodes to make the implementation easier
    dummyHead = new Node();
    dummyTail = new Node();

    // Set the pointers of the dummies appropriately
    dummyHead->setNext(dummyTail);
    dummyTail->setPrev(dummyHead);

    this->first = nullptr;
    this->last = nullptr;
    this->size = 0;

//    cout << "Empty list was created successfully!" << endl;
}

DLLStructure::DLLStructure(int *array, int size)
{
    Node* node, * nextNode, * prevNode;

    // Dummy nodes to make the implementation easier
    dummyHead = new Node();
    dummyTail = new Node();

    // Set the pointers of the dummies appropriately
    dummyHead->setNext(dummyTail);
    dummyTail->setPrev(dummyHead);

    prevNode = dummyHead;
    nextNode = dummyTail;

    // Create a node for each element in the array and set the pointers
    for (int i = 0; i < size; i++)
    {
        node = new Node(array[i], nextNode, prevNode);
        prevNode->setNext(node);
        nextNode->setPrev(node);
        updateMinMax(node);
        prevNode = node;
    }

    // Set first and last fields
    this->first = dummyHead->getNext();
    this->last = dummyTail->getPrev();

    this->size = size;

//    cout << "New list created successfully from an array!" << endl;
}

DLLStructure::DLLStructure(DLLStructure& dlls)
{
    Node* cur, * next, * prev, * orig;
    dummyTail = new Node;
    dummyHead = new Node;
    dummyHead->setNext(dummyTail);
    dummyTail->setPrev(dummyHead);
    prev = dummyHead;
    next = dummyTail;

    // orig = original node we want to copy
    orig = dlls.getNode(dlls.getHead());

    this->size = dlls.getSize();
    for (int i = 0; i < size; i++)
    {
        cur = new Node(orig->getData(), next, prev);
        prev->setNext(cur);
        next->setPrev(cur);
        updateMinMax(cur);
        prev = cur;
        orig = orig->getNext();
    }
    first = dummyHead->getNext();
    last = dummyTail->getPrev();

//    cout << "List was deep-copied successfully!" << endl;
}

// Destructor

DLLStructure::~DLLStructure()
{
    if (this->size == 0)
    {
        delete dummyHead;
        delete dummyTail;
    }
    else
    {
        Node* node;
        for (int i = 0; i < size; i++)
        {
            node = this->first;
            first = first->getNext();
            delete node;
        }
        delete dummyHead;
        delete dummyTail;
    }

//    cout << "DLL destructor was called successfully!" << endl;
}


// Methods

void DLLStructure::printDLL()
{
    if ( size == 0)
    {
        cout << "()" << endl;
    }
    else
    {
        cout << "(" << first->getData();
        Node *node = first->getNext();

        for (int i = 1; i < size; i++) {
            cout << ", " << node->getData();
            node = node->getNext();
        }
        cout << ")" << endl;
    }
}

Node* DLLStructure::getNode(int data)
{
    Node* node = first;

    for (int i = 0; i < size; i++)
    {
        if (node->getData() == data)
            return node;
        else
            node = node->getNext();
    }
    return nullptr;
}

void DLLStructure::insertAfter(int valueToInsertAfter, int valueToBeInserted)
{
    Node* A = this->getNode(valueToInsertAfter);
    if (A == nullptr)
    {
        cout << "Error: "<< valueToInsertAfter << " (valueToInsertAfter) is not in the list." << endl;
        return;
    }
    else
    {
        Node* B = A->getNext();

        // insert node C after A and before B
        Node* C = new Node(valueToBeInserted, B, A);
        A->setNext(C);
        B->setPrev(C);
        updateMinMax(C);
        size++;
    }
}

void DLLStructure::insertBefore(int valueToInsertBefore, int valueToBeInserted)
{
    Node* B = this->getNode(valueToInsertBefore);
    if (B == nullptr)
    {
        cout << "Error: "<< valueToInsertBefore << " (valueToInsertBefore) is not in the list." << endl;
        return;
    }
    else
    {
        // Instead of inserting after B, insert after B.prev
        this->insertAfter(B->getPrev()->getData(), valueToBeInserted);
    }
}

void DLLStructure::Delete(int value)
{
    Node* n = this->getNode(value);
    if (n == nullptr)
    {
        cout << "Error: "<< value << " (value to delete) is not in the list." << endl;
    }
    else
    {
        Node* prev, * next;
        prev = n->getPrev();
        next = n->getNext();
        prev->setNext(next);
        next->setPrev(prev);
        size--;
        if (n->getData() == min || n->getData() == max) updateMinMaxAfterDelete();

        delete n;

    }
}

void DLLStructure::sort()
{
    Node* cur, * next;
    bool swapped;
    do
    {
        cur = first;
        next = cur->getNext();
        swapped = false;
        for (int i = 0; i < size-1; i++)
        {
            if (cur->getData() > next->getData())
            {
                cur->swapValues(next);
                swapped = true;
            }
            cur = next;
            next = next->getNext();
        }
    } while(swapped);
}

bool DLLStructure::isEmpty()
{
    return size == 0;
}

int DLLStructure::getHead()
{
    if (size == 0) return NULL;
    return first->getData();
}

int DLLStructure::getTail()
{
    if (size == 0) return NULL;
    return last->getData();
}

int DLLStructure::getSize()
{
    return size;
}

void DLLStructure::updateMinMax(Node *n)
{
    if (n->getData() < min)
    {
        min = n->getData();
    }
    if (n->getData() > max)
    {
        max = n->getData();
    }
}

void DLLStructure::updateMinMaxAfterDelete()
{
    if (size == 0)
    {
        min = INT_MAX;
        max = INT_MIN;
    }
    else if (size > 0)
    {
        Node* cur = first;
        for (int i = 0; i < size; i++)
        {
            if (cur->getData() > max) max = cur->getData();
            if (cur->getData() < min) min = cur->getData();
        }
    }
}

int DLLStructure::getMin()
{
    return min;
}

int DLLStructure::getMax()
{
    return max;
}
