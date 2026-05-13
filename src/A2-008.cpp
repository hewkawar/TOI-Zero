#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Car {
    int id;
    int p;
    int v;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Car> cars(n);
    for (int i = 0; i < n; i++) {
        cars[i].id = i + 1;
        cin >> cars[i].p >> cars[i].v;
    }

    int unsellable_count = 0;
    int max_v_so_far = -1;
    
    for (int i = n - 1; i >= 0; i--) {
        if (cars[i].v < max_v_so_far) {
            unsellable_count++;
        } else {
            max_v_so_far = cars[i].v;
        }
    }

    cout << unsellable_count << endl;

    return 0;
}
