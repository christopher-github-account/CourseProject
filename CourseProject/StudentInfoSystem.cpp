//Chris Mielitz - 301220844

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Student {
    std::string firstName;
    std::string lastName;
    int studentNumber;
    double midterm1;
    double midterm2;
    double finalExam;

    double calculateAverage(double weight1 = 0.25, double weight2 = 0.25, double weightFinal = 0.5) const {
        return (midterm1 * weight1) + (midterm2 * weight2) + (finalExam * weightFinal);
    }

    char calculateLetterGrade(double average) const {
        if (average >= 90) return 'A';
        if (average >= 80) return 'B';
        if (average >= 70) return 'C';
        if (average >= 60) return 'D';
        return 'F';
    }
};

class StudentManager {
private:
    std::vector<Student> students;

public:
    void addStudent() {
        Student s;
        std::cout << "Enter first name: ";
        std::cin >> s.firstName;
        std::cout << "Enter last name: ";
        std::cin >> s.lastName;
        std::cout << "Enter student number: ";
        std::cin >> s.studentNumber;
        std::cout << "Enter midterm 1 grade: ";
        std::cin >> s.midterm1;
        std::cout << "Enter midterm 2 grade: ";
        std::cin >> s.midterm2;
        std::cout << "Enter final exam grade: ";
        std::cin >> s.finalExam;
        students.push_back(s);
        std::cout << "Student added successfully!\n";
    }

    void printStudents() const {
        std::cout << "\nList of Students:\n";
        for (const auto& s : students) {
            double avg = s.calculateAverage();
            char grade = s.calculateLetterGrade(avg);
            std::cout << s.lastName << ", " << s.firstName
                << " | ID: " << s.studentNumber
                << " | Avg: " << std::fixed << std::setprecision(2) << avg
                << " | Grade: " << grade << "\n";
        }
    }

    void sortStudents() {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            if (a.lastName == b.lastName) {
                return a.firstName < b.firstName;
            }
            return a.lastName < b.lastName;
            });
        std::cout << "Students sorted by last name.\n";
    }

    void calculateLetterGrade()
    {
        std::string firstname;
        std::string lastname;
        std::cout << "Please input student's first name";
        std::cin >> firstname;
        std::cout << "Please input student's last name";
        std::cin >> lastname;

        for (int i = 0; i < students.size(), i++;)
        {
            if (students[i].firstName == firstname && students[i].lastName == lastname)
            {
                Student a = students[i];
                double av = a.calculateAverage();
                char avg = a.calculateLetterGrade(av);
                std::cout << avg << std::endl;
            }
        }
    }

    void updateStudent()
    {
        std::string firstname;
        std::string lastname;
        std::cout << "Please input student's first name";
        std::cin >> firstname;
        std::cout << "Please input student's last name";
        std::cin >> lastname;

        int new_studentn;
        int new_midterm_1;
        int new_midterm2;
        int newfinal;

        for (int i = 0; i < students.size(), i++;)
        {
            if (students[i].firstName == firstname && students[i].lastName == lastname)
            {
                std::cout << "Update student number please";
                std::cin >> new_studentn;
                std::cout << "Update first midterm grade please";
                std::cin >> new_midterm_1;
                std::cout << "Update the second midterm grade please";
                std::cin >> new_midterm2;
                std::cout << "Update final grade please";
                std::cin >> newfinal;

                students[i].studentNumber = new_studentn;
                students[i].midterm1 = new_midterm_1;
                students[i].midterm2 = new_midterm2;
                students[i].finalExam = newfinal;
            }
        }
    }

    void printSpecific()
    {
        std::string firstname;
        std::string lastname;
        std::cout << "Please input student's first name";
        std::cin >> firstname;
        std::cout << "Please input student's last name";
        std::cin >> lastname;

        for (int i = 0; i < students.size(), i++;)
        {
            if (students[i].firstName == firstname && students[i].lastName == lastname)
            {
                std::cout << students[i].studentNumber << std::endl;
                std::cout << students[i].midterm1 << std::endl;
                std::cout << students[i].midterm2 << std::endl;
                std::cout << students[i].finalExam << std::endl;
            }
        }
    }
    
    void deleteStudent()
    {
        std::string firstname;
        std::string lastname;
        std::cout << "Please input student's first name";
        std::cin >> firstname;
        std::cout << "Please input student's last name";
        std::cin >> lastname;

        for (int i = 0; i < students.size(), i++;)
        {
            if (students[i].firstName == firstname && students[i].lastName == lastname)
            {
                students.erase(students.begin() + i-1);
            }
        }
    }

    void deleteAll()
    {
        students.clear();
    }
};

void runStudentInfoSystem() {
    StudentManager manager;
    int choice;
    do {
        std::cout << "\n=== Student Information System ===\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Print Students\n";
        std::cout << "3. Sort Students\n";
        std::cout << "4. Calculate letter grade of student\n";
        std::cout << "5. Update a student information\n";
        std::cout << "6. Print a student\n";
        std::cout << "7. Delete a student\n";
        std::cout << "8. Delete all students\n";
        std::cout << "9. Back to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            manager.addStudent();
            break;
        case 2:
            manager.printStudents();
            break;
        case 3:
            manager.sortStudents();
            break;
        case 4:
            manager.calculateLetterGrade();
        case 5:
            manager.updateStudent();
        case 6:
            manager.printSpecific();
        case 7:
            manager.deleteStudent();
        case 8:
            manager.deleteAll();
        case 9:
            std::cout << "Returning to Main Menu...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);
}