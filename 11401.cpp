#include"11401.h"
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll N, K;

ll Power(ll n, ll k)
{
	if (k == 0) return 1;
	ll temp = Power(n, k / 2);
	if (k % 2 == 0) return temp * temp % MOD;
	else return (temp * temp)%MOD * n%MOD;
}

void Solve()
{
	ll a = 1, b = 1;
	// 이항 계수 : 1부터 k까지는 나누고, k+1부터 n까지는 곱한다
	for (ll i = N; N - K < i; i--) a = (a * i) % MOD;
	for (ll i = 1; i < K + 1; i++) b = (b * i) % MOD;
	cout << ((a%MOD) * (Power(b, MOD - 2)%MOD)) % MOD;
}

void B11401::Solution()
{
	cin >> N >> K;
	Solve();
}