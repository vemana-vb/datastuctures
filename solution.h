#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <set>
#include <limits>
#include <algorithm>

#include "article.h"

#define INVALID -1

class Solution
{
    int requiredClicks = 0;
    set<int> reporters;
public:
    int clicks, cost;
    vector<Article> articles;
    vector<int> reporter;

    Solution();

    const set<int> &getReporters() const;
    void addReporter(int r);
    void setReporters(const set<int> &newReporters);
    int getRequiredClicks() const;
    void setRequiredClicks(int newRequiredClicks);
    int totalClicks();
    int totalCost() const;

    int validate();
};

#endif // SOLUTION_H
