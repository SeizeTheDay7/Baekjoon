#include"1753.h"
using namespace std;
typedef pair<int, int> pii;

void B1753::Solution()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int INF = numeric_limits<int>::max();
	// V : 정점 개수, E : 간선 개수, K : 시작 정점
	int V, E, K;
	cin >> V >> E;
	cin >> K;

	vector<vector<pair<int, int>>> graph(V+1);
	int u, v, w; // u -> v 는 비용 w
	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v,w));
	}
	vector<int> min_cost_vec(V+1,INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, K));
	while (!pq.empty()) {
		int cost_cur = pq.top().first;
		int node_cur = pq.top().second;
		pq.pop();
		if (cost_cur > min_cost_vec[node_cur]) { continue; }

		for (pii edge : graph[node_cur]) {
			int node_next = edge.first;
			int cost_next = edge.second;
			int newcost = cost_cur + cost_next;
			if (newcost < min_cost_vec[node_next]) {
				min_cost_vec[node_next] = newcost;
				pq.push(make_pair(newcost, node_next));
			}
		}
	}

	min_cost_vec[K] = 0;
	for (int i = 1; i < V + 1; ++i) {
		int min_cost = min_cost_vec[i];
		if (min_cost == INF) {
			cout << "INF" << '\n';
		}
		else {
			cout << min_cost << '\n';
		}
	}
}