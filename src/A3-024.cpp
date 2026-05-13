#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long L;
    if (!(cin >> n >> L)) return 0;
    
    vector<pair<long long, long long>> intervals;
    for (int i = 0; i < n; ++i) {
        long long s, t;
        cin >> s >> t;
        intervals.push_back({s, t});
    }
    
    // Sort intervals by their end points.
    // To minimize the number of toll points, this is exactly the minimum number of points to cover all intervals.
    // Classic greedy: sort by end time, place point at the end time, skip all intervals that contain this point.
    // Wait, the toll point can be a floating point number? Yes, but an integer point at the end is optimal.
    // The intervals are [s, t]. 
    // "si <= x <= ti"
    
    sort(intervals.begin(), intervals.end(), [](const pair<long long, long long>& a, const pair<long long, long long>& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });
    
    int points = 0;
    long long last_point = -1;
    
    for (int i = 0; i < n; ++i) {
        if (last_point == -1 || intervals[i].first > last_point) {
            points++;
            last_point = intervals[i].second;
        }
    }
    
    cout << points << "\n";
    return 0;
}
