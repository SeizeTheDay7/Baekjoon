#include"1865.h"
using namespace std;

// 실수 1. 또 인덱스랑 실제 번호랑 헷갈림. 공간 더 줬어야 했음.
// 실수 2. 행렬 초기화를 안 함.
// 실수 3. 행렬 초기화를 int max로 했더니 오버플로우 발생함.
// 실수 4. 문제를 대충 읽어서 도로는 무향, 웜홀은 유향인거 놓침
// 실수 5. 문제를 덜 읽어서 도로가 중복일 수 있는거 놓침
// 실수 6. 웜홀은 시간이 (-)인데 (+)로 넣어버림
// 실수 7. mat[E][S] = min(T, mat[S][E]); 복붙하다 인덱스 실수
// 실수 8. 테케가 다를 때 웜홀 벡터 초기화를 안 해줌

// 웜홀은 도로와 별개라고 생각했는데, 
// 도로와 연계하여 이동하는 경우도 있으니 음수 가중치 도로로 간주해야 할듯.

void B1865::Solution()
{
	const int INF = 10001;
	int TC, N, M, W;
	cin >> TC;
	while (TC--)
	{
		cin >> N >> M >> W;
		vector<vector<int>> mat(N+1,vector<int>(N+1,INF));
		vector<tuple<int, int, int>> wormhole = {};
		int S, E, T;
		for (int i = 0; i < M; ++i) {
			cin >> S >> E >> T;
			// S에서 E로 가는데 T의 시간이 걸린다
			mat[S][E] = min(T, mat[S][E]);
			mat[E][S] = min(T, mat[E][S]);
		}
		for (int i = 0; i < W; ++i) {
			cin >> S >> E >> T;
			mat[S][E] = min(-T, mat[S][E]);
			wormhole.push_back(make_tuple(S, E, T));
		}

		// 플로이드 워셜로 모든 정점 사이 거리 확인
		for (int i = 1; i < N+1; ++i) {
			for (int j = 1; j < N+1; ++j) {
				for (int k = 1; k < N+1; ++k) {
					mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k]);
				}
			}
		}

		// 모든 웜홀 확인
		bool found = false;
		for (auto tup : wormhole) {
			tie(S, E, T) = tup;
			if (mat[E][S] < T) {
				found = true;
				break;
			}
		}

		if (found) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
}
