#include"16928.h"

namespace
{
	std::vector<int> count_vec;
	std::unordered_map<int, int> ladder;
	std::unordered_map<int, int> snake;
	int Simulate(int start, int count_pre)
	{
		// start���� 1���� 6ĭ�� ladder �ִ��� Ȯ��
		// ladder ������ �ű�� �� Simulate()
		// �⺻�����δ� 6ĭ���� Simulate()
		// ���� ������ �װͺ��� 1ĭ �Ʒ���
		// �� �� �ִ� ���� �ƹ��� ������ return 101;
		// ���ӵ� ������ �����ִ� �ʸӿ� 100���� ���� ��ٸ��� �ִٸ�, ���� Ÿ�� �װ����� �����ϴ� ��� ����
		// ��ٸ� > �� > ��ٸ� �̷��� ���� �ݺ��Ǵ� ��찡 �����ϴ� ī��Ʈ�� ������� �װͺ��� ũ�� ����� �� ���

		int count_cur = 101;
		if (start > 100 ) { return count_cur; }
		count_vec[start] = count_pre;

		bool threw_already = false;
		for (int i = 6; i >= 1; --i)
		{
			if (count_vec[start + i] < count_pre + 1) { continue; }
			if (start + i == 100)
			{
				return count_pre + 1;
			}
			else if (ladder.count(start + i))
			{
				if (count_vec[ladder[start + i]] < count_pre + 1) { continue; }
				count_cur = std::min(count_cur,Simulate(ladder[start + i], count_pre + 1));
			}
			else if (snake.count(start + i))
			{
				if (count_vec[snake[start + i]] < count_pre + 1) { continue; }
				count_cur = std::min(count_cur, Simulate(snake[start + i], count_pre + 1));
			}
			else if (!threw_already)
			{
				threw_already = true;
				count_cur = std::min(count_cur, Simulate(start + i, count_pre + 1));
			}
		}
		return count_cur;
	}
}

void B16928::Solution()
{
	int n, m;
	std::cin >> n >> m;
	while (n--) { 
		int from, to;
		std::cin >> from >> to;
		ladder[from] = to;
	}
	while (m--) {
		int from, to;
		std::cin >> from >> to;
		snake[from] = to;
	}
	count_vec = std::vector<int>(107,101);
	std::cout << Simulate(1,0);
}

 // ���� �׷��� ���ٴ� �� ��ġ�� ë�µ� Ȱ���� ����
 // bfs�� ����ġ�� ���� �׷������� �ִ� �Ÿ��� �����Ѵ�.
 // �׷��� vector<bool> visited ������ üũ ����.
 // ��� ��ٸ��� teleport�� ���� ��� �����ߴ�

//#include <bits/stdc++.h>
//using namespace std;
//
//int n, m;
//map<int, int> teleport;
//
//queue<pair<int, int>> q;
//vector<bool> visited(101, false);
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	cin >> n >> m;
//
//	// ��ٸ� 
//	for (int i = 0; i < n; i++) {
//		int from, to;
//		cin >> from >> to;
//		teleport[from] = to;
//	}
//	// ��
//	for (int i = 0; i < m; i++) {
//		int from, to;
//		cin >> from >> to;
//		teleport[from] = to;
//	}
//
//	q.push({ 1, 0 });
//	visited[1] = true;
//
//	while (!q.empty()) {
//		int curr = q.front().first;
//		int count = q.front().second;
//		q.pop();
//
//		if (curr == 100) {
//			cout << count;
//			return 0;
//		}
//
//		for (int dice = 1; dice <= 6; dice++) {
//			int next = curr + dice;
//
//			if (next > 100)
//				continue;
//
//			if (teleport.find(next) != teleport.end())
//				next = teleport[next];
//
//			if (!visited[next]) {
//				visited[next] = true;
//				q.push({ next, count + 1 });
//			}
//		}
//	}
//}