# include <bits/stdc++.h>
# define N 200010
int a[N],b[N],t[N],t_n;
std::vector<int> vec[N];
void _() {
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) vec[i].clear();
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		vec[a[i]].push_back(i);
	}
	t_n=0;
	for(i=n;i>=1;i--) {
		if(vec[i].size()>2) return puts("NO"), void();
		if(vec[i].size()==2) {
			a[vec[i][0]]=b[vec[i][1]]=i;
			t[++t_n]=i;
		}
		else if(vec[i].size()==1) {
			a[vec[i][0]]=b[vec[i][0]]=i;
		}
		else {
			if(!t_n) return puts("NO"), void();
			b[vec[t[t_n]][0]]=a[vec[t[t_n]][1]]=i;
			t_n--;
		}
	}
	puts("YES");
	for(i=1;i<=n;i++) printf("%d ",a[i]);
	puts("");
	for(i=1;i<=n;i++) printf("%d ",b[i]);
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

