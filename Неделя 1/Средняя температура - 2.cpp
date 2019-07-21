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

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> temperatures;
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        temperatures.push_back(temp);
        sum += temp;
    }
    sum /= n;
    int k = 0;
    vector<int> indexes;
    for (int i = 0; i < n; ++i) {
        if (temperatures[i] > sum) {
            ++k;
            indexes.push_back(i);
        }
    }
    cout << k << endl;
    for (auto i : indexes) {
        cout << i << " ";
    }
    return 0;
}
