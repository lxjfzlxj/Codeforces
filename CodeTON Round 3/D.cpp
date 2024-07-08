# include <bits/stdc++.h>
# define SQ 33333
# define N 200010
# define MOD 998244353
int pr[SQ],pr_n=0,fc[22],fn,tt[22],tn,a[N];
bool p[SQ];
long long res;
void dfs(int mx,int x,int mul,int sgn) {
	if(x>tn) return res+=sgn*(mx/mul), void();
	dfs(mx,x+1,mul*tt[x],-sgn);
	dfs(mx,x+1,mul,sgn);
}
int calc(int n,int m) {
	tn=0; res=0;
	int i;
	for(i=1;i<=fn;i++) {
		if(m%fc[i]==0) tt[++tn]=fc[i];
	}
	res=0; dfs(n,1,1,1);
	return res;
}
void _() {
	int n,m,i,a1,ans=1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<n;i++) {
		if(a[i]%a[i+1]) return puts("0"), void();
	}
	a1=a[1]; fn=0;
	for(i=1;i<=pr_n && a1>1;i++) {
		if(a1%pr[i]==0) {
			fc[++fn]=pr[i];
			while(a1%pr[i]==0) a1/=pr[i];
		}
	}
	if(a1>1) fc[++fn]=a1;
	for(i=2;i<=n;i++) {
		if(a[i]!=a[i-1]) ans=1ll*ans*calc(m/a[i],a[i-1]/a[i])%MOD;
		else ans=1ll*ans*(m/a[i])%MOD;
	}
	printf("%d\n",ans);
}

int main() {
	int T,i,j;
	scanf("%d",&T);
	for(i=2;i<=33330;i++) {
		if(!p[i]) pr[++pr_n]=i;
		for(j=1;j<=pr_n && i*pr[j]<=33330;j++) {
			p[i*pr[j]]=true;
			if(!(i%pr[j])) break;
		}
	}
	while(T--) _();
	return 0;
}

