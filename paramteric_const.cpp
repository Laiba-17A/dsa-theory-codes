#include <iostream>
using namespace std;

// Class definition
class Student {
private:
    string name;
    int age;

public:
    // Constructor with parameters
    Student(string n, int a) {
        name = n;
        age = a;
    }

    // Member function to display student information
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    // Create a Student object with a constructor
    Student student1("Ali", 20);

    // Call the member function to display student information
    cout << "Student 1 Information:" << endl;
    student1.displayInfo();

    // Create another Student object using the constructor
    Student student2("Niyal", 22);

    // Call the member function to display student information
    cout << "\nStudent 2 Information:" << endl;
    student2.displayInfo();

    return 0;
}

