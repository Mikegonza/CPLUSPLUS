#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
using namespace std;

class FileHandler {
public:
    static string readFile(const string& filename);
    static void writeFile(const string& filename, const string& content);
};

#endif // FILEHANDLER_H
