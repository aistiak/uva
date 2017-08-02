// I/O problem ignores one line

#include<bits/stdc++.h>
#define ll long long
using namespace std ;

int main(){
   freopen("out.txt","w",stdout);
   ll r ,p , q , c = 0 ;
   double price  , com , t ,p2;
   string result , temp , temp2;
   while(scanf("%lld%lld",&r,&p)){

         t  = 10000 ;
         p2 = 10000 ;
         for(ll i = 0 ; i <= r ; i++){
             cout << i << " = "<< endl;
             getline(cin,temp);
             //cin >> temp ;
         }

         for(ll i = 0 ; i < p ; i++){
                //cout << "hi" << endl;
             getline(cin,temp2);
             cout << "int " << endl;
             cin >> price >> q ;
             for(ll k = 0 ; k < q ; k++){
                getline(cin,temp2);
                //cin >> temp;
             }
             com = r / q ;
             if(com == t && p2<price){
               result = temp2 ;
               p2 = price ;
             }
             else if(t>com){
               t = com ;
               result = temp2 ;
               p2 = price;
             }
         }

         cout <<"RFP #" << ++c << endl;
         cout << result << endl<<endl;

   }

   return 0 ;
}
