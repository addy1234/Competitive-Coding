#include<bits/stdc++.h>
using namespace std;

const int max_N = 3e5 + 10;

int main()
{
	set<int> unread_by_time;
	vector<int> unread_by_app[max_N];

	int N, Q;
	int curr_time = 1;
	scanf("%d%d", &N, &Q);
	while(Q--) {
		int type, x;
		scanf("%d%d", &type, &x);
		if (type == 1) {
			unread_by_time.insert(curr_time);
			unread_by_app[x].push_back(curr_time++);
		} else if (type == 2) {
			for (auto &y : unread_by_app[x])
				unread_by_time.erase(y);
			unread_by_app[x].clear();
		} else {
			auto it = unread_by_time.lower_bound(x + 1);
			unread_by_time.erase(unread_by_time.begin(), it);

		}
		printf("%lu\n", unread_by_time.size());
	}
}