// 백준 1911 [스위핑] 흙길 보수하기!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, L;
    cin >> N >> L;
    vector< pair<int,int> > v(N + 1);

    for (int i = 1; i <= N; i++) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    int count = 0, up = 0;
    for (int i = 1; i <= N; i++) {
        if(v[i].first > up) up = v[i].first;

        while(up < v[i].second) {
            up += L;
            count++;
        }
    }

    cout << count;
    return 0;
}