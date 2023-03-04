//백준 16493 [DP + 배낭] 최대 페이지 수
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> vec;
int dp[101][100001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int N, K;
	cin >> K >> N;
	vec.resize(N+1);

	for (int i = 1; i <= N; i++) {
		int W, V;
		cin >> W >> V;

		vec[i] = { W,V };
	}

	for (int i = 1; i <= N; i++) {
		int weight = vec[i].first;
		int value = vec[i].second;

		for (int j = 1; j <= K; j++) 
			dp[i][j] = (j >= weight) ? max(dp[i - 1][j], dp[i - 1][j - weight] + value) : dp[i - 1][j];
	}

	cout << dp[N][K];
	return 0;
}