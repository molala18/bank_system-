#include <iostream>
#include<string>
using namespace std;
class Admin {
private:
    int id;
    string name, password;
    double salary;
public:
    Admin() {
        id =salary=0;
    }
    void setName(string name) {
        if (name.length() < 5 || name.length() > 20) {
            cout << "Error Name\n";
            return;
        }
        for (int i = 0; i < name.length(); i++) {
            if (!isalpha(name[i])) {
                if (name[i] != ' ') {
                    cout << "Error Name\n";
                    return;
                }

            }
        }
        this->name = name;
    }
    void setPassword(string password) {
        if (password.length() < 8 || password.length() > 20) {
            cout << "Error password\n";
            return;
        }
        this->password = password;
    }
    void setId(int id) {
        this->id = id;
    }
    void setSalary(double salary) {
        if (salary < 5000) {
            cout << "Error: Minimum Salary must be at least 5000 \n";
            return;
        }
        this->salary = salary;
    }
    string getName() {
        return name;
    }
    string getPassword() {
        return password;
    }
    int getId() {
        return id;
    }
    double getSalary() {
         return salary;
      }
    void Display() {
        cout << "Name : " << name << endl;
        cout << "password : " << password << endl;
        cout << "Id : " << id << endl;
        cout << "salary : " << salary << endl;
    }
};
