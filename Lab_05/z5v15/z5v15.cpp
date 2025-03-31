#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

struct number {
    union {
        struct {
            int contest;
            int payment;
        };
        int num[2];
    };
};

struct info {
    string nameUn;
    string addres;
    string speciality;
    number numInfo;
};

const int MAX = 10;

void addUn(info date[], int& count) {
    if (count >= MAX) {
        cout << "��������� �������� �������!\n";
        return;
    }

    cout << "�����������: ";
    cin >> date[count].nameUn;
    cout << "�����������������: ";
    cin >> date[count].addres;
    cout << "�������������: ";
    cin >> date[count].speciality;

    cout << "��������� ����: ";
    cin >> date[count].numInfo.contest;
    cout << "���������: ";
    cin >> date[count].numInfo.payment;

    count++;
}

void printInfo(info date[], int count) {
    for (int i = 0; i < count; i++) {
        cout << "#" << i + 1 << endl;
        cout << "�����������: " << date[i].nameUn << endl;
        cout << "�����������������: " << date[i].addres << endl;
        cout << "�������������: " << date[i].speciality << endl;
        cout << "��������� ���: " << date[i].numInfo.contest << endl;
        cout << "���������: " << date[i].numInfo.payment << endl;
        cout << "-------------------------------------------------" << endl;
    }
 }

void loadFromFile(info date[], int &count) {
    ifstream f("university.txt");

    while (count < MAX&&
        getline(f, date[count].nameUn) &&
        getline(f, date[count].addres) &&
        getline(f, date[count].speciality)) {

        f >> date[count].numInfo.contest;
        f >> date[count].numInfo.payment;
        f.ignore();
        count++;
    }
    f.close();
}


void checkContest(info date[], int count) {
    int constContest = 400;
    string constUn;

    for (int i = 0; i < count; i++) {
        if (date[i].numInfo.contest < constContest) {
            constContest = date[i].numInfo.contest;
            constUn = date[i].nameUn;
        }
    }
    cout << "����������� � ���������� ��������� ������: " << constUn << ": " << constContest << endl;
}

void inFile(info date[], int count) {
    ofstream File("university.txt");
    File.is_open();
    for (int i = 0; i < count; i++) {
        
        File  << date[i].nameUn << endl;
        File << date[i].addres << endl;
        File << date[i].speciality << endl;
        File << date[i].numInfo.contest << endl;
        File << date[i].numInfo.payment << endl;
        
    }
    File.close();
}

int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    
    int count = 0;
    info university[MAX];
    

    while (true) {
        int sw;
        cout << "1 - ����� ����������\n2 - ����� �� ������������ �����\n3 - �������� � ����\n4 - ��������� �� �����\n5 - ��������\n6 - �����\n�����: ";
        cin >> sw;
        cout << endl;
        switch (sw) {

     case 1:  printInfo(university, count); break;
     case 2: checkContest(university, count); break;
     case 3: inFile(university, count); cout << "������ ��������." << endl; break;
     case 4: loadFromFile(university, count); cout << "������ ���������." << endl; break;
     case 5: addUn(university, count);break;
     case 6: return 0;
    }
        cout << endl;
}
}