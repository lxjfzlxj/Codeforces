# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define MOD 998244353
std::map<long long,int> f,g,p2;
std::map<long long,bool> vis;
void calc(long long n) {
	if(!vis[n]) vis[n]=true;
	else return;
	long long r=n/2,l=n-r;
	calc(l); calc(r);
	f[n]=(2ll*(f[l]+f[r])+1ll*(p2[l]-1+MOD)*(p2[r]-1+MOD))%MOD;
	g[n]=(0ll+g[l]+g[r]+f[r])%MOD;
	p2[n]=1ll*p2[l]*p2[r]%MOD;
}
void _() {
	long long n;
	scanf("%lld",&n);
	calc(n);
	printf("%d\n",(f[n]+g[n])%MOD);
}

int main() {
	int T=1;
	scanf("%d",&T);
	vis[1]=true; f[1]=1; g[1]=0; p2[1]=2;
	while(T--) _();
	return 0;
}

