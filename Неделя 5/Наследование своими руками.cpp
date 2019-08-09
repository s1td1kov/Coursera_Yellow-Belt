#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>
#include <queue>
#include <map>

using namespace std;

class Animal {
public:
    Animal(const string& s) : Name(s){
        
    }
    const string Name;
};


class Dog : public Animal {
public:
    Dog(const string& s) : Animal(s) {
        
    }
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

/*int main() {
    Dog dog("dog");
    dog.Bark();
}*/
