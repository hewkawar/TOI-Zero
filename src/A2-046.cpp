#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    string name;
    int score;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n == 0) {
        cout << "Student:" << endl;
        cout << "Highest score: 0" << endl;
        cout << "Lowest score: 0" << endl;
        cout << "Average score: 0.0" << endl;
        cout << "Students who scored above average:" << endl;
        return 0;
    }

    vector<Student> students(n);
    int total_score = 0;
    int highest = -1;
    int lowest = 101;

    for (int i = 0; i < n; i++) {
        cin >> students[i].score;
        students[i].name = "Student" + to_string(i + 1);
        
        total_score += students[i].score;
        if (students[i].score > highest) highest = students[i].score;
        if (students[i].score < lowest) lowest = students[i].score;
    }

    cout << "Student:";
    for (int i = 0; i < n; i++) {
        cout << " " << students[i].name;
    }
    cout << endl;

    cout << "Highest score: " << highest << endl;
    cout << "Lowest score: " << lowest << endl;

    double avg = (double)total_score / n;
    cout << "Average score: " << fixed << setprecision(1) << avg << endl;

    cout << "Students who scored above average:" << endl;
    for (int i = 0; i < n; i++) {
        if (students[i].score > avg) {
            cout << "Student " << (i + 1) << endl;
        }
    }

    return 0;
}
