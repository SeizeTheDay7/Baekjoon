#include"1005.h"

namespace
{
	//std::vector<int> build_time;
	//std::vector<int> full_build_time;
	//std::vector<std::vector<int>> build_need;

	//int Full_Build_Time(int idx)
	//{
	//	if (full_build_time[idx] != -1) { return full_build_time[idx]; }
	//	int pre_time = 0;
	//	for (int pre_idx : build_need[idx])
	//	{
	//		pre_time = std::max(pre_time, Full_Build_Time(pre_idx));
	//	}
	//	full_build_time[idx] = build_time[idx] + pre_time;
	//	return full_build_time[idx];
	//}
}

void B1005::Solution()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	//int T;
	//std::cin >> T;
	//while (T--)
	//{
	//	int result_time = 0;
	//	int N, K; // N : 건물 개수, K : 건물 순서 규칙 개수
	//	std::cin >> N >> K;
	//	
	//	build_time = std::vector<int>(N+1);
	//	for (int i = 1; i <= N; ++i) { std::cin >> build_time[i]; }
	//	full_build_time = std::vector<int>(N + 1, -1);

	//	build_need = std::vector<std::vector<int>>(N+1);
	//	for (int i = 1; i <= K; ++i)
	//	{
	//		int pre, idx;
	//		std::cin >> pre >> idx;
	//		build_need[idx].push_back(pre);
	//	}

	//	int W; // W : 건설할 건물
	//	std::cin >> W;

	//	std::cout << Full_Build_Time(W) << '\n';
	//}

	// 소요되는 시간은 같음. 아래는 정석대로 위상정렬로 푼 거.

	int T, N, K, W;
	std::cin >> T;

	while (T--)
	{
		std::cin >> N >> K;

		std::vector<int> indegree(N + 1,0);
		std::vector<std::vector<int>> next_build(N + 1);
		std::vector<int> build_time(N + 1,0);
		std::vector<int> full_build_time(N + 1,0);
		for (int i = 1; i <= N; ++i){std::cin >> build_time[i];}
		for (int i = 1; i <= K; ++i) {
			int idx, next;
			std::cin >> idx >> next;
			next_build[idx].push_back(next);
			indegree[next]++;
		}
		std::cin >> W;

		std::queue<int> q;
		for (int i = 1; i <= N; ++i) {
			if (indegree[i] == 0) { 
				full_build_time[i] = build_time[i];
				q.push(i);
			}
		}

		while (!q.empty()) {
			int idx = q.front(); 
			q.pop();
			for (int next : next_build[idx]) {
				int this_time = full_build_time[idx] + build_time[next];
				full_build_time[next] = std::max(full_build_time[next], this_time);
				if (--indegree[next] == 0) {
					q.push(next);
				}
			}
		}

		std::cout << full_build_time[W] << '\n';
	}
}