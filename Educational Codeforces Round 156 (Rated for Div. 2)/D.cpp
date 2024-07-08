# include <bits/stdc++.h>
# define N 300010
# define MOD 998244353
char s[N];
int v[N],inv[N];
int main() {
	int n,m,i,x,ans=1;
	char ch[5];
	scanf("%d%d%s",&n,&m,s+2);
	for(i=n;i>=2;i--) {
		if(s[i]=='?') v[i]=i-2;
		else v[i]=1;
		if(v[i]) ans=1ll*ans*v[i]%MOD;
	}
	if(!v[2]) puts("0");
	else printf("%d\n",ans);
	inv[1]=1;
	for(i=2;i<=n;i++) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
	while(m--) {
		scanf("%d%s",&x,ch); x++;
		if(v[x]) ans=1ll*ans*inv[v[x]]%MOD;
		s[x]=ch[0];
		if(s[x]=='?') v[x]=x-2;
		else v[x]=1;
		if(v[x]) ans=1ll*ans*v[x]%MOD;
		if(!v[2]) puts("0");
		else printf("%d\n",ans);
	}
	return 0;
} 
