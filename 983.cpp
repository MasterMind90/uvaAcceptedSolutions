#include <bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long n , m ;
    int cnt = 0 ; 
    while(cin >> n >> m){
        if ( cnt != 0 ){
            cout << endl;
        }
        cnt++;
        unsigned long long g[n+2][n+2] ; 
        memset(g,0,sizeof g);
        for(long long i=n;i>=1;i--){
            for(long long j=1;j<=n;j++){
                cin >> g[i][j] ; 
            }
        }
        unsigned long long sum[n+5][n+5];
        memset(sum,0,sizeof sum);
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=n;j++){
                sum[i][j] += g[i][j];
                sum[i][j] += sum[i-1][j];
                sum[i][j] += sum[i][j-1];
                sum[i][j] -= sum[i-1][j-1];
            }
        }
        unsigned long long len = n-m+1 ; 
        unsigned long long c[len][len] ; 
        memset(c,0,sizeof c);
        for(long long i=0;i<len;i++){
            for(long long j=0;j<len;j++){
                c[i][j] = sum[i+m][j+m] - sum[i][j+m] - sum[i+m][j] + sum[i][j];
            }
        }
        unsigned long long ans = 0  ;
        for(long long i=len-1;i>=0;i--){
            for(long long j=0;j<len;j++){
                cout << c[i][j] << endl;
                ans += c[i][j] ; 
            }
        }
        cout << ans << endl ;
    }
    return 0 ; 
}
