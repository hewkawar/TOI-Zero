#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
};

bool compareIntervals(const Interval& a, const Interval& b) {
    if (a.start != b.start) return a.start < b.start;
    return a.end < b.end;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<Interval> intervals;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            intervals.push_back({a, 360});
            intervals.push_back({0, b});
        } else {
            intervals.push_back({a, b});
        }
    }
    
    sort(intervals.begin(), intervals.end(), compareIntervals);
    
    int max_length = 0;
    if (intervals.empty()) {
        cout << 0 << "\n";
        return 0;
    }
    
    int current_start = intervals[0].start;
    int current_end = intervals[0].end;
    
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i].start <= current_end) {
            current_end = max(current_end, intervals[i].end);
        } else {
            max_length = max(max_length, current_end - current_start);
            current_start = intervals[i].start;
            current_end = intervals[i].end;
        }
    }
    max_length = max(max_length, current_end - current_start);
    
    // Check if the entire circle is covered.
    // The merged intervals might cover the entire circle 0 to 360.
    // Actually, if we merge and there's only one interval from 0 to 360, the answer is 360.
    // The previous loop handles this, but what if there's a gap?
    // It's correct because we split intervals that cross 360 into two.
    // For example, 350 to 60 becomes [350, 360] and [0, 60].
    // If these merge with other intervals to form [0, 360], length is 360.
    
    // Wait, what if [350, 360] and [0, 60] merge with [50, 355]?
    // intervals: [0, 60], [50, 355], [350, 360].
    // Merged: [0, 360]. max_length = 360.
    // What if [350, 360] and [0, 60] and NO other intervals?
    // Merged: [0, 60] (len 60), [350, 360] (len 10).
    // But they are actually connected! 350 to 360 is connected to 0 to 60.
    // So the actual length of this contiguous illuminated segment is 10 + 60 = 70.
    // Let's refine the merging to handle circular connectivity.
    // After merging into a list of disjoint intervals, if there is more than 1 interval,
    // we should check if the first interval starts at 0 and the last interval ends at 360.
    // If so, they are connected, and their combined length is (last_end - last_start) + (first_end - first_start).
    
    vector<Interval> merged;
    current_start = intervals[0].start;
    current_end = intervals[0].end;
    
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i].start <= current_end) {
            current_end = max(current_end, intervals[i].end);
        } else {
            merged.push_back({current_start, current_end});
            current_start = intervals[i].start;
            current_end = intervals[i].end;
        }
    }
    merged.push_back({current_start, current_end});
    
    max_length = 0;
    for (const auto& inter : merged) {
        max_length = max(max_length, inter.end - inter.start);
    }
    
    if (merged.size() > 1) {
        if (merged.front().start == 0 && merged.back().end == 360) {
            int combined_length = (merged.back().end - merged.back().start) + (merged.front().end - merged.front().start);
            max_length = max(max_length, combined_length);
        }
    } else if (merged.size() == 1) {
        if (merged.front().start == 0 && merged.front().end == 360) {
            max_length = 360;
        }
    }
    
    cout << max_length << "\n";
    return 0;
}
