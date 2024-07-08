# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 30
long long a[N];
int ans_n;
struct pair{
	int x,y;
}ans[60];
void opera(int x,int y) {
	a[x]+=a[y];
	ans[++ans_n]=(pair){x,y};
}
void _() {
//	int n,i,mxk=0,mnk=0;
//	long long mx=-2e9,mn=2e9;
//	scanf("%d",&n);
//	for(i=1;i<=n;i++) {
//		scanf("%lld",a+i);
//		if(a[i]>mx) mx=a[i], mxk=i;
//		if(a[i]<mn) mn=a[i], mnk=i;
//	}
//	ans_n=0;
//	if(mx+mn>0) {
//		for(i=1;i<=n;i++) {
//			if(a[i]<0) opera(i,mxk);
//		}
//		for(i=2;i<=n;i++) opera(i,i-1);
//	}
//	else {
//		for(i=1;i<=n;i++) {
//			if(a[i]>0) opera(i,mnk);
//		}
//		for(i=n-1;i>=1;i--) opera(i,i+1);
//	}
//	printf("%d\n",ans_n);
//	for(i=1;i<=ans_n;i++) printf("%d %d\n",ans[i].x,ans[i].y);
////	puts("array:");
////	for(i=1;i<=n;i++) printf("%lld ",a[i]);
////	puts("");
int n,i;
scanf("%d",&n);
for(i=1;i<=n;i++) scanf("%lld",a+i);
int ans_n;
scanf("%d",&ans_n);
while(ans_n--) {
	int x,y;
	scanf("%d%d",&x,&y);
	a[x]+=a[y];
	for(i=1;i<=n;i++) printf("%lld ",a[i]);
	puts("");
}
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}
/*
1
20
1 -14 2 -10 6 -5 10 -13 10 7 -14 19 -5 19 1 18 -16 -7 12 8
31
14 1
18 7
13 11
15 11
6 4
5 17
19 6
19 12
10 5
11 12
1 17
15 19
16 10
14 2
16 11
20 7
7 6
9 5
3 6
6 14
17 18
18 14
12 3
17 16
8 18
13 16
9 8
14 8
16 2
11 8
12 7
*/
