#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Employee {
    string name;
    int id;
    double salary;
    int age;
};

void readData(vector<Employee>& employees) {
    ifstream file("data.txt");
    Employee e;
    while (file >> e.name >> e.id >> e.salary >> e.age) {
        employees.push_back(e);
    }

    file.close();
}

double calculateAverageSalary(vector<Employee>& employees) {
    double total = 0;

    for (auto e : employees) {
        total += e.salary;
    }
    return total / employees.size();
}

Employee findHighestSalary(vector<Employee>& employees) {
    Employee highest = employees[0];

    for (auto e : employees) {
        if (e.salary > highest.salary) {
            highest = e;
        }
    }
    return highest;
}

int main() {
    vector<Employee> employees;
    readData(employees);
    if (employees.empty()) {
        cout << "No data found!" << endl;
        return 0;
    }

    double avgSalary = calculateAverageSalary(employees);
    Employee highest = findHighestSalary(employees);
    cout << "Average Salary: " << avgSalary << endl;
    cout << "Highest Paid Employee:" << endl;
    cout << "Name: " << highest.name << endl;
    cout << "Age: " << highest.age << endl;
    return 0;
}
