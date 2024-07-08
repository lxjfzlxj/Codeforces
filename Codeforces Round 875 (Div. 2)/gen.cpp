# include <bits/stdc++.h>
int rd(int l,int r) {
	return rand()%(r-l+1)+l;
}
int main() {
	srand((unsigned long long)(new char));
	int n=6,k=rd(1,7);
	freopen("E.in","w",stdout);
	puts("1");
	printf("%d %d\n",n,k);
	for(int i=1;i<=k;i++) {
		int x,y;
		while(1) {
			x=rd(1,n), y=rd(1,n);
			if(x>y) std::swap(x,y);
			if((y-x+1)%2==0) if(rd(1,4)>=2) break;
		}
		printf("%d %d\n",x,y);
	}
	return 0;
}
