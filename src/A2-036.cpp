#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void generate_permutations(vector<string>& elements, int index, int n, vector<string>& current_permutation, vector<bool>& used, int& count) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            cout << current_permutation[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
        count++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            current_permutation[index] = elements[i];
            generate_permutations(elements, index + 1, n, current_permutation, used, count);
            used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> elements(n);
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    vector<string> current_permutation(n);
    vector<bool> used(n, false);
    int count = 0;

    generate_permutations(elements, 0, n, current_permutation, used, count);

    cout << count << endl;

    return 0;
}
