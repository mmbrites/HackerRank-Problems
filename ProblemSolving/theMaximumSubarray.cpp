#include <iostream>
#include <vector>

int calculateMaxSubarraySum(const std::vector<int> & arr) {

    int maximum = arr[0];
    int endingOrStart = arr[0];

    for (int i = 1; i < arr.size(); i++) {

        endingOrStart = std::max(endingOrStart + arr[i], arr[i]);
        maximum = std::max(maximum, endingOrStart);

    }

    return maximum;

}

std::vector<int> nonDecrescendingSort(const std::vector<int> & arr) {

    std::vector<int> nonDecrescendingArray(arr);

    for (int i = 0; i < nonDecrescendingArray.size() - 1; i++) {

        for (int j = i + 1; j > i && nonDecrescendingArray[j] < nonDecrescendingArray[j - 1]; j--) {

            int temporaryValue = nonDecrescendingArray[j - 1];
            nonDecrescendingArray[j - 1] = nonDecrescendingArray[j];
            nonDecrescendingArray[j] = temporaryValue;

        }

    }

    return nonDecrescendingArray;

}

int calculateMaxSubsequenceSum(const std::vector<int> & arr) {

    int max = 0;

    std::vector<int> nonDecrescendingArray = nonDecrescendingSort(arr);

    for (int i = 0; i < nonDecrescendingArray.size(); i++) {

        if(nonDecrescendingArray[i] > 0)
            max += nonDecrescendingArray[i];

    }

    if (max == 0)
        max = nonDecrescendingArray[nonDecrescendingArray.size() - 1];

    return max;

}

std::vector<int> maxSubarray(const std::vector<int> & arr) {

    int maxSubarraySum = calculateMaxSubarraySum(arr);
    int maxSubsequenceSum = calculateMaxSubsequenceSum(arr);

    return { maxSubarraySum, maxSubsequenceSum };

}

int main() {

    std::vector<int> arr = { 2, -1, 2, 3, 4, -5 };
    std::vector<int> result = maxSubarray(arr);

    std::cout << result[0] << " " << result[1] << std::endl;

}