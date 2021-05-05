#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
private:
    int numRows, numColumns;
    float** contents;
public:
    Matrix(int rows, int columns);
    Matrix(const Matrix &matrix);
    Matrix();
    ~Matrix();
    void fill(const float *data, int dataSize);
    Matrix& operator = (const Matrix& right);
    float getByRowCol(int row, int col);
    friend Matrix operator * (const Matrix& Matrix1, const Matrix& Matrix2);
};


#endif
