//
// Created by shaul on 03/04/2022.
//

#include "Matrix.hpp"

using namespace std;
namespace zich {

    Matrix::Matrix(std::vector<double> arr, int rows, int cols) {
        if (rows < 0 || cols < 0) {
            throw std::invalid_argument("Please enter only non negative integers");
        }
        if (rows * cols != arr.size()) {
            throw std::invalid_argument("The size you inputted is incorrect");
        }
        for (size_t i = 0; i < rows; ++i) {
            matrix.push_back(std::vector<double>());
            for (size_t j = 0; j < cols; ++j) {
                size_t index = i * static_cast<unsigned long>(cols) + j;
                matrix.at(i).push_back(arr.at(index));
            }
        }
    }

    /**
     * Unary minus operation on this matrix
     * @return a copy of this matrix with - for each entry
     */
    Matrix Matrix::operator-() {
        std::vector<double> arr;
        for (size_t i = 0; i < this->row() * this->cols(); ++i) {
            if (this->matrix[i / cols()][i % cols()] != 0) {
                arr.push_back(-this->matrix[i / cols()][i % cols()]);
            } else {
                arr.push_back(0);
            }
        }
        return Matrix(arr, this->row(), this->cols());
    }

    /**
    * Unary plus operation on this matrix
    * @return a copy of this matrix
    */
    Matrix Matrix::operator+() {
        std::vector<double> arr;
        for (size_t i = 0; i < this->row() * this->cols(); ++i) {
            arr.push_back(this->matrix[i / cols()][i % cols()]);
        }
        return Matrix(arr, this->row(), this->cols());
    }

    /**
     *
     * @param other matrix which we add each entry to our matrix
     * @return A copy of our matrix added with the other matrix
     */
    Matrix Matrix::operator+(Matrix &other) const {
        if (other.row() != this->row() || other.cols() != this->cols()) { // check that row() and cols() works
            throw invalid_argument("Both matrices need to be the same size");
        }
        std::vector<double> arr;
        for (size_t i = 0; i < other.row() * other.cols(); ++i) {
            arr.push_back(other.matrix[i / cols()][i % cols()] + this->matrix[i / cols()][i % cols()]);
        }
        return Matrix(arr, this->row(), this->cols());
    }

    /**
     *
     * @param other matrix which we subtract each entry from our matrix
     * @return A copy of our other matrix subtracted from our matrix
     */
    Matrix Matrix::operator-(Matrix &other) const {
        if (other.row() != this->row() || other.cols() != this->cols()) { // check that row() and cols() works
            throw invalid_argument("Both matrices need to be the same size");
        }
        std::vector<double> arr;
        for (size_t i = 0; i < other.row() * other.cols(); ++i) {
            arr.push_back(this->matrix[i / cols()][i % cols()] - other.matrix[i / cols()][i % cols()]);
        }
        return Matrix(arr, this->row(), this->cols());
    }

    /**
     * Notice we are working with the reference of our matrix
     * @param other matrix which we add each entry to our matrix
     * @return Our matrix added with the other matrix
     */
    Matrix &Matrix::operator+=(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        for (size_t i = 0; i < row(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                this->matrix[i][j] += other.matrix[i][j];
            }
        }
        return *this;
    }

    /**
    * Notice we are working with the reference of our matrix
     * @param other matrix which we add subtract from each entry of our matrix
    * @return Our matrix minus the other matrix
    */
    Matrix &Matrix::operator-=(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        for (size_t i = 0; i < row(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                this->matrix[i][j] -= other.matrix[i][j];
            }
        }
        return *this;
    }

    /**
     * Multiplying a scalar and ^this^ matrix
     * @param scalar  which we are using for the multiplication
     * @return a new matrix which is the product of scalar*this
     */
    Matrix Matrix::operator*(double scalar) const {
        std::vector<double> arr;
        for (size_t i = 0; i < this->row() * this->cols(); ++i) {
            arr.push_back(this->matrix[i / this->cols()][i % this->cols()] * scalar);
        }
        return Matrix(arr, this->row(), this->cols());
    }

    /**
    * Changing each entry in this matrix by Multiplying it by a scalar
    * @param scalar  which we are using for the multiplication
    * @return this matrix which is the product of scalar*this
    */
    Matrix &Matrix::operator*=(double scalar) {
        for (size_t i = 0; i < row(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                this->matrix[i][j] *= scalar;
            }
        }
        return *this;
    }

    /**
     * Simply checking if each entry in other matrix is similar then ours
     * @param other matrix for which we test if our matrix equals it
     * @return true if they are identical false otherwise
     */
    bool operator==(const Matrix &matrix1, const Matrix &matrix2) {
        if (matrix2.row() != matrix1.row() || matrix2.cols() != matrix1.cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        for (size_t i = 0; i < matrix1.row(); ++i) {
            for (size_t j = 0; j < matrix1.cols(); ++j) {
                if (matrix1.matrix[i][j] != matrix2.matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    /**
    * Simply checking if one single entry in other matrix is different then ours
    * @param other matrix for which we test if our matrix doesn't equal it
    * @return false if they are identical true otherwise
    */
    bool Matrix::operator!=(Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        for (size_t i = 0; i < row(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                if (this->matrix[i][j] != other.matrix[i][j]) {
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * Checking if this matrix is greater then other matrix
     * @param other matrix for which we test if this matrix is greater then it
     * @return true if sum of this matrix is greater then sum of other matrix false otherwise
     */
    bool Matrix::operator>(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        double sum_me = 0;
        double sum_other = 0;
        for (size_t i = 0; i < row(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                sum_me += this->matrix[i][j];
                sum_other += other.matrix[i][j];
            }
        }
        return sum_me > sum_other;
    }

    /**
 * Checking if this matrix is smaller then other matrix
 * @param other matrix for which we test if this matrix is smaller then it
 * @return true if sum of this matrix is smaller then sum of other matrix false otherwise
 */
    bool Matrix::operator<(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        double sum_me = 0;
        double sum_other = 0;
        for (size_t i = 0; i < row(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                sum_me += this->matrix[i][j];
                sum_other += other.matrix[i][j];
            }
        }
        return sum_me < sum_other;
    }

    /**
 * Checking if this matrix is greater or equal to other matrix
 * @param other matrix for which we test if this matrix is greater or equal to it
 * @return true if sum of this matrix is greater or equal then the sum of other matrix false otherwise
 */
    bool Matrix::operator>=(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        double sum_me = 0;
        double sum_other = 0;
        for (size_t i = 0; i < row(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                sum_me += this->matrix[i][j];
                sum_other += other.matrix[i][j];
            }
        }
        return sum_me >= sum_other;
    }

    /**
    * Checking if this matrix is smaller or equal to other matrix
    * @param other matrix for which we test if this matrix is smaller or equal to it
    * @return true if sum of this matrix is smaller or equal then the sum of other matrix false otherwise
    */
    bool Matrix::operator<=(const Matrix &other) {
        if (other.row() != this->row() || other.cols() != this->cols()) {
            throw invalid_argument("Both matrices need to be the same size");
        }
        double sum_me = 0;
        double sum_other = 0;
        for (size_t i = 0; i < row(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                sum_me += this->matrix[i][j];
                sum_other += other.matrix[i][j];
            }
        }
        return sum_me <= sum_other;
    }

    /**
     * Adding 1 to each entry in this matrix prefix.
     * @return this matrix with each entry incremented by 1
     */
    Matrix &Matrix::operator++() {
        for (size_t i = 0; i < row(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                this->matrix[i][j]++;
            }
        }
        return *this;
    }

    /**
    * Subtracting 1 to each entry in this matrix postfix.
    * @return this matrix with each entry decremented by 1
    */
    Matrix Matrix::operator++(int we_are_postfixing) {
        Matrix a {*this};
        ++*this;
        return a;
    }

    /**
 * Subtracting 1 to each entry in this matrix prefix.
 * @return this matrix with each entry decremented by 1
 */
    Matrix &Matrix::operator--() {
        for (size_t i = 0; i < row(); ++i) {
            for (size_t j = 0; j < cols(); ++j) {
                this->matrix[i][j]--;
            }
        }
        return *this;
    }

    /**
    * Subtracting 1 to each entry in this matrix postfix.
    * @return this matrix with each entry decremented by 1
    */
    Matrix  Matrix::operator--(int we_are_postfixing) {
        Matrix a {*this};
        --*this;
        return a;
    }

    /**
     * Multiplying a scalar and a matrix
     * @param m the matrix which we are using for the multiplication
     * @param scalar  which we are using for the multiplication
     * @return a new matrix which is the product of scalar*m
     */
    Matrix operator*(double scalar, const Matrix &m) {
        std::vector<double> arr;
        for (size_t i = 0; i < m.row() * m.cols(); ++i) {
            arr.push_back(m.matrix[i / m.cols()][i % m.cols()] * scalar);
        }
        return Matrix(arr, m.row(), m.cols());
    }
    /***
     * Matrix Multiplication
     * @param m1 - left matrix for multiplying
     * @param m2 - right matrix for multiplying
     * @return The matrix which is the product of the multiplication
     */
    Matrix operator*(const Matrix &m1, const Matrix &m2) {
        if (m1.cols() != m2.row()) {
            throw invalid_argument("Sized not eligible for matrix multiplication");
        }
        std::vector<double> arr(m1.row() * m2.cols());
        for (size_t i = 0; i < m1.row(); ++i) {//for the new matrix
            for (size_t j = 0; j < m2.cols(); ++j) {
                for (size_t k = 0; k < m1.cols(); ++k) {
                    arr[m2.cols() * i + j] += m1.matrix[i][k] * m2.matrix[k][j];
                }
            }
        }
        return Matrix(arr, m1.row(), m2.cols());
    }
    /***
     * Matrix Multiplication for this matrix
    * @param m2 - right matrix for multiplying
    * @return The matrix which is the product of the multiplication
    */
    Matrix &Matrix:: operator*=(const Matrix &m2) {
        *this = *this*m2;
        return *this;
    }
    /**
     * My "Printing" matrix override
     * @param output ostream we work on
     * @param m A reference to the matrix we want to print
     * @return The string(ostream) of matrix visualized nicely
     */
    std::ostream &operator<<(ostream &output, const Matrix &m) {
        for (size_t i = 0; i < m.row(); ++i) {
            for (size_t j = 0; j < m.cols(); ++j) {
                if (j == 0) {
                    output << '[';
                }
                if (j != m.cols() - 1) {
                    output << m.matrix[i][j] << ' ';
                } else if(i!=m.row()-1){
                    output << m.matrix[i][j] << "]\n";
                }
                else{
                    output << m.matrix[i][j]<< "]";
                }
            }
        }
        return output;
    }


    //"[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"
    std::istream &operator>>(istream &input, Matrix &m) {
        bool flag = false;
        vector<double> arr;
        string read_number;
        string read_input;
        int first_row_counter_len=1;
        int col_counter = 1;
        int row_counter =1;
        char c = input.get();
        while(c!='\n'){
            if(c==' '){
                arr.push_back(stod(read_number));
                read_number = "";
                col_counter++;
            }
            else if(c==','){
                row_counter++;
                if(!flag) {
                    flag= true;
                    first_row_counter_len = col_counter;
                }
                else if(col_counter!=first_row_counter_len && flag){
                    throw invalid_argument("Bad input");
                }
                col_counter=0;
            }
            if(c!=']'){
                if(c!='[') {
                    read_number +=c;
                }
            }
            read_input+=c;
            c= input.get();
        }
        arr.push_back(stod(read_number));
        //iterate over what we read and make sure to throw error when needed
        for (size_t i = 0; i <read_input.size() ; ++i) {
            if (i==0 && read_input[i]!='['){
                throw invalid_argument("Bad input");
            }
            if(i!=0 &&read_input.at(i)=='['){
                if(read_input.at(i-1)!=' ' || read_input.at(i-2)!=','){
                    throw invalid_argument("Bad input");
                }
            }
        }
        m =  Matrix(arr, row_counter, first_row_counter_len);
        return input;
    }




}