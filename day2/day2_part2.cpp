#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void
printVector(const std::vector<int> &);

int
checkLine(std::vector<int> &, bool);

int
checkLineTwice(std::vector<int> &, bool);

int
getLevelErrorPos(std::vector<int> &v, bool);

int
main(int argc, char **argv)
{
    std::vector<int> vec;
    int safeReports = 0;

    std::ifstream input("day2/input.txt");

    std::string line;
    while (std::getline(input, line)) {
        std::stringstream ss(line);
        std::string token;

        while (ss >> token) {
            vec.push_back(std::stoi(token));
        }

        bool ascending = false;
        if (vec[0] < vec[1]) {
            ascending = true;
        }
        safeReports += checkLineTwice(vec, ascending);

        vec.clear();
    }

    std::cout << safeReports << "\n";

    return 0;
}

int
checkLineTwice(std::vector<int> &v, bool ascending)
{
    int errorPos = getLevelErrorPos(v, ascending);
    if (errorPos > -1) {
        v.erase(v.begin() + errorPos);
        // printVector(v);

        return checkLine(v, ascending);
    }
    return 1;
}

int
getLevelErrorPos(std::vector<int> &v, bool ascending)
{
    int i;
    bool valid = true;
    for (i = 0; i < v.size(); i++) {
        if (i >= 1) {
            if (ascending && v[i - 1] > v[i]) {
                return i;
            }

            if (!ascending && v[i - 1] < v[i]) {
                return i;
            }

            const int diff = abs(v[i - 1] - v[i]);
            if (diff > 3 || diff == 0) {
                return i;
            }
        }
    }

    return -1;
}

int
checkLine(std::vector<int> &v, bool ascending)
{
    int i;
    bool valid = true;
    for (i = 1; i < v.size(); i++) {
        if (ascending && v[i - 1] > v[i]) {
            valid = false;
            break;
        }

        if (!ascending && v[i - 1] < v[i]) {
            valid = false;
            break;
        }

        const unsigned int diff = abs(v[i - 1] - v[i]);
        if (diff > 3 || diff == 0) {
            valid = false;
            break;
        }
    }

    if (valid) {
        // printVector(v);
        return 1;
    }
    return 0;
}

void
printVector(const std::vector<int> &v)
{
    const size_t size = v.size();
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}