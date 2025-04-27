#include <iostream>
#include <array>

template<typename T, size_t ROWS, size_t COLS>
class Matrix {
private:
    std::array<std::array<T, COLS>, ROWS> data;

public:
    Matrix() {
        for (auto& row : data) {
            row.fill(T());
        }
    }

    void set(size_t row, size_t col, const T& value) {
        if (row < ROWS && col < COLS) {
            data[row][col] = value;
        }
    }

    T get(size_t row, size_t col) const {
        if (row < ROWS && col < COLS) {
            return data[row][col];
        }
        throw std::out_of_range("Index hors limites");
    }

    Matrix<T, ROWS, COLS> add(const Matrix<T, ROWS, COLS>& other) const {
        Matrix<T, ROWS, COLS> result;
        for (size_t i = 0; i < ROWS; ++i) {
            for (size_t j = 0; j < COLS; ++j) {
                result.set(i, j, data[i][j] + other.get(i, j));
            }
        }
        return result;
    }
};

// Spécialisation pour les matrices carrées
template<typename T, size_t N>
class Matrix<T, N, N> {
private:
    std::array<std::array<T, N>, N> data;

public:
    Matrix() {
        for (auto& row : data) {
            row.fill(T());
        }
    }

    void set(size_t row, size_t col, const T& value) {
        if (row < N && col < N) {
            data[row][col] = value;
        }
    }

    T get(size_t row, size_t col) const {
        if (row < N && col < N) {
            return data[row][col];
        }
        throw std::out_of_range("Index hors limites");
    }

    Matrix<T, N, N> add(const Matrix<T, N, N>& other) const {
        Matrix<T, N, N> result;
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < N; ++j) {
                result.set(i, j, data[i][j] + other.get(i, j));
            }
        }
        return result;
    }

    // Méthode spécifique aux matrices carrées
    T trace() const {
        T sum = T();
        for (size_t i = 0; i < N; ++i) {
            sum += data[i][i];
        }
        return sum;
    }
};

int main() {
    std::cout << "Exercise 4 - Matrix:" << std::endl;
    
    // Test avec une matrice non carrée
    Matrix<int, 2, 3> m1;
    m1.set(0, 0, 1); m1.set(0, 1, 2); m1.set(0, 2, 3);
    m1.set(1, 0, 4); m1.set(1, 1, 5); m1.set(1, 2, 6);

    // Test avec une matrice carrée
    Matrix<int, 2, 2> m2;
    m2.set(0, 0, 5); m2.set(0, 1, 6);
    m2.set(1, 0, 7); m2.set(1, 1, 8);

    // Test avec une autre matrice carrée
    Matrix<int, 2, 2> m3;
    m3.set(0, 0, 1); m3.set(0, 1, 2);
    m3.set(1, 0, 3); m3.set(1, 1, 4);

    auto m4 = m2.add(m3);
    std::cout << "Addition de matrices carrées:" << std::endl;
    std::cout << m4.get(0, 0) << " " << m4.get(0, 1) << std::endl;
    std::cout << m4.get(1, 0) << " " << m4.get(1, 1) << std::endl;
    
    std::cout << "Trace de la matrice carrée: " << m4.trace() << std::endl;

    return 0;
} 