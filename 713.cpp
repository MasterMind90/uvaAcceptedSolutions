#include <bits/stdc++.h>
using namespace std;
string sum(string a,string b){
    int c = 0 ; 
    if ( a.size() < b.size() ) swap(a,b);
    int len = max(a.size(),b.size());
    int mn = min(a.size(),b.size());
    string ans = "" ; 
    for(int i=len-1,j=mn-1;i>=0;i--,j--){
        int y ; 
        if ( j < 0 ) y = 0 ; 
        else y = b[j]-'0' ; 
        int x = a[i]-'0' ; 
        int total = x+y+c ; 
        int r = total%10 ; 
        stringstream ss ; 
        ss << r ; 
        string t ; 
        ss >> t ; 
        ans += t ;
        c = total / 10;
    }
    if ( c > 0 ){
        stringstream ss ; 
        ss << c ; 
        string t ; 
        ss >> t ; 
        ans += t ;
    }
    for(int i=0;i<ans.size();i++){
        if ( ans[i] != '0' ) return ans.substr(i);
    }
    return "0" ; 
}

int main(){
    int n ; 
    cin >> n ; 
    while(n--){
        string a , b ; 
        cin >> a >> b ; 
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string x = "0" , y ="0" ; 
        for(int i=0;i<a.size();i++){
            if ( a[i] == '0' ) continue ; 
            else{
                x = a.substr(i);
                break;
            }
        }
        for(int i=0;i<b.size();i++){
            if ( b[i] == '0' ) continue ; 
            else{
                y = b.substr(i);
                break;
            }
        }
        string c = sum(x,y);
        cout << c << endl;
    }
    return 0 ; 
}
