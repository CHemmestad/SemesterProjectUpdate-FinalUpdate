#include "Course.h"
#include "AddCourse.h"
#include "InitializeLinkedList.h"
#include <iostream>

using namespace std;

struct Node;

int main() {
	
	int x = 0;
	bool con = true;

	while (con) {
		LinkedList list;
		AddCourse add;
		string course;

		list.makeList();

		system("cls");

		cout << "\n\t\tMAIN MENU\n\n" << endl;
		cout << "Pick an option" << endl;
		cout << "\t1. All Courses\n\t2. Add A Course\n\t3. Delete A Course\n\t4. Edit Course\n";
		cout << "\t5. Leave\n";
		cout << "\n\nEnter a number to choose : ";

		cin >> x;

		switch (x) {
		case 1: //All Courses
			system("cls");
			list.print();
			system("pause");
			break;
		case 2: //Add Course
			system("cls");
			cin.ignore();
			cout << "Type 'BACK' to go back." << endl;
			add.addCourse();
			system("pause");
			break;
		case 3: //Delete Course
			system("cls");
			list.printCourseName();
			cout << "Type 'BACK' to go back." << endl;
			cout << "Which course do you want to delete? : ";
			cin.ignore();
			getline(cin, course);
			list.remove(course);
			remove("Courses.txt");
			rename("NewFile.txt", "Courses.txt");
			system("pause");
			break;
		case 4: //Edit Courses
			system("cls");
			list.printCourseName();
			cout << "Type 'BACK' to go back." << endl;
			cout << "Which course do you want to edit? : ";
			cin.ignore();
			getline(cin, course);
			list.edit(course);
			remove("Courses.txt");
			rename("NewFile.txt", "Courses.txt");
			system("pause");
			break;
		case 5: //Leave
			system("cls");
			con = false;
			break;
		default:
			system("cls");
			cout << ("Invalid") << endl;
			system("pause");
			break;
		}
		list.~LinkedList();
	}

	return 0;
}