#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n , m ;
	while(cin >> n >> m){
		if ( n == 0 || m == 0 ) break;
		vector<long long> numerator ;
		vector<long long> denominator;
		if ( n-m >= m ){
			for(int i=n-m+1;i<=n;i++){
				numerator.push_back(i);
			}
			for(int i=2;i<=m;i++){
				denominator.push_back(i);
			}
			for(int i=0;i<numerator.size();i++){
				for(int j=0;j<denominator.size();j++){
					long long ans = __gcd(numerator[i],denominator[j]);
					numerator[i]/=ans ;
					denominator[j]/=ans ;
				}
			}
			long long num = 1 ;
			long long denom = 1 ;
			for(int i=0;i<numerator.size();i++){
				num *= numerator[i];
			}
			for(int i=0;i<denominator.size();i++){
				denom *= denominator[i];
			}
			cout << n << " things taken " << m << " at a time is " << num/denom << " exactly." << endl;

		}
		else{
			for(int i=m+1;i<=n;i++){
				numerator.push_back(i);
			}
			for(int i=2;i<=n-m;i++){
				denominator.push_back(i);
			}
			for(int i=0;i<numerator.size();i++){
				for(int j=0;j<denominator.size();j++){
					long long ans = __gcd(numerator[i],denominator[j]);
					numerator[i]/=ans ;
					denominator[j]/=ans ;
				}
			}
			long long num = 1 ;
			long long denom = 1 ;
			for(int i=0;i<numerator.size();i++){
				num *= numerator[i];
			}
			for(int i=0;i<denominator.size();i++){
				denom *= denominator[i];
			}
			cout << n << " things taken " << m << " at a time is " << num/denom << " exactly." << endl;
		}
	}
	return 0 ;
}
