#include"1865.h"
using namespace std;

// �Ǽ� 1. �� �ε����� ���� ��ȣ�� �򰥸�. ���� �� ���� ����.
// �Ǽ� 2. ��� �ʱ�ȭ�� �� ��.
// �Ǽ� 3. ��� �ʱ�ȭ�� int max�� �ߴ��� �����÷ο� �߻���.
// �Ǽ� 4. ������ ���� �о ���δ� ����, ��Ȧ�� �����ΰ� ��ħ
// �Ǽ� 5. ������ �� �о ���ΰ� �ߺ��� �� �ִ°� ��ħ
// �Ǽ� 6. ��Ȧ�� �ð��� (-)�ε� (+)�� �־����
// �Ǽ� 7. mat[E][S] = min(T, mat[S][E]); �����ϴ� �ε��� �Ǽ�
// �Ǽ� 8. ���ɰ� �ٸ� �� ��Ȧ ���� �ʱ�ȭ�� �� ����

// ��Ȧ�� ���ο� ������� �����ߴµ�, 
// ���ο� �����Ͽ� �̵��ϴ� ��쵵 ������ ���� ����ġ ���η� �����ؾ� �ҵ�.

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
			// S���� E�� ���µ� T�� �ð��� �ɸ���
			mat[S][E] = min(T, mat[S][E]);
			mat[E][S] = min(T, mat[E][S]);
		}
		for (int i = 0; i < W; ++i) {
			cin >> S >> E >> T;
			mat[S][E] = min(-T, mat[S][E]);
			wormhole.push_back(make_tuple(S, E, T));
		}

		// �÷��̵� ���ȷ� ��� ���� ���� �Ÿ� Ȯ��
		for (int i = 1; i < N+1; ++i) {
			for (int j = 1; j < N+1; ++j) {
				for (int k = 1; k < N+1; ++k) {
					mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k]);
				}
			}
		}

		// ��� ��Ȧ Ȯ��
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
