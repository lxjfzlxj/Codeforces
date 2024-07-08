# include <bits/stdc++.h>
# define N 110
char s[N];
void _() {
	int n,i,now=0;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++) {
		if(s[i]=='Q') now++;
		else if(now) now--;
	}
	puts(now?"No":"Yes");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

