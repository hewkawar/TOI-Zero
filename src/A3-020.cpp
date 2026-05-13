#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long h1, h2, b1, b2, x, y;
    if (!(cin >> h1 >> h2 >> b1 >> b2 >> x >> y)) return 0;
    
    // We want to maximize the total number of robots we can sell.
    // Each sold robot gives 1 unit of money.
    // Condition 1: Same color robots (H1+B1 and H2+B2), up to X.
    // Condition 2: Different color robots (H1+B2 and H2+B1), up to Y.
    // We can make:
    // w1: white head + white body. Uses H1, B1. Max X for (w1 + b2).
    // b2: black head + black body. Uses H2, B2. 
    // w2: white head + black body. Uses H1, B2. Max Y for (w2 + b1).
    // b1: black head + white body. Uses H2, B1.
    // Wait, the rule is "min(L, Y) where L is the number of robots with different colors".
    // So if w1 + b2 > X, we only get X money.
    // If w2 + b1 > Y, we only get Y money.
    // The total money is min(w1 + b2, X) + min(w2 + b1, Y).
    // We want to assign H1, H2, B1, B2 to maximize this total.
    // We have constraints:
    // w1 + w2 <= h1
    // b1 + b2 <= h2
    // w1 + b1 <= b1_tot
    // w2 + b2 <= b2_tot
    // w1, w2, b1, b2 >= 0
    
    long long max_money = 0;
    for (long long w1 = 0; w1 <= h1 && w1 <= b1; ++w1) {
        for (long long w2 = 0; w2 <= h1 - w1 && w2 <= b2; ++w2) {
            for (long long blk1 = 0; blk1 <= h2 && blk1 <= b1 - w1; ++blk1) {
                long long b2_cnt = min(h2 - blk1, b2 - w2);
                
                long long same_color = w1 + b2_cnt;
                long long diff_color = w2 + blk1;
                
                long long money = min(same_color, x) + min(diff_color, y);
                if (money > max_money) {
                    max_money = money;
                }
            }
        }
    }
    
    cout << max_money << "\n";
    return 0;
}
