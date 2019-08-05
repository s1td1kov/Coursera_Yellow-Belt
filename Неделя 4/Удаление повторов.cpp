#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>

using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& elements) {
    sort(elements.begin(), elements.end());
    auto it = unique(elements.begin(), elements.end());
    elements.erase(it, end(elements));
}

