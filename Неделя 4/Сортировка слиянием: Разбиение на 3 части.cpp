#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2) {
        return;
    }
    
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    
    int range_length = range_end - range_begin;
    auto it1 = elements.begin() + range_length / 3;
    auto it2 = elements.begin() + 2 * range_length / 3;
    
    MergeSort(elements.begin(), it1);
    MergeSort(it1, it2);
    MergeSort(it2, elements.end());
    
    vector<typename RandomIt::value_type> interim_result;
    
    merge(elements.begin(), it1, it1, it2, back_inserter(interim_result));
    merge(interim_result.begin(), interim_result.end(), it2, elements.end(), range_begin);
}
