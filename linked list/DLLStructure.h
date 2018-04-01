//
// Created by mgoks on 2/27/18.
//

#ifndef LINKED_LIST_DLLSTRUCTURE_H
#define LINKED_LIST_DLLSTRUCTURE_H

#include "Node.h"
#include <climits>

class DLLStructure
{
public:
    /**
     * Initializes an empty list
     */
    DLLStructure();

    /**
     * A personalized constructor that will create a list from an array passed as argument,
     * meaning that the list will have the same number of elements as the array and each
     * element will have its data assigned to the value from the corresponding array
     * element (you may need to pass the array’s size as an argument as well).
     * Calls the​ new operator​ to dynamically create a ​ new Node​ element for each value
     * in the array.
     * @param array
     * @param size
     */
    DLLStructure(int array[], int size);

    /*
     * If we rely on the default copy constructor that is provided by the compiler to copy the elements of a list into
     * a new one, we only end up with a shallow copy, which means that the node pointers in both the original and
     * the copy list would point to the same node objects in the memory. In order achieve deep-copying, where the node
     * pointers in each list point to different node objects with the same data values, we need to define our own
     * copy constructor.
     */

    /**
     * Copies all elements of this list to newly created DLLStructure
     * @param dlls the reference to a DLLStructure object into which the elements will be copied
     */
    DLLStructure(DLLStructure& dlls);

    /**
     * Makes sure all elements in the list are being destroyed
     * (calling delete operator for each element in the list)
     */
    ~DLLStructure();

    /**
     * Loops over all the elements in the list and print their values to the screen
     */
    void printDLL();

    /**
     * Inserts a new element (valueToBeInserted) after the first occurrence
     * of the value provided by the first argument valueToInsertAfter)
     * If valueToInsertAfter is not in the list, only prints an error message and
     * does not insert valueToBeInserted.
     * @param valueToInsertAfter
     * @param valueToBeInserted
     */
    void insertAfter(int valueToInsertAfter, int valueToBeInserted);

    /**
     * Inserts a new node in to the list before valueToInsertBefore
     * Calls insertAfter()
     * @param valueToInsertBefore
     * @param valueToBeInserted the value that the new node has
     */
    void insertBefore(int valueToInsertBefore, int valueToBeInserted);

    /**
     * Deletes the first occurrence of value
     * @param value
     */
    void Delete(int value);

    /**
     * Sorts the elements in ascending order
     */
    void sort();

    /**
     * Checks if the list is empty
     * @return TRUE if list is empty, FALSE otherwise
     */
    bool isEmpty();

    /**
     *
     * @return value of the first node
     */
    int getHead();

    /**
     *
     * @return value of the last node
     */
    int getTail();

    /**
     *
     * @return number of elements in the list (not including the dummy nodes)
     */
    int getSize();

    /**
     *
     * @return minimum data value present in the list
     * @pre getSize() > 0
     */
    int getMin();

    /**
     *
     * @return maximum data value present in the list
     * @pre getSize() > 0
     */
    int getMax();


private:

    Node* first;    // pointer to first element of the list
    Node* last;     // pointer to last element of the list
    int size;

    // Dummy nodes to make the implementation easier
    Node* dummyHead;
    Node* dummyTail;

    int max = INT_MIN;    // maximum data value in the list
    int min = INT_MAX;    // minimum data value in the list

    /**
     * Updates min if the data value of the node is less than current min and
     * Updates max if the data value of the node is greater than current max
     * @param n the node to update min and max fields with
     * @pre this->contains(n)
     */
    void updateMinMax(Node* n);

    /**
     * Updates min and/or max field after the deletion of a node
     */
    void updateMinMaxAfterDelete();

    /**
     * Returns the pointer to the node that contains data
     * If such node does not exist, returns nullptr.
     * @param data the integer to look for in the node
     * @return pointer to the node that contains data
     */
    Node* getNode(int data);
};

#endif //LINKED_LIST_DLLSTRUCTURE_H
