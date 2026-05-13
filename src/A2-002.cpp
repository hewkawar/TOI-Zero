#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    int max_size = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = abs(pts[i].x - pts[j].x);
            int dy = abs(pts[i].y - pts[j].y);

            if (dx == dy && dx > 0) {
                max_size = max(max_size, dx);
            }
        }
    }

    cout << max_size << endl;

    return 0;
}
