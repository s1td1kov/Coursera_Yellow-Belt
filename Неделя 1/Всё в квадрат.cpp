#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
#include <limits>
#include <tuple>
#include <utility>
#include <cmath>

using namespace std;
template <typename T> vector<T> Pow(vector<T> v);
template <typename First, typename Second> pair<First, Second> Pow(pair<First, Second>& p);
template <typename T> T Pow(T x);
template <typename Key, typename Value> map<Key, Value> Pow(map<Key, Value> m);
template <typename Collection> Collection Sqr(Collection col);

template <typename T>
vector<T> Pow(vector<T> v) {
    for (auto& now : v) {
        now = Pow(now);
    }
    return v;
}

template <typename First, typename Second>
pair<First, Second> Pow(pair<First, Second>& p) {
    p.first = Pow(p.first);
    p.second = Pow(p.second);
    return p;
}

template <typename T>
T Pow(T x) {
    return x * x;
}

template <typename Key, typename Value>
map<Key, Value> Pow(map<Key, Value> m) {
    for (auto& now : m) {
        now.second = Pow(now.second);
    }
    return m;
}


template <typename Collection>
Collection Sqr(Collection col) {
    col = Pow(col);
    return col;
}

int main() {
    
}
