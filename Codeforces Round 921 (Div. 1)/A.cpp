# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define M 1010
char s[M],ans[M];
int las[26],ch[M][26],ans_n;
void _() {
	int n,k,m,i,now,mx;
	scanf("%d%d%d%s",&n,&k,&m,s+1);
	for(i=0;i<26;i++) ch[m][i]=m+1;
	for(i=m;i>=1;i--) {
		memcpy(ch[i-1],ch[i],sizeof(ch[i]));
		ch[i-1][s[i]-'a']=i;
	}
	now=0; ans_n=0;
	int n0=n;
	while(n--) {
		mx=0; ans_n++;
		for(i=0;i<k;i++) {
			if(ch[now][i]>mx) {
				mx=ch[now][i];
				ans[ans_n]=i+'a';
			}
		}
		now=mx;
		if(now==m+1) {
			puts("NO");
			while(ans_n<n0) ans[++ans_n]='a';
			ans[n0+1]=0;
			puts(ans+1);
			return;
		}
	}
	puts("YES");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

