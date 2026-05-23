#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    cout << "Student:";
    for (int i = 1; i <= n; ++i) {
        cout << " Student" << i;
    }
    cout << "\n";

    if (n == 0) {
        cout << "Highest score: 0\n";
        cout << "Lowest score: 0\n";
        cout << "Average score: 0.0\n";
        cout << "Students who scored above average:\n";
        return 0;
    }

    vector<int> scores(n);
    int highest = -1;
    int lowest = 101;
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
        if (scores[i] > highest) highest = scores[i];
        if (scores[i] < lowest) lowest = scores[i];
        sum += scores[i];
    }

    double average = (double)sum / n;

    cout << "Highest score: " << highest << "\n";
    cout << "Lowest score: " << lowest << "\n";
    cout << "Average score: " << fixed << setprecision(1) << average << "\n";
    cout << "Students who scored above average:\n";

    for (int i = 0; i < n; ++i) {
        if ((double)scores[i] > average) {
            cout << "Student " << (i + 1) << "\n";
        }
    }

    return 0;
}