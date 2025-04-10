#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(rows, std::vector<int>(cols));
    }

    void inputMatrix() {
        std::cout << "Enter elements of the matrix:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
                std::cin >> data[i][j];
            }
        }
    }

    void printMatrix() const {
        std::cout << "Matrix:\n";
        for (const auto& row : data) {
            for (const auto& elem : row) {
                std::cout << elem << " ";
            }
            std::cout << "\n";
        }
    }

    Matrix transpose() const {
        Matrix transposed(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposed.data[j][i] = data[i][j];
            }
        }
        return transposed;
    }
};

void runMatrixOperations() {
    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    Matrix matrix(rows, cols);
    matrix.inputMatrix();

    int choice;
    do {
        std::cout << "\n=== Matrix Operations ===\n";
        std::cout << "1. Print Matrix\n";
        std::cout << "2. Transpose Matrix\n";
        std::cout << "3. Back to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            matrix.printMatrix();
            break;
        case 2: {
            Matrix transposed = matrix.transpose();
            std::cout << "Transposed Matrix:\n";
            transposed.printMatrix();
            break;
        }
        case 3:
            std::cout << "Returning to Main Menu...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}