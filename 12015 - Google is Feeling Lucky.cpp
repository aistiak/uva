//12015 - Google is Feeling Lucky
#include<bits/stdc++.h>
using namespace std ;

int main(){
//    freopen("out.txt","w",stdout);
    map<int, vector<string> > in ;
    string s ;
    int tc , n , m;

    cin >> tc ;

    for (int k = 1 ; k<=tc ; k++){
        m = 0;
        in.clear();
        for(int i = 0 ; i < 10 ;i++){
            cin >> s ;
            cin >> n ;
            m = max(m,n);
            in[n].push_back(s);
        }
        cout <<"Case #" <<k <<":" << endl;
        for(int i = 0 ; i<in[m].size() ; i++){
            cout << in[m][i]<<endl;
        }

    }

    return 0 ;
}

