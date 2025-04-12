#include "Headerz4v15.h"
string filename = "File.txt";

void menu() {
    cout << "1 - �������� � ����\n2 - ��������� �� �����\n3 - �������� �������\n4 - �������� �������� �����\n5 - ������� � �����\n6 - �����\n�����: ";
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
        cout << "���� ����!" << endl << endl;
        return 0;
    }

    vector<int> elements;
    Stack* current = myStk;
    while (current != nullptr) {
        elements.push_back(current->data);
        current = current->next;
    }

    unordered_map<int, int> freq;
    int target = -1;

    for (int i = elements.size() - 1; i >= 0; i--) {
        freq[elements[i]]++;
        if (freq[elements[i]] > 1) {
            target = elements[i];
        }
    }

    if (target == -1) {
        cout << "��������� �� �������!" << endl << endl;
        return 0;
    }

    bool isRemoved = false;
    vector<int> newElements;
    for (int elem : elements) {
        if (!isRemoved && elem == target) {
            isRemoved = true;
            continue;
        }
        newElements.push_back(elem);
    }

    while (myStk != nullptr) {
        Stack* temp = myStk;
        myStk = myStk->next;
        delete temp;
    }

    for (auto it = newElements.rbegin(); it != newElements.rend(); ++it) {
        Stack* e = new Stack;
        e->data = *it;
        e->next = myStk;
        myStk = e;
    }

    cout << "������ ������������� ������� '" << target << "' ������" << endl << endl;
    return 0;
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
