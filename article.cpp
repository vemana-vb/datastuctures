#include "article.h"

const std::string &Article::getName() const
{
    return name;
}

void Article::setName(const std::string &newName)
{
    name = newName;
}

double Article::getCost() const
{
    return cost;
}

void Article::setCost(double newCost)
{
    cost = newCost;
}

int Article::getReporter() const
{
    return reporter;
}

void Article::setReporter(int newReporter)
{
    reporter = newReporter;
}

int Article::getClicks() const
{
    return clicks;
}

void Article::setClicks(int newClicks)
{
    clicks = newClicks;
}

char Article::getType() const
{
    return type;
}

void Article::setType(char newType)
{
    type = newType;
}

Article::Article(string name, double cost, int click, int reporter, char type)
    :name(name), cost(cost), clicks(click), reporter(reporter), type(type)
{}

bool Article::operator<(const Article &rhs) const
{
    return name < rhs.name;
}
