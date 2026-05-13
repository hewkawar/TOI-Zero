#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    
    string names[] = {
        "",
        "TechTrends",
        "EcoLife",
        "FoodieHeaven",
        "FashionWeek",
        "HealthyLiving"
    };
    
    long long max_total = -1;
    string top_performer = "";
    
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        long long total = 0;
        long long first_day = 0, last_day = 0;
        for (int j = 0; j < d; ++j) {
            long long u;
            cin >> u;
            total += u;
            if (j == 0) first_day = u;
            if (j == d - 1) last_day = u;
        }
        double avg = (double)total / d;
        string trend;
        if (last_day > first_day) trend = "GROWING";
        else if (last_day < first_day) trend = "DECLINING";
        else trend = "STABLE";
        
        cout << names[id] << ": " << total << " total, " 
             << fixed << setprecision(2) << avg << " avg, " << trend << "\n";
             
        if (total > max_total) {
            max_total = total;
            top_performer = names[id];
        }
    }
    
    cout << "Top performer: " << top_performer << "\n";
    
    return 0;
}
