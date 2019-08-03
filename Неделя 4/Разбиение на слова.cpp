#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> result;
    auto bonder = find(begin(s), end(s), ' ');
    auto beg_it = begin(s);
    if (bonder == end(s)) {
        result.push_back(string(begin(s), end(s)));
        return result;
    } else {
        while (bonder != end(s)) {
            string temp = string(beg_it, bonder);
            beg_it = bonder + 1;
            bonder = find(beg_it, end(s), ' ');
            result.push_back(temp);
            if (bonder == end(s)) {
                result.push_back(string(beg_it, bonder));
            }
        }
        return result;
    }
}
