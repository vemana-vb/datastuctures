#ifndef FILEREADER_H
#define FILEREADER_H


#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

#include "solution.h"
#include "article.h"

using namespace std;

class FileReader
{
public:
    FileReader();

    string readFile(string file, vector<Article> &articles, Solution &optimal);
};

#endif // FILEREADER_H
