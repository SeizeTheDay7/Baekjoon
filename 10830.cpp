#include"10830.h"
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;

namespace
{
	int N;
	ll B;
	vvi mat_origin;
	const int MOD = 1000;

	void Output(vvi mat_res)
	{
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << mat_res[i][j] % MOD << ' ';
			}
			cout << '\n';
		}
	}

	vvi MatMult(vvi mat1, vvi mat2)
	{
		vvi mat_res = vvi(N, vector<int>(N,0));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					mat_res[i][j] += mat1[i][k] * mat2[k][j] % MOD;
		return mat_res;
	}

	vvi MatPower(vvi mat, ll B)
	{
		if (B == 1) return mat;

		vvi mat_temp = MatPower(mat, B / 2);
		mat_temp = MatMult(mat_temp, mat_temp);
		if (B % 2 == 1) mat_temp = MatMult(mat_temp, mat);

		return mat_temp;
		
	}

	void Input()
	{
		cin >> N >> B;
		mat_origin = vvi(N, vector<int>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> mat_origin[i][j];
			}
		}
	}
}

void B10830::Solution()
{
	Input();
	Output(MatPower(mat_origin, B));
}