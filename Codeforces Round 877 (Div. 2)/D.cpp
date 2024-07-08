# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
char s[N];
std::set<int> st;
void _() {
	int n,q,i,x,fst,lst,c1=0,c2=0;
	scanf("%d%d%s",&n,&q,s+1);
	for(i=1;i<n;i++) {
		if(s[i]==s[i+1]) st.insert(i);
	}
	for(i=1;i<=n;i++) {
		if(s[i]=='(') c1++;
		else c2++;
	}
	while(q--) {
		scanf("%d",&x);
		s[x]='('+')'-s[x];
		if(s[x]=='(') c1++, c2--;
		else c1--, c2++;
		if(x>1) {
			if(s[x-1]==s[x]) st.insert(x-1);
			else st.erase(x-1);
		}
		if(x<n) {
			if(s[x]==s[x+1]) st.insert(x);
			else st.erase(x);
		}
		if(((c1>c2?c1-c2:c2-c1)&1) || s[1]==')') puts("NO");
		else if(st.empty()) puts("YES");
		else {
			fst=*st.begin(); lst=*(--st.end());
			if(s[fst]=='(' && s[lst]==')') puts("YES");
			else puts("NO");
		}
	}
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

