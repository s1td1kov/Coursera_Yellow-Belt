#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
    auto result = find_if(numbers.begin(), numbers.end(), [](const int& x) {
        return x < 0;
    });
    while (result != begin(numbers)) {
        --result;
        cout << *result << " ";
    }
}
