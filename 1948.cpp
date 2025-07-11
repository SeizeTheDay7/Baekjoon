#include"1948.h"
using namespace std;
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f

void B1948::Solution()
{
	// 인덱스랑 실제 번호랑 헷갈리는거 주의
	// dfs 하고 최장 길이 갱신되면 경로 역추적해서 노드 세기

	int n, m;
	cin >> n; // 도시의 개수
	cin >> m; // 도로의 개수
	vector<vector<pii>> graph(n+1);
	vector<int> indegree(n + 1);
	vector<int> max_time(n + 1, 0);
	vector<vector<int>> pre_node(n + 1);
	vector<bool> visited(n + 1, false);

	int start, arrive, time;
	for (int i = 0; i < m; ++i) {
		cin >> start >> arrive >> time;
		graph[start].push_back({arrive,time});
		indegree[arrive]++;
	}

	int start_city, arrive_city;
	cin >> start_city >> arrive_city;

	queue<int> q;
	q.push(start_city);
	while (!q.empty()) {
		start = q.front();
		q.pop();
		for (pii edge : graph[start]) {
			arrive = edge.first;
			time = edge.second;
			if (max_time[arrive] == time + max_time[start]) {
				pre_node[arrive].push_back(start);
			}
			else if (max_time[arrive] < time + max_time[start]) {
				max_time[arrive] = time + max_time[start];
				pre_node[arrive] = { start };
			}
			indegree[arrive]--;
			if (indegree[arrive] == 0) {
				q.push(arrive);
			}
		}
	}
	int max_time_road = 0;
	q.push(arrive_city);
	while (!q.empty()) {
		int node_e = q.front(); q.pop();
		for (int node_s : pre_node[node_e]) {
			max_time_road++;
			if (visited[node_s]) continue;
			q.push(node_s);
			visited[node_s] = true;
		}
	}
	cout << max_time[arrive_city] << endl;
	cout << max_time_road << endl;
}