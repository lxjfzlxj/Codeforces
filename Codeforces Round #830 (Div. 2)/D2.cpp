#include <bits/stdc++.h>
std::map<long long, bool> bucket;
std::map<long long, long long> Answer;
std::map<long long, std::set<long long>> preAnswer;
std::map<long long ,std::set<long long>> factor;
int main() {
	int q;
	char type[5];
	long long x;
	std::set<long long>::iterator iter;
	scanf("%d", &q);
	while(q--) {
		scanf("%s%lld", type, &x);
		if(type[0] == '+') {
			bucket[x] = true;
		}
		else if(type[0] == '-') {
			bucket[x] = false;
			for(auto fact: factor[x]) {
				preAnswer[fact].insert(x);
			}
		}
		else {
			if(!Answer.count(x)) {
				Answer[x] = x;
				factor[x].insert(x);
			}
			while(!preAnswer[x].empty()) {
				iter = preAnswer[x].begin();
				if(!bucket[*iter]) break;
				preAnswer[x].erase(iter);
			}
			if(!preAnswer[x].empty()) {
				printf("%lld\n", *iter);
			} else {
				while(bucket[Answer[x]]) {
					Answer[x] += x;
					factor[Answer[x]].insert(x);
				}
				printf("%lld\n", Answer[x]);
			}
		}
	}
	return 0;
}
