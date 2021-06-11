#include <iostream>
#include <vector>
#include "matlib.h"

using namespace std;

int main()
{
    /**DEFINE MATRICES*//*
    Define each matrix as a vector<vector<class>> to a variable (matrix_vector_name). The
    user can use the following class types:
        - 'int'
        - 'float'
        - 'double'
    All interacting matrices (multiplied or transposed) must be the same class. To change
    class type, change each 'int' class to any of the classes listed above.This must be done
    both in the 'DEFINE MATRICES' section and the 'CREATE MATRIX OBJECTS' section. When
    multiplying or transposing matrices, define the resulting matrix as an vector<vector<class>>
    as seen for 'mat3' and 'mat4' below.
    */
    vector<vector<int>> mat1 = {{{6, 5, 4}, {3, 2, 1}}};
    vector<vector<int>> mat2 = {{{1, 2}, {3, 4}, {5, 6}}};
    vector<vector<int>> mat3 = { };
    vector<vector<int>> mat4 = { };

    /**CREATE MATRIX OBJECT*//*
    Create a Matrix object for each of the matrices defined above. Each Matrix object will be
    assigned to a variable (matrix_object_name). The data type should be defined as follows:
        Matrix<class, row_quantity, column_quantity> matrix_object_name(matrix_vector_name);
    Ensure that the class, row_quantity, & column_quantity all match how the matrix_vector_name
    variables are defined above in the 'DEFINE MATRICES' section.
    */
    Matrix<int, 2, 3> m1(mat1);
    Matrix<int, 3, 2> m2(mat2);
    Matrix<int, 2, 2> m3(mat3);
    Matrix<int, 3, 2> m4(mat4);

    /**PRINT MATRICES*//*
    Matrix objects can be printed to the terminal by using the following syntax:
        matrix_object_name.print();
    */
    cout << "m1 = " << endl;
    m1.print();
    cout << endl;
    cout << "m2 = " << endl;
    m2.print();
    cout << endl;

    /**MATRIX MULTIPLICATION*//*
    The user can mutliply two matrix objects by using the '*' operator. For example,
    multiplying matrix object 'm1' by matrix object 'm2' and assigning the resulting
    value to matrix object 'm3' can be done by using the following syntax:
        m3 = m1 * m2;
    */
    m3 = m1 * m2;
    cout << "m3 = m1 x m2 = " << endl;
    m3.print();
    cout << endl;

    /**TRANSPOSE MATRIX*//*
    Matrix objects can be transposed by using the following syntax:
        matrix_object_name.transpose();
    */
    cout << "tanspose(m1) = " << endl;
    m4 = m1.transpose();
    m4.print();
    cout << endl;

}
