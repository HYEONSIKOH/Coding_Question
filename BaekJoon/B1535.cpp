// 백준 1535 [DP - 배낭] 안녕
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> vec;
int dp[101][100001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N, K = 99;
	cin >> N;
	vec.resize(N+1);

	for (int i = 1; i <= N; i++) cin >> vec[i].first; // 체력 cin
	
    for (int i = 1; i <= N; i++) cin >> vec[i].second; // 기쁨 cin

	for (int i = 1; i <= N; i++) {
		int weight = vec[i].first;
		int value = vec[i].second;

		for (int j = 1; j <= K; j++) 
			dp[i][j] = (j >= weight) ? max(dp[i - 1][j], dp[i - 1][j - weight] + value) : dp[i - 1][j];
	}

	cout << dp[N][K];
	return 0;
}