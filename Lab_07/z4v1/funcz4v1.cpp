#include "Headerz4v1.h"
string filename = "File.txt";

void menu() {
    cout << "1 - �������� � ����\n2 - ��������� �� �����\n3 - �������� �������\n4 - ����������� �����\n5 - ������� � �����\n6 - �����\n�����: ";
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
void Push(Stack*& top, int data) {
    Stack* newNode = new Stack;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int refreshStack(Stack*& myStk) {
    if (myStk == nullptr) {
        cout << "���� ����!" << endl << endl;
        return 0;
    }

    Stack* Positive = nullptr;
    Stack* Negative = nullptr;

    while (myStk != nullptr) {
        int x = deleteSt(myStk);
        if (x >= 0) {
            Push(Positive, x);
        }
        else {
            Push(Negative, x);
        }
    }

    cout << "���������� �������������� �����: ";

    while (Positive != nullptr) {
        int x = deleteSt(Positive);
        cout << x << " ";
    }
    cout <<endl << "���������� �������������� �����: ";
    while (Negative != nullptr) {
        int x = deleteSt(Negative);
        cout << x << " ";
    }

    cout << endl << endl;
    return 1;
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
