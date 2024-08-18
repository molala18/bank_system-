#include <iostream>
#include<string>
using namespace std;

class Client{
private:
	int id;
	string name, password;
	double balance;
public:
	Client() {
		balance = 1500;
	}
	Client(int i, double p) {
		id = i;
		password = p;
	}
	Client(int i, double p,string n) {
		id = i;
		password = p;
		name = n;
	}
	void setName(string n) {
		if (n.size() <= 20 && n.size() >= 5) {
			for (int i = 0; i <= n.size(); i++) {
				if (n[i] != '\0' && n[i] != ' ') {
					if (isalpha(n[i])) {
						name = n;
					}
					else {
						cout << "You must enter an alphabetic characters\n";
						break;
					}
				}

			}
		}
		else {
			cout << "The name must contain at least 5 characters and at most 20 characters\n";
		}
		
	}
	void setPassword(string  p) {
		if (p.size() >= 8 && p.size() <= 20) {
			password = p;
		}
		else {
			cout << "The password should not be less than 8 numbers and not more than 20 numbers\n";
		}
	}
	
	void setBalance(double b) {
		if (b >= 1500) {
			balance = b;
		}
	}

	void setId(int i) {
		id = i;
	}

	string getName() {
		return name;
    }
	string getPassword() {
		return password;
	}
	double getBalance() {
		return balance;
	}
	int getId() {
		return id;
	}

	void deposit(double d) {
		balance += d;
	}

	void withdraw(double w) {
		if (w <= balance) {
			balance -= w;
		}
		else {
			cout << "The amount available is not enough to carry out this operation";
		}
	}

	void transferTo(double amount, Client& r) {
		if (balance >= amount) {
			balance -= amount;
			r.deposit(amount);
		}
		else {
			cout << "The amount available is not enough to carry out this operation\n";
		}
	}

	void checkBalance() {
		cout << "The balance is = " << balance << endl;
	}

	void disPlay() {
		cout << "Name : " << name << "\n";
		cout << "Id :" << id << "\n";
		cout << "Balance : " << balance << "\n";
		
	}

};

