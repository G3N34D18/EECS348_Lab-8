#include "matrix.hpp"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:

Matrix::Matrix(size_t N) {
    // initialize an empty NxN matrix
    // for loop to interate through N values 
    for (int i = 0; i < N; i++)
    {   
        // empty vector called temp vector
        std::vector<int> tempVector;
        // foor loop to iterate through N values
        for (int j = 0; j < N; j++)
        {
            // append 0 to each section of an array within an array
            tempVector.push_back(0);
        }
        // pushes tempVector into storage array for matrix
        this->nums.push_back(tempVector);
    }
}

Matrix::Matrix(std::vector<std::vector<int>> values)
{   
    // initializes N to size of values which is size of one side of matrix
    int N = values.size();
    // iterates through size of matrix
    for (int i = 0; i < N; i++)
    {
        // temp vector created
        std::vector<int> tempVector;
        // iterates through other side of vector
        for (int j = 0; j < N; j++)
        {
            // pushes values to tempVector
            tempVector.push_back(values[i][j]);
        }
        // pushes vector to storage of Matrix class
        this->nums.push_back(tempVector);
    }
}

Matrix Matrix::operator+(const Matrix &rhs) const
{
    // initializes N to size of matrix
    int N = this->nums.size();
    // makes new empty result matrix
    Matrix result(N);
    // iterates through rows of matrix
    for (int i = 0; i < N; i++)
    {
        // iterates through items in rows
        for(int j = 0; j < N; j++)
        {
            // appends addition of each matrix to result matrix
            result.nums[i][j] = nums[i][j] + rhs.nums[i][j];
        }
    }
    // returns result matrix
    return result;
}
Matrix Matrix::operator*(const Matrix &rhs) const
{
    // initializes N to size of matrix
    int N = this->nums.size();
    // empty matrix of N size
    Matrix result(N);
    // iterates through rows
    for (int i = 0; i < N; i++)
    {
        // iterates through items of rows
        for (int j = 0; j < N; j++)
        {
            // additional iteration for correct application of matrix multiplication
            for (int k = 0; k < N; k++)
            {   
                // result matrix at each index is equal to sum of multiplication of row by column
                result.nums[i][j] += nums[i][k] * rhs.nums[k][j];
            }
        }
    }
    // return result matrix
    return result;
}
void Matrix::set_value(std::size_t i, std::size_t j, int n)
{   
    // error handling for if index out of range
    if (i >= this->nums.size() || j >= nums[i].size())
    {
        // throw out of range
        throw std::out_of_range("Out of range.");
    }
    // sets value at index
    this->nums[i][j] = n;
}
int Matrix::get_value(std::size_t i, std::size_t j) const
{
    // error handling for if inded out of range
    if (i >= nums.size() || j >= nums[i].size())
    {
        // throw out of range error
        throw std::out_of_range("Out of range");
    }
    // returns item at index
    return this->nums[i][j];
}
int Matrix::get_size() const
{
    // returns size of matrix (if 4 x 4 will return 4)
    return this->nums.size();
}
int Matrix::sum_diagonal_major() const
{
    // initialized sum to 0
    int sum = 0;
    // iteraties through rows
    for (int i = 0; i < this->nums.size(); i++)
    {
        // only adds values at diagonal (0,0; 1,1 etc)
        sum += nums[i][i];
    }
    // returns sum
    return sum;
}
int Matrix::sum_diagonal_minor() const
{
    // initializes sum to 0
    int sum = 0;
    // iterates through rows
    for (int i = 0; i < this->nums.size(); i++)
    {
        // adds values going from right to left
        sum += nums[i][this->nums.size() - i - 1];
    }
    // returns sum
    return sum;
}
void Matrix::swap_rows(std::size_t r1, std::size_t r2)
{
    // initializes vector as tmp
    std::vector<int> tmp;
    // sets tmp to r1
    tmp = this->nums[r1];
    // sets r1 to vector at r2
    this->nums[r1] = this->nums[r2];
    // sets r2 at tmp vector which is r1 original value
    this->nums[r2] = tmp;
}
void Matrix::swap_cols(std::size_t c1, std::size_t c2)
{
    // iterate through all rows and swap item at column section
    for (int i = 0; i < this->nums.size(); i++)
    {
        // sets tmp as value of first column in first row
        int tmp = this->nums[i][c1];
        // sets first column value to value at second column
        this->nums[i][c1] = this->nums[i][c2];
        // sets second colum value to value at first column being stored at tmp
        this->nums[i][c2] = tmp;
    }
}
// e.g. for a member function:

void Matrix::print_matrix() const {
    // print out the matrix
    // sets N as size of matrix
    int N = nums.size();
    // iterates through rows of matrix
    for (int i = 0; i < N; i++)
    {
        // iterates through items in rows
        for (int j = 0; j < N; j++)
        {
            // prints values in each row with a space separation
            std::cout << nums[i][j] << " ";
        }
        // prints newline after row end
        std::cout << std:: endl;
    }
}

void Matrix::load_matrices(const std::string& filename)
{
    // opens file
    std::ifstream file(filename);
    // error checking to make sure file opens correctly
    if (!file)
    {
        // throws error if file opens incorrectly
        throw std::runtime_error("Could not open file.");
    }
    // int value N initialized
    int N;
    // first value in file set to N
    file >> N;
    // initializes empty matricies m1 and m2
    Matrix m1(N);
    Matrix m2(N);
    // iterates through rows in matrix
    for (int i = 0; i < N; i++)
    {
        // iterates through items in rows
        for (int j = 0; j < N; j++)
        {
            // initializes num to integer
            int num;
            // takes each value from file 
            file >> num;
            // sets value to matrix position
            m1.set_value(i, j, num);
        }
    }
    // does same as above code but for second matrix
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            file >> num;
            m2.set_value(i, j, num);
        }
    }
// closes file
file.close();
}