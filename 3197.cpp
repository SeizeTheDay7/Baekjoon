#include"3197.h"
using namespace std;
typedef pair<int, int> pii;
#define fastio cin.tie(0)->sync_with_stdio(0)

void B3197::Solution()
{
	fastio;

	int R, C;
	cin >> R >> C;
	vector<string> lake(R);
	for (int i = 0; i < R; i++)
		cin >> lake[i];

	queue<pii> waterq;
	pii duck;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (lake[i][j] == '.') {
				waterq.push({ i,j });
			}
			else if (lake[i][j] == 'L') {
				waterq.push({ i,j });
				duck = { i,j };
			}
		}
	}

	vector<int> dx = { 1,-1,0,0 };
	vector<int> dy = { 0,0,1,-1 };

	vector<vector<bool>> visited(R, vector<bool>(C, false));
	queue<pii> duckq;
	queue<pii> nextdq;
	visited[duck.first][duck.second] = true;
	nextdq.push(duck);
	bool found = false;
	int day = 0;
	while (1)
	{
		duckq = nextdq;
		nextdq = queue<pii>();
		while (!duckq.empty())
		{
			pii d = duckq.front(); duckq.pop();
			for (int i = 0; i < 4; i++) {
				int newx = d.first + dx[i], newy = d.second + dy[i];
				if (0 <= newx && newx < R && 0 <= newy && newy < C
					&& !visited[newx][newy]) {
					if (lake[newx][newy] == '.') { duckq.push({ newx,newy }); }
					else if (lake[newx][newy] == 'X') { nextdq.push({ newx,newy }); }
					else if (lake[newx][newy] == 'L') { found = true; break; }
					visited[newx][newy] = true;
				}
			}
		}
		if (found) break;

		int qlen = waterq.size();
		while (qlen--)
		{
			pii w = waterq.front(); waterq.pop();
			for (int i = 0; i < 4; i++) {
				int newx = w.first + dx[i], newy = w.second + dy[i];
				if (0 <= newx && newx < R && 0 <= newy && newy < C
					&& lake[newx][newy] == 'X')
				{
					lake[newx][newy] = '.';
					waterq.push({ newx,newy });
				}
			}
		}

		day++;
	}

	cout << day;
}
//{
//	fastio;
//
//	// ���� ���� �ڿ� ���� �� �ʿ������� �� �� �ִ��� üũ.
//	// �ٵ� ���� üũ���� �����̾��� ���������� bfs �ٽ� ������.
//	int R, C;
//	string s;
//	cin >> R >> C;
//	vector<string> lake(R);
//	pii duck;
//	queue<pii> iceq;
//
//	vector<int> dx = { 1,-1,0,0 };
//	vector<int> dy = { 0,0,1,-1 };
//
//	vector<vector<bool>> visited(R, vector<bool>(C));
//	vector<vector<bool>> willmelt(R, vector<bool>(C));
//	for (int i = 0; i < R; i++) {
//		cin >> lake[i];
//	}
//
//	// ���� ������ Ȯ��
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			if (lake[i][j] == 'L') { duck = { i,j }; }
//			else if (lake[i][j] == 'X') {
//				for (int k = 0; k < 4; k++) {
//					int newx = i + dx[k];
//					int newy = j + dy[k];
//					if (0 <= newx && newx < R && 0 <= newy && newy < C
//						&& ((lake[newx][newy] == '.') || (lake[newx][newy] == 'L'))) {
//						willmelt[i][j] = true;
//						iceq.push({ i,j });
//						break;
//					}
//				}
//			}
//		}
//	}
//
//	bool done = false;
//	int day = 0;
//	queue<pii> duckq;
//	duckq.push(duck);
//	visited[duck.first][duck.second] = true;
//	while (true)
//	{
//		int dd = 0;
//		// ������ �湮���� ���� ���� ���� Ž��
//		while (!duckq.empty()) {
//			pii d = duckq.front(); duckq.pop();
//			for (int i = 0; i < 4; i++) {
//				int newx = d.first + dx[i];
//				int newy = d.second + dy[i];
//				if (0 <= newx && newx < R && 0 <= newy && newy < C
//					&& !visited[newx][newy])
//				{
//					if (lake[newx][newy] == '.') {
//						visited[newx][newy] = true;
//						duckq.push({ newx,newy });
//					}
//					else if (lake[newx][newy] == 'L') {
//						done = true;
//						break;
//					}
//				}
//			}
//			if (done) break;
//		}
//		if (done) break;
//
//		// ������ ���� �� �����¿� Ȯ���ϰ� ���� ���� ���� Ȯ��
//		int iceqlen = iceq.size();
//		while (iceqlen--) {
//			pii ice = iceq.front(); iceq.pop();
//			int icex = ice.first, icey = ice.second;
//			lake[icex][icey] = '.';
//			bool newduck = false;
//			for (int i = 0; i < 4; i++) {
//				int newx = icex + dx[i], newy = icey + dy[i];
//				if (0 <= newx && newx < R && 0 <= newy && newy < C)
//				{
//					// �����¿쿡 ������ �湮�� ���� �ִٸ� ���� ť�� �߰�
//					if (visited[newx][newy] && 
//						((lake[newx][newy] == '.') || (lake[newx][newy] == 'L'))) {
//						newduck = true;
//					}
//					// �����¿쿡 ���� ���� ������ �ƴ� ������ �ִٸ� ���� ����
//					else if (!willmelt[newx][newy] && lake[newx][newy] == 'X') {
//						willmelt[newx][newy] = true;
//						iceq.push({ newx,newy });
//					}
//				}
//			}
//			if (newduck) {
//				visited[icex][icey] = true;
//				duckq.push(ice);
//			}
//		}
//
//		day++;
//	}
//	cout << day;
//}