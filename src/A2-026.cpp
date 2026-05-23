#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int over_count = 0;
    long long max_weight = 0;
    string max_name = "";

    for (int i = 0; i < n; ++i) {
        string name;
        long long weight;
        cin >> name >> weight;

        if (weight > 15) {
            over_count++;
        }

        if (i == 0 || weight > max_weight) {
            max_weight = weight;
            max_name = name;
        }
    }

    cout << over_count << "\n";
    cout << max_name << " " << max_weight << "\n";

    return 0;
}