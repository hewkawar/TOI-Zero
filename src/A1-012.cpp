#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num;
    char op;
    if (cin >> num >> op) {
        int reversed_num = (num % 10) * 10 + (num / 10);
        if (op == '+') {
            cout << num << " + " << reversed_num << " = " << (num + reversed_num) << "\n";
        } else if (op == '*') {
            cout << num << " * " << reversed_num << " = " << (num * reversed_num) << "\n";
        }
    }
    
    return 0;
}
