#include <bits/stdc++.h>

using namespace std;

int calcDamage(const string& str) {
	int dmg = 0;
	int shotDmg = 1;

	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == 'C') {
			shotDmg *= 2;
		} else if (str[i] == 'S') {
			dmg += shotDmg;
		}
	}

	return dmg;
}

int main()
{
	int n;
	cin >> n;

	for (int zz = 0; zz < n; ++zz) {
		int health;
		cin >> health;

		string code;
		cin >> code;

		int iter = 0;
		int lastI = code.size() - 1;

		int damage = calcDamage(code);

		bool impossible = false;

		while (damage > health) {
			if (lastI > 0) {
				int lastI_local = lastI;
				while (lastI_local > 0 && code[lastI_local] == code[lastI_local - 1]) {
					--lastI_local;
				}

				if (lastI_local == 0) {
					impossible = true;
					break;
				}

				if (code[lastI_local] == 'S') {
					++iter;

					char tmp = code[lastI_local - 1];
					code[lastI_local - 1] = code[lastI_local]; 
					code[lastI_local] = tmp;

					if (lastI_local == lastI)
						--lastI;

					damage = calcDamage(code);

				} else if (code[lastI_local] == 'C') {
					lastI = lastI_local - 1;
				}
			}
			
			if (lastI == 0) {
				impossible = true;
				break;
			}
		}

		cout << "Case #" << (zz + 1) << ": " << ((impossible && damage > health) ? "IMPOSSIBLE" : to_string(iter)) << endl;
	}

	return 0;
}