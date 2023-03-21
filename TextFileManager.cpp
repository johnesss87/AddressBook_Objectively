#include "TextFileManager.h"

string TextFileManager::getTextFileName() {

    return TEXT_FILE_NAME;
}

bool TextFileManager::isTextFileEmpty() {
    bool fileEmpty = true;
    fstream textFile;
    textFile.open(getTextFileName().c_str(), ios::app);

    if (textFile.good() == true) {
        textFile.seekg(0, ios::end);
        if (textFile.tellg() != 0)
            fileEmpty = false;
    }
    textFile.close();
    return fileEmpty;
}
