#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L;
    if (!(cin >> L)) return 0;

    string dna1 = "";
    string dna2 = "";

    for (int i = 0; i < L; ++i) {
        char c;
        cin >> c;
        dna1 += c;
    }

    for (int i = 0; i < L; ++i) {
        char c;
        cin >> c;
        dna2 += c;
    }

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int chrom_num, pos;
        char new_c;
        cin >> chrom_num >> pos >> new_c;

        if (chrom_num == 1) {
            dna1[pos] = new_c;
        } else if (chrom_num == 2) {
            dna2[pos] = new_c;
        }
    }

    int mismatches = 0;
    for (int i = 0; i < L; ++i) {
        char c1 = dna1[i];
        char c2 = dna2[i];
        bool match = false;
        
        if ((c1 == 'A' && c2 == 'T') || (c1 == 'T' && c2 == 'A') ||
            (c1 == 'C' && c2 == 'G') || (c1 == 'G' && c2 == 'C')) {
            match = true;
        }
        
        if (!match) {
            mismatches++;
        }
    }

    for (char c : dna1) {
        cout << c << " "; 
    }
    cout << "\n";
    for (char c : dna2) {
        cout << c << " ";
    }
    cout << "\n";
    cout << mismatches << "\n";

    return 0;
}