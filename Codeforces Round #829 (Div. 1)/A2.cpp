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
	int i,cnt=0,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		sum+=a[i];
		if(a[i]==1) cnt++;
	}
	if(sum%2) return puts("-1"), void();
	if(sum>0) work(1,sum/2);
	else work(-1,-sum/2);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

