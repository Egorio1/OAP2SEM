#include <string>
#include <iostream>
#include <fstream>
using namespace std;
void write(string&line) {
	ofstream File("File.txt");
	File << line << endl;
	File.close();
	cout << "������ ������� �������� � ����." << endl;
}
string read(string&line, string &content) {
	ifstream File("File.txt");
	File.is_open();
	File.close();
	return content;
	cout << "������ ������� ��������� �� �����" << endl;
}	
int main() {
	setlocale(LC_ALL, "Ru");
	string line;
	int krsk = 0, kvsk = 0, fgsk = 0;
	cout << "������� ������ �������� ��������� �� ���� � ������" << endl;
	getline(cin, line);
	write(line);
	string content = read(line, content);
	int roundBrack = 0; 
	int squareBrack = 0; 
	int curlyBrack = 0; 

	for (char ch : line) {
		if (ch == '(' || ch == ')') {
			roundBrack++;
		}
		else if (ch == '[' || ch == ']') {
			squareBrack++;
		}
		else if (ch == '{' || ch == '}') {
			curlyBrack++;
		}
	}
	cout << "���������� ������� ������ (): " << roundBrack << endl;
	cout << "���������� ���������� ������ []: " << squareBrack << endl;
	cout << "���������� �������� ������ {}: " << curlyBrack << endl;
}