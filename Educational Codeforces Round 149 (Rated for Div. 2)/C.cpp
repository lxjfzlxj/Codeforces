# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 300010
char s[N];
int t[N],t_n;
void _() {
	int i,n,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	t[t_n=1]=0;
	for(i=1;i<=n;i++) {
		if(s[i]!='?') t[++t_n]=i; 
	}
	t[++t_n]=n+1;
	for(i=1;i<t_n;i++) {
		for(j=t[i]+1;j<t[i+1];j++) s[j]=s[t[i]];
	}
	puts(s+1);
}

int main() {
	int T=1;
	scanf("%d",&T);
	s[0]='0';
	while(T--) _();
	return 0;
}

