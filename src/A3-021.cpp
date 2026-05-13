#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;
    
    vector<long long> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    // Sort the times to find the fastest runner.
    // The fastest runner has the minimum s[i].
    long long min_s = s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] < min_s) min_s = s[i];
    }
    
    // The problem statement says:
    // A runner is eliminated if they are lapped by the fastest runner while they haven't finished yet.
    // Lapped means the fastest runner finishes their (R+1)-th lap before or exactly when 
    // the slower runner finishes their R-th lap.
    // Wait, the example says:
    // fastest runner takes 6 seconds.
    // 2nd runner takes 7 seconds. 6*2 = 12. 7*1 = 7. 6*2 > 7, so not lapped in lap 1.
    // 3rd runner takes 15 seconds. 6*2 = 12. 15*1 = 15. 12 <= 15. So 3rd is lapped by 1st runner before 3rd runner finishes lap 1!
    // So 3rd runner is eliminated.
    // In general, a runner is eliminated if there exists some lap R < K (for the slower runner)
    // such that the fastest runner finishes their (R+1)-th lap at time <= slower runner finishes their R-th lap.
    // That means: min_s * (R + 1) <= s[i] * R
    // We only care if this happens while the slower runner hasn't finished.
    // The slower runner finishes at time s[i] * K. But actually, they are eliminated if the overlap happens
    // BEFORE or AT their finish time.
    // Actually, if min_s * (R + 1) <= s[i] * R for some R <= K, they are eliminated.
    // But wait! If R = K, the slower runner finishes their K-th lap at s[i] * K. 
    // The fastest runner finishes their (K+1)-th lap at min_s * (K+1).
    // The problem says "แซงระหว่างที่ยังวิ่งในรอบที่น้อยกว่า" (lapped while running in a lap less than K?)
    // "เมื่อเริ่มต้นจะไม่นับว่าถูกแซง และการถูกแซงที่เส้นชัยพอดีถือว่าเป็นการแซงด้วยเช่นเดียวกัน"
    // So if min_s * (R+1) <= s[i] * R for any R <= K?
    // Wait, the slower runner is "still running" their R-th lap, so they haven't finished K laps yet.
    // But if R = K, they are finishing their K-th lap. Are they still "in the race"?
    // Let's check the example.
    // N=5, K=3. min_s = 6.
    // p2: s=7. min_s*(R+1) = 6*(R+1). s[i]*R = 7*R.
    // R=1: 12 <= 7 (F). R=2: 18 <= 14 (F). R=3: 24 <= 21 (F). Not eliminated.
    // p3: s=15. R=1: 12 <= 15 (T). Eliminated!
    // p4: s=9. R=1: 12 <= 9 (F). R=2: 18 <= 18 (T). Eliminated!
    // p5: s=11. R=1: 12 <= 11 (F). R=2: 18 <= 22 (T). Eliminated!
    // So p2 is not eliminated. p1 is not eliminated.
    // Result: 2.
    // Wait, what if R > K? If R > K, the slower runner has already finished. They can't be lapped.
    // So we just need to check if there is ANY integer R such that 1 <= R <= K-1
    // such that min_s * (R+1) <= s[i] * R.
    // Wait, for p4, R=2 gives 18 <= 18, so eliminated! But wait, R=2 is < K.
    // What if R=K? For example, K=2, min_s=6, s=9.
    // R=1: 12 <= 9 (F). R=2: 18 <= 18 (T). If K=2, does R=2 eliminate the runner?
    // The slower runner finishes 2 laps at 18. The faster runner finishes 3 laps at 18.
    // They are at the finish line at the same time. Does this count as lapped?
    // The text says "การถูกแซงที่เส้นชัยพอดีถือว่าเป็นการแซงด้วยเช่นเดียวกัน" (lapped exactly at finish line counts).
    // BUT the text also says "แซงระหว่างที่ยังวิ่งในรอบที่น้อยกว่า" (lapped while running in a lap less than...).
    // Actually, if the fastest runner finishes lap R+1 when the slower runner finishes lap R, the faster runner has run 1 more lap.
    // If the slower runner is finishing their K-th lap, they are done. 
    // Wait, if R=K, the slower runner finishes their K-th lap. At that EXACT moment, the faster runner finishes their (K+1)-th lap.
    // Does the slower runner get eliminated? "การถูกแซงที่เส้นชัยพอดีถือว่าเป็นการแซงด้วยเช่นเดียวกัน" implies YES.
    // Let's check R <= K or R < K.
    // In example, K=3. p4 has R=2 <= 3.
    // Let's rewrite the condition: min_s * (R+1) <= s[i] * R for some R in 1..K.
    // => min_s <= R * (s[i] - min_s).
    // If s[i] == min_s, then min_s <= 0, impossible since min_s > 0.
    // If s[i] > min_s, then R >= ceil(min_s / (s[i] - min_s)).
    // So the condition is that the minimum R satisfying min_s * (R+1) <= s[i] * R is <= K.
    // Wait, we need min_s * (R+1) <= s[i] * R.
    // min_s * R + min_s <= s[i] * R
    // min_s <= R * (s[i] - min_s)
    // R >= min_s / (s[i] - min_s). Since R must be integer, min R = ceil(min_s / (s[i] - min_s)).
    // So if ceil(min_s / (s[i] - min_s)) <= K, then they are eliminated.
    // ceil(A / B) is (A + B - 1) / B.
    // Let's check p4: min_s = 6, s[i] = 9.
    // R >= 6 / 3 = 2. So min R = 2. Since 2 <= 3, eliminated.
    // Let's check p5: min_s = 6, s[i] = 11.
    // R >= 6 / 5 = 1.2. min R = 2. 2 <= 3, eliminated.
    // Let's check p2: min_s = 6, s[i] = 7.
    // R >= 6 / 1 = 6. min R = 6. 6 > 3, so not eliminated.
    // So the condition is exactly ceil(min_s / (s[i] - min_s)) <= K.
    // Is it really R <= K? Or R < K?
    // "และการถูกแซงที่เส้นชัยพอดีถือว่าเป็นการแซงด้วยเช่นเดียวกัน" -> "and being lapped exactly at the finish line counts as lapped too".
    // If the slower runner finishes their K-th lap at time K*s[i], and the faster runner finishes their (K+1)-th lap at time (K+1)*min_s.
    // If (K+1)*min_s <= K*s[i], they are lapped at or before the finish line of their K-th lap.
    // So the slower runner is eliminated.
    // Yes, R can be K. 
    
    int not_eliminated = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == min_s) {
            not_eliminated++;
        } else {
            long long diff = s[i] - min_s;
            long long min_R = (min_s + diff - 1) / diff;
            if (min_R > k) {
                not_eliminated++;
            }
        }
    }
    
    cout << not_eliminated << "\n";
    return 0;
}
