#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<string, char> > v(8);

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int grade[] = {10, 8, 6, 5, 4, 3, 2, 1, 0};

    for (int i = 0; i < 8; i++) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    int Red = 0, Blue = 0;

    for (int i = 0; i < 8; i++) {
        if (v[i].second == 'B') Blue += grade[i];
        else Red += grade[i];
    }

    if (Red > Blue) cout << "Red";
    else cout << "Blue";

    return 0;
}