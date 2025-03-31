#include <iostream>
#include <string>
#include <Windows.h>
#include <map>
#include <iomanip>

using namespace std;

struct BitDate {
	int lastKonk;

	BitDate(int lk = 0):lastKonk(lk){}

	bool operator<(const BitDate& other) const {
		return lastKonk < other.lastKonk;
	}
};

istream& operator>>(istream& is, BitDate& bd) {
	int lk;
	is >> lk;

	if (!is) return is;

	bd.lastKonk = lk;
	return is;
}

ostream& operator<<(ostream& os, const BitDate& bd) {
	os << setw(2) << setfill('0') << bd.lastKonk;
	return os;

}
enum class Spec {
	�� = 1, ����, ��,
} speciality;

const map<Spec, string> facultyNames = {
	{Spec::��, "��"},
	{Spec::����, "����"},
	{Spec::��, "��"}
};

ostream& operator<<(ostream& os, const Spec& speciality) {
	auto it = facultyNames.find(speciality);
	if (it != facultyNames.end()) {
		os << it->second;
	}
	else {
		os << "����������� ���������";
	}
	return os;
}

struct Usniversity
{
	string nameUn;
	string addres;
	Spec speciality;
	string payment;
	BitDate conk;
	bool operator<(const Usniversity& other) const {
		return conk < other.conk;
	}
} stud;

void input(Usniversity un[], int size) {
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

	cout << "������� �������� ������������: ";
	cin >> un[num].nameUn;

	cout << "������� ������: ";
	cin >> un[num].addres;

	cout << "�������� ������������(1 - ��, 2 - ����, 3 - ��): ";
	cin >> yFac;
	un[num].speciality = static_cast<Spec>(yFac);

	cout << "������� ��������� ��������: ";
	cin >> un[num].payment;

	cout << "������� ����: ";
	cin >> un[num].conk;
}

void output(Usniversity un[], int size) {
	for (int i = 0; i < size; i++) {
		if (un[i].nameUn.empty()) continue;
		cout << "����� ������: " << i + 1 << "\n" << "�������� ������������: " << un[i].nameUn<< "\n" << "������: "
			<< un[i].addres<< "\n" << "�������� �������������: " << un[i].speciality<< "\n" << "���������� �������� " <<
			un[i].payment << "\n" << "����: " << un[i].conk << "\n";
		cout << endl;
	}
}

void search(Usniversity un[], int size) {
	string fam;
	cout << "������� �������� ������������: ";
	cin >> fam;
	for (int i = 0; i < size; i++) {
		if (fam == un[i].nameUn) {
			cout << "����� ������: " << i + 1 << "\n" << "�������� ������������: " << un[i].nameUn << "\n" << "������: "
				<< un[i].addres << "\n" << "�������� �������������: " << un[i].speciality << "\n" << "���������� �������� " <<
				un[i].payment << "\n" << "����: " << un[i].conk << "\n";
		}
	}
}

void searchMinBall(Usniversity un[], int size) {
	Usniversity* minUn = nullptr;
	for (int i = 0; i < size; i++) {
		if (!un[i].nameUn.empty()) {
			minUn = &un[i];
			break;
		}
	}
	if (!minUn) return; 

	for (int i = 0; i < size; i++) {
		if (!un[i].nameUn.empty() && un[i] < *minUn) {
			minUn = &un[i];
		}
	}

	cout << "����� ������: " << (minUn - un) + 1 << "\n"
		<< "��������: " << minUn->nameUn << "\n"
		<< "�����: " << minUn->addres << "\n"
		<< "�������������: " << minUn->speciality << "\n"
		<< "��������� ��������: " << minUn->payment << "\n"
		<< "����: " << minUn->conk << "\n";
}



int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Usniversity stud[10] = {
	{"����", "�����", Spec::��,"2000", 360},
		{"����", "������", Spec::��,"2000", 300},
		{"�����", "�����", Spec::��,"2000", 395}
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
			cout << "������� ����� ������������ ��� ��������: ";
			cin >> index;

			if (index < 1 || index > 10) {
				cout << "�������� �����!\n";
				break;
			}

			stud[index - 1] = Usniversity{};
			cout << "����������� ������!\n";
			cout << endl;
			break;
		}
		case 4:search(stud, 10);
			cout << endl;
			break;

		case 5: cout << "����������� � ����������� ����������� ������:\n";
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
