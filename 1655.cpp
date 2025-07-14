#include"1655.h"
#define INF 0x3f3f3f3f
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

// push() ������ size()�� ���ϴµ� 
// ĳ���Ѵ�ð� ���� size()�� �״�� ����ؼ� ���� ����

void B1655::Solution()
{
	fastio;

	// �켱���� ť �ΰ��� �غ��Ѵ�
	// �� ť�� �ּ� ���̰�, �Ʒ� ť�� �ִ� ���̴�.
	// �ƹ� ť���� ������ �Ʒ��� ť�� �ִ´�
	// �Ʒ��� ť top()�� �ôµ�
	//   ���� ���� �׺��� ũ�� �� ť�� �ִ´�
	//   ���� ���� �׺��� �۰ų� ������ �Ʒ� ť�� �ִ´�
	// �ְ� ���� �ô��� �� ť ũ�Ⱑ
	//   �Ʒ� ť ũ�� + 1 ��� �� ť ���� �Ʒ� ť�� �ֱ�
	//   �Ʒ� ť ũ�� - 2 ��� �Ʒ� ť ���� �� ť�� �ֱ�
	// ������
	// ��������
	// ������
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