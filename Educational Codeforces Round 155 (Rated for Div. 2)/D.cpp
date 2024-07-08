# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 300010
# define MOD 998244353
int a[N],cnt[2][N],xx[N];
void _() {
	int n,i,j,sum,ans=0,l0,l1,r0,r1;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(j=30;j>=0;j--) {
		cnt[0][0]=1;
		for(i=1;i<=n;i++) {
			xx[i]=xx[i-1]^((a[i]>>j)&1);
			cnt[0][i]=cnt[0][i-1]+(xx[i]==0);
			cnt[1][i]=cnt[1][i-1]+(xx[i]==1);
		}
		sum=0;
		for(i=1;i<=n;i++) {
			l0=cnt[xx[i-1]][i-1]; l1=i-l0;
			r0=cnt[xx[i]][n]-cnt[xx[i]][i-1]; r1=n-i+1-r0;
			if((a[i]>>j)&1) sum=(1ll*l0*r0+1ll*l1*r1+sum)%MOD;
			else sum=(1ll*l0*r1+1ll*l1*r0+sum)%MOD;
		}
		ans=(1ll*sum*(1<<j)+ans)%MOD;
	}
	printf("%d",ans);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}
