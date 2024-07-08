# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 300000
long long sum[N];
int las[N];
std::pair<int,int> pr[N];
void prt(int l1,int r1,int l2,int r2) {
	if(l1>l2) std::swap(l1,l2), std::swap(r1,r2);
	if(r1>l2) std::swap(r1,l2);
	if(l2>r2) std::swap(l2,r2);
	printf("%d %d %d %d\n",l1+1,r1,l2+1,r2);
}
void _() {
	int k,n,i,t1,t2;
	long long x;
	scanf("%d",&k); n=1<<k+1;
	for(i=1;i<=n;i++) {
		scanf("%lld",&x);
		sum[i]=sum[i-1]^x;
	}
	memset(las,-1,n+5<<2);
	for(i=0;i<=n;i++) pr[i]=std::make_pair(-1,-1);
	for(i=0;i<=n;i++) {
		t1=sum[i]%(1<<k);
		if(las[t1]>=0) {
			t2=(sum[i]^sum[las[t1]])>>k;
			if(pr[t2].first!=-1) return prt(pr[t2].first,pr[t2].second,las[t1],i), void();
			pr[t2]=std::make_pair(las[t1],i);
		}
		las[sum[i]%(1<<k)]=i;
	}
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

