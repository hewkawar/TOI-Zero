#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate_permutations(int n, const vector<string>& elements, vector<string>& current, vector<bool>& used, int& total_count) {
    if (current.size() == n) {
        for (int i = 0; i < n; ++i) {
            cout << current[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
        total_count++;
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            used[i] = true;
            current.push_back(elements[i]);

            generate_permutations(n, elements, current, used, total_count);

            current.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> elements(n);
    for (int i = 0; i < n; ++i) {
        cin >> elements[i];
    }

    vector<string> current;
    vector<bool> used(n, false);
    int total_count = 0;

    generate_permutations(n, elements, current, used, total_count);

    cout << total_count << "\n";

    return 0;
}