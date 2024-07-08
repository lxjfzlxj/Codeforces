# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 110
char s[N];
void _() {
	int n,i,j,ans=0;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i=j) {
		for(j=i;j<=n && s[j]==s[i];j++);
		if(j-i+1>ans) ans=j-i+1;
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

