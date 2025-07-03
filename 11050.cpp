#include "11050.h"

void B11050::Solution()
{
	//int a, b;
	//std::cin >> a >> b;
	//int ab = a - b;
	//int temp = 1;
	//int np, nkp = 1, kp = 1;
	//for (int i = 1; i <= a; i++)
	//{
	//	temp *= i;
	//	if (i == b) nkp = temp;
	//	if (i == ab) kp = temp;
	//}
	//np = temp;
	//std::cout << np / (nkp * kp);

	int a, b;
	int cnt = 1;
	scanf("%d %d", &a, &b);
	for (int j = 1;j <= b;j++) {
		cnt = cnt * a;
		cnt = cnt / j;
		a--;
	}
	printf("%d", cnt);
}