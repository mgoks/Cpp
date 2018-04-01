#include <iostream>
#include "SmartPointer.h"
#include "Exceptions.h"

using namespace std;

int main()
{
    // Test cases

    SmartPointer<int> sPointerI(11);
    cout << sPointerI.getValue() << ", ";
    SmartPointer<int> sPointerI2;
    sPointerI2.setValue(133);
    cout << sPointerI2.getValue() << endl;

    cout << "\nTest exceptions:\n";
    try{
        SmartPointer<int> sPointerNeg(-1);
    } catch (NegativeNumberException& e){
        cerr << e.what();
    }
    try{
        SmartPointer<int> sPointerMem(12);
        cout << sPointerMem.getValue() << endl;
        cout << "Not out of memory, hooray!" << endl;
    } catch (OutOfMemoryException& e){
        cerr << e.what();
    }

    SmartPointer<float> sPointerF;
    sPointerF.setValue(13.31);
    cout << "\nTest generic typing:\n" << sPointerF.getValue() << ", ";
    SmartPointer<double> sPointerD(13.65413213216549847654654);
    cout << sPointerD.getValue() << endl;

    cout << "\nTest overloaded operators:\n";
    SmartPointer<float> sPointerF2;
    SmartPointer<float> sPointerF3;
    sPointerF2.setValue(1.5);
    sPointerF3.setValue(2.5);
    SmartPointer<float> sPointerFSum = sPointerF2 + sPointerF3;
    sPointerF2.setValue(sPointerF2.getValue() * 2);
    SmartPointer<float> sPointerFDiff = sPointerF2 - sPointerF3;
    SmartPointer<float> sPointerFProd = sPointerF2 * sPointerF3;
    cout << "float : " << sPointerFSum.getValue() << ", " << sPointerFDiff.getValue() << ", " << sPointerFProd.getValue() << ", " << endl;

    SmartPointer<int> spInt1(5);
    SmartPointer<int> spInt2(4);
    SmartPointer<int> spIntSum = spInt1 + spInt2;
    SmartPointer<int> spIntDiff = spInt1 - spInt2;
    SmartPointer<int> spIntProd = spInt1 * spInt2;
    cout << "int   : " << spIntSum.getValue() << ", " << spIntDiff.getValue() << ", " << spIntProd.getValue() << endl;

    SmartPointer<double> spDouble1(654.45);
    SmartPointer<double> spDouble2(64.5646465);
    SmartPointer<double> spDoubleSum = spDouble1 + spDouble2;
    SmartPointer<double> spDoubleDiff = spDouble1 - spDouble2;
    SmartPointer<double> spDoubleProd = spDouble1 * spDouble2;
    cout << "double: " << spDoubleSum.getValue() << ", " << spDoubleDiff.getValue() << ", " << spDoubleProd.getValue() << endl;
    cout << endl;

    int i;

    cout << "Test handling arrays:\n";
    SmartPointer<int> spIntArray(10, true);
    cout << "{" << spIntArray.getValueAt(0);
    for (i = 1; i < 10; ++i)
        cout << ", " << spIntArray.getValueAt(i);
    cout << "}\n";

    for (i = 0; i < 10; ++i)
        spIntArray.setValueAt(i, i);
    cout << "{" << spIntArray.getValueAt(0);
    for (i = 1; i < 10; ++i)
        cout << ", " << spIntArray.getValueAt(i);
    cout << "}\n";

    double a[10] = {10.654, 11.31321, 12.987, 13.654, 14.654, 15.654, 16.321, 17.741, 18.852, 19.963};
    SmartPointer<double> spDoubleArray(a, 10);
    cout << "{" << spDoubleArray.getValueAt(0);
    for (i = 1; i < 10; ++i)
        cout << ", " << spDoubleArray.getValueAt(i);
    cout << "}\n";

    return 0;
}
