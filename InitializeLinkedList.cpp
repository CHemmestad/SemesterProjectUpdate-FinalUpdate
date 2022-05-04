#include "InitializeLinkedList.h"

struct Node {
	string name;
	string id;
	string credits;
	string type;
	string maxCapacity;
	string daysOfWeek;
	string start;
	string end;
	string classroom;
	string date;
	Node* next;
};

LinkedList::LinkedList() {
	pos = NULL;
	head = NULL;
	tail = NULL;
}

LinkedList::~LinkedList() {
	//delete[] head;
}

void LinkedList::newFile() {
	ofstream outfile;
	outfile.open("NewFile.txt");

	pos = head;
	while (pos != NULL) {
		outfile << endl << "Class" << endl;
		outfile << pos->name << endl;
		outfile << "ID" << endl;
		outfile << pos->id << endl;
		outfile << "Credits" << endl;
		outfile << pos->credits << endl;
		outfile << "Type" << endl;
		outfile << pos->type << endl;
		outfile << "Max" << endl;
		outfile << pos->maxCapacity << endl;
		outfile << "Days" << endl;
		outfile << pos->daysOfWeek << endl;
		outfile << "Start" << endl;
		outfile << pos->start << endl;
		outfile << "End" << endl;
		outfile << pos->end << endl;
		outfile << "Room" << endl;
		outfile << pos->classroom << endl;

		outfile << "Date" << endl;
		outfile << pos->date << endl;

		outfile << "END" << endl;

		pos = pos->next;
	}
	outfile << "END OF LIST" << endl;
	outfile.close();
}

void LinkedList::remove(string course) {
	pos = head;
	Node* temp = NULL;
	if (course == "BACK") {
		delete temp;
		pos = NULL;
	}
	while (pos != NULL) {
		if (pos->name == course) {
			temp = pos;
			pos = pos->next;
			delete temp;
			break;
		}
		else if (pos->next->name == course) {
			temp = pos->next;
			pos->next = pos->next->next;
			delete temp;
			break;
		}
		else {
			pos = pos->next;
		}
	}
	newFile();
}

void LinkedList::edit(string course) {
	pos = head;
	int x;
	string change;
	if (course == "BACK") {
		pos = NULL;
	}
	while (pos != NULL) {
		if (pos->name == course) {
			system("cls");
			cout << "1. Name : " << pos->name << endl;
			cout << "2. ID : " << pos->id << endl;
			cout << "3. Credits : " << pos->credits << endl;
			cout << "4. Type : " << pos->type << endl;
			cout << "5. Max : " << pos->maxCapacity << endl;
			cout << "6. Days : " << pos->daysOfWeek << endl;
			cout << "7. Start : " << pos->start << endl;
			cout << "8. End : " << pos->end << endl;
			cout << "9. Room : " << pos->classroom << endl;
			cout << "10.Date : " << pos->date << endl;
			cout << "11.Exit" << endl;
			cout << "Enter the number for the one you want to change? : ";
			cin >> x;
			if (x != 0 && x < 11) {
				cout << "What do you want to change it to? : ";
			}
			switch (x) {
			case 1:
				cin.ignore();
				getline(cin, change);
				pos->name = change;
				pos = NULL;
				break;
			case 2:
				cin.ignore();
				getline(cin, change);
				pos->id = change;
				pos = NULL;
				break;
			case 3:
				cin.ignore();
				getline(cin, change);
				pos->credits = change;
				pos = NULL;
				break;
			case 4:
				cin.ignore();
				getline(cin, change);
				pos->type = change;
				pos = NULL;
				break;
			case 5:
				cin.ignore();
				getline(cin, change);
				pos->maxCapacity = change;
				pos = NULL;
				break;
			case 6:
				cin.ignore();
				getline(cin, change);
				pos->daysOfWeek = change;
				pos = NULL;
				break;
			case 7:
				cin.ignore();
				getline(cin, change);
				pos->start = change;
				pos = NULL;
				break;
			case 8:
				cin.ignore();
				getline(cin, change);
				pos->end = change;
				pos = NULL;
				break;
			case 9:
				cin.ignore();
				getline(cin, change);
				pos->classroom = change;
				pos = NULL;
				break;
			case 10:
				cin.ignore();
				getline(cin, change);
				pos->date = change;
				pos = NULL;
				break;
			case 11:
				pos = NULL;
				break;
			default:
				system("cls");
				cout << "Invalid" << endl;
				break;
			}
		}
		else {
			pos = pos->next;
		}
	}
	newFile();
}

void LinkedList::print() {
	pos = head;
	while (pos != NULL) {
		cout << "------------------------------" << endl;
		cout << pos->name << endl;
		cout << pos->daysOfWeek << endl;
		cout << pos->classroom << endl;
		cout << pos->date << endl;
		pos = pos->next;
	}
	cout << endl;
}

void LinkedList::printCourseName() {
	pos = head;
	while (pos != NULL) {
		cout << "______________________________" << endl << endl;
		cout << pos->name << endl;
		pos = pos->next;
	}
	cout << endl;
}

void LinkedList::makeList() {
	string current;

	ifstream infile;
	infile.open("Courses.txt");

	while (current != "END OF LIST") {
		getline(infile, current);
		if (current == "END OF LIST") {
			break;
		}
		//cout << "something6" << endl;
		//system("pause");
		//cout << "Does not equal 'END OF LIST'" << endl; //Check
		//cout << current << endl; //Check
		Node* temp = new Node();
		temp->next = NULL;
		if (!infile) {
			continue;
		}
		while (current != "END") {
			//cout << "something7" << endl;
			//cout << "Does not equal 'End'" << endl; //Check
			//cout << current << endl; //Check
			getline(infile, current);
			if (current == "END") {
				break;
			}
			if (current == "Class") {
				getline(infile, current);
				temp->name = current;
			}
			else if (current == "ID") {
				getline(infile, current);
				temp->id = current;
			}
			else if (current == "Credits") {
				getline(infile, current);
				temp->credits = current;
			}
			else if (current == "Type") {
				getline(infile, current);
				temp->type = current;
			}
			else if (current == "Max") {
				getline(infile, current);
				temp->maxCapacity = current;
			}
			else if (current == "Days") {
				getline(infile, current);
				temp->daysOfWeek = current;
			}
			else if (current == "Start") {
				getline(infile, current);
				temp->start = current;
			}
			else if (current == "End") {
				getline(infile, current);
				temp->end = current;
			}
			else if (current == "Room") {
				getline(infile, current);
				temp->classroom = current;
			}
			else if (current == "Date") {
				getline(infile, current);
				temp->date = current;
			}
		}
		//cout << "'END' loop ended" << endl; //Check
		if (head == NULL) {
			head = temp;
			pos = temp;
			tail = temp;
		}
		else {
			pos->next = temp;
			pos = pos->next;
			tail = pos;
		}
	}
	//cout << "'END OF LIST' loop ended" << endl; //Check
	infile.close();
}