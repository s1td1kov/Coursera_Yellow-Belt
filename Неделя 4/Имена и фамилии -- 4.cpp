#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>
#include <queue>
#include <map>

using namespace std;

string FindName(const map<int, string>& m, int year) {
    auto it = m.upper_bound(year);
    string name;
    if (it != m.begin()) {
        name = (--it)->second;
    }
    return name;
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        first_names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        last_names[year] = last_name;
    }
    string GetFullName(int year) {
        const string first_name = FindName(first_names, year);
        const string last_name = FindName(last_names, year);
        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        }
        if (last_name.empty()) {
            return first_name + " with unknown last name";
        }
        if (first_name.empty()) {
            return last_name + " with unknown first name";
        }
        return first_name + " " + last_name;
    }
private:
    map<int, string> first_names;
    map<int, string> last_names;
};

/*int main() {
    Person person;
    
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    return 0;
}*/
