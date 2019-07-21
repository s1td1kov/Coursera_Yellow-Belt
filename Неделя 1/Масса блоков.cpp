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
    uint64_t n;
    cin >> n;
    uint64_t r;
    cin >> r;
    uint64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        uint64_t w, h, d;
        cin >> w >> h >> d;
        sum += w * h * d;
    }
    cout << sum * r << endl;
    return 0;
}
