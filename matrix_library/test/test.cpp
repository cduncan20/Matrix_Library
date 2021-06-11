#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "../include/matlib.h"

using namespace std;

/**TEST 1 - DEFINE MATRIX: Positive Row/Column Quantity*//*
This test verifies that if the user enters a row or column quantity for
a matrix and the quantity is less than 1, then the variable 'flag_pos' becomes
false and an error is output in the terminal.
*/
bool test_pos_row_col()
{
  vector<vector<int>> mat = {{{6, 5, 4}, {3, 2, 1}}};    // Test vector matrix (mat)
  Matrix<int, -2, 3> m(mat); // Test Matrix object (m)
  return m.flag_pos;
}

/**TEST 2 - MULTIPLICATION: Correct Row/Column Quantity*//*
This test verifies that when two matrices are being multiplied, they have the correct
quantity of rows & columns to be multiplied by one another. If they don't then the variable
'flag_mult' becomes false and an error is output.
*/
bool test_mult_row_col_qty()
{
  vector<vector<int>> mat1 = {{{6, 5, 4}, {3, 2, 1}}};    // Test vector matrix 1 (mat1)
  vector<vector<int>> mat2 = {{{1, 2}, {3, 4}, {5, 6}}};  // Test vector matrix 2 (mat2)
  vector<vector<int>> mat3 = { }; // Result vector matrix (mat3)
  Matrix<int, 2, 2> m1(mat1); // Test Matrix object 1 (m1)
  Matrix<int, 3, 2> m2(mat2); // Test Matrix object 2 (m2)
  Matrix<int, 2, 2> m3(mat3); // Result Matrix object (m3)
  m3 = m1 * m2; // Matrix multiplication
  return m3.flag_mult;
}

/**TEST 3 - MULTIPLICATION: Result has correct size*//*
This test verifies that the multiplication operator '*' outputs a matrix
of the correct size. For example, if matrix m1 is of size m x n and 
m2 is of size a x b, then the resulting matrix m3 should be of 
size m x b. If correct, the bool value 'true' is returned.
*/
int test_mult_size()
{
  // Define test matrices
  vector<vector<int>> mat1 = {{{6, 5, 4}, {3, 2, 1}}};    // Test vector matrix 1 (mat1)
  vector<vector<int>> mat2 = {{{1, 2}, {3, 4}, {5, 6}}};  // Test vector matrix 2 (mat2)
  vector<vector<int>> mat3 = { }; // Result vector matrix (mat3)
  Matrix<int, 2, 3> m1(mat1); // Test Matrix object 1 (m1)
  Matrix<int, 3, 2> m2(mat2); // Test Matrix object 2 (m2)
  Matrix<int, 2, 2> m3(mat3); // Result Matrix object (m3)
  m3 = m1 * m2; // Matrix multiplication

  // Check to see if m3 row qty is equal to m1 row qty and m3 column qty is equal to m2 column qty.
  if(m3.n_row == m1.n_row && m3.n_col == m2.n_col)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/**TEST 4 - MULTIPLICATION: Result has correct elements values*//*
This test verifies that the multiplication operator '*' executes and
outputs a matrix with the correct values for each element.
*/
bool test_mult_result()
{
  // Define test matrices
  vector<vector<int>> mat1 = {{{6, 5, 4}, {3, 2, 1}}};    // Test vector matrix 1 (mat1)
  vector<vector<int>> mat2 = {{{1, 2}, {3, 4}, {5, 6}}};  // Test vector matrix 2 (mat2)
  vector<vector<int>> mat3 = { }; // Result vector matrix (mat3)
  vector<vector<int>> mat4 = {{{41, 56}, {14, 20}}}; // Correct result vector matrix (mat4)
  Matrix<int, 2, 3> m1(mat1); // Test Matrix object 1 (m1)
  Matrix<int, 3, 2> m2(mat2); // Test Matrix object 2 (m2)
  Matrix<int, 2, 2> m3(mat3); // Result Matrix object (m3)
  Matrix<int, 2, 2> m4(mat4); // Correct result Matrix object (mat4)
  m3 = m1 * m2; // Matrix multiplication

  // Verify that all values for elements in m3 are equal to all values for elements in m4.
  bool flag_cor_els = true;  // Flag for checking of correct. Return true if correct.
  for(int i=0; i<m3.n_row; i++)  // Loop though m3 rows
  {
      for(int j=0; j<m3.n_col; j++)  // Loop though m3 columns
      {
          if(m3.mat_els[i][j] != m4.mat_els[i][j])  // Element value check
          {
            flag_cor_els = false;  // Flag false if single value is incorrect
          }
      }
  }
  return flag_cor_els;
}

/**TEST 5 - TRANSPOSE: Result has correct size*//*
This test verifies when a matrix is transposed, the output matrix is of the 
correct size. For example, if matrix mat1 is of size m x n and it is 
transposed to become matrix m3, then the resulting matrix m3 should be of 
size n x m. If correct, the bool value 'true' is returned.
*/
int test_trans_size()
{
  // Define test matrices
  vector<vector<int>> mat1 = {{{6, 5, 4}, {3, 2, 1}}};    // Test vector matrix 1 (mat1)
  vector<vector<int>> mat3 = { }; // Result vector matrix (mat3)
  Matrix<int, 2, 3> m1(mat1); // Test Matrix object 1 (m1)
  Matrix<int, 3, 2> m3(mat3); // Result Matrix object (m3)
  m3 = m1.transpose();

  // Check to see if m3 row qty is equal to m1 column qty and m3 column qty is 
  // equal to m1 row qty.
  if(m3.n_row == m1.n_col && m3.n_col == m1.n_row)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/**TEST 6 - TRANSPOSE: Result has correct elements values*//*
This test verifies when transposing a matrix, the output matrix has the correct 
values for each element.
*/
bool test_trans_result()
{
  // Define test matrices
  vector<vector<int>> mat1 = {{{6, 5, 4}, {3, 2, 1}}};    // Test vector matrix 1 (mat1)
  vector<vector<int>> mat3 = { }; // Result vector matrix (mat3)
  vector<vector<int>> mat4 = {{{6, 3}, {5, 2}, {4, 1}}}; // Correct result vector matrix (mat4)
  Matrix<int, 2, 3> m1(mat1); // Test Matrix object 1 (m1)
  Matrix<int, 3, 2> m3(mat3); // Result Matrix object (m3)
  Matrix<int, 3, 2> m4(mat4); // Correct result Matrix object (mat4)
  m3 = m1.transpose();

  // Verify that all values for elements in m3 are equal to all values for elements in m4.
  bool flag_cor_els = true;  // Flag for checking of correct. Return true if correct.
  for(int i=0; i<m3.n_row; i++)  // Loop though m3 rows
  {
      for(int j=0; j<m3.n_col; j++)  // Loop though m3 columns
      {
          if(m3.mat_els[i][j] != m4.mat_els[i][j])  // Element value check
          {
            flag_cor_els = false;  // Flag false if single value is incorrect
          }
      }
  }
  return flag_cor_els;
}

/**TEST 1 - DEFINE MATRIX: Positive Row/Column Quantity*/
// Test verifies that if the user enters a non-positive row or column quantity for
// a matrix, then an error is output.
TEST(Matrix_Library_Test, positive_row_col) 
{
  EXPECT_EQ(test_pos_row_col(), false);
}

/**TEST 2 - MULTIPLICATION: Correct Row/Column Quantity*/
// Test verifies that when two matrices are being multiplied, they have the 
// correct number of rows & columns.
TEST(Matrix_Library_Test, multiplication_row_col_qty)
{
  EXPECT_EQ(test_mult_row_col_qty(), false);
}

/**TEST 3 - MULTIPLICATION: Result has correct size*/
// Test to see if resulting multiplied matrix is of the correct size.
TEST(Matrix_Library_Test, multiplication_result_size)
{
  EXPECT_EQ(test_mult_size(), true);
}

/**TEST 4 - MULTIPLICATION: Result has correct elements values*/
// Test to see the resulting multiplied matrix element values are correct.
TEST(Matrix_Library_Test, multiplication_result_elements)
{
  EXPECT_EQ(test_mult_result(), true);
}

/**TEST 5 - TRANSPOSE: Result has correct size*/
// Test verifies that when matrix is transposed, it's size is correct.
TEST(Matrix_Library_Test, transpose_result_size)
{
  EXPECT_EQ(test_trans_size(), true);
}

/**TEST 6 - TRANSPOSE: Result has correct elements values*/
// Test to see the resulting transposed matrix element values are correct.
TEST(Matrix_Library_Test, transpose_result_elements)
{
  EXPECT_EQ(test_trans_result(), true);
}