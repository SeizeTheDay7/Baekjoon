#include"12865.h"
using namespace std;
#define fastIO cin.tie(0)->sync_with_stdio(0)

void B12865::Solution()
{
	int N, W, V, K;
	cin >> N >> K;
	vector<int> dp(K+1);
	for(int i=1; i<N+1; i++)
	{
		cin >> W >> V;
		for (int j = K; 1 <= j; j--) {
			int temp = 0;
			if (j - W >= 0) temp = dp[j - W] + V;
			dp[j] = max(dp[j], temp);
		}
	}
	cout << dp[K];
}