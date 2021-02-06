#include "Matrix.h"

#include <malloc.h>
#include <cblas.h>

Matrix::~Matrix(){
    free(data);
}

Matrix::Matrix(int rows, int columns, double** data) : rows(rows), columns(columns)
{
    this->data = (double**) malloc(rows*columns*sizeof(double));
    for(int i=0;i<rows;i++)
        for(int j=0;j<columns;j++)
            this->data[i][j] = data[i][j];
}

Matrix::Matrix(int rows, int columns, int archetype = MatrixArchetype::ZEROS) : rows(rows), columns(columns)
{
    elements = rows*columns;
    data = (double**) malloc(rows*columns*sizeof(double));
    switch(archetype){
        case MatrixArchetype::ZEROS:
            for(int i=0;i<rows;i++)
                for(int j=0;j<columns;j++)
                    data[i][j] = 0.0;
        case MatrixArchetype::ONES:
            for(int i=0;i<rows;i++)
                for(int j=0;j<columns;j++)
                    data[i][j] = 0.0;
        case MatrixArchetype::ID:
            for(int i=0;i<rows;i++)
                for(int j=0;j<columns;j++)
                    data[i][j] = (i==j)? 1.0 : 0.0;
    }
}

Matrix::Matrix(const Matrix& m){
    rows = m.rows;
    columns = m.columns;
    elements = rows*columns;
    this->data = (double**) malloc(rows*columns*sizeof(double));
    for (int i=0;i<rows;i++)
        for(int j=0;j<columns;j++)
            data[i][j] = m.data[i][j];
}

//Check for column bounds
void Matrix::putColumn(int j, double* elems){
    for(int i=0;i<rows;i++)
        data[i][j] = elems[i];
}

//Check for row bounds
void Matrix::putRow(int i, double* elems){
    for(int j=0;j<columns;j++)
        data[i][j] = elems[j];
}

//Check for column and line bounds
void Matrix::put(int i, int j, double elem){
    data[i][j] = elem;
}

//Check for indexes bounds
double Matrix::get(int i, int j){
    return data[i][j];
}

//Check for row bound
double* Matrix::getRow(int i){
    double* res = (double*) malloc(columns*sizeof(double));
    for(int j=0;j<columns;j++)
        res[j] = data[i][j];
    return res;
}

//Check for column bound
double* Matrix::getColumn(int j){
    double* res = (double*) malloc(rows*sizeof(double));
    for(int i=0;i<rows;i++)
        res[i] = data[i][j];
    return res;
}

double** Matrix::getData(){
    return data;
}

int Matrix::getRows(){
    return rows;
}
int Matrix::getColumns(){
    return columns;
}

int Matrix::getType(){
    return type;
}

int Matrix::getElements(){
    return elements;
}

//Check for columns==other->rows
Matrix& Matrix::operator*=(Matrix const& other){
    Matrix c(this->rows,other.columns,MatrixArchetype::ZEROS);
    cblas_dgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans,this->rows,other.columns,this->rows,1.0,*data,this->rows,*(other.data),other.columns,0.0,*(c.getData()),this->rows);
    return c;
}

//Check for equal sizes
Matrix& Matrix::operator+=(Matrix const& other){
    for (int i=0;i<rows;i++)
        for(int j=0;i<columns;j++)
            data[i][j] += other.data[i][j];
    return *this;
}

//Check for equal sizes
Matrix& Matrix::operator-=(Matrix const& other){
    for (int i=0;i<rows;i++)
        for(int j=0;i<columns;j++)
            data[i][j] -= other.data[i][j];
    return *this;
}

//Check for rows==other->columns
Matrix Matrix::operator*(Matrix const& other){
    Matrix res = *this;
    return res *= other;
}

//Check for equal sizes
Matrix Matrix::operator+(Matrix const& other){
    Matrix res = *this;
    return res += other;
}

//Check for equal sizes
Matrix Matrix::operator-(Matrix const& other){
    Matrix res = *this;
    return res -= other;
}

bool Matrix::operator==(Matrix const& other){
    if(columns!=other.columns||rows!=other.rows) return false;
    for(int i=0;i<rows;i++)
        for(int j=0;j<columns;j++)
            if(data[i][j]!=other.data[i][j]) return false;
    return true;
}

bool Matrix::operator!=(Matrix const& other){
    return (*this==other)? false : true;
}