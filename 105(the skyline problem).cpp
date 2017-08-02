
/// uva 105
/// the sky line problem
#include<bits/stdc++.h>
#define ll long long
#define MAX 10000000
using namespace std ;
ll arr[MAX] = {0} ;
int main(){
   //freopen("out.txt","w",stdout) ;
    ll l , h , r ;
    ll lowPoint = 0, highPoint = 0 ,  f = 1 ;

    while(cin >> l >> h >> r ){
        if(f == 1){
            lowPoint = l ;
            f = 0 ;
        }
        highPoint = max(highPoint,r);
        for(int i = l ; i<r ; i++){
              arr[i] = max(arr[i],h) ;
        }

    }
    ll temp  ;
    for(int i = lowPoint ; i <=highPoint ; i+=1){
           if(temp!=arr[i]){
           //  printf("%lld%5lld ",i,arr[i]);
            cout <<  i<< " "<< arr[i] ;
           if(i!=highPoint) cout << " " ;
           }
           temp = arr[i] ;
    }
    cout << endl;

    return 0 ;
}
