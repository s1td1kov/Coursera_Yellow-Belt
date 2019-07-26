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
#include <random>
#include <limits>
#include <tuple>
#include <utility>
#include <cmath>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }
    
    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }
    
private:
    int fail_count = 0;
};

void TestRational() {
    
    AssertEqual(Rational().Numerator(), 0);
    AssertEqual(Rational().Denominator(), 1);
    
    AssertEqual(Rational(1, 2).Numerator(), 1);
    AssertEqual(Rational(1, 2).Denominator(), 2);
    
    AssertEqual(Rational(1, -2).Numerator(), -1);
    AssertEqual(Rational(1, -2).Denominator(), 2);
    
    AssertEqual(Rational(-1, -2).Numerator(), 1);
    AssertEqual(Rational(-1, -2).Denominator(), 2);
    
    AssertEqual(Rational(0, 5).Numerator(), 0);
    AssertEqual(Rational(0, 5).Denominator(), 1);
    
    AssertEqual(Rational(3, 6).Numerator(), 1);
    AssertEqual(Rational(3, 6).Denominator(), 2);
    
    AssertEqual(Rational(6, 3).Numerator(), 2);
    AssertEqual(Rational(6, 3).Denominator(), 1);
    
    AssertEqual(Rational(1, 1).Numerator(), 1);
    AssertEqual(Rational(1, 1).Denominator(), 1);
    
    AssertEqual(Rational(numeric_limits<int>::max(), numeric_limits<int>::max()).Numerator(), 1);
    AssertEqual(Rational(numeric_limits<int>::max(), numeric_limits<int>::max()).Denominator(), 1);
    
    AssertEqual(Rational(numeric_limits<int>::min(), numeric_limits<int>::min()).Numerator(), 1);
    AssertEqual(Rational(numeric_limits<int>::min(), numeric_limits<int>::min()).Denominator(), 1);
    
}

int main() {
    TestRunner tr;
    tr.RunTest(TestRational, "TestRational");
    return 0;
}
