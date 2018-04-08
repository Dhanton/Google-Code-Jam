
int dh_sort(vector<int>& vec) 
{
	bool done = false;
	int errorIndex = -1;
	size_t n = vec.size();

	while (!done) {
		done = true;

		for (int i = 0; i < n - 2; ++i) {
			if (vec[i] > vec[i + 2]) {
				int tmp = vec[i];
				vec[i] = vec[i + 2];
				vec[i + 2] = tmp;

				done = false;
			}

			if (errorIndex == -1) {
				if (vec[i] > vec[i + 1]) {
					errorIndex = i;
				} else if (vec[i + 1] > vec[i + 2]) {
					errorIndex = i + 1;
				}
			}
		}

		if (!done) {
			errorIndex = -1;
		}
	}

	return errorIndex;
}
