# include <bits/stdc++.h>
# define N 200010
int a[N];
std::multiset<int> mt;
void _() {
	int n,m,i,ans=0;
	long long sum=0,ex=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	mt.clear();
	for(i=m;i>=2;i--) {
		if(a[i]>0) mt.insert(a[i]);
		sum+=a[i];
		while(sum+ex>0) {
			auto it=--mt.end();
			ex-=2*(*it);
			mt.erase(it);
			ans++;
		}
	}
	sum=ex=0;
	mt.clear();
	for(i=m+1;i<=n;i++) {
		if(a[i]<0) mt.insert(-a[i]);
		sum+=a[i];
		while(sum+ex<0) {
			auto it=--mt.end();
			ex+=2*(*it);
			mt.erase(it);
			ans++;
		}
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

