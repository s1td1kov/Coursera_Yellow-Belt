#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>
#include <queue>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border) {
    auto first_less = numbers.lower_bound(border);
    if (first_less == numbers.begin()) {
        return first_less;
    }
    
    if (first_less == numbers.end()) {
        return prev(numbers.end());
    }
    
    auto result = (*first_less -  border < border - *prev(first_less));
    return result ? first_less : prev(first_less);
}

/*int main() {
    set<int> numbers = {1, 4, 6};
    cout <<
    *FindNearestElement(numbers, 0) << " " <<
    *FindNearestElement(numbers, 3) << " " <<
    *FindNearestElement(numbers, 5) << " " <<
    *FindNearestElement(numbers, 6) << " " <<
    *FindNearestElement(numbers, 100) << endl;
    
    set<int> empty_set;
    
    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
    return 0;
}*/
