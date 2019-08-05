#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>

using namespace std;

/*enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;  // возраст
    Gender gender;  // пол
    bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    vector<typename InputIt::value_type> range_copy(range_begin, range_end);
    auto middle = begin(range_copy) + range_copy.size() / 2;
    nth_element(
                begin(range_copy), middle, end(range_copy),
                [](const Person& lhs, const Person& rhs) {
                    return lhs.age < rhs.age;
                }
                );
    return middle->age;
}
*/


void PrintStats(vector<Person> persons) {
    vector<Person> AllPersons = persons;
    vector<Person> AllFemales = persons;
    vector<Person> AllMales = persons;
    vector<Person> EmployedFemales = persons;
    vector<Person> UnemployedFemales = persons;
    vector<Person> EmployedMales = persons;
    vector<Person> UnemployedMales = persons;
    cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;
    
    auto it1 = partition(AllFemales.begin(), AllFemales.end(), [](const Person& person) {
        return person.gender == Gender::FEMALE;
    });
    AllFemales.erase(it1, end(AllFemales));
    cout << "Median age for females = " << ComputeMedianAge(AllFemales.begin(), AllFemales.end()) << endl;
    
    auto it2 = partition(AllMales.begin(), AllMales.end(), [](const Person& person) {
        return person.gender == Gender::MALE;
    });
    AllMales.erase(it2, end(AllMales));
    cout << "Median age for males = " << ComputeMedianAge(AllMales.begin(), AllMales.end()) << endl;
    
    auto it3 = partition(EmployedFemales.begin(), EmployedFemales.end(), [](const Person& person) {
        return person.gender == Gender::FEMALE && person.is_employed == true;
    });
    EmployedFemales.erase(it3, end(EmployedFemales));
    cout << "Median age for employed females = " << ComputeMedianAge(EmployedFemales.begin(), EmployedFemales.end()) << endl;
    
    auto it4 = partition(UnemployedFemales.begin(), UnemployedFemales.end(), [](const Person& person) {
        return person.gender == Gender::FEMALE && person.is_employed == false;
    });
    UnemployedFemales.erase(it4, end(UnemployedFemales));
    cout << "Median age for unemployed females = " << ComputeMedianAge(UnemployedFemales.begin(), UnemployedFemales.end()) << endl;
    
    auto it5 = partition(EmployedMales.begin(), EmployedMales.end(), [](const Person& person) {
        return person.gender == Gender::MALE && person.is_employed == true;
    });
    EmployedMales.erase(it5, EmployedMales.end());
    cout << "Median age for employed males = " << ComputeMedianAge(EmployedMales.begin(), EmployedMales.end()) << endl;
    
    auto it6 = partition(UnemployedMales.begin(), UnemployedMales.end(), [](const Person& person) {
        return person.gender == Gender::MALE && person.is_employed == false;
    });
    UnemployedMales.erase(it6, UnemployedMales.end());
    cout << "Median age for unemployed males = " << ComputeMedianAge(UnemployedMales.begin(), UnemployedMales.end()) << endl;
}

/*int main() {
    vector<Person> persons = {
        {31, Gender::MALE, false},
        {40, Gender::FEMALE, true},
        {24, Gender::MALE, true},
        {20, Gender::FEMALE, true},
        {80, Gender::FEMALE, false},
        {78, Gender::MALE, false},
        {10, Gender::FEMALE, false},
        {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}*/
