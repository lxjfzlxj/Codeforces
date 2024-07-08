#include <bits/stdc++.h>
std::map<long long, bool> bucket;
std::map<long long, long long> position;
int main() {
	int q;
	char type[5];
	long long x;
	scanf("%d", &q);
	while(q--) {
		scanf("%s%lld", type, &x);
		if(type[0]=='+') {
			bucket[x] = true;
		} else {
			if(!position[x]) {
				position[x] = x;
			}
			while(bucket[position[x]]) {
				position[x] += x;
			}
			printf("%lld\n", position[x]);
		}
	}
	return 0;
}
