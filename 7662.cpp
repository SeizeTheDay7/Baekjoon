#include"7662.h"

// ´äÁö º½.

void B7662::Solution()
{
	char c;
	int T, k, n;
	std::cin >> T;
	while (T--)
	{
		std::cin >> k;
		std::multiset<int> ms;
		for (int i = 0; i < k; ++i)
		{
			std::cin >> c >> n;
			if (c == 'I'){
				ms.insert(n);
			}
			else if (c == 'D') {
				if (ms.empty()) {
					continue;
				}
				else if (n == 1) {
					auto iter = ms.end();
					iter--;
					ms.erase(iter);
				}
				else if (n == -1) {
					ms.erase(ms.begin());
				}
			}
		}
		if (ms.empty()) {
			std::cout << "EMPTY" << '\n';
		}
		else {
			auto iter = ms.end();
			iter--;
			std::cout << *iter << " " << *ms.begin() << '\n';
		}
	}
}