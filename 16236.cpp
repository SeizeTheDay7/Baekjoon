#include"16236.h"
using namespace std;
typedef pair<int, int> pii;

// �Ǽ� 1. found�� �ִ°� ��ü�� �Դ°� �ƴ϶� 
// ���� �� �ִ� �ĺ��ε� mat ���� �ʱ�ȭ���ѹ���
// �Ǽ� 2. �Ʊ� ���� �ڽ��� ũ��� ���� ���� ����⸦ ���� �� ���� ũ�Ⱑ 1 �����Ѵ�.
// ���� ���� �ؼ��� �߸���. '�翬��' ������ ������ �����Ŷ� �����ع��� �Ǽ�.
// ������ �Ϻη� �򰥸��� ������ �鵵 �ֱ� ��.

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

	// �� �� �����϶����� bfs �ϴ� �ùķ��̼�
	// ���� �� �ִ� �� ã�� ������ bfs
	// �Ÿ��� ������ i�� ���� ��, �װ͵� ������ j�� ������ �켱
	// ũ�Ⱑ ������ ���� ���ϰ� ����� ����
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