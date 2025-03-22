#include <iostream>
#include <string>
#include <fstream>
#include <io.h>
#include <fcntl.h>

using namespace std;

struct TRAIN
{
	int numTrain;
	string finalPunkt;
	string time;
};

void changeInfo(TRAIN data[]) {
	int num = 0;
	string finalPunkt = "";
	string time = "";
	
	int changeNum;
	cout << "������� ����� ������ ��� ��������� ����������: " ; 
	cin >> changeNum;

	for (changeNum; changeNum <= 8; changeNum++) {
		
		cout << "������� ����� ����� ������: ";
		cin >> num;

		cout << "������� ����� ���������� ������: ";
		cin >> finalPunkt;

		cout << "������� ����� ������(hh:mm): ";
		cin >> time;

		data[changeNum] = { num, finalPunkt, time };
		break;
	}
}

void printTrain(TRAIN data[]) {

	string currentTime;
	cout << "������� ������� �����(hh:mm): ";
	cin >> currentTime;
	int currentHours = atoi(currentTime.substr(0, 2).c_str());
	int currentMinutes = atoi(currentTime.substr(3, 2).c_str());

	int count = 0;
	for (int i = 0; i < 8; i++) {
		int trainHours = atoi(data[i].time.substr(0, 2).c_str());
		int trainMinutes = atoi(data[i].time.substr(3, 2).c_str());
		
		if (trainHours > currentHours) {
			count++;
			cout << "����� #" << data[i].numTrain << " � " << data[i].finalPunkt <<
				" ������������ � " << data[i].time << endl;
		}

		else if (trainHours == currentHours) {
			if (trainMinutes >= currentMinutes) {
				cout << "����� #" << data[i].numTrain << " � " << data[i].finalPunkt <<
					" ������������ � " << data[i].time << endl;
				count++;
			}
		}
	}
	if (count == 0) {
		cout << "��� �������." << endl;
	}
}
int main() {
	setlocale(LC_ALL, "RU");

	int sw;
		struct TRAIN tr;
			TRAIN trainList[8] = {
			{1,"�����", "17:00"},
			{2,"�������", "16:00"},
			{3,"������", "14:00"},
			{4,"������", "12:00"},
			{5,"�����������", "15:00"},
			{6,"�������", "13:00"},
			{7,"������", "11:00"},
			{8,"����� ���������", "18:00"}
			};
			while (true) {
				cout << "1 - ���������� ���������� � �������, 2 - �������� �����, 3 - �����."; cin >> sw;
				switch (sw) {
				case 1: {
					printTrain(trainList);
					break;
				}
				case 2: {
					changeInfo(trainList);
					break;
			    }
				case 3: {
					return 0;
				}
		}
	}
}