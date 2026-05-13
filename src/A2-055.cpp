#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<double> temps(n);
    double sum = 0;
    int alert = 0;
    for (int i = 0; i < n; ++i) {
        cin >> temps[i];
        sum += temps[i];
        if (temps[i] >= 37.0) {
            alert++;
        }
    }
    
    sort(temps.begin(), temps.end());
    
    double avg = sum / n;
    double median;
    if (n % 2 != 0) {
        median = temps[n / 2];
    } else {
        median = (temps[n / 2 - 1] + temps[n / 2]) / 2.0;
    }
    
    double max_t = temps.back();
    double min_t = temps.front();
    
    cout << fixed << setprecision(2);
    cout << "SUM=" << sum << "\n";
    cout << "AVG=" << avg << "\n";
    cout << "MEDIAN=" << median << "\n";
    cout << "MAX=" << max_t << "\n";
    cout << "MIN=" << min_t << "\n";
    cout << "ALERT=" << alert << "\n";
    cout << "SORTED=";
    for (int i = 0; i < n; ++i) {
        cout << temps[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}
