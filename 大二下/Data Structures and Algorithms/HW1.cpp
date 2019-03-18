#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;


int main()
{
	int N, M, K, cur;
	cin >> N >> M >> K;
	deque<int> int_arr, window;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		if (i < N - M)
			int_arr.push_back(cur);
		if (i < M - 1) {
			window.push_back(cur);
		}
		else if (i == M - 1) {
			window.push_back(cur);
			sort(window.begin(), window.end());
			cout << window[K - 1] << endl;
		}
		else {
			if (int_arr[i - M] > window[K - 1]) {
				window.erase(lower_bound(window.begin() + K - 1, window.end(), int_arr[i - M]));
			}
			else if (int_arr[i - M] == window[K - 1]) {
				window.erase(window.begin() + K - 1);
			}
			else {
				window.erase(lower_bound(window.begin(), window.begin() + K - 1, int_arr[i - M]));
			}
			if (cur > window[K - 1]) {
				window.insert(lower_bound(window.begin() + K - 1, window.end(), cur), cur);
			}
			else if (cur == window[K - 1]) {
				window.insert(window.begin() + K - 1, cur);
			}
			else {
				window.insert(lower_bound(window.begin(), window.begin() + K - 1, cur), cur);
			}
			cout << window[K - 1] << endl;
		}
	}
	return 0;
}