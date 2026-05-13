#include <iostream>
#include <vector>

using namespace std;

struct Report {
    long long x, y, d;
};

int main() {
    int n;
    cin >> n;
    
    vector<Report> reports(n);
    for (int i = 0; i < n; ++i) {
        cin >> reports[i].x >> reports[i].y >> reports[i].d;
    }
    
    for (long long tx = 0; tx <= 1000; ++tx) {
        for (long long ty = 0; ty <= 1000; ++ty) {
            bool ok = true;
            for (const auto& r : reports) {
                long long dx = tx - r.x;
                long long dy = ty - r.y;
                if (dx * dx + dy * dy != r.d * r.d) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << tx << " " << ty << "\n";
                return 0;
            }
        }
    }
    return 0;
}
