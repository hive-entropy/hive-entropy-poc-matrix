#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
private:
    int rows;
    int columns;
    int elements;
    int type;
    double[] data;

public:
    Matrix();
    Matrix(int rows, int columns, double[] data);
    Matrix(int rows, int columns);
    ~Matrix();

    void pushColumn(double[] elems);
    void pushRow(double[] elems);
    void put(int i, int j, double data);

    double get(int i, int j);

    Matrix operator*(Matrix other);
    Matrix operator+(Matrix other);
    Matrix operator-(Matrix other);
    Matrix operator==(Matrix other);
    Matrix operator!=(Matrix other);
};


#endif