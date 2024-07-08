# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 5010
int a[N],cnt[N];
bool f[N][N<<1];
struct pair{
	int l,val;
};
std::vector<pair> vec[N];
void _() {
	int n,i,j,k,mex,vmax;
	scanf("%d",&n); vmax=std::min(n*2,8191);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) vec[i].clear();
	for(i=1;i<=n;i++) {
		memset(cnt,0,n+5<<2); mex=0;
		for(j=i;j<=n;j++) {
			cnt[a[j]]++;
			while(cnt[mex]) mex++;
			if(a[i]>a[j] && mex>a[i] && cnt[a[i]]==1) {
				vec[j].push_back((pair){i,mex});
				break;
			}
		}
		memset(cnt,0,n+5<<2); mex=0;
		for(j=i;j>=1;j--) {
			cnt[a[j]]++;
			while(cnt[mex]) mex++;
			if(a[i]>a[j] && mex>a[i] && cnt[a[i]]==1) {
				vec[i].push_back((pair){j,mex});
				break;
			}
		}
		if(!a[i]) vec[i].push_back((pair){i,1});
	}
	f[0][0]=true;
	for(i=1;i<=n;i++) {
		for(k=0;k<=vmax;k++) f[i][k]=f[i-1][k];
		for(auto j:vec[i]) {
			for(k=0;k<=vmax;k++) f[i][k]|=f[j.l-1][k^j.val];
		}
	}
	for(k=vmax;k>=0 && !f[n][k];k--);
	printf("%d\n",k);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}
