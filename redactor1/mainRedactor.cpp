#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <filesystem>
#include "createFile.h"
#include "writeFile.h"
#include "getFilesLists.h"
#include "openFile.h"
#include "chooseDirectory.h"

using namespace std;

int main()
{
	
	

	string path = "C:\\Users\\user\\Documents\\"; //����������� ���� � ����� �� �������
	
identificator:
	string pathSexy = "\x1b[33m" + path + "\x1b[37m";//�������� ������� ���� �� ����, ������� ������ ���� ������� ���������� ������ ��� ������ ��� �� ����� ������ ���� ������� ��
	
	cout << "[+]Current PATH " << pathSexy << endl; //������� ������� ����
	

	cout << endl;
	cout << "[1]Create file" << endl;
	cout << "[2]Create and write in file" << endl;
	cout << "[3]Change path of files" << endl;
	cout << "[4]Check list of files" << endl;
	cout << "[5]Open and re-written file" << endl;

	cout << "Choose options> ";
	int choise;
	cin >> choise;

	Sleep(500);
	system("cls");

	

	if (choise == 1) {
		
		cout << "Enter the filename> ";
		string userFilename;//������ ��� ��������� �����
		cin.ignore();
		getline(cin, userFilename);
		/*cin.ignore();
		getline(cin, userFilename);*/
		cout << userFilename << endl;
		string userPath = path + userFilename + ".txt";//����������� ������ ���� � ������ �����: ���� �� ���� ������ ���� ��� ����� ����� ���� ���������� ��� ��� �����
		cout << userPath << endl;
		createFile(userFilename, userPath);//�������� ������� �� ������
		cout << "[1]Exit" << endl;
		cout << "[2]Back to menu" << endl;
		cout << "Choose> ";
		
		int cng;
		cin >> cng;
		system("cls");
		if (cng == 1) {
			return 0;
		}
		else if (cng == 2) {
			goto identificator;
		}
		else {
			cout << "mistake:(";
			return 0;
		}
		


	}
	else if (choise == 2) {
		cout << "Enter the filename> ";
		string userFilename;//������ ��� ��������� �����
		cin.ignore();
		getline(cin, userFilename);
		string userPath = path + userFilename + ".txt";

		Sleep(500);
		system("cls");

		string userContent;//������ ���������� ������� ����� ������� � ����
		cout << "Enter info which will be written in file> ";
		
		cin.ignore();//������ ����� �����(����� ������ ����������� ����� �������)
		getline(cin, userContent);//��� �� ���, �� ���� ��������� ���� ������ �� ��� �������� ��� ������ �������  � ������� ������ ������ �������
		

		writeFile(userPath, userContent, userFilename);//�������� ������� �� ������
		cout << "[1]Exit" << endl;
		cout << "[2]Back to menu" << endl;
		cout << "Choose> ";

		int cng;
		cin >> cng;
		system("cls");
		if (cng == 1) {
			return 0;
		}
		else if (cng == 2) {
			goto identificator;
		}
		else {
			cout << "mistake:(";
			return 0;
		}
	}
	else if (choise == 3) {
		
		cout << "Choose options> " << endl;
		cout << "[1]Choose exists directory " << endl;
		cout << "[2]Create new directory " << endl;
		cout << "Choise> " << endl;
		int chs;
		cin >> chs;
		if (chs == 1)
		{
			string currentPath = "C:\\Users\\user\\Documents\\";
			string input;
			

			while (true) {
				
				
				
					
				
				cout << "Current directory: " << "\x1b[33m" << currentPath << "\x1b[37m" << endl;
				cout << endl;
				cout << "Enter command (q - exit, cd <folder> - go to folder): ";
				
				getline(cin, input);
				
				system("cls");

				if (input == "q") {
					path = currentPath;
					goto identificator;
				}
				else if (input.substr(0, 3) == "cd ") {
					string folder = input.substr(3);
					string newPath = currentPath + folder + "\\";
					if (filesystem::is_directory(newPath)) {
						currentPath = newPath;
					}
					else {
						cout << "Folder is not found!";
					}
				}
				
				
				printDirectoryContents(currentPath);
				
			}


			
		}
		if (chs == 2) {
			string folderPath;
			cout << "Enter path to new directory> ";
			cin.ignore();
			getline(cin, folderPath);
			filesystem::path path(folderPath);
			system("cls");
			try
			{
				filesystem::create_directories(path);
				cout << "Directory is created!" << endl;


			}
			catch(exception e)
			{
				cout << "Somethind went wrong:((" << e.what() << endl;
			}

			cout << "[1]Exit" << endl;
			cout << "[2]Back to menu" << endl;
			cout << "Choose> ";

			int cng;
			cin >> cng;
			system("cls");
			if (cng == 1) {
				return 0;
			}
			else if (cng == 2) {
				goto identificator;
			}
			else {
				cout << "mistake:(";
				return 0;
			}
		}
		else {
			cout << "miSSStake:[";
			return 0;
		}

		//cout << "Enter new path> ";
		//cin >> path;//������ ����� ���� � ����� (�������� D:\RedacteredFile1\ �� ���� ��������� ���� �� ����� � �� �������� � ����� ���� \ ��������
		//goto identificator;
	}
	else if(choise == 4){
		try {
			showFilesList(path);//����� ������ ������ �� ������
		}
		catch (exception a) {
			cout << "Something went wrong!" << a.what() << endl;
		}
		cout << "[1]Exit" << endl;
		cout << "[2]Back to menu" << endl;
		cout << "Choose> ";

		int cng;
		cin >> cng;
		system("cls");
		if (cng == 1) {
			return 0;
		}
		else if (cng == 2) {
			goto identificator;
		}
		else {
			cout << "mistake:(";
			return 0;
		}
	}
	else if (choise == 5) {
		Sleep(500);
		system("cls");
		cout << "Enter the name of file which you want open> ";
		string userFilename;//������ ��� ������ �����
		cin.ignore();
		getline(cin, userFilename);
		string userPath =path + userFilename + ".txt";//������ ���� � ������ �����
		
		

		openFile(userPath);
		cout << "[1]Exit" << endl;
		cout << "[2]Back to menu" << endl;
		cout << "Choose> ";

		int cng;
		cin >> cng;
		system("cls");
		if (cng == 1) {
			return 0;
		}
		else if (cng == 2) {
			goto identificator;
		}
		else {
			cout << "mistake:(";
			return 0;
		}
	}
	else {
		cout << "MIIIIIIIIIIIISTAAAAAAAAAAAAAAAKEEEE!!!!" << endl;
		cout << "[1]Exit" << endl;
		cout << "[2]Back to menu" << endl;
		cout << "Choose> ";

		int cng;
		cin >> cng;
		system("cls");
		if (cng == 1) {
			return 0;
		}
		else if (cng == 2) {
			goto identificator;
		}
		else {
			cout << "mistake:(";
			return 0;
		}
	}
}

