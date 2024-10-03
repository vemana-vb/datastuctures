#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <istream>
#include <set>
#include <sstream>
#include <chrono>

#include "article.h"
#include "filereader.h"
#include "filewriter.h"
#include "solution.h"

using namespace std;

#define INVALID -1

Solution optimalSolution;

bool prune(Solution sol, vector<Article> &articles) {
    set<int> rs {};
    for(const auto &article: sol.articles)
        rs.insert(article.getReporter());

    int sel = rs.size();
    int rem = sol.getReporters().size() - sel;

    if(rem > articles.size())
        return true;

    int clicks = 0;
    for(const auto &a: sol.articles)
        clicks += a.getClicks();

    for(const auto &a: articles)
        clicks += a.getClicks();

    if(sol.getRequiredClicks() > clicks)
        return true;

    int res = 0;
    for(const auto &each: sol.articles)
        res |= (1 << (tolower(each.getType())-'a'));
    for(const auto &each: articles)
        res |= (1 << (tolower(each.getType())-'a'));

    int valid = 0;
    valid |= 1 << 4;
    valid |= 1 << 6;
    valid |= 1 << 11;
    valid |= 1 << 18;
    if(res != valid)
        return true;

    return false;
}

int minres = 1e9;
void optimzedBruteforce(vector<Article> a, int aidx, Solution sol) {
    if (aidx == a.size()) {
        int res = sol.validate();
        if((res != INVALID && res < optimalSolution.cost) || (optimalSolution.cost == 0 && res > 0)) {
            optimalSolution = sol;
            optimalSolution.cost = res;
        }

        return;
    }

    for(int i=aidx; i<a.size(); ++i) {
        Article article = a[i];
        sol.articles.push_back(article);
        sol.reporter.push_back(article.getReporter());
        optimzedBruteforce(a, i+1, sol);

        sol.reporter.pop_back();
        sol.articles.pop_back();

        if(i < a.size()-1) {
            vector<Article> r;
            for(int j=i+1; j<a.size(); ++j)
                r.push_back(a[j]);
            if(prune(sol, r))
                return;
        }

        optimzedBruteforce(a, i+1, sol);
    }

    return;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Error: Invalid arguments\n" << endl;
        cerr << "Usage: " << argv[0] << " file.txt" << endl;
        return 1;
    }

    optimalSolution = Solution();

    FileReader reader;
    FileWriter writer;

    std::vector<Article> articles;
    string file = reader.readFile(argv[1], articles, optimalSolution);

    auto start = std::chrono::high_resolution_clock::now();
    optimzedBruteforce(articles, 0, optimalSolution);
    auto stop = std::chrono::high_resolution_clock::now();

    writer.writeFile(file, optimalSolution, start, stop);
    std::cout << "Results written to " << file << std::endl;
    return 0;
}




