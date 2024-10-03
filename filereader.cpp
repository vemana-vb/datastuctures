#include "filereader.h"

FileReader::FileReader()
{

}

string FileReader::readFile(string file, vector<Article> &articles, Solution &optimal)
{
    std::ifstream iFile(file);
    if (!iFile.is_open()) {
        perror("file");
        return "";
    }

    std::string line;
    std::getline(iFile, line);
    stringstream stream;
    int a, r;
    std::string tmp;
    stream << line;
    stream >> a >> tmp >> tmp >> r;

    std::getline(iFile, line);
    stream.str(line);
    int temp;
    stream >> temp;
    optimal.setRequiredClicks(temp);

    std::getline(iFile, tmp);
    while(std::getline(iFile, line)) {
        stream.clear();
        stream.str(line);
        string name;
        char type;
        int reporter, clicks;
        double cost;
        stream >> name >> type >> reporter >> cost >> clicks;
        Article a(name, cost, clicks, reporter, type);
        optimal.addReporter(reporter);
        articles.push_back(a);
    }
    iFile.close();

    optimal.cost = numeric_limits<int>::infinity();
    optimal.clicks = numeric_limits<int>::infinity();

    return file.substr(0, file.find_last_of('.')) + ".out";
}
