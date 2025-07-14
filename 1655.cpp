#include"1655.h"
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

// push() 때문에 size()가 변하는데 
// 캐싱한답시고 이전 size()를 그대로 사용해서 로직 오류

void B1655::Solution()
{
	fastio;

	// 우선순위 큐 두개를 준비한다
	// 위 큐는 최소 힙이고, 아래 큐는 최대 힙이다.
	// 아무 큐에도 없으면 아래쪽 큐에 넣는다
	// 아래쪽 큐 top()를 봤는데
	//   현재 수가 그보다 크면 위 큐에 넣는다
	//   현재 수가 그보다 작거나 같으면 아래 큐에 넣는다
	// 넣고 나서 봤더니 위 큐 크기가
	//   아래 큐 크기 + 1 라면 위 큐 빼서 아래 큐에 넣기
	//   아래 큐 크기 - 2 라면 아래 큐 빼서 위 큐에 넣기
	// ㅁㅁㅅ
	// ㅁㅁㅁㅅ
	// ㅁㅅㅅ
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