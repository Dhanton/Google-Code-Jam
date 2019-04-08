#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int zz = 0; zz < t; ++zz) {
		int n;
		cin >> n;

		int tmp_n = n;
		int subs = 0;

		for (int i = 0; i < 100; ++i) {
			int digit = tmp_n % 10;

			if (digit == 4) {
				subs += pow(10, i);
			}

			tmp_n /= 10;

			if (tmp_n == 0) break;
		}

		int a = n - subs;
		int b = n - a;

		cout << "Case #" << (zz + 1) << ": " << a << ' ' << b << endl;
	}

	return 0;
}