#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int max_score = -1;
    vector<int> scores(n);
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] == max_score) {
            count++;
        }
    }

    cout << max_score << endl;
    cout << count << endl;

    return 0;
}
