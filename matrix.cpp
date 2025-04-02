#include "matrix.hpp"

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

        this.nums.push_back(tempVector);
    }
}

Matrix operator+(const Matrix &rhs) const
{

}
Matrix operator*(const Matrix &rhs) const
{

}
void set_value(std::size_t i, std::size_t j, int n)
{
    if (i >= nums.size() || j >= nums[i].size())
    {
        throw std::out_of_range("Out of range.");
    }
    this->nums[i][j] = n;
}
int get_value(std::size_t i, std::size_t j) const
{
    if (i >= nums.size() || j >= nums[i].size())
    {
        throw std::out_of_range("Out of range");
    }
    return this->nums[i][j];
}
int get_size() const
{
    return nums.size()
}
int sum_diagonal_major() const
{

}
int sum_diagonal_minor() const
{

}
void swap_rows(std::size_t r1, std::size_t r2)
{
    std::vector<int> tmp;
    tmp = nums[r1];
    nums[r1] = nums[r2];
    nums[r2] = tmp;
}
void swap_cols(std::size_t c1, std::size_t c2)
{
    // iterate through all rows and swap item at column section
}
// e.g. for a member function:

void Matrix::print_matrix() const {
    // print out the matrix
    // print items in order with spaces until switching rows, print newline
}
