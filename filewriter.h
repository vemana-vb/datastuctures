#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
#include <fstream>
#include <chrono>

#include "solution.h"

using namespace std;
using namespace chrono;

class FileWriter
{
public:
    FileWriter();

    void writeFile(string file, Solution &optimal, time_point<system_clock, nanoseconds> start, time_point<system_clock, nanoseconds> end);
};

#endif // FILEWRITER_H
