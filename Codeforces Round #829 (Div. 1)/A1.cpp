# include <bits/stdc++.h>
# define N 200010
int n,a[N];
bool cg[N];
void work(int v,int c) {
	int i;
	memset(cg,false,n+5);
	printf("%d\n",n-c);
	for(i=2;i<=n;i++) {
		if(c && a[i]==v && !cg[i-1]) cg[i]=true, c--;
	}
	for(i=1;i<=n;i++) {
		if(!cg[i]) {
			if(cg[i+1]) printf("%d %d\n",i,i+1);
			else printf("%d %d\n",i,i);
		}
	}
}
void _() {
	int i,cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		if(a[i]==1) cnt++;
	}
	if(n&1) return puts("-1"), void();
	if(cnt<n/2) work(-1,n/2-cnt);
	else work(1,cnt-n/2);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

