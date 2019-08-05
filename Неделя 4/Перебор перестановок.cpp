#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>

using namespace std;

void PrintPerm(const vector<int>& v) {
    for (auto now : v) {
        cout << now << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> perm;
    for (int i = 1; i <= n; ++i) {
        perm.push_back(i);
    }
    sort(rbegin(perm), rend(perm));
    PrintPerm(perm);
    while (prev_permutation(begin(perm), end(perm))) {
        PrintPerm(perm);
    }
}
