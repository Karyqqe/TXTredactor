#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;



void printDirectoryContents(std::string path) {
    cout << "Directory's content " << "\x1b[33m" << path << "\x1b[37m" << ":" << endl;
    for (auto entry : fs::directory_iterator(path)) {
        cout << entry.path().string() << endl;
    }
}