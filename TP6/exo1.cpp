#include <iostream>
using namespace std;
int** createMatrix(int n, int m) {
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = i * m + j + 1;
        }
    }
    return matrix;
}

void printMatrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int** transposeMatrix(int** matrix, int n, int m) {
    int** transposed = new int*[m];
    for (int i = 0; i < m; ++i) {
        transposed[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            transposed[i][j] = matrix[j][i];
        }
    }
    return transposed;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int n = 3, m = 3;
    int** matrix = createMatrix(n, m);
    cout << "Matrice initiale :" << endl;
    printMatrix(matrix, n, m);
    
    int** transposed = transposeMatrix(matrix, n, m);
    cout << "Matrice transposée :" << endl;
    printMatrix(transposed, m, n);
    
    freeMatrix(matrix, n);
    freeMatrix(transposed, m);
    return 0;
}