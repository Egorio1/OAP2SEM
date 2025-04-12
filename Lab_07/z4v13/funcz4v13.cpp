#include "Headerz4v13.h"
string filename = "File.txt";

void menu() {
    cout << "1 - �������� � ����\n2 - ��������� �� �����\n3 - �������� �������\n4 - ������� ���������� ���������\n5 - ������� � �����\n6 - �����\n�����: ";
}
void saveInFile(Stack* myStk) {
    ofstream File(filename);
    if (!File.is_open()) {
        cout << "������ �������� �����!" << endl;
        return;
    }

    Stack* current = myStk;
    while (current != NULL) {
        File << current->data << " ";
        current = current->next;
    }

    File.close();
    cout << "���� �������� � ����." << endl << endl;
}

void readFile(Stack*& myStk) {
    ifstream File(filename);
    if (!File.is_open()) {
        cout << "������ �������� �����!" << endl;
        return;
    }

    while (myStk != NULL) {
        Stack* temp = myStk;
        myStk = myStk->next;
        delete temp;
    }
    myStk = NULL;

    int value;
    while (File >> value) {
        Stack* e = new Stack;
        e->data = value;
        e->next = myStk;
        myStk = e;
    }

    File.close();
    cout << "���� �������� �� �����." << endl << endl;
}

void addElem(Stack*& myStk) {
    int x;
    cout << "������� �������: ";
    cin >> x;
    Stack* e = new Stack;

    e->data = x;
    e->next = myStk;
    myStk = e;

    cout << "������� ��������" << endl << endl;
}

int checkDupl(Stack*& myStk) {
    if (myStk == nullptr) {
        cout << "���� ����!" << endl;
        return 0;
    }

    unordered_map<int, int> frequency;
    Stack* tempStack = nullptr;
    int duplicates_count = 0;

    Stack* current = myStk;
    while (current != nullptr) {
        frequency[current->data]++;
        current = current->next;
    }

    for (const auto& pair : frequency) {
        if (pair.second > 1) {
            duplicates_count++;
        }
    }

    current = myStk;
    while (current != nullptr) {
        Stack* next = current->next;
        current->next = tempStack;
        tempStack = current;
        current = next;
    }

    myStk = tempStack;
    return duplicates_count;
}

int deleteSt(Stack*& myStk) {
    if (myStk == NULL) {
        cout << "���� ����!" << endl;
        return -1;
    }
    else {
        Stack* e = myStk;
        int x = myStk->data;
        myStk = myStk->next;
        delete e;
        return x;
    }
}

void clearSt(Stack*& myStk) {
    if (myStk == NULL) {
        cout << "���� ����!" << endl;
        return;
    }

    cout << "���������� �����: ";
    while (myStk != NULL) {
        cout << deleteSt(myStk) << " ";
    }
    cout << endl << "���� ������." << endl << endl;
}
