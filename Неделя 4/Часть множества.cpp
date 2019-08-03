#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> result;
    auto border_if = find_if(begin(elements), end(elements), [border](const T& x) {
        return x > border;
    });
    for (; border_if != end(elements); ++border_if) {
        result.push_back(*border_if);
    }
    return result;
}
