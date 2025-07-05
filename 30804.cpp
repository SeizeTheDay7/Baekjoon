#include"30804.h"

namespace
{
	int find_max_seq(int i, int j, std::vector<int>* fruits)
	{
		int max_count = 0;
		// fruits�� ��ȸ�ϸ鼭 i�� j�� �ƴ϶�� ī��Ʈ �ʱ�ȭ
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

	// �׸���� Ǯ� O(n^2). ���� ���� ���� �Ұ���.
	// ������ �����ؼ� �������� ���ڷθ� �̷���� ���ӵ� ���� ã��
	// 9C2 ����� ����ŭ �� ������ ��� ���ӵ� ���� ã���� O(kn)

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
