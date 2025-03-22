#include <iostream>
#include <string>
#include <fstream>
#include <Tchar.h>
#include <Windows.h>

using namespace std;

typedef int day;
typedef int month;

struct date
{
    day dd;
    month mm;

    bool operator==(const date& other) const {
        return mm == other.mm && dd == other.dd;
    }
};

struct dannye
{
    string fam;
    string name;
    string otch;
    string street;
    string home;
    string house;
    string number;
    string work;
    string dol;
    date birthDate;
};

void printPerson(const dannye& person) {
    cout << "�.�.�: " << person.fam << " " << person.name << " " << person.otch << endl
        << "���� ��������: " << person.birthDate.dd << "." << person.birthDate.mm << endl
        << "�����: ��. " << person.street << " �. " << person.home << " ��. " << person.house << endl
        << "�������: " << person.number << endl
        << "����� ������: " << person.work << endl
        << "���������: " << person.dol << endl;
}

void saveToFile(const dannye& person) {
    ofstream file("File.txt", ios::app);
    file << person.fam << "|" << person.name << "|" << person.otch << "|"
        << person.birthDate.dd << "|" << person.birthDate.mm << "|"
        << person.street << "|" << person.home << "|" << person.house << "|"
        << person.number << "|" << person.work << "|" << person.dol << endl;
    file.close();
}

void searchInFile(const string& filename, const string& fam) {
    ifstream file(filename);
    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t pos = line.find(fam + "|");
        if (pos == 0) {
            dannye person;
            size_t start = 0;
            size_t end = line.find('|');

            person.fam = line.substr(start, end);
            start = end + 1;

            end = line.find('|', start);
            person.name = line.substr(start, end - start);
            start = end + 1;

            end = line.find('|', start);
            person.otch = line.substr(start, end - start);
            start = end + 1;

            end = line.find('|', start);
            person.birthDate.dd = stoi(line.substr(start, end - start));
            start = end + 1;

            end = line.find('|', start);
            person.birthDate.mm = stoi(line.substr(start, end - start));
            start = end + 1;

            end = line.find('|', start);
            person.street = line.substr(start, end - start);
            start = end + 1;

            end = line.find('|', start);
            person.home = line.substr(start, end - start);
            start = end + 1;

            end = line.find('|', start);
            person.house = line.substr(start, end - start);
            start = end + 1;

            end = line.find('|', start);
            person.number = line.substr(start, end - start);
            start = end + 1;

            end = line.find('|', start);
            person.work = line.substr(start, end - start);
            start = end + 1;

            person.dol = line.substr(start);

            printPerson(person);
            found = true;
            break;
        }
    }

    if (!found) cout << "������ �� �������!" << endl;
    file.close();
}

void deleteFromFile(const string& filename, const string& fam) {
    ifstream inFile(filename);
    ofstream outFile("temp.txt");
    string line;
    bool deleted = false;

    while (getline(inFile, line)) {
        if (line.find(fam + "|") != 0) {
            outFile << line << endl;
        }
        else {
            deleted = true;
        }
    }

    inFile.close();
    outFile.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    if (!deleted) cout << "������ �� �������!" << endl;
}

int main(int argc, _TCHAR* argv[]) {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    date currentDate;
    cout << "������� ���� (�� ��): ";
    cin >> currentDate.dd >> currentDate.mm;

    while (true) {
        cout << "\n1 - ��������\n2 - �����\n3 - �������\n4 - �����\n �����: ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            dannye person;
            cout << "�������: "; getline(cin, person.fam);
            cout << "���: "; getline(cin, person.name);
            cout << "��������: "; getline(cin, person.otch);
            cout << "���� ��������: "; cin >> person.birthDate.dd;
            cout << "����� ��������: "; cin >> person.birthDate.mm;
            cin.ignore();
            cout << "�����: "; getline(cin, person.street);
            cout << "���: "; getline(cin, person.home);
            cout << "��������: "; getline(cin, person.house);
            cout << "�������: "; getline(cin, person.number);
            cout << "����� ������: "; getline(cin, person.work);
            cout << "���������: "; getline(cin, person.dol);

            saveToFile(person);

            if (currentDate == person.birthDate) {
                cout << "\n!!! � ���� ��������, " << person.fam << " " << person.name << " !!!\n";
            }
        }
        else if (choice == 2) {
            string fam;
            cout << "����� �������: ";
            getline(cin, fam);
            searchInFile("File.txt", fam);
        }
        else if (choice == 3) {
            string fam;
            cout << "������� �������: ";
            getline(cin, fam);
            deleteFromFile("File.txt", fam);
        }
        else if (choice == 4) {
            break;
        }
    }
    return 0;
}