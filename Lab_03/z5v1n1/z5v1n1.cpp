#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	ifstream File1("FILE1.txt");
	ofstream File2("FILE2.txt");
	string line;
	int i = 1;
	int sizeFile1 = 0; 
	int sizeFile2 = 0; 

	while (getline(File1, line)) {
		if (i % 2 == 0) {
			File2 << line << endl;
			for (int j = 0; j < size(line); j++) {
				sizeFile1++;
				
			}
			sizeFile1+=2;
		}
		i++;
		for (int j = 0; j < size(line); j++) {
			sizeFile2++;
			
		}
		sizeFile2+=2;
	}

	cout << "������ ����������." << endl;
	cout << "���� 2 �������� " << sizeFile1 << " ����" << endl;
	cout << "���� 1 �������� " << sizeFile2 << " ����" << endl;
}