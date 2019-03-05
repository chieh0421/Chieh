#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Kth_smallest_number(vector<int> in, int K) {
	vector<int> cur(in.begin(), in.end());
	sort(cur.begin(), cur.end());
	return cur[K - 1];
}

int main()
{
	int N, M, K, cur;
	cin >> N >> M >> K;
	vector<int> int_arr;
	while (int_arr.size() < M - 1) {
		cin >> cur;
		int_arr.push_back(cur);
	}
	for (int i = 0; i <= N - M; i++) {
		cin >> cur;
		int_arr.push_back(cur);
		cout << Kth_smallest_number(int_arr, K) << endl;
		int_arr.erase(int_arr.begin());
	}
	return 0;
}