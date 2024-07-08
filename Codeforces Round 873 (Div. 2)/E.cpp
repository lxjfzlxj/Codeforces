# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 500010
char t[N],s[N<<1];
int n,tr[N<<1],f[N<<1],g[N<<1];
int min(int x,int y) {return x<y?x:y;}
void add(int x,int y) {
	int i;
	for(i=x;i<=n;i+=i&(-i)) tr[i]=min(tr[i],y);
}
int query(int x) {
	int i,ans=2e9;
	for(i=x;i>=1;i-=i&(-i)) ans=min(ans,tr[i]);
	return ans;
}
void _() {
	int i,mid,r,j;
	long long ans=0;
	scanf("%d%s",&n,t+1);
	for(i=1;i<=n*2-1;i++) s[i]=i%2?t[(i+1)/2]:'#';
	n=n*2-1;
	mid=r=1; f[1]=0;
	for(i=2;i<=n;i++) {
		f[i]=min(f[mid*2-i],r-i);
		while(i-f[i]-1>=1 && i+f[i]+1<=n && s[i-f[i]-1]==s[i+f[i]+1]) f[i]++;
		if(i+f[i]>r) mid=i, r=i+f[i];
	}
	memset(tr,63,n+5<<2);
	memset(g,0,n+5<<2);
	for(i=n;i>=1;i--) {
		if(s[i]!='#') {
			j=query(i);
			if(j<=n) g[i]=g[j*2-i+2]+1;
			ans+=g[i];
		} else {
			add(i-f[i],i);
		}
	}
	printf("%lld\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

