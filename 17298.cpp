#include"17298.h"

void B17298::Solution()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int N;
	std::cin >> N;
	std::stack<int> stk;
	std::vector<int> arr(N);
	std::vector<int> res(N,-1);
	for(int i=0; i<N; ++i)
	{
		std::cin >> arr[i];
		while (!stk.empty() && arr[stk.top()] < arr[i])
		{
			res[stk.top()] = arr[i];
			stk.pop();
		}
		stk.push(i);
	}
	for (int r : res)
	{
		std::cout << r << ' ';
	}
}