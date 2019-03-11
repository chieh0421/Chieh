#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
	int N, M, K, cur;
	cin >> N >> M >> K;
	/*deque<int>  window;
	int *int_arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> cur;
		int_arr[i] = cur;
		if (i < M - 1)
			window.push_back(cur);
		else if (i == M - 1) {
			window.push_back(cur);
			sort(window.begin(), window.end());
			cout << window[K - 1] << endl;
		}
		else {
			window.erase(lower_bound(window.begin(), window.end(), int_arr[i - M]));
			window.insert(lower_bound(window.begin(), window.end(), cur), cur);
			cout << window[K - 1] << endl;
		}
	}
	delete[] int_arr;
	return 0;*/
	map<int, int> int_map;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		int_map.insert(i,cur);
		if (i == M - 1) {
			sort(int_map.begin(), int_map.end());
			cout <<  << endl;
		}
	}
}