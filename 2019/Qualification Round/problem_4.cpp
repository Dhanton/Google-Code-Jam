#include <bits/stdc++.h>

using namespace std;

struct bit {
	char c = '0';
	double weight = 0;
};

string get_bitcode_str(const vector<bit>& bitcode)
{
	string msg;
	for (auto& b : bitcode) {
		msg += b.c;
	}

	return msg;
}

//global oof
double current_zeroes = 0.0;
double current_ones = 0.0;

void write_bitcode(vector<bit>& bitcode, int chunk_size)
{
	int current_size = 0;
	char current_char = '0';

	current_zeroes = 0.0;
	current_ones = 0.0;

	for (int i = 0; i < bitcode.size(); ++i) {
		bitcode[i].c = current_char;

		if (current_char == '0') {
			++current_zeroes;
		} else if (current_char == '1') {
			++current_ones;
		}
		
		++current_size;
		if (current_size >= chunk_size) {
			current_size = 0;
			current_char = (current_char == '0' ? '1' : '0');
		}
	}
}

int main()
{
	int t;
	cin >> t;

	// cin.ignore(std::numeric_limits<std::streamsize>::max());

	for (int zz = 0; zz < t; ++zz) {
		int n, b, f;
		cin >> n >> b >> f;

		vector<bit> bitcode;
		bitcode.resize(n);

		write_bitcode(bitcode, 2);

		int current_itr = 0;

		while (current_itr < f) {
			cout << get_bitcode_str(bitcode) << endl;
			cerr << get_bitcode_str(bitcode) << endl;

			// int non_broken;
			// cin >> non_broken;

			// if (non_broken == -1) return -1;

			int num_0 = 0;
			int num_1 = 0;

			string broken_bitcode;
			std::getline(std::cin, broken_bitcode);

			for (auto c : broken_bitcode) {
				if (c == '0') {
					++num_0;
				} else if (c == '1') {
					++num_1;
				}
			}

			for (auto& b : bitcode) {
				if (b.c == '0') {
					b.weight += (double) num_0 / current_zeroes;
				} else if (b.c == '1') {
					b.weight += (double) num_1 / current_ones;
				}
			}

			++current_itr;
			write_bitcode(bitcode, n/pow(2, current_itr + 1));
		}

		int highest_weight = -1;
		for (auto& b : bitcode) {
			if (b.weight > highest_weight) {
				highest_weight = b.weight;
			}
		}

		for (int i = 0; i < bitcode.size(); ++i) {
			if (bitcode[i].weight == highest_weight) {
				cout << i << ' ';
			}
		}

		cout << endl;

		int result;
		cin >> result;

		if (result == -1) return -1;
	}

	return 0;
}