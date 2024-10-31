#include <iostream>
#include <vector>

int findMissingNumber(const std::vector<int>& arr, int N) {
    int totalSum = N * (N + 1) / 2;
    int arraySum = 0;

    for (int num : arr) {
        arraySum += num;
    }

    return totalSum - arraySum;
}

int main() {
    int N = 5;
    std::cout << "Enter the value of N: ";
    std::cin >> N;
    std::vector<int> array;
    std::cout << "Enter " << N - 1 << " numbers: ";
    for (int i = 0; i < N - 1; ++i) {
        int num;
        std::cin >> num;
        array.push_back(num);
    }

    int missingNumber = findMissingNumber(array, N);
    std::cout << "The missing number is: " << missingNumber << std::endl;

    return 0;
}