#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string first_name, last_name;
    int age;
    if (cin >> first_name >> last_name >> age) {
        if (first_name.length() > 5 && last_name.length() > 5) {
            cout << first_name.substr(0, 2) << last_name.back() << (age % 10) << "\n";
        } else {
            cout << first_name[0] << age << last_name.back() << "\n";
        }
    }
    
    return 0;
}
