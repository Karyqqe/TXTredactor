#include <string>
#include <iostream>
#include <filesystem>

void showFilesList(std::string path) {
	std::string path2 = path;
	for (auto entry : std::filesystem::directory_iterator(path2))//��� ��� ��� ����� ��� �������� ������� ���������� �� ����� �����
		std::cout << entry.path().filename() << std::endl;//��� �� ����� ���������� �� ����� ��������� ��������� ������� � � ������� entry.path() ����� ������ �� ������ ���� � ��������� � ����� .filename() ����� �������� ������ ��� �����
}