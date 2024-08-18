#include <iostream>
#include <string>
#include<fstream> 
#include <vector>
using namespace std;
const int MAXCLIENTS = 100;
const int MAXEMPLOYEES = 10;
class Client;
class Employee;

class Employee {
protected:
	string name;
	int id;
	string password;
	double salary;
	int clientcount;
	Client clients[MAXCLIENTS];

public:
	Employee() {
		id = 0;
		salary = 0;
		clientcount = 0;
	}
	Employee(int i, string n, double sa, string p, int c, Client* cli) {
		id = i;
		name = n;
		salary = sa;
		password = p;
		clientcount = c;

		for (int i = 0; i < MAXCLIENTS && i < c; i++) {
			clients[i] = cli[i];
		}

	}
	void setName(string n) {

		if (n.length() < 5 || n.length() > 20) {
			cout << " Invalid Name : Name must be between 5 and 20 characters long." << endl;
			return;
		}
		bool isvalid = true;
		for (int i = 0; i < n.length(); i++) {
			if (!isalpha(n[i])) {
				isvalid = false;
				break;
			}
		}
		if (isvalid) {
			name = n;
		}
		else {
			cout << "Invalid Name: Name must contain only alphabetic characters." << endl;
		}

	}
	void setId(int i) {
		id = i;

	}
	void setSalary(double s) {
		if (s < 5000) {
			cout << "Salary Is Too Little !" << endl;
		}
		else {
			salary = s;
		}


	}

	void setPassword(string p) {
		if (p.length() < 5 || p.length() > 20) {
			cout << " Invalid Password : Password must be between 5 and 20 characters long." << endl;
			return;
		}
		else {
			password = p;
		}

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

	bool login() const {

		cout << "Please Enter Your ID" << endl;
		int logInId;
		cin >> logInId;
		string logInPassword;
		cout << "Please Enter Your Password" << endl;
		cin >> logInPassword;
		if (id == logInId && password == logInPassword) {
			return true;
		}
		else
			return false;
	}
	void addNewClient() {
		Client newclient;
		if (clientcount < MAXCLIENTS) {


			int newid;
			cout << "Enter Client ID " << endl;
			cin >> newid;
			newclient.setId(newid);
			cout << "Enter Client Name " << endl;
			string newname;
			cin >> newname;
			newclient.setName(newname);
			cout << "Enter Client Balance " << endl;
			double newbalance;
			cin >> newbalance;
			newclient.setBalance(newbalance);
			cout << "Enter Client Password " << endl;
			string newpassword;
			cin >> newpassword;
			newclient.setPassword(newpassword);
			clients[clientcount] = newclient;
			clientcount++;
			cout << "Client Added Successfully " << endl;
		}

		else
			cout << "Sorry You Can't Add New Clients " << endl;

	}
	void searchForClient() {
		int searchid;
		cout << "Enter The Client ID You Want To Look For It" << endl;
		cin >> searchid;
		for (int i = 0; i < clientcount; i++) {
			if (searchid == clients[i].getId()) {
				cout << "CLient name is : " << clients[i].getName() << endl;
				return;
			}
		}
		cout << "Client Not Found" << endl;
	}

	void listClient() {
		for (int i = 0; i < clientcount; i++) {
			cout << "Client Name IS : " << clients[i].getName() << endl << "Client ID IS : "
				<< clients[i].getId() << endl << "Client Balance IS : " << clients[i].getBalance() << endl;
		}
	}

	void updateClientInfo() {
		int id;
		cout << "Enter The Client ID You Want To Update " << endl;
		cin >> id;
		string newname;
		cout << "Enter The New Name " << endl;
		cin >> newname;
		int newid;
		cout << "Enter The New ID " << endl;
		cin >> newid;
		double newbalance;
		cout << "Enter The New Balance " << endl;
		cin >> newbalance;
		for (int i = 0; i < clientcount; i++) {
			if (id == clients[i].getId()) {
				clients[i].setName(newname);
				clients[i].setId(newid);
				clients[i].setBalance(newbalance);
				cout << "Client Info Has Been Updated Successfully" << endl;
			}

		}

		cout << "Client Not Found !!" << endl;
	}

	void displayEmployee() {
		cout << "Employee Name IS : " << name << endl;
		cout << "Employee ID IS : " << id << endl;
		cout << "Employee Salary IS : " << salary << "L.E" << endl;
	}

};
