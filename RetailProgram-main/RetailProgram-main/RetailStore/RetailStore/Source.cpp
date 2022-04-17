#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cstring>
#include <algorithm>

using namespace std;

/*STRUCTS AND CLASSES TO CREATE STORE*/

struct Item {
	string itemName;
	double itemCost;
	int itemAmount;
};

struct Transactions {
	vector<Item> items;
	double orderTotal;
};

struct Customer {
	string name;
	vector<Transactions> transactionHistory;
};


/*BINARY SEARCH logn*/
int
BinarySearch(vector<Customer> list, string x, int &b) {
	transform(x.begin(), x.end(), x.begin(), toupper);
	int middle;
	Customer a;
	int low = 0;
	int high = list.size() - 1;
	bool found = false;
	if (list.size() == 0) {
		cout << "EMPTY LIST!" << endl;
		return -1;
	}
	while (!found) {
		if (high < low) {
			cout << "Name does not exist" << endl;
			return -1;
		}
		middle = ceil((high + low) / 2);
		if (list.at(middle).name < x) {
			low = middle + 1;
		}
		else if (list.at(middle).name > x) {
			high = middle - 1;
		}
		else if (list.at(middle).name == x) {
			return middle;
		}
	}
	a.name = x;
	list.push_back(a);
	cout << "Name does not exist! Customer name has been entered into the system for future transactions!" << endl;
	return list.size()-1;
}

class Store {
private:
	string storeName;
	double storeTreasury;
	vector<Customer> Customers;
public:
	vector<Item> Inventory;
	Store(string a, double b, vector<Customer> CustomerList) : storeName(a), storeTreasury(b), Customers(CustomerList) {}
	~Store() {}
	string getStoreName() {
		return storeName;
	}
	double getStoreTreasure() {
		return storeTreasury;
	}
	void getCustomers(vector<Customer> &list) {
		list = Customers;
	}
	void updateCustomers(Customer a) {
		int bs;
		int b = BinarySearch(Customers, a.name, bs);
		if (b == -1) cout << "Customer does not exist no update performed" << endl << endl;
		else {
			Customers.at(b) = a;
		}
	}
	void addCustomers(Customer a) {
		Customers.push_back(a);
	}
	void updateCustomers(vector<Customer> list) {
		this->Customers = list;
	}
};

/*UTILITY FUNCTIONS*/

void 
Menu(char &a) {
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	cout << "                                  WELCOME TO WALMART                                  \n";
	cout << "                            Enter '1' for a transaction                               \n";
	cout << "                            Enter '2' for a customer print                          \n";
	cout << "                            Enter '3' for an inventory print                          \n";
	cout << "                            Enter '4' to exit program                                 \n";
	cout << "                            Your Input:";
	cin >> a;
	cout << endl << endl;
}

void 
PrintInventory(vector<Item> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << "Inventory item index:" << i + 1 << " Item name:" << list.at(i).itemName << " Item amount:" << list.at(i).itemAmount << " Item cost:$" << list.at(i).itemCost << endl;
	}
	cout << endl;
}

void
PrintCustomers(Store a) {
	vector<Customer> list;
	a.getCustomers(list);
	for (int i = 0; i < list.size(); i++) {
		cout << "Customer name:" << list.at(i).name << endl;
	}
	cout << endl;
}

/*MERGE SORT nlogn*/
vector<Item> 
MergeSort(vector<Item> &list) {
	auto middleLeft = next(list.begin(), floor(list.size() / 2));
	auto middleRight = next(list.begin(), ceil(list.size() / 2));
	if (list.size() <= 1) return list;
	else if (list.size() > 1) {
		vector<Item> left(list.begin(), middleLeft);
		vector<Item> right(middleRight, list.end());
		left = MergeSort(left);
		right = MergeSort(right);
		list.clear();
		while (!left.empty() && !right.empty()) {
			if (right.front().itemName < left.front().itemName) {
				list.push_back(right.front());
				right.erase(right.begin());
			}
			else {
				list.push_back(left.front());
				left.erase(left.begin());
			}
		}
		while (!left.empty()) {
			list.push_back(left.front());
			left.erase(left.begin());
		}
		while (!right.empty()) {
			list.push_back(right.front());
			right.erase(right.begin());
		}
		return list;
	}
}
vector<Customer>
MergeSort(vector<Customer> list) {
	auto middleLeft = next(list.begin(), floor(list.size() / 2));
	auto middleRight = next(list.begin(), ceil(list.size() / 2));
	if (list.size() <= 1) return list;
	else if (list.size() > 1) {
		vector<Customer> left(list.begin(), middleLeft);
		vector<Customer> right(middleRight, list.end());
		left = MergeSort(left);
		right = MergeSort(right);
		list.clear();
		while (!left.empty() && !right.empty()) {
			if (right.front().name < left.front().name) {
				list.push_back(right.front());
				right.erase(right.begin());
			}
			else {
				list.push_back(left.front());
				left.erase(left.begin());
			}
		}
		while (!left.empty()) {
			list.push_back(left.front());
			left.erase(left.begin());
		}
		while (!right.empty()) {
			list.push_back(right.front());
			right.erase(right.begin());
		}
		return list;
	}
}
/*BINARY SEARCH logn*/
Customer
BinarySearch(vector<Customer> list, string x) {
	transform(x.begin(), x.end(), x.begin(), toupper);
	int middle;
	Customer a;
	int low = 0;
	int high = list.size() - 1;
	bool found = false;
	if (list.size() == 0) {
		cout << "EMPTY LIST!" << endl;
		return a;
	}
	while (!found) {
		if (high < low) {
			cout << "Name does not exist" << endl;
			return list.at(0);
		}
		middle = ceil((high + low) / 2);
		if (list.at(middle).name < x) {
			low = middle + 1;
		}
		else if (list.at(middle).name > x) {
			high = middle - 1;
		}
		else if (list.at(middle).name == x) {
			return list.at(middle);
		}
	}
	a.name = x;
	list.push_back(a);
	cout << "Name does not exist! Customer name has been entered into the system for future transactions!" << endl;
	return list.at(list.size()-1);
}

Item
BinarySearch(vector<Item> list, string x) {
	transform(x.begin(), x.end(), x.begin(), toupper);
	int middle;
	Item a;
	int low = 0;
	int high = list.size() - 1;
	bool found = false;
	if (list.size() == 0) {
		cout << "EMPTY LIST!" << endl;
		return a;
	}
	while (!found) {
		if (high < low) {
			cout << "Item name does not exist" << endl;
			return list.at(0);
		}
		middle = ceil((high + low) / 2);
		if (list.at(middle).itemName < x) {
			low = middle + 1;
		}
		else if (list.at(middle).itemName > x) {
			high = middle - 1;
		}
		else if (list.at(middle).itemName == x) {
			return list.at(middle);
		}
	}
	cout << "Item name does not exist!" << endl;
	return list.at(0);
}

void 
TransMenu(char &a) {
	/*VARIABLE DECLARATION*/
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	cout << "                                  Transaction                                         \n";
	cout << "                            Enter '1' to add an item                                  \n";
	cout << "                            Enter '2' to remove an item                               \n";
	cout << "                            Enter '3' to pay                                          \n";
	cout << "                            Enter '4' to exit transaction menu                        \n";
	cout << "                            Your Input:";
	cin >> a;
	cout << endl << endl;
}

void 
TransStartMenu(string &a) {
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	cout << "                                  Transaction                                         \n";
	cout << "                              Enter your name:";
	cin >> a;
	cout << endl << endl;
}
//Purpose: Function to facilitate transactions
//Input:
//Output: 
void
TransactionFacilitator(Store a) {
	char userInput;
	Customer temp;
	string nameInput;
	TransStartMenu(nameInput);
	vector<Customer> list;
	a.getCustomers(list);
	temp = BinarySearch(list, nameInput);
	while (userInput != '4') {
		TransMenu(userInput);
		switch (userInput) {
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			cout << "Transaction cancelled!" << endl << endl;
			break;
		}
	}
}


int 
main() {
	/*VARIABLE DECLARATION*/
	char userInput = '5';
	/*CUSTOMER LIST CREATION*/
	Customer a, b, c;
	a.name = "SAMUEL HALE";
	b.name = "NOEMI DE LA ROSA";
	c.name = "YUSIF AFFARA";
	vector<Customer> InitializeCustomer = { a, b, c };
	/*INVENTORY CREATION*/
	Item One, Two, Three;
	One.itemName = "APPLE";
	One.itemCost = 1.25;
	One.itemAmount = 50;
	Two.itemName = "CEREAL";
	Two.itemCost = 2.50;
	Two.itemAmount = 100;
	Three.itemName = "BIKE";
	Three.itemCost = 125;
	Three.itemAmount = 20;
	vector<Item> InitializeInventory = { One, Two, Three };
	/*STORE CREATION*/
	Store A("Walmart", 0, InitializeCustomer);
	A.Inventory = InitializeInventory;
	A.Inventory = MergeSort(A.Inventory);
	InitializeCustomer = MergeSort(InitializeCustomer);
	A.updateCustomers(InitializeCustomer);
	/*START PROGRAM*/
	while (userInput != '4') {
		Menu(userInput);
		while (isalpha(userInput) && userInput != '1' && userInput != '2' && userInput != '3' && userInput != '4') {
			cout << "Invalid Entry! Correct Entries are '1', '2', '3', or '4'| You Entered:" << userInput << " Please Try Again:";
			cin >> userInput;
			cout << endl << endl;
		}
		switch (userInput) {
		case '1':
			TransactionFacilitator(A);
			break;
		case '2':
			PrintCustomers(A);
			break;
		case '3':
			PrintInventory(A.Inventory);
			break;
		case '4':
			cout << "GOODBYE!";
			cout << endl << endl;
			break;
		}
	}
	return 0;
}