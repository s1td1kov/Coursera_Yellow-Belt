#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>
#include <queue>
#include <map>

using namespace std;

bool comp(string a, string b) {
    return a < b;
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) {
    auto left = lower_bound(range_begin, range_end, prefix);
    
    string next_prefix = prefix;
    ++next_prefix[prefix.size() - 1];
    
    auto right = lower_bound(range_begin, range_end, next_prefix);
    
    return make_pair(left, right);
}

/*int main() {
    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};
    
    const auto mo_result =
    FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    const auto mt_result =
    FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
    (mt_result.second - begin(sorted_strings)) << endl;
    
    const auto na_result =
    FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
    (na_result.second - begin(sorted_strings)) << endl;
    
    return 0;
}*/
