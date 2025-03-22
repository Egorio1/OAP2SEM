#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct sanatorium{
	string nameSanatorium;
	string locate;
	string treatment;
	int quantityPack;
};

bool compareSanatorium(const sanatorium& a, const sanatorium& b) {
	if (a.treatment == b.treatment) {
		return a.nameSanatorium < b.nameSanatorium;
	}
	else {
		return a.treatment < b.treatment;
	}
}

void printInfo(sanatorium data[], int size) {
	sort(data, data + size, compareSanatorium);
	int a = 1;
	string currentTreatment = "";
	for (int i = 0; i < size; i++) {
		a++;
		currentTreatment = data[i].treatment;
		for (int j = 0; j < size; j++) {
			
			if (currentTreatment == data[j].treatment && a!=3) {
					cout << data[j].nameSanatorium << "\t" << data[j].locate << "\t" << data[j].quantityPack << endl;
			}
		}
		if (a != 3) {
			cout << data[i].treatment << endl;
			cout << "------------------------------------" << endl;
		}
	}
}

int checkInfo(sanatorium data[], int size) {
	int sw;

	while (true) {
		cout << "1 - ��������� �������, 2 - ������������, 3 - �������� �������, 4 - �����: ";
		cin >> sw;
		bool yessn = false;
		switch (sw) {
		case 1: {
			for (int i = 0; i < size; i++) {
				if (data[i].quantityPack > 1) {
					cout << data[i].nameSanatorium << "\t" << data[i].locate << "\t" << data[i].quantityPack <<"\t" << data[i].treatment << endl;
					yessn = true;
				}
			}
			if (!yessn) {
				cout << "��� ���������� �� ���������� ����������" << endl;
			}
			break;
		}

		case 2: {
			string curLocate;
			bool yessn = false;
			cout << "������� �������������� ����� ������������ ���������(�����, ������, ������, �������): ";
			cin >> curLocate;
			for (int i = 0; i < size; i++) {
				if (curLocate == data[i].locate) {
					cout << data[i].nameSanatorium << "\t" << data[i].locate << "\t" << data[i].quantityPack << "\t" << data[i].treatment << endl;
					yessn = true;
				}
			}
			if (!yessn) {
				cout << "��� ���������� �� ���������� ����������" << endl;
			}
			break;
		}

		case 3: {
			string curTreatment;
			bool yessn = false;
			cout << "������� �������� �������(���������, ������, �����������): ";
			cin >> curTreatment;
			for (int i = 0; i < size; i++) {
				if (curTreatment == data[i].treatment) {
					cout << data[i].nameSanatorium << "\t" << data[i].locate << "\t" << data[i].quantityPack << "\t" << data[i].treatment << endl;
					yessn = true;
				}
			}
			if (!yessn) {
				cout << "��� ���������� �� ���������� ����������" << endl;
			}
			break;
		}

		case 4: {
			return 0;
		}

		}
	}
}

int main() {
 	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int sw;
	sanatorium info[4] = {
		{"���1", "�����", "���������", 0},
		{"���2", "������", "������", 10},
		{"���4", "�������", "������", 32},
		{"���3", "������", "�����������", 14},
	};
	while (true) {
		cout << "1 - ���������� � ���� ����������, 2 - ����� ���������� �� ����������, 3 - �����: ";
		cin >> sw;
		switch (sw) {
		case 1: {
			printInfo(info, 4);
			break;
		}

		case 2: {
			checkInfo(info, 4);
			break;
		}

		case 3: {
			return 0;
		}
		}
	}
	
}