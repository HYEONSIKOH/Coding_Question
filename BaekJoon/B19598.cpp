// 백준 19598 [스위핑] 회의실 개수
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, s, e, ans, cnt;
vector< pair<int, int> > v;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        v.push_back({ s, 1 });
        v.push_back({ e,-1 });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cnt += v[i].second;
        ans = max(ans, cnt);
    }

    cout << ans << '\n';
    return 0;
}