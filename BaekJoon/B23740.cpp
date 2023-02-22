// 백준 23740 [스위핑] 버스 노선 개편하기
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector< pair< pair<int, int>, ll> > v, ans;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; i++)
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;

    sort(v.begin(), v.end());
    
    int s = v[0].first.first, e = v[0].first.second; 
    long long cost = v[0].second;
    for (int i = 1; i < N; i++) {
        int now_s = v[i].first.first, now_e = v[i].first.second;
        long long now_cost = v[i].second;

        if (now_s <= e && s <= now_s) {
            e = max(now_e, e);
            cost = min(cost, now_cost);
        }

        else {
            ans.push_back({ {s, e}, cost });
            s = now_s, e = now_e, cost = now_cost;
        }
    }
    ans.push_back({ {s, e}, cost });
    sort(ans.begin(), ans.end());
    
    int sz = ans.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; i++)
        cout << ans[i].first.first << ' ' << ans[i].first.second << ' ' << ans[i].second << '\n';

    return 0;
}