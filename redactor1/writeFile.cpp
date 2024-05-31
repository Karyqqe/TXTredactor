#include <iostream>
#include <fstream>
void writeFile(std::string path, std::string content, std::string filename) {
	std::ofstream file(path, std::ios::app); //создаем обьект file который хранит в качестве значение файл по пути path и пишем айос апп для того чтобы в файл можно было дозаписывать 
	if (file.is_open()) {
		file << content << std::endl; //пушим всю записанную нами инфу в созданный файл
		std::cout << "\x1b[32m Information has been written secsessfully! File: " << filename << "\x1b[37m" << std::endl;
		file.close();
	}
	else {
		std::cout << "\x1b[31m Something went wrong, file: " << filename << "\x1b[37m" << std::endl;
	}
}