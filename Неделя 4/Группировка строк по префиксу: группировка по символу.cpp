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
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {
    
    auto left = lower_bound(range_begin, range_end, string(1, prefix));
    auto next = static_cast<char>(prefix + 1);
    auto right = lower_bound(range_begin, range_end, string(1, next));
    
    return make_pair(left, right);
}

/*int main() {
    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};
    
    const auto m_result =
    FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    const auto p_result =
    FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
    (p_result.second - begin(sorted_strings)) << endl;
    
    const auto z_result =
    FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
    (z_result.second - begin(sorted_strings)) << endl;
    
    return 0;
}*/
