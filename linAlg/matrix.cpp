#include "matrix.h"

//Automatically sets all elems in data to 0.0
Matrix::Matrix(long rows, long cols)
: rows(rows), cols(cols) {
    if(rows < 1 || cols < 1){
        throw std::invalid_argument("Invalid dimensions of matrix, rows: " + std::to_string(rows) + ", cols: " + std::to_string(cols));
    }else{
        data.resize(rows*cols);
    }
}

//Deepcopy constructor
Matrix::Matrix(const Matrix &m) : rows(m.rows), cols(m.cols), data(m.data) {}

//Copy swap idiom
Matrix Matrix::operator=(Matrix m2) {
    std::swap(data, m2.data);
    std::swap(rows, m2.rows);
    std::swap(cols, m2.cols);
}

//Move constructor, to avoid unecessary copying when initializing a new matrix with an rvalue.
Matrix::Matrix(Matrix &&other) noexcept 
 : rows(other.rows), cols(other.cols), data(std::move(other.data)) {
    other.rows = 0;
    other.cols = 0;
}

//Move operator, to avoid unecessary copying when assigning an rvalue to a matrix.
Matrix Matrix::operator=(Matrix &&other) noexcept {
    if (this != &other){
        data = std::move(other.data);
        rows = other.rows;
        cols = other.cols;

        other.rows = 0;
        other.cols = 0;
    }
    return *this;
}

//Overide << to enable matrix printing
std::ostream &operator<<(std::ostream &os, Matrix &m) {
    long i = 0;
    long j = 0;

    for (i = 0; i < m.rows; i++){
        os << "[";
        for (j = 0; j < m.cols - 1; j++){
            os << m.at(i, j) << ", ";
        }
        os << m.at(i, j) << "]\n";
    }
    return os;
}

//Returns index of row in which the biggest elem is
long Matrix::getMaxRow() const {
    double max = this->at(0,0);
    long maxIndex = 0;

    for (long i = 0; i < rows; ++i) {
        for (long j = 0; j < cols; ++j) {
            if (this->at(i, j) > max) {
                max = this->at(i, j);
                maxIndex = i;
            }
        }
    }
    return maxIndex;
}

// Matrix multiplication
Matrix Matrix::operator*(const Matrix &m2) const {
    if(cols != m2.rows){
        throw std::invalid_argument("Dimensions do not match for matrix multiplication");
    }

    Matrix product(rows, m2.cols);

    for (long i = 0; i < rows; i++){
        for (long k = 0; k < cols; k++){
            double data_copy = data[i * cols + k];
            for (long j = 0; j < m2.cols; j++){
                product.at(i, j) +=  data_copy * m2.data[k * m2.cols + j];
            }
        }
    }

    return product;
}

//Matrix scaling
Matrix Matrix::operator*(double scalar) const {
    Matrix scaled(rows, cols);
    
    for (long i = 0; i < rows; i++){
        for (long j = 0; j < cols; j++){
            scaled.at(i, j) = this->at(i, j) * scalar;
        }
    }

    return scaled;
}

//Matrix addition
Matrix Matrix::operator+(const Matrix &m2) const {
    if(rows != m2.rows || cols != m2.cols){
        throw std::invalid_argument("Matrix dimensions do not match for addition.");
    }

    Matrix sum(rows, cols);

    for (long i = 0; i < rows; i++){
        for (long j = 0; j < cols; j++){
            sum.at(i, j) = this->at(i, j) + m2.at(i, j);
        }
    }

    return sum;
}

//Adding scalar to each elem in matrix
Matrix Matrix::operator+(double scalar) const {
    Matrix scaled(rows, cols);
    for(long i = 0; i < rows; i++){
        for(long j = 0; j < cols; j++){
            scaled.at(i, j) = this->at(i, j) + scalar;
        }
    }

    return scaled;
}

//Applies the function given as argument to all elements, mutates the object
void Matrix::map(double (*f)(double)) {
    for(long i = 0; i < rows; i++){
        for(long j = 0; j < cols; j++){
            this->at(i, j) = f(this->at(i, j));
        }
    }
}

//Applies the function given as argument to all elements, will return new matrix
Matrix Matrix::map(double (*f)(double)) const {
    Matrix mapped(rows, cols);

    for(long i = 0; i < rows; i++){
        for(long j = 0; j < cols; j++){
            mapped.at(i, j) = f(this->at(i, j));
        }
    }

    return mapped;
}

//Sets each element in matrix to a random double within given bounds
void Matrix::setRandomVal(double lowerBound, double upperBound) {
    for(long i = 0; i < rows; i++){
        for(long j = 0; j < cols; j++){
            this->at(i, j) = randDouble(lowerBound, upperBound);
        }
    }
}

//Returns transposed version of matrix
Matrix Matrix::transposed() const {
    Matrix transposed(rows, cols);

    for(long i = 0; i < rows; i++){
        for(long j = 0; j < cols; j++){
            transposed.at(i, j) = this->at(j, i);
        }
    }

    return transposed;
}

//Element-wise multiplication between matrices
Matrix Matrix::hadamard(const Matrix &m2) const {
    if (rows != m2.rows || cols != m2.cols){
        throw std::invalid_argument("Matrix dimensions do not match for element-wise multiplication(hadamard)");
    }

    Matrix product(rows, cols);

    for(long i = 0; i < rows; i++){
        for(long j = 0; j < cols; j++){
            product.at(i, j) = this->at(i,j) * m2.at(i, j);
        }
    }

    return product;
}
