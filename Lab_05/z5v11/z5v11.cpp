#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

struct Date {
    union {
        struct {
            int day;
            int month;
            int year;
        };
        int dateArray[3];
    };
};

struct Car {
    string name;
    string color;
    string bodyType;
    string owner;
    Date productionDate;
    Date inspectionDate;
};

void inputCar(Car& car) {
    cout << "\n���� ������ �� ����������:\n";
    cout << "�����: ";
    getline(cin, car.name);
    cout << "����: ";
    getline(cin, car.color);
    cout << "��� ������: ";
    getline(cin, car.bodyType);
    cout << "��������: ";
    getline(cin, car.owner);

    cout << "���� ������������ (�� �� ����): ";
    for (int i = 0; i < 3; i++) {
        cin >> car.productionDate.dateArray[i];
    }

    cout << "���� ���������� (�� �� ����): ";
    for (int i = 0; i < 3; i++) {
        cin >> car.inspectionDate.dateArray[i];
    }
    cin.ignore();
}

void printCar(const Car& car) {
    cout << "\n�����: " << car.name
        << "\n����: " << car.color
        << "\n��� ������: " << car.bodyType
        << "\n��������: " << car.owner
        << "\n���� ������������: "
        << car.productionDate.day << "."
        << car.productionDate.month << "."
        << car.productionDate.year
        << "\n���� ����������: "
        << car.inspectionDate.day << "."
        << car.inspectionDate.month << "."
        << car.inspectionDate.year
        << "\n-------------------------\n";
}

void saveToFile(const vector<Car>& cars, const string& filename) {
    ofstream file(filename);
    for (const auto& car : cars) {
        file << car.name << "\n"
            << car.color << "\n"
            << car.bodyType << "\n"
            << car.owner << "\n"
            << car.productionDate.day << " "
            << car.productionDate.month << " "
            << car.productionDate.year << "\n"
            << car.inspectionDate.day << " "
            << car.inspectionDate.month << " "
            << car.inspectionDate.year << "\n";
    }
    file.close();
}

vector<Car> loadFromFile(const string& filename) {
    vector<Car> cars;
    ifstream file(filename);
    if (!file.is_open()) return cars;

    Car temp;
    while (getline(file, temp.name) &&
        getline(file, temp.color) &&
        getline(file, temp.bodyType) &&
        getline(file, temp.owner)) {

        for (int i = 0; i < 3; i++) {
            file >> temp.productionDate.dateArray[i];
        }
        for (int i = 0; i < 3; i++) {
            file >> temp.inspectionDate.dateArray[i];
        }
        file.ignore();
        cars.push_back(temp);
    }
    file.close();
    return cars;
}

void searchByOwner(const vector<Car>& cars, const string& owner) {
    bool found = false;
    for (const auto& car : cars) {
        if (car.owner == owner) {
            printCar(car);
            found = true;
        }
    }
    if (!found) {
        cout << "���������� ��������� " << owner << " �� �������!\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Car> cars;
    string filename = "cars.txt";

    cars = loadFromFile(filename);

    while (true) {
        cout << "\n����:\n"
            << "1 - �������� ����������\n"
            << "2 - �������� ��� ����������\n"
            << "3 - ����� �� ���������\n"
            << "4 - ��������� � ����\n"
            << "5 - ��������� �� �����\n"
            << "6 - �����\n"
            << "�����: ";

        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            Car newCar;
            inputCar(newCar);
            cars.push_back(newCar);
            break;
        }
        case 2: {
            cout << "\n������ �����������:\n";
            for (const auto& car : cars) {
                printCar(car);
            }
            break;
        }
        case 3: {
            string owner;
            cout << "������� ������� ���������: ";
            getline(cin, owner);
            searchByOwner(cars, owner);
            break;
        }
        case 4: {
            saveToFile(cars, filename);
            cout << "������ ��������� � ����!\n";
            break;
        }
        case 5: {
            cars = loadFromFile(filename);
            cout << "������ ��������� �� �����!\n";
            break;
        }
        case 6: {
            return 0;
        }
        default: {
            cout << "�������� �����!\n";
        }
        }
    }
}

