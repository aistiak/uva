// I/O problem ignores one line

#include<bits/stdc++.h>
#define ll long long
using namespace std ;

int main(){
  // freopen("out.txt","w",stdout);
   ll r ,p , q , c = 0 ;
   double price  , com , t ,p2;
   //string result , temp , temp2;
   char result[1000] , temp[1000] , temp2[1000];



   while(scanf("%lld%lld\n",&r,&p)){

         t  = 10000 ;
         p2 = 10000 ;
         for(ll i = 0 ; i < r ; i++){
            // cout << i << " = "<< endl;
             gets(temp);
             //scanf("%[^\n]s",temp);
             printf("%s\n",temp);
             //getline(cin,temp);

         }
        // cout << "done" << endl;

         for(ll i = 0 ; i < p ; i++){
                //cout << "hi" << endl;
              gets(temp2);
             //scanf("%[^\n]s",temp2);
             //getline(cin,temp2);
             //cout << "int " << endl;
             //cin >> price >> q ;
             scanf("%lf%lld",&price,&q);
             for(ll k = 0 ; k < q ; k++){
                gets(temp2);
                //scanf("%[^\n]",temp2);
                //getline(cin,temp2);
                //cin >> temp;
             }
             com = r / q ;
             if(com == t && p2<price){
               strcpy(result,temp2);
               //result = temp2 ;
               p2 = price ;
             }
             else if(t>com){
               t = com ;
               strcpy(result,temp2);
               //result = temp2 ;
               p2 = price;
             }
         }

         cout <<"RFP #" << ++c << endl;
         cout << result << endl<<endl;

   }

   return 0 ;
}
