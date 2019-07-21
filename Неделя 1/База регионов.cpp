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

using namespace std;

bool operator<(const Region& lhs, const Region& rhs) {
    return make_tuple(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) < make_tuple(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    map<Region, int> temp_m;
    for (auto now : regions) {
        ++temp_m[now];
    }
    int max_el = 0;
    for (auto item : temp_m) {
        if (item.second > max_el) {
            max_el = item.second;
        }
    }
    return max_el;
}

int main() {
    
}
