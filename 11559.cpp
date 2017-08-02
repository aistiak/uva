// AC
#include<bits/stdc++.h>
#define ll long long
using namespace std ;

int main(){
     //freopen("out.txt","w",stdout);
     ll n , b , h , w , cost , f_cost , h_rate , temp , flag = 0 ;

     while(scanf("%lld%lld%lld%lld",&n,&b,&h,&w)!=EOF){
           cost = b+1 ;

           for(ll i = 0 ; i<h ; i++){
              scanf("%lld",&h_rate);

              for(ll j = 0 ; j < w ; j++){
                 scanf("%lld",&temp);
                 if(temp>=n) flag = 1 ;
              }
              if(flag == 1) {

                 cost = min(cost,h_rate*n);
              }
              flag = 0 ;
           }
           if(b>=cost){
             printf("%lld\n",cost);
           }else {
             printf("stay home\n");
           }
     }
     return 0 ;
}
