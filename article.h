#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>

using namespace std;

class Article
{
    std::string name;
    double cost;
    int clicks, reporter;
    char type;

public:
    Article() = default;
    Article(string, double, int, int, char);

    bool operator<(const Article& rhs) const ;
    const std::string &getName() const;
    void setName(const std::string &newName);
    double getCost() const;
    void setCost(double newCost);
    int getReporter() const;
    void setReporter(int newReporter);
    int getClicks() const;
    void setClicks(int newClicks);
    char getType() const;
    void setType(char newType);
};

#endif // ARTICLE_H
