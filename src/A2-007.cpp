#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bucket {
    int id;
    int a, b;
    bool operator<(const Bucket& other) const {
        return a < other.a;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<Bucket> buckets(n);
    for (int i = 0; i < n; i++) {
        buckets[i].id = i + 1;
        cin >> buckets[i].a >> buckets[i].b;
    }

    vector<int> targets(m);
    for (int i = 0; i < m; i++) {
        cin >> targets[i];
    }
    sort(targets.begin(), targets.end());

    sort(buckets.begin(), buckets.end());

    vector<int> ans;
    int target_idx = 0;

    vector<int> parent(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int best_parent = 0;
        int min_len = 2e9;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (buckets[j].a <= buckets[i].a && buckets[i].b <= buckets[j].b) {
                int len = buckets[j].b - buckets[j].a;
                if (len < min_len) {
                    min_len = len;
                    best_parent = buckets[j].id;
                }
            }
        }
        parent[buckets[i].id] = best_parent;
    }
    
    vector<vector<int>> children(n + 1);
    for (int i = 1; i <= n; i++) {
        children[parent[i]].push_back(i);
    }
    
    vector<bool> is_target(n + 1, false);
    for (int t : targets) {
        is_target[t] = true;
    }

    vector<int> subtree_size(n + 1, 0);
    vector<int> target_count(n + 1, 0);
    
    auto dfs_size = [&](auto& self, int u) -> void {
        subtree_size[u] = 1;
        target_count[u] = is_target[u] ? 1 : 0;
        for (int v : children[u]) {
            self(self, v);
            subtree_size[u] += subtree_size[v];
            target_count[u] += target_count[v];
        }
    };
    
    for (int root : children[0]) {
        dfs_size(dfs_size, root);
    }
    
    struct Result {
        int moves;
        int extra;
        vector<int> picked;
        bool operator<(const Result& other) const {
            if (moves != other.moves) return moves < other.moves;
            return extra < other.extra;
        }
    };
    
    auto dfs_solve = [&](auto& self, int u) -> Result {
        if (target_count[u] == 0) return {0, 0, {}};
        
        Result pick_u;
        pick_u.moves = 1;
        pick_u.extra = subtree_size[u] - target_count[u];
        pick_u.picked = {u};
        
        Result dont_pick;
        dont_pick.moves = 0;
        dont_pick.extra = 0;
        for (int v : children[u]) {
            Result res_v = self(self, v);
            dont_pick.moves += res_v.moves;
            dont_pick.extra += res_v.extra;
            for (int p : res_v.picked) {
                dont_pick.picked.push_back(p);
            }
        }
        
        if (is_target[u]) {
            return pick_u;
        }
        
        if (pick_u < dont_pick) return pick_u;
        return dont_pick;
    };
    
    Result final_ans;
    final_ans.moves = 0;
    final_ans.extra = 0;
    for (int root : children[0]) {
        Result res = dfs_solve(dfs_solve, root);
        final_ans.moves += res.moves;
        final_ans.extra += res.extra;
        for (int p : res.picked) {
            final_ans.picked.push_back(p);
        }
    }
    
    sort(final_ans.picked.begin(), final_ans.picked.end());
    
    cout << final_ans.moves << endl;
    for (int i = 0; i < (int)final_ans.picked.size(); i++) {
        cout << final_ans.picked[i] << (i == (int)final_ans.picked.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}
