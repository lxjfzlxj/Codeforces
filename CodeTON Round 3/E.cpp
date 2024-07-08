# include <bits/stdc++.h>
# define N 200010
char s[N];
int sum[N],l[N],r[N],sta[N],top;
void _() {
	int n,i;
	long long ans=0;
	scanf("%d%s",&n,s+1);
	sum[0]=0;
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]=='('?1:-1);
	sta[0]=-1;
	for(i=0,top=0;i<=n;i++) {
		while(top && sum[sta[top]]>sum[i]) top--;
		l[i]=sta[top]+1; sta[++top]=i;
	}
	sta[0]=n+1;
	for(i=n,top=0;i>=0;i--) {
		while(top && sum[sta[top]]>=sum[i]) top--;
		r[i]=sta[top]-1; sta[++top]=i;
	}
	for(i=0;i<=n;i++) ans-=(1ll*(i-l[i]+1)*(r[i]-i+1)-1)*sum[i];
	std::sort(sum,sum+n+1);
	for(i=0;i<=n;i++) ans+=1ll*i*sum[i];
	printf("%lld\n",ans);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

