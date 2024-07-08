# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 30
char s[N][N],t[N];
void _() {
	int j,n,m,i,now=1;
	scanf("%d%d",&n,&m);
	t[1]='v'; t[2]='i'; t[3]='k'; t[4]='a';
	for(i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(j=1;j<=m;j++) {
		for(i=1;i<=n && s[i][j]!=t[now];i++);
		if(i<=n) now++;
		if(now>4) break;
	}
	puts(now>4?"YES":"NO");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

