# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 110
char s[N]; 
void _() {
	int n,i,j;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i=j+1) {
		putchar(s[i]);
		for(j=i+1;s[j]!=s[i];j++);
	}
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

