//156 - Ananagrams
#include<bits/stdc++.h>
#define ll long long
using namespace std ;
string lower(string s ){
       string s1 = "";
       ll sz = s.size() ;

       for(int i = 0 ; i<sz ;i++){
          s1+=tolower(s[i]);
       }

       return s1 ;
}
int main(){
   // freopen("out.txt","w",stdout);
     string s1 ,temp ;
     vector<string> arr, v2;
     map <string,string>m1 ;
     map<string,ll>m2;
     map<string,string>::iterator it ;
      m1.clear() ;
      m2.clear() ;
     while(cin>>s1){
         if(s1 == "#") break ;
         arr.push_back(s1);
//         temp = lower(s1) ;
//         sort(temp.begin(),temp.end())
//         m1[s1] = temp ;
     }
     ll sz = arr.size();
     for(ll i = 0 ; i<sz ;i++){
         temp = arr[i];
         temp = lower(temp);
         sort(temp.begin(),temp.end());
         m2[temp]++;
     }

    for( ll i = sz - 1 ; i>=0 ; i--){
       temp = arr[i] ;
       temp = lower(temp);
       sort(temp.begin(),temp.end());
       if(m2[temp] == 1){
          v2.push_back(arr[i]);
          //cout << arr[i] << endl;
       }
    }
    sort(v2.begin(),v2.end());
    for(int i = 0 ; i<v2.size() ;i++){
         cout << v2[i] << endl;
    }
    return 0 ;
}

