#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

int openFile(string path) {
	ifstream inputFile(path);//создаем обьект по имени inputFile значением которого является наш файл который лежит по полному пути path, создаем через ifstream так как нам нужно только чтение
	if (!inputFile) {
		cout << "\x1b[31m Something went wrong, file: " << path << endl;
		Sleep(2000);
		return 0;
	}
	string line;
	while (getline(inputFile, line)) {// выводим все строки из файла
		cout << line << endl;
	}
	inputFile.close();

	cout << "Do you want to re-written something? " << endl;
	cout << "[1] YES" << endl;
	cout << "[2] NO" << endl;
	cout << "Choise> ";

	int chs;
	cin >> chs;
	system("cls");
	if (chs == 2) {
		return 0;
	}
	else if (chs == 1) {

		ofstream outputFile(path, ios::app);//создаем файл outputFile который хранит значение файла по пути path, ios::app пишется для того чтобы в ффайл можно было дозаписать информацию
		if (outputFile.is_open()) {
			string addInfo;//добавляемая инфа 
			cout << "Enter info for additional> ";
			cin.ignore();//чистим буфер ввода
			getline(cin, addInfo);//вводим добавляемую инфу
			outputFile << addInfo << endl;//пихаем записанную инфу в файл
			outputFile.close();
			std::cout << "\x1b[32m File: " << path << " is re-written!!\x1b[37m" << std::endl;
		}
		else {
			std::cout << "\x1b[31m Something went wrong, file: " << path << "\x1b[37m" << std::endl;
			return 0;
		}
	}
	else {
		cout << "MissssshhhhTake";
		return 0;
	}

	
	



		
	return 0;
}
