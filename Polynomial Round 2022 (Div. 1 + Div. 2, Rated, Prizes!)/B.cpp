# include <bits/stdc++.h>
# define N 100010
int a[N];
void _() {
	int n,m,k,i,cnt=0;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++) scanf("%d",a+i);
	if(m<k) return puts("NO"), void();
	for(i=1;i<=m;i++) {
		if(a[i]>n/k+1) return puts("NO"), void();
		if(a[i]==n/k+1) cnt++;
	}
	if(cnt<=n%k) puts("YES");
	else puts("NO");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

