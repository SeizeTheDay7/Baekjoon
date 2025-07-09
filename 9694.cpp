#include"9694.h"
using namespace std;

void B9694::Solution()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	const int INF = 1000000;
	int T, N, M;
	int x, y, z;
	cin >> T;
	int c;

	for(int c = 1; c<=T; ++c)
	{
		// N : 관계 개수, M : 정치인 수
		cin >> N >> M;
		vector<int> prev_node(M, -1);
		vector<int> min_cost_vec(M,0);
		for (int i = 1; i < M; ++i) {
			min_cost_vec[i] = INF;
		}
		vector<vector<pair<int,int>>> fam_edge(M);
		for (int i = 0; i < N; ++i) {
			// 정치인 x, 의 친구 y, 친밀도 z
			cin >> x >> y >> z;
			fam_edge[x].push_back(make_pair(y,z));
			fam_edge[y].push_back(make_pair(x,z));
		}

		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
		pq.push({0,0});
		while (!pq.empty()) {
			int min_cost_cur = pq.top().first;
			int node_cur = pq.top().second;
			pq.pop();

			if (min_cost_cur > min_cost_vec[node_cur]) { continue; }

			for (pair<int, int> edge : fam_edge[node_cur]) {

				int node_next = edge.first;
				int cost_to_next = edge.second;
				int new_cost_next = min_cost_cur + cost_to_next;

				if (new_cost_next < min_cost_vec[node_next]) {
					prev_node[node_next] = node_cur;
					min_cost_vec[node_next] = new_cost_next;
					pq.push(make_pair(new_cost_next, node_next));
				}
			}
		}
		cout << "Case #" << c << ": ";
		if (min_cost_vec[M - 1] == INF) {
			cout << -1 << '\n';
		}
		else {
			vector<int> buffer;
			for (int idx = M - 1; idx != -1; idx = prev_node[idx]) {
				buffer.push_back(idx);
			}
			for (int i = buffer.size()-1; -1 < i; --i) {
				cout << buffer[i] << ' ';
			}
			cout << '\n';
		}
	}
}