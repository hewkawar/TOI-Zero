#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> arr(5, vector<int>(5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    int bad_row = -1;
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += arr[i][j];
        }
        if (sum % 2 != 0) {
            bad_row = i;
            break;
        }
    }

    int bad_col = -1;
    for (int j = 0; j < 5; j++) {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += arr[i][j];
        }
        if (sum % 2 != 0) {
            bad_col = j;
            break;
        }
    }

    cout << bad_row << " " << bad_col << endl;

    return 0;
}
