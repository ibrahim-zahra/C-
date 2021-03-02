#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool IsLoggedIn() {
	string username, password, un, up;

	cout << "Enter username:" << endl;
	cin >> username;
	
	cout << "Enter password:" << endl;
	cin >> password;

	ifstream read("data\\" + username+".txt");
	getline(read, un);
	getline(read, up);

	if (un == username && up == password) {
		return true;
	}
	else return false;

}
int main() {
	int choice;
	cout << "1:Register\n2: Login\n Your choice: ";
	cin >> choice;
	if (choice == 1) {
		string username, password;

		cout << "select a username"<<endl;
		cin >> username;

		cout << "select a password" << endl;
		cin >> password;

		ofstream file;
		file.open("data\\" + username + ".txt");
		file << username << endl << username;
		file.close();
		main();

	}
	else if (choice == 2) {
		bool status = IsLoggedIn();
		if (!status) {
			cout << "Failed to login" << endl;
			system("PAUSE");
			return 0;

		}
		else {
			cout << "Succeded to login" << endl;
			system("PAUSE");
			return 1;
		}
	}
}