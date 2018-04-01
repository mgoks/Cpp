//
// Created by Murat Goksel on 3/23/18.
//

#include <iostream>
#include "Exceptions.h"

#ifndef UNTITLED_SMARTPOINTER_H
#define UNTITLED_SMARTPOINTER_H

using namespace std;

/**
 * A custom smart pointer that automatically deletes the memory for built-in generic
 * (int, float, or double) type that is allocated through it
 */
template <typename T>
class SmartPointer
{
public:
    /**
     * Allocates a variable and initializes it to zero
     */
    SmartPointer()
    {
        try{
            ptr = new T;
        } catch (bad_alloc& badAlloc){
            throw OutOfMemoryException();
        }
        *ptr = 0;
    }

    /**
    * Allocates an array and initializes all indices to zero
    * @param size The size of the array
    * @param isArray A boolean variable indicating the construction of the array. It should be always be TRUE as the
    * constructor will allocate an array even though the input is FALSE.
    */
    SmartPointer(int size, bool isArray)
    {
        int i;

        this->isArray = true;
        this->size = size;
        try{
            ptr = new T[size];
        } catch (bad_alloc& badAlloc){
            throw OutOfMemoryException();
        }
        for (i = 0; i < size; ++i)
            ptr[i] = 0;
    }

    /**
     * Allocates a variable and initializes it to a value
     * @param value The value to initialize the variable to
     */
    explicit SmartPointer(T value)
    {
        if (value < 0)
            throw NegativeNumberException();
        try{
            ptr = new T;
        } catch (bad_alloc& badAlloc){
            throw OutOfMemoryException();
        }
        *ptr = value;
    }

    /**
     * Creates a SmartPointer which points to a copy of the input array
     * @param value Pointer to the array original array
     * @param size Array size
     */
    SmartPointer(T* value, int size)
    {
        int i;

        this->isArray = true;
        this->size = size;
        for (i = 0; i < size; ++i)
            if (value[i] < 0)
                throw NegativeNumberException();
        try{
            ptr = new T[size];
        } catch (bad_alloc& badAlloc){
            throw OutOfMemoryException();
        }
        for (i = 0; i < size; ++i)
            ptr[i] = value[i];
    }

    /**
     * Deletes the allocated memory
     */
    ~SmartPointer()
    {
        if (!isArray)
            delete ptr;
        else
            delete[] ptr;
    }

    /**
     * For a single variable
     * @return the value of the variable the pointer points to
     */
    T getValue()
    {
        return *ptr;
    }

    /**
     * For array
     * @param i The index variable
     * @return the value at index i
     * @pre isArray == true
     */
    T getValueAt(int i)
    {
        if (!isArray){
            cerr << "Error: SmartPointer does not point to an array.\n";
            return -1;
        } else if (i >= size || i < 0){
            cerr << "Error: Array index out of bounds\n";
            return -2;
        }
        return ptr[i];
    }

    /**
     * For single variable
     * @param value The value to assign to the variable the pointer points to
     */
    void setValue(T value)
    {
        if (value < 0)
            throw NegativeNumberException();
        *ptr = value;
    }

    /**
     * For array
     * @param i Index variable
     * @param value
     */
    void setValueAt(int i, T value)
    {
        if (!isArray){
            cerr << "Error: SmartPointer does not point to an array.\n";
            return;
        } else if (i >= size || i < 0){
            cerr << "Error: Array index out of bounds\n";
            return;
        }
        if (value < 0)
            throw NegativeNumberException();
        ptr[i] = value;
    }

    /**
     * Performs addition on variables allocated through SmartPointers
     * @param spAddend1
     * @param spAddend2
     * @return
     */
    friend SmartPointer operator+(SmartPointer& spAddend1, SmartPointer& spAddend2)
    {
        SmartPointer<T> spSum(spAddend1.getValue() + spAddend2.getValue());
        return spSum;
    }

    /**
     * Performs subtraction
     * @param spMinuend
     * @param spSubtrahend
     * @return the difference of minuend and subtrahend
     * @pre minuend >= subtrahend
     */
    friend SmartPointer operator-(SmartPointer& spMinuend, SmartPointer& spSubtrahend)
    {
        SmartPointer<T> spDiff(spMinuend.getValue() - spSubtrahend.getValue());
        return spDiff;
    }

    /**
     * Performs multiplication
     * @param spFactor1
     * @param spFactor2
     * @return product of the values of the input SmartPointers
     */
    friend SmartPointer operator*(SmartPointer& spFactor1, SmartPointer& spFactor2)
    {
        SmartPointer<T> spProduct(spFactor1.getValue() * spFactor2.getValue());
        return spProduct;
    }

private:
    T* ptr = nullptr;
    bool isArray = false;
    int size = 0;
};

#endif //UNTITLED_SMARTPOINTER_H