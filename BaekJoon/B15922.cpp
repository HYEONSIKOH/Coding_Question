// 백준 15922 [스위핑] 아우으 우아으이야!
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;
    vector< pair<int,int> > vec(N);

    for (int i = 0; i < N; i++) cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(), vec.end());

    int s = vec[0].first, e = vec[0].second;
    long long ans = 0;
    for (int i = 1; i < N; i++) {
        int now_s = vec[i].first, now_e = vec[i].second;

        if(e >= now_s) e = max(e, now_e);
        else {
            ans += e - s;
            s = now_s;
            e = now_e;
        }
    }
    ans += e - s;

    cout << ans;
    return 0;
}