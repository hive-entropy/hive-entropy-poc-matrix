#ifndef MATRIX_H
#define MATRIX_H

namespace MatrixArchetype{
    static const int ZEROS = 0;
    static const int ONES = 1;
    static const int ID = 2;
}


class Matrix{
    private:
        int rows;
        int columns;
        int elements;
        int type;
        double** data;

    public:
        Matrix(int rows, int columns, double** data);
        Matrix(int rows, int columns, int archetype);
        Matrix(const Matrix& m);
        ~Matrix();

        void putColumn(int j, double* elems);
        void putRow(int i, double* elems);
        void put(int i, int j, double elem);

        double get(int i, int j);
        double* getRow(int i);
        double* getColumn(int j);

        double** getData();
        int getRows();
        int getColumns();
        int getType();
        int getElements(); 

        Matrix operator*(Matrix const& other);
        Matrix operator+(Matrix const& other);
        Matrix operator-(Matrix const& other);
        Matrix& operator*=(Matrix const& other);
        Matrix& operator+=(Matrix const& other);
        Matrix& operator-=(Matrix const& other);
        bool operator==(Matrix const& other);
        bool operator!=(Matrix const& other);
};


#endif