#include"14940.h"

void B14940::Solution()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> mapv(n, std::vector<int>(m, 0));
	std::vector<std::vector<int>> countv(n, std::vector<int>(m, 0));
	std::queue<std::vector<int>> que;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			std::cin >> mapv[i][j];
			if (mapv[i][j] == 2) { que.push({ i,j }); }
		}
	}
	std::vector<int> ver = { 1,-1,0,0 };
	std::vector<int> hor = { 0,0,1,-1 };
	while (!que.empty())
	{
		int i = que.front()[0];
		int j = que.front()[1];
		que.pop();

		for (int k = 0; k < 4; ++k)
		{
			if ((0 <= i + ver[k]) && (i + ver[k] < n) &&
				(0 <= j + hor[k]) && (j + hor[k] < m) &&
				mapv[i+ver[k]][j+hor[k]] == 1)
			{
				mapv[i + ver[k]][j + hor[k]] = -1;
				countv[i + ver[k]][j + hor[k]] = countv[i][j] + 1;
				que.push({ i + ver[k], j + hor[k] });
			}
		}
		//for (int dir = 0; dir < 4; ++dir)
		//{
		//	int ny = y + dy[dir];
		//	int nx = x + dx[dir];

		//	if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		//	if (visited[ny][nx]) continue;
		//	if (mapv[ny][nx] != 1) continue;

		//	visited[ny][nx] = true;
		//	countv[ny][nx] = countv[y][x] + 1;
		//	que.push({ ny, nx });
		//}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (mapv[i][j] == 1) { std::cout << -1 << ' '; }
			else { std::cout << countv[i][j] << ' '; }
		}
		std::cout << '\n';
	}
}