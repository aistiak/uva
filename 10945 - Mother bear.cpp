
// 10945 - Mother bear
#include<bits/stdc++.h>
using namespace std ;

string rev(string s){

   string temp = "";

   for(int i = s.size()-1 ; i>=0 ; i--){
      temp+=s[i];
   }

   return temp ;

}
int main(){
//    freopen("out.txt","w",stdout);
    vector <string > v ;
    char ch ;
    string s= "", t="" ;

    while(scanf("%c",&ch)!=EOF){

      if(ch =='\n'){ // if new line

            if(t == "DONE" ) break ;

        v.push_back(s);
        s = "";
        t = "";
      }
      if(isalpha(ch)) {
         t+=ch;
         s+=tolower(ch);
      }

    }

//    for(int i = 0  ; i <v.size() ; i++){
//         cout << v[i] << endl;
//    }

    // process
    for(int i = 0 ; i<v.size() ; i+=1){
           string temp = "";
           temp = v[i];//rev(v[i]);
           reverse(temp.begin(),temp.end());
//         for(int j = v[i].size() -1 ; j >=0 ; j-=1) temp+=v[i][j];
//        //reverse(temp.begin(),temp.end());
//        cout << "temp = " << temp << endl;
//        cout << "s = " << v[i] << endl;

        if(v[i] == temp) cout << "You won't be eaten!" << endl;
        else cout <<  "Uh oh.." << endl;
    }
    return 0 ;
}
