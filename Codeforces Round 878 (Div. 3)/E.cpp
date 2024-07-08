# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
char s1[N],s2[N];
bool dif[N];
std::vector<int> vec[N];
void _() {
	int n,t,q,i,op,o1,o2,p1,p2,cnt=0;
	scanf("%s%s%d%d",s1+1,s2+1,&t,&q);
	n=strlen(s1+1);
	for(i=1;i<=n;i++) {
		dif[i]=(s1[i]!=s2[i]);
		cnt+=dif[i];
	}
	for(i=1;i<=q;i++) {
		scanf("%d",&op);
		if(op==1) {
			scanf("%d",&p1);
			cnt-=dif[p1];
			if(i+t-1<=q) vec[i+t-1].push_back(p1);
		}
		else if(op==2) {
			scanf("%d%d%d%d",&o1,&p1,&o2,&p2);
			std::swap(o1==1?s1[p1]:s2[p1],o2==1?s1[p2]:s2[p2]);
			if(s1[p1]!=s2[p1] && !dif[p1]) {
				dif[p1]=1; cnt++;
			}
			if(s1[p1]==s2[p1] && dif[p1]) {
				dif[p1]=0; cnt--;
			}
			if(s1[p2]!=s2[p2] && !dif[p2]) {
				dif[p2]=1; cnt++;
			}
			if(s1[p2]==s2[p2] && dif[p2]) {
				dif[p2]=0; cnt--;
			}
		}
		else puts(cnt?"NO":"YES");
		for(auto x:vec[i]) cnt+=dif[x];
	}
	for(i=1;i<=q;i++) vec[i].clear();
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}


