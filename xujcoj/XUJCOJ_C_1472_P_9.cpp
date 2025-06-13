#include<iostream>
using namespace std;
int dl(int m, int a, int b)
{
	int t = -1;
	for (int i = 1; i <= m;)
	{
		if (m == 1)
		{
			cout << "No" << endl;
			return 0;
		}
		else
		{
			t *= -1;
			if (t == 1)
			{
				for (int j = 1; j <= a; j++)
				{
					if ((i + j) == m)
					{
						cout << "Yes" << endl;
						return 0;
					}
					if (j == a)
					{
						i += 1;
					}
				}
			}
			if (t == -1)
			{
				for (int j = 1; j <= b; j++)
				{
					if ((i + j) == m)
					{
						cout << "No" << endl;
						return 0;
					}
					if (j == b)
					{
						i += 1;
					}
				}
			}
		}
	}
}
int main()
{
	int n, m, a, b;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> m >> a >> b;
		dl(m, a, b);
	}
	return 0;
}