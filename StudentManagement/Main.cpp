#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Student
{
	int id;
	string name;
	double score;
};

void displayMenu();
int inputNumberOfStudent();
void insertStudent(int n, vector<Student>  &listStudent);
int checkID(int id, vector<Student> &listStudent);
void displayStudent(vector <Student> listStudent);
void saveToFile(vector<Student> &listStudent);
void loadFile(vector<Student> listStudent);

vector<Student>  listStudent;
//vector<Student>::iterator it;



void main()
{
	int choice;


	do
	{
		displayMenu();
		cout << "input your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int n = inputNumberOfStudent();
			insertStudent(n, listStudent);
			break;
		}
		case 2:
			displayStudent(listStudent);
			break;
		case 3:
			saveToFile(listStudent);
			break;
		default:
			exit(0);
			break;
		}
	} while (true);
}

void displayMenu()
{
	system("CLS");
	cout << "\n===========================MENU===========================\n";
	cout << "1. Insert student\n";
	cout << "2. Display\n";
	cout << "3. Save to file\n";
	cout << "4. Load from file\n";
	cout << "orther. Exit\n";
}

int inputNumberOfStudent()
{
	cout << "enter number of student : ";
	int n;
	cin >> n;

	while (!cin || n <= 0)
	{
		// user didn't input number
		cout << "Please enter number of student";
		cin.clear(); // reset failed bit
		cin.ignore(numeric_limits<streamsize>::max(), '\n');// skip bad input
		cin >> n;
	}
	return n;
}

void insertStudent(int n, vector<Student>  &listStudent)
{
	Student tmpStudent;

	for (int i = 0; i < n; i++)
	{
		do
		{
			cout << "\nPlease input id of student " << i + 1 << ": ";
			cin.ignore();
			cin >> tmpStudent.id;

			if (checkID(tmpStudent.id, listStudent) == -1)
			{
				break;
			}

			cout << "student id has already, press any key to try again!";
			system("pause>NULL");

		} while (checkID(tmpStudent.id, listStudent) == 1);

		cout << "\nPlease input name of student " << i + 1 << ": ";
		cin.ignore();
		getline(cin, tmpStudent.name);
		cout << "\nPlease input score of student " << i + 1 << ": ";
		cin >> tmpStudent.score;
		listStudent.push_back(tmpStudent);
	}

}

int checkID(int id, vector<Student> &listStudent)
{
	for (auto tmp : listStudent)
	{
		if (id == tmp.id)
		{
			return 1;
			break;
		}
	}
	return -1;
}

void displayStudent(vector <Student> listStudent)
{
	system("CLS");

	if (listStudent.empty())
	{
		cout << "No records press any key to back to menu";
		system("pause>NULL");
		return;
	}

	cout << "\n\tID\t" << "NAME\t" << "\tSCORE\t";
	cout << "\n\t================================\n";

	for (auto tmp : listStudent)
	{
		cout << "\t" << tmp.id << "\t" << tmp.name << "\t\t" << tmp.score << "\t \n";
	}

	cout << "\n\tPress any key to back to menu";
	system("pause>NULL");
}

void saveToFile(vector<Student> &listStudent)
{
	ofstream outfile;
	outfile.open("student.txt");

	if (listStudent.empty())
	{
		cout << "no data! press any key to back to menu";
		system("pause>NULL");
		return;
	}
	if (outfile.is_open())
	{
		for (auto tmp : listStudent)
		{
			outfile << tmp.id << endl;
			outfile << tmp.name << endl;
			outfile << tmp.score << endl;
			
		}
		outfile.close();
	}

	cout << "Data has been saved to file! Press any key to back to menu";
	system("pause>NULL");

}

void loadFile(vector<Student> listStudent)
{
}