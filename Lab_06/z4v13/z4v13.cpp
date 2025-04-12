#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

struct list {
    int symbol;
    list* next;
};

void insert(list*& p, int value) {
    list* newP = new list;
    newP->symbol = value;
    newP->next = p;
    p = newP;
}

void delElem(list*& p) {
    if (p == nullptr) {
        cout << "������ ����!" << endl;
        return;
    }

    int value;
    cout << "������� ��������� �����: ";
    cin >> value;

    if (p->symbol == value) {
        list* temp = p;
        p = p->next;
        delete temp;
        return;
    }

    list* current = p;
    while (current->next != nullptr) {
        if (current->next->symbol == value) {
            list* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }

    cout << "������� �� ������!" << endl;
}

void searchElem(list* p) {
    int sumValue = 0;
    while (p != NULL) {
        if (p->symbol < -9 && p->symbol > -100) {
            sumValue += p->symbol;
        }
        p = p->next;
    }
    if (sumValue != 0) {
        cout << "����� ������������� ����������� ���������: " << sumValue << endl;
    }
    else {
        cout << "����� ��������� ���" << endl;
    }
}

void printList(list* p) {
    if (p == NULL) {
        cout << endl << "������ ����." << endl << endl;
    }
    else {
        cout << "������: ";
        while (p != NULL) {
            cout << p->symbol << " ";
            p = p->next;
        }
        cout << endl;
    }
}

void printFile(list* p) {
    ofstream File("File.txt");
    while (p != nullptr) {
        File << p->symbol << endl;
        p = p->next;
    }
    cout << endl << "������ �������� � ����." << endl << endl;
    File.close();
}

void readFile(list*& p) {
    ifstream File("File.txt");
    if (!File.is_open()) {
        cout << "������ �������� �����!" << endl;
        return;
    }

    while (p != nullptr) {
        list* temp = p;
        p = p->next;
        delete temp;
    }

    list** tail = &p;
    string line;
    while (getline(File, line)) {
        *tail = new list{ stoi(line), nullptr };
        tail = &((*tail)->next);
    }

    File.close();
    cout << "������ ������� ���������" << endl;
}

void menu() {
    cout << "1 - �������� �������\n2 - ������� �������\n3 - C���� ������������� ����������� ���������\n4 - ����� ������\n5 - �������� � ����\n6 - ��������� �� �����\n7 - �����\n�����: ";
}

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list* first = nullptr;
    int choise;
    int value;

    while (true) {
        menu();
        cin >> choise;
        switch (choise) {
        case 1: {
            cout << "������� �����: ";
            cin >> value;
            insert(first, value);
            cout << endl << "����� ���������" << endl << endl;
            break;
        }
        case 2: {
            delElem(first);
            break;
        }
        case 3: {
            searchElem(first);
            break;
        }
        case 4: {
            printList(first);
            break;
        }
        case 5: {
            printFile(first);
            break;
        }
        case 6: {
            readFile(first);
            break;
        }
        case 7: {
            while (first != nullptr) {
                list* temp = first;
                first = first->next;
                delete temp;
            }
            return 0;
        }
        }
    }
}