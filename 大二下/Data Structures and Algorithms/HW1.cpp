#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int>pp;

bool compare(const pp&left, const pp& right) {
	return left.second < right.first;
}

map<int, int>::iterator find(map<int, int>::iterator start, map<int, int>::iterator end, int value) {
	while (start != end) {
		if (start->first == value)
			return start;
		start++;
	}
	return end;
}

int main()
{
	int N, M, K, cur;
	cin >> N >> M >> K;
	map<int,int> int_map;
	map<int, int>::iterator it;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		int_map.insert(pp(i + 1, cur));
		if (i == M - 1) {
			sort(int_map.begin(), int_map.end(),compare);
			for (int j = 1; j < K; j++)
				it++;
			cout << it->second << endl;
		}
		else if (i >= M) {
			int_map.erase(find(int_map.begin(), int_map.end(), i - M + 1));
			cout << it->second << endl;
		}
	}
}




