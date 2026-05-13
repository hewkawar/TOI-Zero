#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string t_in, t_out;
    cin >> t_in >> t_out;

    // Parse HH.MM
    int h_in = stoi(t_in.substr(0, t_in.find('.')));
    int m_in = stoi(t_in.substr(t_in.find('.') + 1));
    
    int h_out = stoi(t_out.substr(0, t_out.find('.')));
    int m_out = stoi(t_out.substr(t_out.find('.') + 1));

    // Validate times
    bool valid_in = (h_in >= 0 && h_in <= 23 && m_in >= 0 && m_in <= 59);
    bool valid_out = (h_out >= 0 && h_out <= 23 && m_out >= 0 && m_out <= 59);
    
    int time_in_mins = h_in * 60 + m_in;
    int time_out_mins = h_out * 60 + m_out;

    if (!valid_in || !valid_out || time_out_mins < time_in_mins) {
        cout << "ERROR" << endl;
        return 0;
    }

    int duration = time_out_mins - time_in_mins;

    if (duration < 15) {
        cout << "FREE" << endl;
        return 0;
    }

    int hours = duration / 60;
    if (duration % 60 > 0) {
        hours++;
    }

    int fee = 0;
    if (hours == 1) fee = 25;
    else if (hours == 2) fee = 50;
    else if (hours == 3) fee = 80;
    else if (hours == 4) fee = 110;
    else if (hours == 5) fee = 145;
    else if (hours == 6) fee = 180;
    else fee = 250;

    cout << fee << endl;

    return 0;
}
