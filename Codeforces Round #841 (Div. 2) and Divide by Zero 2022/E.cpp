# include <bits/stdc++.h>
# define N 1000010
long long f[N];
bool p[N];
int pr[N],mu[N],pr_n=0;
void calc(int n) {
	int i;
	for(i=1;i<=n;i++) f[n]+=1ll*mu[i]*(n/i)*(n/i);
	f[n]=(f[n]-1)/2;
}
void _() {
	int n,i;
	long long m,sum=0,ans=0;
	scanf("%d%lld",&n,&m);
	for(i=n/2;i>=2 && m>sum;i--) {
		if(!f[n/i]) calc(n/i);
		if(m>sum) {
			if(m<=sum+f[n/i]/(i-1)*(i-1)) {
				ans+=(m-sum)/(i-1);
				if((m-sum)%(i-1)) ans++;
			} else {
				ans+=f[n/i]/(i-1);
			}
		}
		sum+=f[n/i]/(i-1)*(i-1);
	}
	if(m>sum) puts("-1");
	else printf("%lld\n",m+ans);
}

int main() {
	int T=1,i,j;
	scanf("%d",&T);
	mu[1]=1;
	for(i=2;i<=1e6;i++) {
		if(!p[i]) pr[++pr_n]=i, mu[i]=-1;
		for(j=1;j<=pr_n && i*pr[j]<=1e6;j++) {
			p[i*pr[j]]=true;
			if(!(i%pr[j])) break;
			mu[i*pr[j]]=-mu[i];
		}
	}
	while(T--) _();
	return 0;
}

