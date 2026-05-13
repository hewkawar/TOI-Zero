#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int depth;
    int len;
};

class SegTree {
    int n;
    vector<int> tree;
public:
    SegTree(const vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }
    
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        }
    }
    
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 2e9;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return min(p1, p2);
    }
    
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int current_depth = 0;
    vector<int> depths; // depths of segments
    vector<int> lengths; // lengths of segments
    
    for (int i = 0; i < n; i++) {
        int d, l;
        cin >> d >> l;
        current_depth += d;
        depths.push_back(current_depth);
        lengths.push_back(l);
    }
    
    int max_d = 0;
    for (int d : depths) max_d = max(max_d, d);
    
    vector<long long> max_W(max_d + 1, 0);

    vector<vector<int>> segments_by_depth(max_d + 1);
    for (int i = 0; i < n; i++) {
        segments_by_depth[depths[i]].push_back(i);
    }
    
    vector<int> parent(n);
    vector<long long> size(n, 0);
    vector<bool> active(n, false);
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = lengths[i];
    }
    
    auto find = [&](auto& self, int i) -> int {
        if (parent[i] == i) return i;
        return parent[i] = self(self, parent[i]);
    };
    
    long long current_max_w = 0;
    
    auto merge = [&](int i, int j) {
        int root_i = find(find, i);
        int root_j = find(find, j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            size[root_j] += size[root_i];
            current_max_w = max(current_max_w, size[root_j]);
        }
    };
    
    for (int d = max_d; d >= 1; d--) {
        for (int i : segments_by_depth[d]) {
            active[i] = true;
            current_max_w = max(current_max_w, size[i]);
            
            if (i > 0 && active[i - 1]) {
                merge(i, i - 1);
            }
            if (i < n - 1 && active[i + 1]) {
                merge(i, i + 1);
            }
        }
        max_W[d] = current_max_w;
    }
    
    for (int i = 0; i < q; i++) {
        long long w;
        cin >> w;
        
        int low = 1, high = max_d;
        int best_d = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (max_W[mid] >= w) {
                best_d = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << best_d << endl;
    }

    return 0;
}
