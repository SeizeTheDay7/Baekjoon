#include "1260.h"

// bfs에서 큐에 넣을 때 방문처리해야 중복 처리 안됨
// dfs에서 스택에 넣을 때 낮은 것부터 처리하려면 큰 것부터 넣어야 함
// vector를 인자로 넣으면 값 복사가 이루어져서 엄청난 오버헤드 발생
// 인자에 넣을 거면 포인터를 전달했어야 했음

namespace {
	std::vector<std::vector<int>> graph;
	std::vector<bool> dfs_visited;
	void dfs(int node)
	{
		dfs_visited[node] = true;
		std::cout << node << ' ';
		for (int next_node : graph[node])
		{
			if (!dfs_visited[next_node])
				dfs(next_node);
		}
	}

	void bfs(int v)
	{
		std::queue<int> q;
		std::vector<bool> visited(graph.size(), false);
		q.push(v);
		visited[v] = true;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			std::cout << node << ' ';
			for (int next_node : graph[node])
			{
				if (!visited[next_node])
				{
					visited[next_node] = true;
					q.push(next_node);
				}
			}
		}
	}
}

void B1260::Solution()
{
	//int n, m, v;
	//scanf("%d %d %d", &n, &m, &v);

	//std::unordered_map<int, std::set<int>> g;
	//std::vector<bool> visited(n+1, false);
	//for (int i = 0; i < m; i++)
	//{
	//	int a, b;
	//	scanf("%d %d", &a, &b);
	//	g[a].insert(b);
	//	g[b].insert(a);
	//}

	//// dfs
	//std::stack<int> s;
	//s.push(v);
	//while (!s.empty())
	//{
	//	int node = s.top();
	//	s.pop();
	//	if (visited[node]) continue;
	//	visited[node] = true;
	//	printf("%d ", node);

	//	for (auto it = g[node].rbegin(); it != g[node].rend(); ++it)
	//	{
	//		s.push(*it);
	//	}
	//}

	//printf("\n");
	//std::fill(visited.begin(), visited.end(), false);

	//// bfs
	//std::queue<int> q;
	//visited[v] = true;
	//q.push(v);
	//while (!q.empty())
	//{
	//	int node = q.front();
	//	q.pop();
	//	printf("%d ", node);

	//	for (int i : g[node])
	//	{
	//		if (!visited[i]) {
	//			visited[i] = true;
	//			q.push(i);
	//		}
	//	}
	//}

	
	int n, m, v;
	std::cin >> n >> m >> v;
	graph.resize(n+1);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < n + 1; ++i)
		std::sort(graph[i].begin(), graph[i].end());

	dfs_visited.resize(n + 1, false);
	dfs(v);
	std::cout << std::endl;
	bfs(v);
}