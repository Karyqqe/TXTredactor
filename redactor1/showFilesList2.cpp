#include <string>
#include <iostream>
#include <filesystem>

void showFilesList(std::string path) {
	std::string path2 = path;
	for (auto entry : std::filesystem::directory_iterator(path2))//вот эта вот шн€га это итератор который проходитс€ по нашей папке
		std::cout << entry.path().filename() << std::endl;//вот мы такие проходимс€ по папке встречаем текстовые обьекты и с помощью entry.path() берем только их полный путь и добавл€ем к этому .filename() чтобы отсавить только им€ файла
}