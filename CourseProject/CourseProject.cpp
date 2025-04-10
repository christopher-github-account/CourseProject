#include <iostream>
#include "StudentInfoSystem.hpp"
#include "MatrixOperations.hpp"

void displayMenu() {
    std::cout << "1. Student Information System\n";
    std::cout << "2. Matrix Operations\n";
    std::cout << "3. Exit\n";
}

int main() {
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            runStudentInfoSystem();
            break;
        case 2:
            runMatrixOperations();
            break;
        case 3:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}