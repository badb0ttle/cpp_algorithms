/*blank*/
#include <bits/stdc++.h>

using i64 = long long;
void work()
{
    int n, k;
		std::cin >> n >> k;
		int n1 = n - (k - 1);
		if (n1 > 0 && n1 % 2 == 1) {
			std::cout << "YES" << '\n';
			for (int i = 0; i < k - 1; ++i) std::cout << "1 ";
			std::cout << n1 << '\n';
			return;
		}
		int n2 = n - 2 * (k - 1);
		if (n2 > 0 && n2 % 2 == 0) {
			std::cout << "YES" << '\n';
			for (int i = 0; i < k - 1; ++i) std::cout << "2 ";
			std::cout << n2 << '\n';
			return;
		}
		std::cout << "NO" << '\n';
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    while (_--)
        work();
    return 0;
}