#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    if (n < 1 || n > 10 || m < 1 || m > 20) {
        cout << "Data Incorrect\n";
        return 0;
    }
    
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        long long sum = 0;
        int max_score = -1;
        for (int j = 0; j < m; ++j) {
            int score;
            cin >> score;
            sum += score;
            if (score > max_score) max_score = score;
        }
        total += sum;
        double avg = (double)sum / m;
        cout << "Team " << i << ": Average = " << fixed << setprecision(2) << avg << ", Max = " << max_score << "\n";
    }
    cout << "Total Score of All Teams = " << total << "\n";
    
    return 0;
}
