#include <bits/stdc++.h>
using namespace std;

int main(){
	int n ;
	while(cin >> n, n!=0 ){
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		}
		int cnt = 0 ;
		int c = 0 ;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				cnt++ ;

				int ans = __gcd(v[i],v[j]);
				//cout << v[i] << "," << v[j] << ":" << ans << endl;
				if ( ans == 1 ) c++;
			}
		}
        if ( c == 0 ) {
            cout << "No estimate for this data set." << endl;
            continue ;
        }
		long double res = sqrt(6.0*(long double)cnt/(long double)c) ;
		cout << fixed << setprecision(6) << res << endl;
	}
	return 0 ;
}
