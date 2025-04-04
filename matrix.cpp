#include "matrix.hpp"
#include <stdexcept>
#include <iostream>
// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:

Matrix::Matrix(size_t N) {
    // initialize an empty NxN matrix
    for (int i = 0; i < N; i++)
    {
        std::vector<int> tempVector;
        for (int j = 0; j < N; j++)
        {
            // append 0 to each section of an array within an array
            tempVector.push_back(0);
        }

        this->nums.push_back(tempVector);
    }
}

Matrix::Matrix(std::vector<std::vector<int>> values)
{
    int N = values.size();
    for (int i = 0; i < N; i++)
    {
        std::vector<int> tempVector;
        for (int j = 0; j < N; j++)
        {
            tempVector.push_back(values[i][j]);
        }
        this->nums.push_back(tempVector);
    }
}

Matrix Matrix::operator+(const Matrix &rhs) const
{
    int N = this->nums.size();
    Matrix result(N);
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            result.nums[i][j] = nums[i][j] + rhs.nums[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator*(const Matrix &rhs) const
{
    int N = this->nums.size();
    Matrix result(N);
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                result.nums[i][j] += nums[i][k] * rhs.nums[k][j];
            }
        }
    }
    return result;
}
void Matrix::set_value(std::size_t i, std::size_t j, int n)
{
    if (i >= this->nums.size() || j >= nums[i].size())
    {
        throw std::out_of_range("Out of range.");
    }
    this->nums[i][j] = n;
}
int Matrix::get_value(std::size_t i, std::size_t j) const
{
    if (i >= nums.size() || j >= nums[i].size())
    {
        throw std::out_of_range("Out of range");
    }
    return this->nums[i][j];
}
int Matrix::get_size() const
{
    return this->nums.size();
}
int Matrix::sum_diagonal_major() const
{
    int sum = 0;
    for (int i = 0; i < this->nums.size(); i++)
    {
        sum += nums[i][i];
    }
    return sum;
}
int Matrix::sum_diagonal_minor() const
{
    int sum = 0;
    for (int i = 0; i < this->nums.size(); i++)
    {
        sum += nums[i][this->nums.size() - i -1];
    }
    return sum;
}
void Matrix::swap_rows(std::size_t r1, std::size_t r2)
{
    std::vector<int> tmp;
    tmp = this->nums[r1];
    this->nums[r1] = this->nums[r2];
    this->nums[r2] = tmp;
}
void Matrix::swap_cols(std::size_t c1, std::size_t c2)
{
    // iterate through all rows and swap item at column section
    for (int i = 0; i < this->nums.size(); i++)
    {
        int tmp = this->nums[i][c1];
        this->nums[i][c1] = this->nums[i][c2];
        this->nums[i][c2] = tmp;
    }
}
// e.g. for a member function:

void Matrix::print_matrix() const {
    // print out the matrix
    int N = nums.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << nums[i][j] << " ";
        }
        std::cout << std:: endl;
    }
}
