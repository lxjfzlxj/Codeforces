# include <bits/stdc++.h>
# define N 5010
int cnt[N],a[N],f[N];
void _() {
	int n,i,mex,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		if(a[i]<=n) cnt[a[i]]++;
	}
	for(mex=0;cnt[mex];mex++);
	f[mex]=0;
	for(i=mex-1;i>=0;i--) {
		f[i]=2e9;
		for(j=i+1;j<=mex;j++) f[i]=std::min(f[i],f[j]+(cnt[i]-1)*j+i);
	}
	printf("%d\n",f[0]);
	for(i=1;i<=n;i++) {
		if(a[i]<=n) cnt[a[i]]--;
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) _();
	return 0;
} 
