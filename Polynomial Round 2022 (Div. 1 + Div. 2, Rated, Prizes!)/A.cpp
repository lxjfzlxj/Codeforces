# include <bits/stdc++.h>
# define N 110
char s[N];
void _() {
	int n,i;
	bool b;
	scanf("%d%s",&n,s+1);
	b=(s[1]=='1');
	for(i=2;i<=n;i++) {
		putchar(b?'-':'+');
		if(s[i]=='1') b^=1;
	}
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

