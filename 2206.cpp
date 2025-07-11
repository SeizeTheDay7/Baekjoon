#include"2206.h"
using namespace std;
typedef tuple<int,int,bool> tiib;

// try1 : 모든 벽 한 번씩 없애보고 bfs
// 실수
// 1. wallq pop을 빼먹음
// 2. 방문을 체크 안해서 무한 bfs 돌아버림
// 3. while에 조건문을 잘못 삽입해서 무한 반복해버림
// 결과 : 시간 초과

// try2 : 0과 연결된 벽만 한 번씩 없애보고 bfs 시도
// 결과 : 시간 초과

// try3 : 입력 최적화
// 결과 : 시간 초과

// try4 : 0,0과 연결된 벽들만 없애보기
// 실수
// 1. bfs를 했어야 했는데 입구 오른쪽하고 아래쪽만 확인해봄
// 결과 : 시간 초과

// try5 : 0,0에서 bfs 해보고 안되면 끝점에서 bfs해보고 set에 동일한 벽 있는지 확인
// 결과 : 시간 초과

// try6 : char 대신 int를 비교하도록 변환
// 결과 : 시간 초과

// try 7 : 답지 보고 destroyed 도입한 bfs 한 번
// 결과 : 틀렸습니다

// try 8 : 
// 수정 
// 이전 반례 : ㄷ자 통로가 있을 때, 통로를 지난 후에 벽을 부숴야
// 목표에 도달 가능하다면 destroyed가 먼저 visited 처리를 해버리면 안됨

void B2206::Solution()
{
	// 시작은 0,0이 아니라 (1,1)이라고 표현한 것 주의
	cin.tie(0); ios::sync_with_stdio(false);

	vector<int> dx = { 1,-1,0,0 };
	vector<int> dy = { 0,0,1,-1 };

	int N, M;
	cin >> N >> M;
	vector<vector<int>> mmap(N,vector<int>(M));
	vector<vector<bool>> visited(N, vector<bool>(M));
	vector<vector<bool>> visited_d(N, vector<bool>(M));

	string s;
	for (int i = 0; i < N; ++i) {
		cin >> s;
		for (int j = 0; j < M; ++j) {
			mmap[i][j] = s[j] - '0';
		}
	}
	
	// int = index, bool = 벽 부쉈는지
	int count = 0;
	bool found = false;
	queue<tiib> q;
	q.push(make_tuple(0,0,false));
	while (!q.empty())
	{
		count++;
		int qlen = q.size();
		for (int i = 0; i < qlen; ++i) {
			int x, y; bool destroyed;
			tie(x, y, destroyed) = q.front(); q.pop();
			if (x == N - 1 && y == M - 1) {
				found = true;
				break;
			}
			for (int i = 0; i < 4; ++i) {
				int newx = x + dx[i];
				int newy = y + dy[i];
				if (0 <= newx && newx < N && 0 <= newy && newy < M) {
					if (destroyed) {
						if (visited_d[newx][newy]) continue;
						if (mmap[newx][newy] == 0) {
							q.push(make_tuple(newx, newy, destroyed));
						}
						visited_d[newx][newy] = true;
					}
					else {
						if (visited[newx][newy]) continue;
						if (mmap[newx][newy] == 1) {
							q.push(make_tuple(newx,newy,true));
						}
						else if (mmap[newx][newy] == 0) {
							q.push(make_tuple(newx, newy, destroyed));
						}
						visited[newx][newy] = true;
					}

				}
			}
		}
		if (found) break;
	}

	if (found) cout << count;
	else cout << -1;
}