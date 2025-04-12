#include "Headerz4v11.h"
string filename = "File.txt";

void menu() {
	cout << "1 - �������� � ����\n2 - ��������� �� �����\n3 - �������� �������\n4 - �������� ��������� ������� 3\n5 - ������� � �����\n6 - �����\n�����: ";
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

void deleteElemThi(Stack*& myStk) {
    Stack* current = myStk;
    Stack* prev = NULL;
    bool deleted = false;

    while (current != NULL) {
        if (current->data % 3 == 0) {
            Stack* temp = current;
            if (prev == NULL) {
                myStk = current->next;
            }
            else {
                prev->next = current->next;
            }
            current = current->next;
            delete temp;
            deleted = true;
        }
        else {
            prev = current;
            current = current->next;
        }
    }

    if (deleted) {
        cout << "��������, ������� 3, �������." << endl << endl;
    }
    else {
        cout << "���������, ������� 3, �� �������." << endl << endl;
    }
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
