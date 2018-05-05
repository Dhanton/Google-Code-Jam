#include <bits/stdc++.h>

using namespace std;

bool eliminate_ant(list<int>& ants)
{
	int sum = 0;

	for (auto it = ants.begin(); it != ants.end(); ++it) {
		int current_weight = *it;

		if (sum > 6 * current_weight) {
			auto max_weight = it;
			auto it2 = prev(it, 1);

			while (it2 != ants.end()) {
				int previous_weight = *it2;
				int previous_sum = sum - previous_weight;

				if (previous_weight >= *max_weight && previous_sum <= 6 * current_weight) {
					max_weight = it2;
				}

				advance(it2, -1);
			}

			ants.erase(max_weight);

			return true;
		}

		sum += current_weight;
	}

	//No ant was eliminated
	return false;
}

int main()
{
	int t;
	cin >> t;

	for (int zz = 0; zz < t; ++zz) {
		int n;
		cin >> n;

		list<int> ants;

		for (int i = 0; i < n; ++i) {
			int w;
			cin >> w;

			ants.push_back(w);
		}

		bool eliminated = true;

		while (eliminated) {
			eliminated = eliminate_ant(ants);
		}

		//Get the size of the list
		cout << "Case #" << (zz + 1) << ": " << ants.size() << endl;

	}

	return 0;
}