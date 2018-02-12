#include <iostream>
using namespace std;

/*
 * Answer 1
 *
 * A function in C++ cannot return an array by value but it can return
 * the memory address or a reference to the array.
 * Returning an array by address involves returning a pointer to the the address of the
 * first element of the array.
 * When returning a reference to the array, the reference is passed to the
 * caller. The caller can then use this reference to continue modifying
 * the array.
 */

const int rows = 5;
const int cols = 5;
const int len = 25;    // Length of the 1D-array which represents the a matrix

void fillMatrix(int matrix[rows][cols]);
void printMatrix(int matrix[rows][cols]);
void transposeMatrix(int matrix[rows][cols]);

void multiply(int a[rows][cols], int b[rows][cols], int c[rows][cols]);
void recMultiply(int a[rows][cols], int b[rows][cols], int c[rows][cols]);

void fillMatrix2(int** pp);
void printMatrix2(int** pp);
void transposeMatrix2(int** pp);

void fillMatrix(int a[len]);
void printMatrix(int a[len]);


int main() 
{
    // 2 & 3
    int a[rows][cols] = {0};
    fillMatrix(a);  
    cout << "2 & 3)\nMatrix A:" << endl;
    printMatrix(a); 

    // 4
    transposeMatrix(a);
    cout << "4)\nTranspose of A (A^T):" << endl;
    printMatrix(a);

    // 5
    int b[rows][cols] = {0};
    fillMatrix(b);
    cout << "5) Iterative multiplication\nMatrix B:" << endl;
    printMatrix(b);
    int AxB[rows][cols] = {0};
    multiply(a, b, AxB);
    cout << "A^T x B:" << endl;
    printMatrix(AxB);

    // 6
    cout << "6) Recursive multiplication" << endl;
    int recAxB[rows][cols] = {0};
    recMultiply(a, b, recAxB);
    cout << "A^T x B:" << endl;
    printMatrix(recAxB);

    // 7
    cout << "7) Matrix operations with pointer notation" << endl;
    int array2d[rows][cols] = { { } };
    int* ptr[rows];    // array of 5 pointers
    for (int i = 0; i < rows; i++)
        ptr[i] = array2d[i];    // point ptr to inner array that is in the outer array array2d
    cout << "fillMatrix(int**), printMatrix(int**):" << endl;
    fillMatrix2(ptr);
    printMatrix2(ptr);
    cout << "transposeMatrix(int**):" << endl;
    transposeMatrix2(ptr);
    printMatrix2(ptr);

    // 8
    cout << "8) Using 1D array:" << endl;
    int array1d[len];
    fillMatrix(array1d);
    printMatrix(array1d);

    return 0;
}

/*
 * Answer 2
 * Fills input matrix with random integers
 */
void fillMatrix(int matrix[rows][cols])
{
    // Set the seed for rand()
    time_t t;
    srand((unsigned) time(&t));
    int i,j;

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            matrix[i][j] = rand() % 10;
}

/*
 * Answer 3
 * Prints each row of the input 2D-matrix line by line
 */
void printMatrix(int matrix[rows][cols])
{
    int i,j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            cout << matrix[i][j] << '\t';
        cout << endl;
    }
    cout << endl;
}

/*
 * Answer 4
 */
void transposeMatrix(int matrix[rows][cols])
{
    int temp, i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (i != j)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
            else break;
        }
    }
}

/**
 * Answer 5
 * @param a factor matrix 1
 * @param b factor matrix 2
 * @param c product matrix
 */
void multiply(int a[rows][cols], int b[rows][cols], int c[rows][cols])
{
    int i;  // counter for rows of C
    int j;  // counter for columns of C
    int k;  // counter for row of A and column of B that being used to calculate C[i][j]

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            c[i][j] = 0;

            for (k = 0; k < rows; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
}

/**
 * Answer 6
 */
void recMultiply(int a[rows][cols], int b[rows][cols], int c[rows][cols])
{
    static int i, j, k = 0;

    if (i >= rows) // if all rows are traversed
    {
        return;
    }
    else
    {
        if (j < cols)
        {
            if (k < cols)
            {
                c[i][j] += a[i][k] * b[k][j];
                k++;
                recMultiply(a, b, c);
            }
            k = 0;
            j++;
            recMultiply(a, b, c);
        }
        j = 0;
        i++;
        recMultiply(a,b,c);
    }
}

/*
 * Answer 7: Pointer notation
 */
void fillMatrix2(int** pp)
{
    time_t t;
    srand((unsigned) time(&t) + 1);
    int i,j;

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            *(*(pp+j)+i) = rand() % 10;
}
void printMatrix2(int** pp)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            cout << *(*(pp+j)+i) << '\t';
        cout << endl;
    }
    cout << endl;
}
void transposeMatrix2(int** pp)
{
    int temp, i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (i != j)
            {
                temp = *(*(pp+j)+i);
                *(*(pp+j)+i) = *(*(pp+i)+j);
                *(*(pp+i)+j) = temp;
            }
            else break;
        }
    }
}

/*
 * Answer 8:
 * As long as we know the dimensions, it is possible to 
 * implement a matrix using a 1-dimensional array instead of a
 * 2-dimensional one.
 */
void fillMatrix(int a[len])
{
    time_t t;
    srand((unsigned) time(&t) + 2);
    int i;

    for (i = 0; i < len; i++)
        a[i] = rand() % 10;
}

void printMatrix(int a[len])
{
    int i = 0, j = 0, k = 0;

    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            cout << a[k] << '\t';
            k++;
            j++;
        }
        i++;
        cout << endl;
    }
    cout << endl;
}
