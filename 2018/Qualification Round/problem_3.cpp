#include <bits/stdc++.h>

using namespace std;
using Map = vector<vector<int>>;

struct Pos {
	int x = 200;
	int y = 200;
};

bool isFilled(const Map& map, Pos pos)
{
	int count = 0;

	for (int i = max(pos.x - 1, 0); i < min(pos.x + 2, (int) map.size()); ++i) {
		for (int j = max(pos.y - 1, 0); j < min(pos.y + 2, (int) map[i].size()); ++j) {
			count += map[i][j];
		}
	}

	return (count == 9);
}

int main()
{
	int n;
	cin >> n;

	for (int zz = 0; zz < n; ++zz) {
		Map map;
		map.resize(1000);
		for (auto& vec : map)
			vec.resize(1000, 0);

		int a;
		cin >> a;

		int cubeNumber = floor(a/9);

		Pos center;

		for (int i = 0; i < 1000; ++i) {
			cout << center.x << ' ' << center.y << endl;

			if (isFilled(map, center)) {
				if (cubeNumber > 0) {
					center.x += 3;
					--cubeNumber;
				} else {
					center.x += 1;
				}
			}

			int x, y;
			cin >> x >> y;

			if (x == -1 || y == -1) {
				return 1;
			} else if (x == 0 && y == 0) {
				break;
			} else {
				map[x][y] = 1;
			}
		}

	}

	return 0;
}