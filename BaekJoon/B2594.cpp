// 백준 2594 [스위핑] 놀이공원
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;
    
    vector< pair<int,int> > v(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;

        if (v[i].first % 100 < 10) v[i].first -= 50;
        else v[i].first -= 10;

        if (v[i].second % 100 >= 50) v[i].second += 50;
        else v[i].second += 10;
    }

    sort(v.begin(), v.end());
    v[N].first = 2200;

    int ans = 0, rest, last = 1000;
    for (int i = 0; i <= N; i++) {
        if (v[i].first > last) {
            if (v[i].first % 100 < last % 100)
                rest = v[i].first - 40 - last;
            
            else rest = v[i].first - last;

            rest = rest / 100 * 60 + rest % 100;
 
            if (rest > ans) ans = rest;
        }
        cout << rest << ' ';
        if (v[i].second > last) last = v[i].second;
    }

    cout << ans;
    return 0;
}