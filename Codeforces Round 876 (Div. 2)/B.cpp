# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
std::vector<int> vec[N];
void _() {
	int n,i,j,x,y,sz;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) vec[i].clear();
	for(i=1;i<=n;i++) {
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
	}
	for(i=1;i<=n;i++) {
		std::sort(vec[i].begin(),vec[i].end(),std::greater<int>());
		for(j=0,sz=vec[i].size();j<sz && j<i;j++) ans+=vec[i][j];
	}
	printf("%lld\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

