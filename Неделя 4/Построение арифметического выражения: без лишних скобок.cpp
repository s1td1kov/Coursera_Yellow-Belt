#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iterator>
#include <queue>
#include <map>

using namespace std;

struct Operation {
    char type = 0;
    int number = 0;
};

bool NeedsBrackets(char first, char last) {
    return (first == '+' || first == '-') && (last == '*' || last == '/');
}

int main() {
    int initial_number;
    cin >> initial_number;
    
    int number_of_operations;
    cin >> number_of_operations;
    vector<Operation> operations(number_of_operations);
    for (int i = 0; i < number_of_operations; ++i) {
        cin >> operations[i].type;
        cin >> operations[i].number;
    }
    
    deque<string> expression;
    expression.push_back(to_string(initial_number));
    char first = '*';
    for (const auto& operation : operations) {
        if(NeedsBrackets(first, operation.type)) {
            expression.push_front("(");
            expression.push_back(")");
        }
        
        expression.push_back(" ");
        expression.push_back(string(1, operation.type));
        expression.push_back(" ");
        expression.push_back(to_string(operation.number));
        
        first = operation.type;
    }
    
    for (const string& s : expression) {
        cout << s;
    }
    
    return 0;
}
