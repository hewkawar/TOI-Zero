#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string firstName, lastName;
    if (cin >> firstName >> lastName) {
        cout << "Hello " << firstName << " " << lastName << "\n";
        cout << firstName.substr(0, 2) << lastName.substr(0, 2) << "\n";
    }
    
    return 0;
}
