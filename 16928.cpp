#include"16928.h"

namespace
{
	std::vector<int> count_vec;
	std::unordered_map<int, int> ladder;
	std::unordered_map<int, int> snake;
	int Simulate(int start, int count_pre)
	{
		// start에서 1에서 6칸에 ladder 있는지 확인
		// ladder 있으면 거기로 간 Simulate()
		// 기본적으로는 6칸으로 Simulate()
		// 뱀이 있으면 그것보다 1칸 아래로
		// 갈 수 있는 곳이 아무도 없으면 return 101;
		// 연속된 뱀으로 막혀있는 너머에 100으로 가는 사다리가 있다면, 뱀을 타서 그곳으로 가야하는 경우 존재
		// 사다리 > 뱀 > 사다리 이렇게 무한 반복되는 경우가 존재하니 카운트를 적어놓고 그것보다 크면 경우의 수 취소

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

 // 뭔가 그래프 같다는 걸 눈치는 챘는데 활용을 못함
 // bfs는 가중치가 없는 그래프에서 최단 거리를 보장한다.
 // 그래서 vector<bool> visited 만으로 체크 가능.
 // 뱀과 사다리를 teleport로 동일 취급 가능했다

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
//	// 사다리 
//	for (int i = 0; i < n; i++) {
//		int from, to;
//		cin >> from >> to;
//		teleport[from] = to;
//	}
//	// 뱀
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