#include <iostream>
#include <string>
#include <fstream>

using namespace std;



int checkGrade(double &studentMax, double &student, double &procent) {
	procent = student / studentMax * 100;
	return procent;
}

struct student
{
	string lastName;
	string name;
	string surname;
	int exam;
	int grade[10];
};

int main() {
	setlocale(LC_ALL, "RU");
	double student = 0;
	double studentMax = 0;
	struct student st;
	double procent = 0;
	ofstream File("File.txt");
	File.is_open();

	if (!File.is_open()) { 
		cout << "������ �������� �����!" << endl;
		return 1;
	}
	while (true) {
		int sw;
		cout << "1 - �������� ����� ��������, 2 - ����� �� ������: ";
		cin >> sw;

		switch(sw){
		
		case 1: {
			cout << "������� ��� ��������: ";
			cin >> st.lastName >> st.name >> st.surname;

			cout << "������� ���������� ���������: ";
			cin >> st.exam;

			cout << "������� ������ �� ���������: " << endl;
			for (int i = 0; i < st.exam; i++) {
				cout << i + 1 << " �������: ";
				cin >> st.grade[i];
			}
			
			File << "��� �������� " << st.lastName << " " << st.name << " " << st.surname << endl
				<< "���������� ������� ���������: " << st.exam << endl;
			
			File << "������ �� ��������: " << endl;
			
			for (int i = 0; i < st.exam; i++) {
				File << i + 1 << " �������: " << st.grade[i] << endl;;
			}
			bool gradeExam = false;
			for (int i = 0; i < st.exam; i++) {
				if (st.grade[i] == 4 || st.grade[i] == 5) {
					gradeExam = true;
				}
				else {
					gradeExam = false;
					break;
				}
			}
			if (gradeExam) {
				studentMax++;
				File << "������ ���� ��� �������� �� 4 � 5" << endl;
			}
			break;
		}
		case 2: {
			cout << "����� �� ����� ������." << endl;
			break;

		}
		
		default: {
			cout << "������� ������� ������." << endl;
			checkGrade(student, studentMax, procent);
			File << "������� ��������� ��������� ������� ������� �� 4 � 5 � ����� ���������� ���������: " << procent << endl;
			File.close();
			return 0;
		    }
		}
		student++;
	}
}