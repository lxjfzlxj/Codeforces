# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 300010
char s[N],l[N],r[N];
int las[10],ch[N][10];
void _() {
	int n,m,i,j,now=0,mx;
	scanf("%s%d%s%s",s+1,&m,l+1,r+1); n=strlen(s+1);
	for(i=0;i<=9;i++) las[i]=n+1;
	for(i=n;i>=0;i--) {
		for(j=0;j<=9;j++) ch[i][j]=las[j];
		if(i) las[s[i]-'0']=i;
	}
	for(i=1;i<=m;i++) {
		mx=0;
		for(j=l[i]-'0';j<=r[i]-'0';j++) mx=std::max(mx,ch[now][j]);
		now=mx;
		if(now==n+1) break;
	}
	puts(i<=m?"YES":"NO");
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}