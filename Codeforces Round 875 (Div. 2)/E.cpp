# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 300010
# define MOD 998244353
typedef unsigned long long ull;
std::vector<int> st[N],ed[N];
std::map<ull,std::pair<int,int>> mp;
ull val[N];
int c[N],inv[N],fac[N<<1],ifac[N<<1];
std::mt19937_64 rd(std::chrono::steady_clock::now().time_since_epoch().count());
int C(int n,int m) {
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
int calc(int n) {
	if(n&1) return 0;
	n/=2;
	return 1ll*C(n*2,n)*inv[n+1]%MOD;
}
int qpow(int x,int p) {
	int res=1;
	while(p) {
		if(p&1) res=1ll*res*x%MOD;
		x=1ll*x*x%MOD; p>>=1; 
	}
	return res;
}
void _() {
	int n,k,i,cnt=0,l,r,ans=1;
	ull now=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) {
		st[i].clear();
		ed[i].clear();
	}
	for(i=1;i<=k;i++) {
		scanf("%d%d",&l,&r);
		st[l].push_back(i);
		ed[r].push_back(i);
		val[i]=rd();
	}
	mp.clear();
	memset(c,0,n+5<<2);
	for(i=1;i<=n;i++) {
		for(auto j:st[i]) now^=val[j];
		if(!mp.count(now)) mp[now].first=++cnt;
		mp[now].second++;
		c[mp[now].first]=mp[now].second;
		for(auto j:ed[i]) now^=val[j];
	}
	inv[1]=1;
	for(i=2;i<=n+1;i++) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
	fac[0]=1;
	for(i=1;i<=n*2;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	ifac[n*2]=qpow(fac[n*2],MOD-2);
	for(i=n*2-1;i>=0;i--) ifac[i]=1ll*ifac[i+1]*(i+1)%MOD;
	for(i=1;i<=cnt;i++) ans=1ll*ans*calc(c[i])%MOD;
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}
