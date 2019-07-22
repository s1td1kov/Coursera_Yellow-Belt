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

template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, const Key& k) {
    if (m.count(k) == 0) {
        throw runtime_error("");
    } else {
        return m.at(k);
    }
}

int main() {
    
}
