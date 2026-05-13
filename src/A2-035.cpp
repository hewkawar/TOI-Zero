#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr(3);
    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
        cout << "Input number " << i + 1 << " stored." << endl;
    }

    int choice;
    if (cin >> choice) {
        if (choice == 1) {
            cout << "Original order: " << arr[0] << " " << arr[1] << " " << arr[2] << endl;
        } else if (choice == 2) {
            vector<int> sorted_arr = arr;
            sort(sorted_arr.begin(), sorted_arr.end(), greater<int>());
            cout << "Descending order: " << sorted_arr[0] << " " << sorted_arr[1] << " " << sorted_arr[2] << endl;
        } else if (choice == 3) {
            vector<int> sorted_arr = arr;
            sort(sorted_arr.begin(), sorted_arr.end());
            cout << "Ascending order: " << sorted_arr[0] << " " << sorted_arr[1] << " " << sorted_arr[2] << endl;
        }
    }

    return 0;
}
