#include <array>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>

#define COLLUMN_SIZE 1000

int
main(int argc, char **argv)
{

    std::ifstream file;
    file.open("day1/input.txt");

    std::array<int, COLLUMN_SIZE> left = { 0 }, right = { 0 };

    std::string token;
    int value, iterations = 0;
    while (file >> token) {
        value = std::stoi(token);
        left[iterations] = value;
        file >> token;

        value = std::stoi(token);
        right[iterations] = value;
        iterations++;
    }

    int answer = 0;
    for (int i = 0; i < left.size(); i++) {
        int times = 0;
        for (int j = 0; j < right.size(); j++) {
            if (left[i] == right[j]) {
                times++;
            }
        }
        answer += times * left[i];
    }

    std::cout << answer << "\n";
    return 0;
}
