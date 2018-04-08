#include <bits/stdc++.h>

using namespace std;

int main()
{
	int number;
	cin >> number;

	for (int zz = 0; zz < number; ++zz) {
		int size;
		cin >> size;

		vector<int> even;
		vector<int> odd;
		for (int i = 0; i < size; ++i) {
			int n; 
			cin >> n;

			if (i % 2 == 0) {
				even.push_back(n);
			} else {
				odd.push_back(n);
			}
		}

		std::sort(even.begin(), even.end());
		std::sort(odd.begin(), odd.end());

		int errorIndex = -1;

		for (int i = 0; i < min(even.size(), odd.size()); ++i) {
			if (even[i] > odd[i]) {
				errorIndex = i * 2;
				break;
			}

			if (i < even.size() - 1) {
				if (odd[i] > even[i + 1]) {
					errorIndex = i * 2 + 1;
					break;
				}
			}
		}

		cout << "Case #" << (zz + 1) << ": " << (errorIndex == -1 ? "OK" : to_string(errorIndex)) << endl;
	}

	return 0;
}