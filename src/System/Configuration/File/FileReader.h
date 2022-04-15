#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <iostream>
#include <fstream>

class FileReader {
public:
    explicit FileReader(const char *file);

    ~FileReader();

    bool isOpen();

    int getLine(std::string &buffer);

    void close();

private:
    std::string fileName;
    std::ifstream file;

    bool open();
};

#endif
