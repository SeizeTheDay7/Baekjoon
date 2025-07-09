#include"3055.h"
using namespace std;

void B3055::Solution()
{
	pair<int,int> start;
	int R, C;
	cin >> R >> C;
	vector<vector<char>> twmap(R,vector<char>(C));
	queue<pair<int,int>> waterq;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			char e; cin >> e;
			twmap[i][j] = e;
			if (e == 'S') { start = { i,j }; }
			if (e == '*') { waterq.push({ i,j }); }
		}
	}

	vector<int> dx = { 1,-1,0,0 };
	vector<int> dy = { 0,0,1,-1 };
	queue<pair<int, int>> hghq;
	bool found = false;
	int day = 0;
	hghq.push(start);
	while (true)
	{
		day++;
		int qlen = waterq.size();
		while (qlen--) {
			int x = waterq.front().first;
			int y = waterq.front().second;
			waterq.pop();

			for (int i = 0; i < 4; ++i) {
				int newx = x + dx[i];
				int newy = y + dy[i];
				if (-1 < newx && newx < R && -1 < newy && newy < C
					&& twmap[newx][newy] == '.') {
					twmap[newx][newy] = '*';
					waterq.push({ newx,newy });
				}
			}
		}
		
		qlen = hghq.size();
		while (qlen--) {
			int x = hghq.front().first;
			int y = hghq.front().second;
			hghq.pop();

			for (int i = 0; i < 4; ++i) {
				int newx = x + dx[i];
				int newy = y + dy[i];

				if (-1 < newx && newx < R && -1 < newy && newy < C) {
					if (twmap[newx][newy] == '.') {
						twmap[newx][newy] = 'S';
						hghq.push({ newx,newy });
					}
					else if (twmap[newx][newy] == 'D') {
						found = true;
						break;
					}
				}
			}
		}

		if (found) { 
			cout << day;
			break; 
		}
		if (waterq.size() == 0 && hghq.size() == 0) {
			cout << "KAKTUS";
			break; 
		}
	}
}