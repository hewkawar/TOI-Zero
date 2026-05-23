#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> numbers(3);
    for (int i = 0; i < 3; ++i) {
        cin >> numbers[i];
        cout << "Input number " << (i + 1) << " stored.\n";
    }

    int menu;
    while (cin >> menu) {
        if (menu == 0) {
            break;
        } else if (menu == 1) {
            cout << "Original order: " << numbers[0] << " " << numbers[1] << " " << numbers[2] << "\n";
        } else if (menu == 2) {
            vector<int> desc = numbers;
            sort(desc.begin(), desc.end(), greater<int>());
            cout << "Descending order: " << desc[0] << " " << desc[1] << " " << desc[2] << "\n";
        } else if (menu == 3) {
            vector<int> asc = numbers;
            sort(asc.begin(), asc.end());
            cout << "Ascending order: " << asc[0] << " " << asc[1] << " " << asc[2] << "\n";
        }
    }

    return 0;
}