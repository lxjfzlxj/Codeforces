# include <bits/stdc++.h>
# define N 300010
# define MOD 998244353
int pr[N],pr_n=0,mn[N];
bool p[N],fc[N];
void _() {
	int n,tot=0,tp,fac,ans=0,i,j,lsans=1;
	long long m,now=1,pm=1;
	scanf("%d%lld",&n,&m);
	for(i=2;i<=n;i++) {
		if(!p[i]) pr[++pr_n]=i, mn[i]=i;
		for(j=1;j<=pr_n && i*pr[j]<=n;j++) {
			p[i*pr[j]]=true;
			mn[i*pr[j]]=pr[j];
			if(!(i%pr[j])) break;
		}
	}
	for(i=1;i<=n;i++) {
		pm=1ll*(m%MOD)*pm%MOD;
		tot=(tot+pm)%MOD;
	}
	for(i=1;i<=n && now<=m;i++) {
		tp=i;
		while(tp>1) {
			fac=mn[tp];
			while(!(tp%fac)) tp/=fac;
			if(!fc[fac]) fc[fac]=true, now*=fac;
		}
		lsans=1ll*lsans*(m/now%MOD)%MOD;
		ans=(ans+lsans)%MOD;
	}
	printf("%d",(tot-ans+MOD)%MOD);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

