# include <bits/stdc++.h>
# define N 5010
char s[N];
int sum[N],f[N];
std::map<int,int> mp;
int main() {
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%s",&n,s+1);
		for(i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]=='+'?1:-1);
		mp.clear();
		for(i=1;i<=n;i++) {
			f[i]=2e9;
			if(sum[i]==0) f[i]=0;
			if(mp[sum[i]]) f[i]=f[mp[sum[i]]];
			else mp[sum[i]]=i;
			f[i]=std::min(f[i],f[i-1]+1);
		}
		printf("%d\n",f[n]);
	}
	return 0;
}
