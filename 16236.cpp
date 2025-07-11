#include"16236.h"
using namespace std;
typedef pair<int, int> pii;

// 실수 1. found에 넣는거 자체는 먹는게 아니라 
// 먹을 수 있는 후보인데 mat 값을 초기화시켜버림
// 실수 2. 아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다.
// 국어 지문 해석을 잘못함. '당연히' 먹으면 레벨이 오를거라 생각해버린 실수.
// 문제가 일부러 헷갈리게 서술된 면도 있긴 함.

void B16236::Solution()
{
	vector<int> dx = { 1,-1,0,0 };
	vector<int> dy = { 0,0,1,-1 };

	int N;
	cin >> N;
	vector<vector<int>> mat(N,vector<int>(N));
	pii shark;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> mat[i][j];
			if (mat[i][j] == 9) { 
				shark = { i,j };
				mat[i][j] = 0;
			};
		}
	}

	// 한 번 움직일때마다 bfs 하는 시뮬레이션
	// 먹을 수 있는 놈 찾을 때까지 bfs
	// 거리가 같으면 i가 작은 거, 그것도 같으면 j가 작은거 우선
	// 크기가 같으면 먹진 못하고 통과는 가능
	int time = 0;
	int level = 2;
	int eaten = 0;
	while (1)
	{
		queue<pii> q;
		q.push(shark);
		int dist = 0;
		vector<pii> found;
		vector<vector<bool>> visited(N, vector<bool>(N, false));
		while (!q.empty())
		{
			dist++;
			int qlen = q.size();
			for (int i = 0; i < qlen; ++i) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int k = 0; k < 4; ++k) {
					int newx = x + dx[k];
					int newy = y + dy[k];
					if (0 <= newx && newx < N && 0 <= newy && newy < N
						&& !visited[newx][newy]) {
						if (mat[newx][newy] == 0) {
							q.push({ newx,newy });
						}
						else if (mat[newx][newy] < level) {
							found.push_back({ newx,newy });
						}
						else if (mat[newx][newy] == level) {
							q.push({ newx,newy });
						}
						visited[newx][newy] = true;
					}
				}
			}
			if (!found.empty()) break;
		}

		if (found.empty()) break;
		int minfx = N;
		int minfy = N;
		for (pii f : found) {
			int fx = f.first, fy = f.second;
			if (fx < minfx || (fx == minfx && fy < minfy)){ 
				minfx = fx; minfy = fy; 
			}
		}
		eaten += 1;
		if (eaten == level) {
			eaten = 0;
			level++;
		}
		time += dist;
		mat[minfx][minfy] = 0;
		shark = { minfx, minfy };
	}
	cout << time;
}