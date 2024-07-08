# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int b[N],ans[N],ans_n;
void _() {
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",b+i);
	ans_n=0;
	ans[++ans_n]=b[1];
	for(i=2;i<=n;i++) {
		if(b[i-1]==1) ans[++ans_n]=b[i];
		else ans[++ans_n]=1, ans[++ans_n]=b[i];
	}
	printf("%d\n",ans_n);
	for(i=1;i<=ans_n;i++) printf("%d ",ans[i]); puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

