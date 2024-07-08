# include <bits/stdc++.h>
# define N 100010
int n,a[N],b[N],c[N],tr[N],pos[N<<1];
void add(int x,int y) {
	for(int i=x;i<=n;i+=i&(-i)) tr[i]+=y;
}
int query(int x) {
	int ans=0;
	for(int i=x;i>=1;i-=i&(-i)) ans+=tr[i];
	return ans;
}
void _() {
	int i;
	bool fg=true;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i), pos[a[i]]=i;
	for(i=1;i<=n;i++) {
		scanf("%d",b+i);
		if(!pos[b[i]]) fg=false;
		c[i]=pos[b[i]];
	}
	if(!fg) {
		for(i=1;i<=n;i++) pos[a[i]]=0;
		return puts("NO"), void();	
	}
	memset(tr,0,n+5<<2);
	long long tot=0;
	for(i=1;i<=n;i++) {
		tot+=i-1-query(c[i]);
		add(c[i],1);
	}
	if(tot&1) puts("NO");
	else puts("YES");
	for(i=1;i<=n;i++) pos[a[i]]=0;
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

