#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int zz = 0; zz < t; ++zz) {
		int n,l;
		cin >> n >> l;

		vector<string> words;

		for (int i = 0; i < n; ++i) {
			string word;
			cin >> word;

			words.push_back(word);
		}

		//Word or '-' character
		cout << "Case #" << (zz + 1) << ": " << '-' << endl;
	}

	return 0;
}