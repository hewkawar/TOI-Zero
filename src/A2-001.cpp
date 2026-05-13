#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<long long> red(n);
    for(int i = 0; i < n; i++) {
        cin >> red[i];
    }
    
    vector<long long> blue(m);
    for(int i = 0; i < m; i++) {
        cin >> blue[i];
    }
    
    int intersections = 1; // Start at 0,0
    
    int i = 0, j = 0;
    while(i < n && j < m) {
        if (red[i] == blue[j]) {
            intersections++;
            i++;
            j++;
        } else if (red[i] < blue[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    cout << intersections << endl;
    
    return 0;
}
