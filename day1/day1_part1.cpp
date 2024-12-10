#include <array>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>

#define COLLUMN_SIZE 1000

template<size_t N>
void
quickSort(std::array<int, N> &, int, int);

template<size_t N>
int
partition(std::array<int, N> &, int, int);

template<size_t N>
void
swap(std::array<int, N> &, int, int);

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

    quickSort(left, 0, left.size() - 1);
    quickSort(right, 0, right.size() - 1);

    int answer = 0;
    for (int i = 0; i < left.size(); i++) {
        answer += abs(left[i] - right[i]);
    }

    std::cout << answer << "\n";

    return 0;
}

template<size_t N>
void
quickSort(std::array<int, N> &arr, int begin, int end)
{
    if (begin < end) {
        int q = partition(arr, begin, end);
        quickSort(arr, begin, q - 1);
        quickSort(arr, q + 1, end);
    }
};

template<size_t N>
int
partition(std::array<int, N> &arr, int begin, int end)
{
    int pivo = arr[begin];
    int i = begin + 1;
    int j = end;

    while (i <= j) {
        while (i <= j && arr[i] <= pivo) {
            i++;
        }

        while (i <= j && arr[j] > pivo) {
            j--;
        }

        if (i < j) {
            swap(arr, i, j);
        }
    }
    swap(arr, begin, j);
    return j;
};

template<size_t N>
void
swap(std::array<int, N> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
