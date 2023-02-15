// 백준 1806 [누적합 + 투포인터] 부분합
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> vec(N + 1);
    vector<int> psum(N + 1);

    bool temp = false;
    for (int i = 1; i <= N; i++) {
        cin >> vec[i];
        psum[i] = psum[i - 1] + vec[i];

        if (psum[i] >= K) temp = true;
    }

    if (!temp) {
        cout << 0;
        return 0;
    }

    int ans = K;
    int s = 0, e = 0;
    while (e <= N) {
        int num = psum[e] - psum[s];

        if (num >= K) {
            ans = min(ans, e - s);
            s++;
        }

        else e++;
    }

    cout << ans;
    return 0;
}
