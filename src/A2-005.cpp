#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long w, h;
    int m, n;
    cin >> w >> h >> m >> n;

    vector<long long> x_cuts(m);
    for (int i = 0; i < m; i++) {
        cin >> x_cuts[i];
    }

    vector<long long> y_cuts(n);
    for (int i = 0; i < n; i++) {
        cin >> y_cuts[i];
    }

    vector<long long> widths;
    widths.push_back(x_cuts[0]);
    for (int i = 1; i < m; i++) {
        widths.push_back(x_cuts[i] - x_cuts[i - 1]);
    }
    widths.push_back(w - x_cuts[m - 1]);

    vector<long long> heights;
    heights.push_back(y_cuts[0]);
    for (int i = 1; i < n; i++) {
        heights.push_back(y_cuts[i] - y_cuts[i - 1]);
    }
    heights.push_back(h - y_cuts[n - 1]);

    sort(widths.begin(), widths.end(), greater<long long>());
    sort(heights.begin(), heights.end(), greater<long long>());

    vector<long long> areas;
    for (int i = 0; i < min(3, (int)widths.size()); i++) {
        for (int j = 0; j < min(3, (int)heights.size()); j++) {
            areas.push_back(widths[i] * heights[j]);
        }
    }

    sort(areas.begin(), areas.end(), greater<long long>());

    cout << areas[0] << " " << areas[1] << endl;

    return 0;
}
