//
// Created by Murat Goksel on 3/24/18.
//
#include <exception>
#ifndef UNTITLED_EXCEPTIONS_H
#define UNTITLED_EXCEPTIONS_H

using namespace std;

/**
 * To be thrown when allocating a new variable if the system runs out of memory.
 * This exception should be treated. When thrown, a message should be displayed to the
 * screen warning the user that the variable was not being allocated.
 */
class OutOfMemoryException: public exception
{
public:
    /**
     *
     * @return warning message
     */
    virtual const char* what() const throw()
    {
        return "Warning: System out of memory\nThe variable was not allocated.\n";
    }
};

/**
 * To be thrown whenever a user tries to assign a negative number to any variable that was being allocated
 * through SmartPointer class. This exception should be treated and the warning message should be displayed to
 * the screen.
 */
class NegativeNumberException: public exception
{
public:
    /**
     *
     * @return A message warning the user that SmartPointer class does not handle negative numbers
     */
    virtual const char* what() const throw()
    {
        return "Warning: You tried to assign a negative number to a variable through SmartPointer class.\nSmartPointer class does not handle negative numbers.\n";
    }
};

#endif //UNTITLED_EXCEPTIONS_H
