//
// Created by MHeis on 07.04.2022.
//

#include "FileReader.h"

FileReader::FileReader(const char *file) {
    this->fileName = file;
}

FileReader::~FileReader() {
    if (this->isOpen()) {
        this->file.close();
    }
}

bool FileReader::isOpen() {
    return this->file.is_open();
}

int FileReader::getLine(std::string &buffer) {
    std::string line;
    if (open()) {
        if (!std::getline(this->file, buffer)) {
            return -1;
        }
        return buffer.length();
    }
    return -1;
}

bool FileReader::open() {
    if (this->isOpen()) {
        return true;
    }

    this->file.open(this->fileName.data());

    return this->isOpen();
}

void FileReader::close() {
    if (this->isOpen()) {
        this->file.close();
    }
}
