#include"30804.h"

namespace
{
	int find_max_seq(int i, int j, std::vector<int>* fruits)
	{
		int max_count = 0;
		// fruits를 순회하면서 i랑 j가 아니라면 카운트 초기화
		int count = 0;
		for (int f : *fruits)
		{
			if (f != i && f != j) { count = 0; }
			else {
				count++;
				max_count = std::max(count, max_count); 
			}
		}
		return max_count;
	}
}

void B30804::Solution()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; 
	std::cin >> n;
	std::vector<int> fruits;
	for (int i = 0; i < n; ++i)
	{
		int f;
		std::cin >> f;
		fruits.push_back(f);
	}

	// 그리디로 풀어도 O(n^2). 과일 개수 보니 불가능.
	// 역으로 생각해서 두종류의 숫자로만 이루어진 연속된 수열 찾기
	// 9C2 경우의 수만큼 두 종류만 골라서 연속된 수열 찾으면 O(kn)

	int res = 0;
	for (int i = 1; i <= 8; ++i)
	{
		for (int j = i+1; j <= 9; ++j)
		{
			res = std::max(res, find_max_seq(i, j, &fruits));
		}
	}
	std::cout << res;
}

//#include <bits/stdc++.h>
//using namespace std;
//
//int N, types, cnt[10], answer;
//queue<int> q;
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0);
//	cin >> N;
//	while (N--)
//	{
//		int fruit;
//		cin >> fruit;
//
//		q.push(fruit);
//
//		if (cnt[fruit]++ == 0)
//		{
//			++types;
//		}
//
//		while (types > 2)
//		{
//			fruit = q.front();
//			q.pop();
//
//			if (--cnt[fruit] == 0)
//			{
//				--types;
//			}
//		}
//
//		answer = max(answer, static_cast<int>(q.size()));
//	}
//
//	cout << answer;
//}
