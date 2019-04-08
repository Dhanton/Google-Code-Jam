#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int zz = 0; zz < t; ++zz) {
		int n;
		cin >> n;

		string path;

		for (int i = 0; i < 2 * n - 2; ++i) {
			char c;
			cin >> c;

			if (c == 'S') {
				path.push_back('E');
			} else {
				path.push_back('S');
			}
		}

		cout << "Case #" << (zz + 1) << ": " << path << endl;
	}

	return 0;
}