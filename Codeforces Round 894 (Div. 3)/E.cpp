# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N];
std::multiset<int> mt;
void _() {
	int n,m,d,i;
	long long sum=0,ans=0;
	scanf("%d%d%d",&n,&m,&d);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	mt.clear();
	for(i=1;i<=n;i++) {
		mt.insert(a[i]); sum+=a[i];
		while(mt.size()>m || !mt.empty() && (*mt.begin())<=0) {
			sum-=*mt.begin();
			mt.erase(mt.begin());
		}
		ans=std::max(ans,sum-1ll*d*i);	
	}
	printf("%lld\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

