#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, l, layers;
    cin >> w >> l >> layers;
    
    int price;
    cin >> price;

    int perimeter = 2 * (w + l);
    int total_length = perimeter * layers;
    int total_price = total_length * price;

    cout << total_length << endl;
    cout << total_price << endl;

    return 0;
}
