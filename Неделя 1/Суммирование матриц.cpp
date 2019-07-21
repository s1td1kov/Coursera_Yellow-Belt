#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>

using namespace std;

class Matrix {
public:
    
    Matrix(int new_rows = 0, int new_columns = 0) {
        Reset(new_rows, new_columns);
    }
    
    void Reset(int new_rows, int new_columns) {
        if (new_rows < 0) {
            throw out_of_range("");
        }
        if (new_columns < 0) {
            throw out_of_range("");
        }
        
        rows = new_rows;
        cols = new_columns;
        mat.assign(new_rows, vector < int > (new_columns));
    }
    
    void SetElement(const int& index1, const int& index2, const int& el) {
        mat[index1][index2] = el;
    }
    
    int At(const int& num1, const int& num2) const {
        if (num1 > GetNumRows() - 1 || num2 > GetNumColumns() - 1 || num1 < 0 || num2 < 0) {
            throw out_of_range("");
        }
        return mat.at(num1).at(num2);
    }
    
    int& At(const int& num1, const int& num2) {
        if (num1 > GetNumRows() - 1 || num2 > GetNumColumns() - 1 || num1 < 0 || num2 < 0) {
            throw out_of_range("");
        }
        return mat.at(num1).at(num2);
    }
    
    int GetNumRows() const {
        return rows;
    }
    
    int GetNumColumns() const {
        return cols;
    }
    
private:
                   
    int rows;
    int cols;
    vector<vector<int>> mat;
};

istream& operator >> (istream& stream, Matrix& matrix) {
    int n, m;
    stream >> n >> m;
    matrix.Reset(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            stream >> matrix.At(i, j);
        }
    }
    return stream;
}

ostream& operator << (ostream& stream, const Matrix& matrix) {
    stream << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
    for (int i = 0; i < matrix.GetNumRows(); ++i) {
        for (int j = 0; j < matrix.GetNumColumns(); ++j) {
            stream << matrix.At(i, j) << " ";
        }
        stream << endl;
    }
    return stream;
}

bool operator == (const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.GetNumRows() == matrix2.GetNumRows() && matrix1.GetNumColumns() == matrix2.GetNumColumns()) {
        bool k = true;
        for (int i = 0; i < matrix1.GetNumRows(); ++i) {
            for (int j = 0; j < matrix1.GetNumColumns(); ++j) {
                if (matrix1.At(i, j) != matrix2.At(i, j)) {
                    k = false;
                }
            }
        }
        return k;
    } else {
        return false;
    }
}

Matrix operator + (const Matrix& matrix1, const Matrix& matrix2) {
    if(matrix1.GetNumColumns() == 0 && matrix1.GetNumRows() == 0 && matrix2.GetNumColumns() == 0 && matrix2.GetNumRows() == 0) {
        return {};
    }
    
    if (matrix1.GetNumRows() != matrix2.GetNumRows()) {
        throw invalid_argument("");
    }
    
    if (matrix1.GetNumColumns() != matrix2.GetNumColumns()) {
        throw invalid_argument("");
    }
    
    Matrix matrix;
    matrix.Reset(matrix1.GetNumRows(), matrix1.GetNumColumns());
    for (int i = 0; i < matrix1.GetNumRows(); ++i) {
        for (int j = 0; j < matrix1.GetNumColumns(); ++j) {
            matrix.SetElement(i, j, matrix1.At(i, j) + matrix2.At(i, j));
        }
    }
    return matrix;
}

int main() {
    Matrix one, two;
    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}
