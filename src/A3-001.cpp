#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    long long left_weight = 0;
    int left_child = 0;
    long long right_weight = 0;
    int right_child = 0;
};

vector<Node> tree;

long long dfs(int u) {
    long long lw = tree[u].left_weight;
    if (tree[u].left_child != 0) {
        lw = dfs(tree[u].left_child);
    }
    long long rw = tree[u].right_weight;
    if (tree[u].right_child != 0) {
        rw = dfs(tree[u].right_child);
    }
    
    return 2 * max(lw, rw);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    tree.resize(n + 1);
    
    vector<int> in_degree(n + 1, 0);
    
    long long total_initial_weight = 0;
    
    for (int i = 1; i <= n; ++i) {
        int a, l, b, r;
        cin >> a >> l >> b >> r;
        if (a == 0) {
            tree[i].left_child = l;
            in_degree[l]++;
        } else {
            tree[i].left_weight = l;
            total_initial_weight += l;
        }
        
        if (b == 0) {
            tree[i].right_child = r;
            in_degree[r]++;
        } else {
            tree[i].right_weight = r;
            total_initial_weight += r;
        }
    }
    
    int root = 1;
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0) {
            root = i;
            break;
        }
    }
    
    long long total_final_weight = dfs(root);
    cout << total_final_weight - total_initial_weight << "\n";
    
    return 0;
}
