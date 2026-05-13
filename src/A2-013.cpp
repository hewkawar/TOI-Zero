#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char pearl_type;
    int pearl_weight;
    cin >> pearl_type >> pearl_weight;

    char tea_type;
    int sweetness, volume;
    cin >> tea_type >> sweetness >> volume;

    int pearl_cal_per_g = 0;
    if (pearl_type == 'H') pearl_cal_per_g = 5;
    else if (pearl_type == 'O') pearl_cal_per_g = 3;
    else if (pearl_type == 'J') pearl_cal_per_g = 2;

    int tea_cal_per_cc = 0;
    if (tea_type == 'R') {
        if (sweetness == 1) tea_cal_per_cc = 12;
        else if (sweetness == 2) tea_cal_per_cc = 18;
        else if (sweetness == 3) tea_cal_per_cc = 25;
    } else if (tea_type == 'T') {
        if (sweetness == 1) tea_cal_per_cc = 15;
        else if (sweetness == 2) tea_cal_per_cc = 20;
        else if (sweetness == 3) tea_cal_per_cc = 30;
    } else if (tea_type == 'M') {
        if (sweetness == 1) tea_cal_per_cc = 10;
        else if (sweetness == 2) tea_cal_per_cc = 15;
        else if (sweetness == 3) tea_cal_per_cc = 20;
    }

    int total_cal = (pearl_weight * pearl_cal_per_g) + (volume * tea_cal_per_cc);

    cout << total_cal << endl;

    return 0;
}
