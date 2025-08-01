#include"1655.h"
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

// push() 凶庚拭 size()亜 痕馬澗汽 
// 蝶縮廃岩獣壱 戚穿 size()研 益企稽 紫遂背辞 稽送 神嫌

void B1655::Solution()
{
	fastio;

	// 酔識授是 泥 砧鯵研 層搾廃陥
	// 是 泥澗 置社 琵戚壱, 焼掘 泥澗 置企 琵戚陥.
	// 焼巷 泥拭亀 蒸生檎 焼掘楕 泥拭 隔澗陥
	// 焼掘楕 泥 top()研 挫澗汽
	//   薄仙 呪亜 益左陥 滴檎 是 泥拭 隔澗陥
	//   薄仙 呪亜 益左陥 拙暗蟹 旭生檎 焼掘 泥拭 隔澗陥
	// 隔壱 蟹辞 挫希艦 是 泥 滴奄亜
	//   焼掘 泥 滴奄 + 1 虞檎 是 泥 皐辞 焼掘 泥拭 隔奄
	//   焼掘 泥 滴奄 - 2 虞檎 焼掘 泥 皐辞 是 泥拭 隔奄
	// けけさ
	// けけけさ
	// けささ
	priority_queue<int, vector<int>, greater<int>> uq;
	priority_queue<int> dq;
	int N, cur;
	cin >> N;
	while (N--)
	{
		cin >> cur;
		if (dq.empty()) dq.push(cur);
		else
		{
			int dqv = dq.top();
			if (dqv < cur) uq.push(cur);
			else dq.push(cur);
		}

		int uqs = uq.size();
		int dqs = dq.size();
		if (uqs == dqs + 1) { dq.push(uq.top()); uq.pop(); }
		else if (uqs == dqs - 2) { uq.push(dq.top()); dq.pop(); }

		cout << dq.top() << '\n';
	}
}