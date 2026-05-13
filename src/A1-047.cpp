#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, a;
    if (!(cin >> n >> a)) return 0;

    int totalMinutes = n * a;
    if (totalMinutes == 0) {
        cout << "No teaching" << endl;
    } else {
        int hours = totalMinutes / 60;
        int minutes = totalMinutes % 60;

        if (hours > 0 && minutes > 0) {
            cout << hours << " hours " << minutes << " minutes" << endl;
        } else if (hours > 0) {
            cout << hours << " hours" << endl;
        } else {
            cout << minutes << " minutes" << endl;
        }
    }
    
    return 0;
}
