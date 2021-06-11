#ifndef MATLIB_H_INCLUDED
#define MATLIB_H_INCLUDED

#include <vector>

using namespace std;

/**Class*//*
Used for member function definitions. Uses templates
*/
template<class T, int m, int n>  // Define template data type
class Matrix
{
    public:
        vector<vector<T>> mat_els; // elements holds matrix element values
        int n_row, n_col;   // Define number of rows & columns
        bool flag_pos, flag_mult;

        // Declare copy constructor & desctructor
        Matrix(vector<vector<T>> &); // Constructor
        ~Matrix();                   // Destructor

        // Declare print() function
        void print();

        // Declare Matrix Multiplication copy operator
        template<class T2, int m2, int n2,int m3, int n3>
        friend Matrix<T2, m2, l> operator*(const Matrix<T2, m2, n2> &, const Matrix<T2, m3, n3> &);

        // Declare Matrix Transpose copy function
        friend class Matrix<T, n4, m4>;
        Matrix<T, n4, m4> transpose();
};

/**CONSTRUCTOR*//*
- Description: Below builds contructor for the above class, which is used to initialize matrix.
               This is defined outside of the class.
- Input(s):
    1. 'mat' is the vector of vectors that defines all elements within the matrix.
    2. 'm' is the number of rows in matrix
    3. 'n' is the number of columns in matrix
- Output(s):
    1. Matrix object that holds matrix elements as vector of vectors
*/
template<class T, int m, int n> // Define template data type
// Create copy constructor for copying the reference values of vector<vector<T>> object 'mat' into new object.
Matrix<T, m, n>::Matrix(vector<vector<T>> &mat): n_row(m), n_col(n) // Initialize rows & columns (n_row & n_col) of class (Matrix).
{
    // Populate mat_els with vector elements while testing for errors
    try
    {
        // Quick Check: Are columns or rows negative? If so, throw error
        if(m <= 0 || n <= 0)
        {
            throw invalid_argument("Matrix row and/or column sizes < 1.");
        }

        // Populate mat_els with vector elements
        for(vector<T> i: mat) {
            mat_els.push_back(i);
        }
    }

    // If errors occures, display error
    catch (exception &e)
    {
        cout << "Error: " << e.what() << endl;
        flag_pos=false;
    }
}

/**DESTRUCTOR*/
template<class T, int m, int n>
Matrix<T, m, n>::~Matrix()
{
}

/**PRINT MATRIX*/
template<class T, int m, int n>
void Matrix<T, m, n>::print()
{
    flag_mult=true;
    for (int i = 0; i < n_row; i++)
    {
        for (int j = 0; j < n_col; j++)
        {
            cout << mat_els[i][j] << " ";
        }
        cout << endl;
    }
}


/**MATRIX MULTIPLICATION*//*
Multiplication function created as an operator
- Input(s):
    1. m1 is the object of a matrix that is to be multiplied of size 'm1 x n2'.
    2. m2 is the object of another matrix or size 'm2 x n2'.
- Output(s):
    1. m3 is the objext of a matrix of size 'm1 x n2', which is the result of m1 x m2.
- NOTES:
    1. Multiplication is done using the '*' operation. For example: m3 = m1 * m2;
*/
template<class T, int m1, int n1, int m2, int n2> // Define template data type
// Create copy operator '*' for copying the reference values of vector<vector<T>> objects 'mat1' & 'mat2' into calculating new object 'mat3'.
Matrix<T, m1, n2> operator*(const Matrix<T, m1, n1> &mat1, const Matrix<T, m2, n2> &mat2)
{
    try
    {

        // Verify matrices sizes are correct so they can be multiplied
        if(n1 != m2)
        {
            throw invalid_argument("Matrices cannot be multiplied due to mat1 columns not equalling mat2 rows.");
        }

        // Define size & temp holder for mat3 (output) matrix.
        int n_row = mat1.n_row; // mat3 rows
        int n_col = mat2.n_col; // mat3 columns
        vector<vector<T>> tmp_mat; // temp holder

        // Create tmp_mat matrix of size 'm1 x n2' that is filled with zeros
        for(int i = 0; i < m1; i++) // Loop through number of rows 'm1'
        {
            // Create vector 'mat3_i_els' for storing number of elements in row 'i' as a zeros
            vector<T> mat3_i_els; // Vector for holding zeros. End size will be of size 'n2'.
            for(int j = 0; j < n2; j++) // Loop through number of elements in row 'i'
            {
                mat3_i_els.push_back(0); // Add a zero to vector for each element in row 'i'
            }
            tmp_mat.push_back(mat3_i_els); // Add row of zeros to 'tmp_mat' until 'm1' rows of zeros exist in 'tmp_mat'.
        }

        // Perform matrix multiplication of mat1 x mat2 and store result in new matrix 'mat3'.
        Matrix<T, m1, n2> mat3(tmp_mat); // Define Matrix object for storing matrix 'mat3' using vector elements of 'tmp_mat'.
        for(int i = 0; i < n_row; ++i) // Loop through number of rows in mat3
        {
            for(int j = 0; j < n_col; ++j) // Loop through number of columns in mat3
            {
                mat3.mat_els[i][j] = 0; // Assign value '0' to initialize element [i][j] in mat3.


                for(int k = 0; k < mat1.n_col; k++) // Loop through columns of mat1, or rows of mat2.
                {
                    T temp = mat1.mat_els[i][k] * mat2.mat_els[k][j]; // Multiply mat1 & mat2 elements
                    mat3.mat_els[i][j] = temp + mat3.mat_els[i][j];  // Sum multiplied elements and assign to mat3[i][j] element
                }
            }
        }
        return mat3;
    }

    // If errors occures, display error
    catch(exception &e)
    {
        cout << "Error: " << e.what() << endl;

        vector<vector<T>> tmp_mat = { }; // temp holder
        Matrix<T, m1, n2> mat3(tmp_mat);
        mat3.flag_mult=false;
        return mat3;
    }
}

/**Transpose*//*
Function transposes matrix object
- Input(s):
    1. None
- Output(s):
    1. m4 is the objext of a matrix of size 'n x m', which is the transpose of m1 (size 'm x n').
- NOTES:
    1. Tranpose is done using the tranpose function. For example: m4 = m1.transpose();
*/
template<class T, int m, int n>
Matrix<T, n, m> Matrix<T, m, n>::transpose() // Define transpose function.
{

    // Define temp holder for m4 (output) matrix.
    vector<vector<T>> tmp_mat; // temp holder

    // Create tmp_mat matrix of size 'n x m' that is filled with zeros
    for(int i = 0; i < n; i++) // Loop through number of columns 'n'
    {
        // Create vector 'm4_i_els' for storing number of elements in m1 column 'i' as a zeros
        vector<T> m4_i_els; // Vector for holding zeros. End size will be of size 'm'.
        for(int j = 0; j < m; j++) // Loop through number of elements in column 'i'
        {
            m4_i_els.push_back(0); // Add a zero to vector for each element in column 'i'
        }
        tmp_mat.push_back(m4_i_els); // Add vector of zeros to 'tmp_mat' until 'n' rows of zeros exist in 'tmp_mat'.
    }

    // Perform Transpose of matrix m1
    Matrix<T, n, m> m4(tmp_mat); // Define Matrix object for storing matrix 'm4' using vector elements of 'tmp_mat'.
    for (int i = 0; i < n_row; ++i) // loop through rows of m1
    {
        for (int j = 0; j < n_col; ++j) // loop through columns of m1
        {
            m4.mat_els[j][i] = mat_els[i][j]; // Assign m1[i][j] to m4[j][i]
        }
    }
    return m4;
}

#endif // MATLIB_H_INCLUDED
