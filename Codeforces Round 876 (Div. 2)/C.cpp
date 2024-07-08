# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 100010
int ans[N],ans_n,a[N];
void _() {
	int n,i,j,k,las;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	if(a[n]) return puts("NO"), void();
	puts("YES");
	for(i=1,ans_n=0;i<=n;i=j+1) {
		for(j=i;j<=n && a[j];j++);
		ans[++ans_n]=j-i;
		for(k=i;k<j;k++) ans[++ans_n]=0;
	}
	for(i=ans_n;i>=1;i--) printf("%d ",ans[i]);
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

