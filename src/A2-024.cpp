#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, P;
    if (!(cin >> L >> P)) return 0;

    int dR, dM, dF;
    cin >> dR >> dM >> dF;

    vector<int> score(L + 1, 0);
    for (int i = 0; i < P; ++i) {
        int pos, pts;
        cin >> pos >> pts;
        if (pos <= L) {
            score[pos] = pts;
        }
    }

    int sR = 0, sM = 0, sF = 0;
    
    for (int i = 0; i <= L; i += dR) sR += score[i];
    for (int i = 0; i <= L; i += dM) sM += score[i];
    for (int i = 0; i <= L; i += dF) sF += score[i];

    int max_score = max({sR, sM, sF});

    if (sR == max_score) cout << "Rabbit " << sR << "\n";
    if (sM == max_score) cout << "Monkey " << sM << "\n";
    if (sF == max_score) cout << "Frog " << sF << "\n";

    return 0;
}