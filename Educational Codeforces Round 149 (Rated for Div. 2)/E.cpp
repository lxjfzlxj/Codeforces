# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define MOD 998244353
# define N 555555
int a[N],fac[N],p2[N];
void _() {
	int n,k,i,j,v,c1,c2,ans=1;
	scanf("%d",&k); n=1<<k; 
	for(i=1;i<=n;i++) scanf("%d",a+i);
	fac[0]=p2[0]=1;
	for(i=1;i<=n;i++) {
		fac[i]=1ll*fac[i-1]*i%MOD;
		p2[i]=p2[i-1]*2%MOD;
	}
	for(i=k;i>=1;i--) {
		v=1<<i-1; c1=c2=0;
		for(j=1;j<=v;j++) {
			if(a[j*2-1]>0 && a[j*2]>0 && (a[j*2-1]<=v && a[j*2]<=v || a[j*2-1]>v && a[j*2]>v)) {
				report("0\n");
			}
			if(a[j*2-1]<=v && a[j*2]<=v) {
				if(a[j*2-1]==-1 && a[j*2]==-1) c1++;
				else c2++;
			}
			if(a[j*2-1]>=1 && a[j*2-1]<=v) a[j]=a[j*2-1];
			else if(a[j*2]>=1 && a[j*2]<=v) a[j]=a[j*2];
			else a[j]=-1;
		}
		ans=1ll*ans*fac[c1+c2]%MOD*p2[c1]%MOD;
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

