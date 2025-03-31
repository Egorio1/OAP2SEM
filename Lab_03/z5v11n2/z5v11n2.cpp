#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
void writeToFile(const string& filename, const string& firstline, const string& secondline) {
    ofstream file(filename);
    file.is_open();
        file << firstline << endl << secondline;
        file.close();
        cout << "������ ������� �������� � ����" << endl;
}
void readFromFile(const string& filename, string& firstline, string& secondline) {
    ifstream file(filename);
    file.is_open();
        getline(file, firstline);
        getline(file, secondline);
        file.close();
        cout << "������ ������� ��������� �� �����"<< endl;
}
string findShortestWord(const string& line) {
    stringstream ss(line);
    string word, shortestWord;
    size_t minLength = SIZE_MAX;
    while (ss >> word) {
        if (word.length() < minLength) {
            minLength = word.length();
            shortestWord = word;
        }
    }
    return shortestWord;
}
string findLongestWord(const string& line) {
    stringstream ss(line);
    string word, longestWord;
    size_t maxLength = 0;

    while (ss >> word) {
        if (word.length() > maxLength) {
            maxLength = word.length();
            longestWord = word;
        }
    }
    return longestWord;
}
int countVowels(const string& word) {
    const string vowels = "aouieyAOUIEY";
    int count = 0;
    for (char ch : word) {
        if (vowels.find(ch) != string::npos) {
            count++;
        }
    }
    return count;
}

int main() {
    setlocale(LC_ALL, "RU");
    string firstline, secondline;
    cout << "������� ������ ������: ";
    getline(cin, firstline);
    cout << "������� ������ ������: ";
    getline(cin, secondline);
    writeToFile("File.txt", firstline, secondline);
    string fileFirstline, fileSecondline;
    readFromFile("File.txt", fileFirstline, fileSecondline);
    string shortestWord = findShortestWord(fileFirstline);
    cout << "����� �������� ����� � ������ ������: " << shortestWord << endl;
    string longestWord = findLongestWord(fileSecondline);
    cout << "����� ������� ����� �� ������ ������: " << longestWord << endl;
    int vowelsInShortest = countVowels(shortestWord);
    cout << "���������� ������� ���� � ����� �������� ����� ������ ������: " << vowelsInShortest << endl;
    int vowelsInLongest = countVowels(longestWord);
    cout << "���������� ������� ���� � ����� ������� ����� ������ ������: " << vowelsInLongest << endl;
    ofstream file("File.txt");
    if (file.is_open()) {
        file << endl << "����� �������� ����� ������ ������: " << shortestWord << endl;
        file << "����� ������� ����� ������ ������: " << longestWord << endl;
        file << "���������� ������� ���� � ����� �������� ����� ������ ������: " << vowelsInShortest << endl;
        file << "���������� ������� ���� � ����� ������� ����� ������ ������: " << vowelsInLongest << endl;
        file.close();
        cout << "���������� ������� �������� � ����." << endl;
    }
    else {
        cout << "������ �������� ����� ��� ������ �����������." << endl;
    }

    return 0;
}