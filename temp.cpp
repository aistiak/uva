#include<bits/stdc++.h>
#define ll long long
using namespace std ;
string fun(ll n )
{
    string s = "" ,temp ="";
    while(n>0) {
        s+= n%10 + '0' ;
        n/=10;
    }
    for(ll k = s.size()-1  ; k >=0 ; k--) {
        temp+=s[k] ;
    }

    return "0"+temp ;
}
int main()
{

    //freopen("out.txt","w",stdout);
    ll n , tem , f = 0  , c = 0;
    vector<ll> in ;
    vector<string> rs ;
    string temp , tempp;
    while(cin >> n , n) {
        in.clear() ;
        rs.clear() ;
        for(ll i = 0 ; i<n ; i++) {
            cin >> tem ;
            in.push_back(tem) ;
        }

        ///processing

        int len = in.size() ;

        for(ll k = 0 ; k < len  ; k++) {

            temp = fun(in[k]) ;
            f = 0 ;
            while(in[k+1] - in[k] == 1 && k < len - 1) {
                if(f == 0 ) {
                    f = 1 ;
                    tempp  = fun(in[k]);
                }
                temp = fun(in[k+1]);
                k++;
            }

            if(f == 1) {
                string t = "" ;
                ll sz =  temp.size() ;// in[0].size();
                for(ll j = 0 ; j<sz ; j++) {
                    if(temp[j] != tempp[j]) {
                        for(;j<sz;j++)
                        t+=temp[j] ;
                    }
                }
                t =  tempp + "-"+ t ;
                rs.push_back(t) ;
            } else {
                //cout << temp << endl;
                rs.push_back(temp);
            }

        }

        cout << "Case " << ++c << ":" << endl;
        ll le = rs.size() ;
        for(ll j = 0 ; j < le ; j++) {
            cout << rs[j] << endl;
        }

        cout << endl;


    }



    return 0 ;
}
