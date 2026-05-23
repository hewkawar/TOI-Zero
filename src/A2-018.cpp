#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char start_color;
    int num_lights;

    
    if (!(cin >> start_color >> num_lights)) return 0;
    
    string colors[] = {"Red", "Green", "Blue"};
    int current_index = 0;
    
    if (start_color == 'R') {
        current_index = 0;
    } else if (start_color == 'G') {
        current_index = 1;
    } else if (start_color == 'B') {
        current_index = 2;
    }

    for (int i = 0; i < num_lights; ++i) {
        cout << colors[current_index];
        
        if (i < num_lights - 1) {
            cout << " ";
        }
        
        current_index = (current_index + 1) % 3;
    }
    
    cout << "\n";

    return 0;
}