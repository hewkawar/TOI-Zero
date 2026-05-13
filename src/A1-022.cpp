#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int d, m;
    if (!(cin >> d >> m)) return 0;

    if ((m == 12 && d >= 22) || (m == 1 && d <= 19)) cout << "capricorn" << endl;
    else if ((m == 1 && d >= 20) || (m == 2 && d <= 18)) cout << "aquarius" << endl;
    else if ((m == 2 && d >= 19) || (m == 3 && d <= 20)) cout << "pisces" << endl;
    else if ((m == 3 && d >= 21) || (m == 4 && d <= 19)) cout << "aries" << endl;
    else if ((m == 4 && d >= 20) || (m == 5 && d <= 20)) cout << "taurus" << endl;
    else if ((m == 5 && d >= 21) || (m == 6 && d <= 21)) cout << "gemini" << endl;
    else if ((m == 6 && d >= 22) || (m == 7 && d <= 22)) cout << "cancer" << endl;
    else if ((m == 7 && d >= 23) || (m == 8 && d <= 22)) cout << "leo" << endl;
    else if ((m == 8 && d >= 23) || (m == 9 && d <= 22)) cout << "virgo" << endl;
    else if ((m == 9 && d >= 23) || (m == 10 && d <= 23)) cout << "libra" << endl;
    else if ((m == 10 && d >= 24) || (m == 11 && d <= 21)) cout << "scorpio" << endl;
    else if ((m == 11 && d >= 22) || (m == 12 && d <= 21)) cout << "sagittarius" << endl;
    
    return 0;
}
