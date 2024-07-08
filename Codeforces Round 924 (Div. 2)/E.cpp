# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int n,x,y,f[N],g[N],ret;
void prt(int s) {
	int i;
	if(!s) return;
	for(i=0;i<=g[s];i++) printf("%d ",ret+i*y);
	prt(s-g[s]*(g[s]+1)/2);
}
void _() {
	int i,j,sum,ii;
	long long s;
	scanf("%d%d%d%lld",&n,&x,&y,&s);
	ret=x%y;
	s-=1ll*ret*n;
	if(s<0 || s%y) report("NO\n");
	s/=y;
	memset(f,63,s+5<<2);
	f[0]=0;
	for(i=1;(ii=i*(i+1)/2)<=s;i++) {
		for(j=ii;j<=s;j++) {
			if(f[j-ii]+i+1<f[j]) {
				f[j]=f[j-ii]+i+1;
				g[j]=i;
			}
		}
	}
	for(i=1,sum=0;i<=n;i++) {
		sum+=x/y+i-1;
		if(sum>s) break;
		if(f[s-sum]<=n-i) {
			puts("YES");
			for(j=1;j<=i;j++) printf("%d ",x+(j-1)*y);
			prt(s-sum);
			for(j=1;j<=n-i-f[s-sum];j++) printf("%d ",ret);
			puts("");
			return;
		}
	}
	puts("NO");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

