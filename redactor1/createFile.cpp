#include <iostream>
#include <fstream>

void createFile(std::string filename, std::string path) {
	
	std::ofstream file(path);//������� ������ � ������ file �� ������� ���� ������� ���������� � path
	if (file.is_open()) {
		std::cout << "\x1b[32m File: " << filename << " is created!!\x1b[37m" << std::endl;
		file.close();
	}
	else {
		std::cout << "\x1b[31m Something went wrong, file: " << filename << "\x1b[37m" << std::endl;
	}
};