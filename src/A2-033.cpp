#include <iostream>
#include <string>

using namespace std;

int parse_time(const string& s) {
    size_t dot = s.find('.');
    if (dot == string::npos) return -1;
    
    string hs = s.substr(0, dot);
    string ms = s.substr(dot + 1);
    
    if (hs.empty() || ms.empty()) return -1;
    if (hs[0] == '-') return -1;
    
    for (char c : hs) if (!isdigit(c)) return -1;
    for (char c : ms) if (!isdigit(c)) return -1;
    
    if (ms.length() != 2) return -1;
    
    int h = stoi(hs);
    int m = stoi(ms);
    
    if (h < 0 || h > 23) return -1;
    if (m < 0 || m > 59) return -1;
    
    return h * 60 + m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;
    
    int t1 = parse_time(s1);
    int t2 = parse_time(s2);
    
    if (t1 == -1 || t2 == -1 || t1 >= t2) {
        cout << "ERROR\n";
        return 0;
    }
    
    int diff = t2 - t1;
    
    if (diff < 15) {
        cout << "FREE\n";
    } else {
        int hours = (diff + 59) / 60;
        
        if (hours == 1) cout << "25\n";
        else if (hours == 2) cout << "50\n";
        else if (hours == 3) cout << "80\n";
        else if (hours == 4) cout << "110\n";
        else if (hours == 5) cout << "145\n";
        else if (hours == 6) cout << "180\n";
        else cout << "250\n";
    }
    
    return 0;
}