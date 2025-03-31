#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <map>

using namespace std;

struct BitDate {
	int day : 8;
	int month : 16;
	int year : 24;

	BitDate(int d = 0, int m = 0, int y = 0) : day(d), month(m), year(y) {}
};

istream& operator>>(istream& is, BitDate& bd) {
	int d, m, y;
	is >> d >> m >> y;

	if (!is) return is;

	bd.day = d;
	bd.month = m;
	bd.year = y;
	return is;
}

ostream& operator<<(ostream& os, const BitDate& bd) {
	os << setw(2) << setfill('0') << bd.day << "."
		<< setw(2) << setfill('0') << bd.month << "."
		<< setw(4) << setfill('0') << bd.year;
	return os;

}
enum class title {
	����������� = 1,
	������,
	��������,
	�����������
} jobT;

const map<title, string> facultyNames = {
	{title::�����������, "�����������"},
	{title::������, "������"},
	{title::��������, "��������"},
	{title::�����������, "�����������"}
};

ostream& operator<<(ostream& os, const title& faculty) {
	auto it = facultyNames.find(faculty);
	if (it != facultyNames.end()) {
		os << it->second;
	}
	else {
		os << "����������� ���������";
	}
	return os;
}

struct student
{
	string lastName;
	string name;
	string fathName;
	string education;
	BitDate admissionDate;
	int expirience;
	title jobT;
} stud;



void input(student st[], int size) {
	int num;
	int yFac;
	string date;
	cout << "������� ����� ������ (1-10): ";
	cin >> num;
	num--;

	if (num < 0 || num >= size) {
		cout << "�������� ����� ������!" << endl;
		return;
	}

	cout << "������� ���(����� ������): ";
	cin >> st[num].lastName >> st[num].name >> st[num].fathName;

	cout << "������� ���� �����������(�� �� ����): ";
	cin >> st[num].admissionDate;

	cout << "������� �����������: ";
	cin >> st[num].education;

	cout << "�������� ���������(1 - �����������,2 - ������,3 - ��������,4 - �����������): ";
	cin >> yFac;
	st[num].jobT = static_cast<title>(yFac);;

	cout << "������� ����: ";
	cin >> st[num].expirience;
}

void output(student st[], int size) {
	for (int i = 0; i < size; i++) {
		if (st[i].lastName.empty()) continue;
		cout << "����� ������: " << i + 1 << "\n" << "���: " << st[i].lastName << " " << st[i].name << " " << st[i].fathName << " " << "\n" << "���� �����������: "
			<< st[i].admissionDate << "\n" << "�����������: " << st[i].education<< "\n" << "���������: " << st[i].jobT << "\n" << "����: " << st[i].expirience << "\n";
		cout << endl;
	}
}

void search(student st[], int size) {
	string fam;
	cout << "������� �������: ";
	cin >> fam;
	for (int i = 0; i < size; i++) {
		if (fam == st[i].lastName) {
			cout << "����� ������: " << i + 1 << "\n" << "���: " << st[i].lastName << " " << st[i].name << " " << st[i].fathName << " " << "\n" << "���� �����������: "
				<< st[i].admissionDate << "\n" << "�����������: " << st[i].education << "\n" << "���������: " << st[i].jobT << "\n" << "����: " << st[i].expirience << "\n";
			cout << endl;
		}
	}
}

void searchMinBall(student st[], int size) {
	int minBall = 0;
	int mini = 0;
	for (int i = 0; i < size; i++) {
		if (st[i].lastName.empty()) continue;
		if (minBall < st[i].expirience) {
			minBall = st[i].expirience;
			mini = i;
		}
	}
	for (int i = 0; i < size; i++) {
		if (mini == i) {
			cout << "����� ������: " << i + 1 << "\n" << "���: " << st[i].lastName << " " << st[i].name << " " << st[i].fathName << " " << "\n" << "���� �����������: "
				<< st[i].admissionDate << "\n" << "�����������: " << st[i].education<< "\n" << "���������: " << st[i].jobT << "\n" << "����: " << st[i].expirience << "\n";
			cout << endl;
		}
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	student stud[10] = {
	{"������", "����", "��������", "������",{11, 03, 2025}, 1, title::�����������},
		{"������", "����", "��������", "�������",{16, 03, 2025}, 1, title::������},
		{"�������", "������", "���������", "������",{1, 03, 2023}, 3, title::�����������}
	};
	while (true) {
		cout << "1 - ����\n2 - �����\n3 - ��������\n4 - �����\n5 - ����� �� �����\n6 - �����\n�����: ";
		int swap;
		cin >> swap;
		cout << endl;
		switch (swap)
		{
		case 1:input(stud, 10);
			cout << endl;
			break;

		case 2:output(stud, 10);
			break;

		case 3: {
			cout << endl;
			output(stud, 10);
			int index;
			cout << "������� ����� ��������� ��� ��������: ";
			cin >> index;

			if (index < 1 || index > 10) {
				cout << "�������� �����!\n";
				break;
			}

			stud[index - 1] = student{};
			cout << "�������� ������!\n";
			cout << endl;
			break;
		}
		case 4:search(stud, 10);
			cout << endl;
			break;

		case 5: cout << "�������� � ������������ ������:\n";
			searchMinBall(stud, 10);
			cout << endl;
			break;

		case 6:
			return 0;

		default: cout << "�������� ����." << endl;
			break;
		}
	}

}