#include "solution.h"

Solution::Solution()
{
    this->cost = numeric_limits<int>::infinity();
    this->clicks = numeric_limits<int>::infinity();
}

const set<int> &Solution::getReporters() const
{
    return reporters;
}

void Solution::addReporter(int r)
{
    reporters.insert(r);
}

void Solution::setReporters(const set<int> &newReporters)
{
    reporters = newReporters;
}

int Solution::getRequiredClicks() const
{
    return requiredClicks;
}

void Solution::setRequiredClicks(int newRequiredClicks)
{
    requiredClicks = newRequiredClicks;
}

int Solution::totalClicks()
{
    int clicks = 0;
    for(int i=0; i<articles.size(); ++i)
        clicks += articles[i].getClicks();
    return clicks;
}

int Solution::totalCost() const
{
    return cost;
}

int Solution::validate()
{
    set<int> s;
    for(auto each: reporter)
        s.insert(each);

    if(s.size() != reporters.size()) {
        return INVALID;
    }

    int tg=1, tl=1, te=1, ts=1;
    for(int i=0; i< articles.size(); ++i) {
        if(articles[i].getType() == 'L') tl = 0;
        else if(articles[i].getType() == 'G') tg = 0;
        else if(articles[i].getType() == 'E') te = 0;
        else if(articles[i].getType() == 'S') ts = 0;
    }

    if(tg || tl || te || ts)
        return INVALID;

    int al = articles.size();
    int half = al / 2;
    int cnt[26];
    for(int i=0; i<26; ++i)  cnt[i] = 0;

    for(int i=0; i<al; ++i)
        cnt[articles[i].getType()-'A']++;

    if(cnt['G'-'A'] > half)
        return INVALID;
    if(cnt['S'-'A'] > half)
        return INVALID;
    if(cnt['E'-'A'] > half)
        return INVALID;
    if(cnt['L'-'A'] > half)
        return INVALID;

    int clicks = 0;
    for(int i=0; i<articles.size(); ++i)
        clicks += articles[i].getClicks();

    if(clicks < requiredClicks) {
        return INVALID;
    }

    this->clicks = clicks;

    int cost = 0;
    if(cnt['G'-'A'] > 1)
        cost -= 150;
    if(cnt['S'-'A'] > 1)
        cost -= 150;
    if(cnt['E'-'A'] > 1)
        cost -= 150;
    if(cnt['L'-'A'] > 1)
        cost -= 150;

    int ct[reporter.size()+1];
    for(int i=0; i<reporter.size(); ++i)
        ct[i] = 0;

    for(int i=0; i<articles.size(); ++i)
        ct[articles[i].getReporter()]++;

    for(int i=0; i<reporter.size(); ++i)
        if(ct[i])
            cost += (ct[i]-1) * 100;

    for(int i=0; i<articles.size(); ++i)
        cost += articles[i].getCost();

    return cost;
}
