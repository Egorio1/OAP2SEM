
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    
    string str;
    cout << "������� ������: ";
    getline(cin, str);

    ofstream outFile("File.txt");
    if (!outFile.is_open()) {
        cout << "�� ������� ������� ���� ��� ������." << endl;
        return 1;
    }
    outFile << str;
    outFile.close();

    ifstream inFile("File.txt");
    if (!inFile.is_open()) {
        cout << "�� ������� ������� ���� ��� ������." << endl;
        return 1;
    }

    string fileContent;
    getline(inFile, fileContent);
    inFile.close();

    istringstream iss(fileContent);
    string word;

    cout << "�����, ���������� ����� '�':" << endl;
    while (iss >> word) {
        if (word.find('x') != string::npos || word.find('X') != string::npos) {
            cout << word << endl;
        }
    }

    return 0;
}