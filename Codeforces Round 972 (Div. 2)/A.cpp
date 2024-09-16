# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
    char ch[10]="aeiou";
    int n,i,j;
    scanf("%d",&n);
    for(j=0;j<5;j++) {
        int cnt=n/5;
        if(j<n%5) cnt++;
        while(cnt--) putchar(ch[j]);
    }
    puts("");
}
int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}