#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Lombard {
    string lastName;
    string productName;
    int gradePrice;
    double loanAmount;
    int storagePeriod;

    struct {
        int day : 5;
        int month : 4;
        int year : 7;
    } date;

    bool isExpired(int currentDay, int currentMonth, int currentYear) const {
        int endYear = date.year + 2000;
        int endMonth = date.month;
        int endDay = date.day + storagePeriod;

        while (endDay > 31) {
            endDay -= 31;
            endMonth++;
            if (endMonth > 12) {
                endMonth = 1;
                endYear++;
            }
        }

        if (endYear < currentYear) return true;
        if (endYear == currentYear && endMonth < currentMonth) return true;
        if (endYear == currentYear && endMonth == currentMonth && endDay < currentDay) return true;
        return false;
    }
};

void printItem(Lombard items[], int size, int currentDay, int currentMonth, int currentYear) {
    for (int i = 0; i < size; i++) {
        if (items[i].lastName.empty()) continue;

        cout << "����� #" << i + 1 << endl;
        cout << "������� �������: " << items[i].lastName << endl;
        cout << "������������ ������: " << items[i].productName << endl;
        cout << "��������� ���������: " << items[i].gradePrice << endl;
        cout << "����� ��� �����: " << items[i].loanAmount << endl;
        cout << "���� �����: " << items[i].date.day << "."
            << items[i].date.month << "."
            << (items[i].date.year + 2000) << endl;
        cout << "���� ��������: " << items[i].storagePeriod << " ����" << endl;
        cout << "������: "
            << (items[i].isExpired(currentDay, currentMonth, currentYear) ? "���������" : "� ��������")
            << "\n-------------------------" << endl;
    }
}

void searchExpired(Lombard items[], int size, int currentDay, int currentMonth, int currentYear) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (items[i].isExpired(currentDay, currentMonth, currentYear)) {
            if (items[i].lastName.empty()) continue;
            cout << "����� #" << i + 1 << endl;
            cout << "������� �������: " << items[i].lastName << endl;
            cout << "������������ ������: " << items[i].productName << endl;
            cout << "���� ��������� ��������: "
                << (items[i].date.day + items[i].storagePeriod) % 31 << "."
                << (items[i].date.month + (items[i].date.day + items[i].storagePeriod) / 31) % 12 << "."
                << (currentYear + (items[i].date.month + (items[i].date.day + items[i].storagePeriod) / 31) / 12) << endl;
                cout << "-------------------------" << endl;
                found = true;
        }
    }
    if (!found) cout << "������������ ������� ���!\n";
}



void searchByName(Lombard items[], int size, int currentDay, int currentMonth, int currentYear) {
    string name;
    cout << "������� �������� ������: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (items[i].productName == name && !items[i].lastName.empty()) {
            cout << "����� #" << i + 1 << endl;
            cout << "������� �������: " << items[i].lastName << endl;
            cout << "��������� ���������: " << items[i].gradePrice << endl;
            cout << "���� ��������� ��������: "
                << (items[i].date.day + items[i].storagePeriod) % 31 << "."
                << (items[i].date.month + (items[i].date.day + items[i].storagePeriod) / 31) % 12 << "."
                << (currentYear + (items[i].date.month + (items[i].date.day + items[i].storagePeriod) / 31) / 12) << endl;
            cout << "-------------------------" << endl;
            found = true;
        }
    }
    if (!found) cout << "����� �� ������!\n";
}

void inputItem(Lombard items[], int size, int currentDay, int currentMonth, int currentYear) {

    int num;

    cout << "������� ����� ������ ������� �� ������ ��������: "; cin >> num;

    for (int i = 0; i < size; i++) {
        {
            if (i = num - 1)
                cout << "\n=== ���� ������ ������ ===" << endl;
            cout << "������� �������: ";
            cin >> items[i].lastName;
            cout << "������������ ������: ";
            cin >> items[i].productName;
            cout << "��������� ���������: ";
            cin >> items[i].gradePrice;
            cout << "����� ��� �����: ";
            cin >> items[i].loanAmount;
            cout << "���� �������� (����): ";
            cin >> items[i].storagePeriod;

            items[i].date.day = currentDay;
            items[i].date.month = currentMonth;
            items[i].date.year = currentYear - 2000;

            cout << "����� ������� ��������!" << endl;
            break;
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Lombard items[5] = {
        {"������", "����", 10000, 5000, 30, {11, 3, 25}},
        {"�������", "�������", 15000, 8000, 30, {13, 2, 25}},
        {"������", "�������", 30000, 20000, 60, {1, 1, 25}}
    };

    int currentDay, currentMonth, currentYear;
    cout << "������� ������� ���� (�� �� ��): ";
    cin >> currentDay >> currentMonth >> currentYear;
    currentYear += 2000;

    while (true) {
        cout << "\n����:\n"
            << "1 - �������� ��� ������\n"
            << "2 - ����� ������������\n"
            << "3 - ������� �����\n"
            << "4 - ����� �� ��������\n"
            << "5 - �������� �����\n"
            << "6 - �����\n"
            << "�����: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            printItem(items, 5, currentDay, currentMonth, currentYear);
            break;

        case 2:
            searchExpired(items, 5, currentDay, currentMonth, currentYear);
            break;

        case 3: {
            printItem(items, 5, currentDay, currentMonth, currentYear);
            int index;
            cout << "������� ����� ������ ��� ��������: ";
            cin >> index;

            if (index < 1 || index > 5) {
                cout << "�������� �����!\n";
                break;
            }

            items[index - 1] = Lombard{};
            cout << "����� ������!\n";
            break;
        }

        case 4:
            searchByName(items, 5, currentDay, currentMonth, currentYear);
            break;

        case 5:
            inputItem(items, 5,currentDay, currentMonth, currentYear);
            break;

        case 6:
            return 0;

        default:
            cout << "�������� �����!\n";
        }
    }
}