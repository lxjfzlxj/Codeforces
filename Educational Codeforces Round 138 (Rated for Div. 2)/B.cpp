# include <bits/stdc++.h>
int max(int x,int y) {return x>y?x:y;} 
void _() {
	int x,n,i,mx=0;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		ans+=x;
	}
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		ans+=x; mx=max(mx,x);
	}
	printf("%lld\n",ans-mx);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

