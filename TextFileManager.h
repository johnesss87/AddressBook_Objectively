#ifndef TEXTFILEMANAGER_H
#define TEXTFILEMANAGER_H

#include <iostream>
#include <fstream>

using namespace std;

class TextFileManager {

    const string TEXT_FILE_NAME;

public:
    TextFileManager(string textFileName) : TEXT_FILE_NAME(textFileName) {
    }

    string getTextFileName();
    bool isTextFileEmpty();
};

#endif
