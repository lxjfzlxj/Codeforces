#include <bits/stdc++.h>
#define report(args...) return printf(args), void()
#define N 100010
std::vector<int> a[N];
int buc[N<<1];
void _() {
	int n,i,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&k);
		a[i].clear();
		while(k--) {
			int x;
			scanf("%d",&x);
			a[i].push_back(x);
			buc[x]++;
		}
	}
	bool ans=false;
	for(i=1;i<=n;i++) {
		bool b=0;
		for(auto x:a[i]) {
			if(buc[x]==1) {b=1; break;}
		}
		if(!b) ans=true;
	}
	for(i=1;i<=n;i++) {
		for(auto x:a[i]) buc[x]--;
	}
	puts(ans?"Yes":"No");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

