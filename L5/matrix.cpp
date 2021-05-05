#include "matrix.h"

#include <iostream>

using namespace std;

Matrix::Matrix(int rows, int columns) {
    numRows = rows;
    numColumns = columns;
    contents = new float*[numRows];
    for (int i = 0; i < numRows; i++){
        contents[i] = new float[numColumns];
        for (int j = 0; j < numColumns; j++) {
            contents[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &matrix){
    numRows = matrix.numRows;
    numColumns = matrix.numColumns;
    contents = new float * [numRows];
    for (int i = 0; i < numRows; i++){
        contents[i] = new float[numColumns];
        for (int j = 0; j < numColumns; j++) {
            contents[i][j] = matrix.contents[i][j];
        }
    }
}

Matrix::Matrix(){
    numRows = 1;
    numColumns = 1;
    contents = new float*[numRows];
    for (int i = 0; i < numRows; i++){
        contents[i] = new float[numColumns];
        for (int j = 0; j < numColumns; j++) {
            contents[i][j] = 0;
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < numRows; i++){
        delete [] contents[i];
    }
    delete [] contents;
}


void Matrix::fill(const float *data, int dataSize){
    int i = 0;
    int j = 0;
    for (i = 0; i < this->numRows; i++) {

        for (j = 0; j < this->numColumns; j++) {
            if (i * this -> numRows + j >= dataSize) break;
            contents[i][j] = data[i*this->numRows + j];
        }
        if (i * this -> numRows + j >= dataSize) break;
    }
}

Matrix &Matrix::operator=(const Matrix &right) {
    if (this == &right){
        return *this;
    }
    for(int i = 0; i < this->numRows; i++){
        delete [] contents[i];
    }
    delete [] contents;
    this->numRows = right.numRows;
    this->numColumns = right.numColumns;
    contents = new float*[this->numRows];
    for (int i = 0; i < this->numRows; i++){
        contents[i] = new float[this->numColumns];
        for (int j = 0; j < this->numColumns; j++){
            contents[i][j] = right.contents[i][j];
        }
    }
    return *this;
}

Matrix operator*(const Matrix &Matrix1, const Matrix &Matrix2) {
    Matrix res(Matrix1.numRows, Matrix2.numColumns);
    for (int row = 0; row < Matrix1.numRows; row++){
        for (int col = 0; col < Matrix2.numColumns; col++){
            for (int item = 0; item < Matrix1.numColumns; item++){
                res.contents[row][col] += Matrix1.contents[row][item] * Matrix2.contents[item][col];
            }
        }
    }
    return res;
}

float Matrix::getByRowCol(int row, int col){
  return contents[row][col];
}
