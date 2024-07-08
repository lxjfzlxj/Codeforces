#include <bits/stdc++.h>
#define report(args...) return printf(args), void()
# define N 200010
char s[N];
void out(int l,int r) {
	for(int i=l;i<=r;i++) putchar(s[i]);
	putchar(' ');
}
void _() {
	int n;
	scanf("%s",s+1);
	n=strlen(s+1);
	if(s[1]==s[n]) out(1,1), out(2,n-1), out(n,n);
	else {
		int i;
		for(i=2;i<n && s[i]!='a';i++);
		if(i<n) out(1,i-1), out(i,i), out(i+1,n);
		else out(1,1), out(2,n-1), out(n,n);
	}
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

