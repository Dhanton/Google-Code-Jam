#include <bits/stdc++.h>

using namespace std;

bool calc_primes(int first, int id, vector<int>& vec, const vector<int>& ct, int length)
{
	vec.resize(length, -1);

	vec[id] = first;

	for (int i = id + 1; i < length; ++i) {
		if (vec[i - 1] == 0 || ct[i - 1] % vec[i - 1] != 0) {
			return false;
		}

		vec[i] = ct[i - 1]/vec[i - 1];
	}

	for (int i = id - 1; i >= 0; --i) {
		if (vec[i + 1] == 0 || ct[i] % vec[i + 1] != 0) {
			return false;
		}

		vec[i] = ct[i]/vec[i + 1];
	}

	return true;
}

int main()
{
	int t;
	cin >> t;

	for (int zz = 0; zz < t; ++zz) {
		int n, l;
		cin >> n >> l;

		vector<int> ct_numbers;
		for (int i = 0; i < l; ++i) {
			int tmp;
			cin >> tmp;

			ct_numbers.push_back(tmp);
		}

		//find 2 factors of first
		int first_prime = -1;

		auto min_it = min_element(ct_numbers.begin(), ct_numbers.end());
		int min_ct = *min_it;
		int min_i = distance(ct_numbers.begin(), min_it);

		for (int i = 2; i < min(min_ct, n); ++i) {
			if (min_ct % i == 0) {
				first_prime = i;
				break;
			}
		}

		vector<int> primes;
		bool result = calc_primes(first_prime, min_i, primes, ct_numbers, l + 1);

		if (!result) {
			primes.clear();
			++min_i;

			calc_primes(first_prime, min_i, primes, ct_numbers, l + 1);
		}

		set<int> sorted(primes.begin(), primes.end());

		std::string msg;

		for (int prime : primes) {
			auto it = sorted.find(prime);
			if (it != sorted.end()) {
				msg += char(distance(sorted.begin(), it) + 97);
			}
		}


		cout << "Case #" << (zz + 1) << ": " << msg << endl;
	}

	return 0;
}