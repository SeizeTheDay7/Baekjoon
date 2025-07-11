#include"2206.h"
using namespace std;
typedef tuple<int,int,bool> tiib;

// try1 : ��� �� �� ���� ���ֺ��� bfs
// �Ǽ�
// 1. wallq pop�� ������
// 2. �湮�� üũ ���ؼ� ���� bfs ���ƹ���
// 3. while�� ���ǹ��� �߸� �����ؼ� ���� �ݺ��ع���
// ��� : �ð� �ʰ�

// try2 : 0�� ����� ���� �� ���� ���ֺ��� bfs �õ�
// ��� : �ð� �ʰ�

// try3 : �Է� ����ȭ
// ��� : �ð� �ʰ�

// try4 : 0,0�� ����� ���鸸 ���ֺ���
// �Ǽ�
// 1. bfs�� �߾�� �ߴµ� �Ա� �������ϰ� �Ʒ��ʸ� Ȯ���غ�
// ��� : �ð� �ʰ�

// try5 : 0,0���� bfs �غ��� �ȵǸ� �������� bfs�غ��� set�� ������ �� �ִ��� Ȯ��
// ��� : �ð� �ʰ�

// try6 : char ��� int�� ���ϵ��� ��ȯ
// ��� : �ð� �ʰ�

// try 7 : ���� ���� destroyed ������ bfs �� ��
// ��� : Ʋ�Ƚ��ϴ�

// try 8 : 
// ���� 
// ���� �ݷ� : ���� ��ΰ� ���� ��, ��θ� ���� �Ŀ� ���� �ν���
// ��ǥ�� ���� �����ϴٸ� destroyed�� ���� visited ó���� �ع����� �ȵ�

void B2206::Solution()
{
	// ������ 0,0�� �ƴ϶� (1,1)�̶�� ǥ���� �� ����
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
	
	// int = index, bool = �� �ν�����
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