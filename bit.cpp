#include<bits/stdc++.h>
#define ll long long
#define max 100001
using namespace std ;

ll tree[max];
ll query(ll idx)
{
    ll sum=0;
    while(idx>0) {
        sum+=tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void update(ll idx, ll x, ll n) //n is the size of the array, x is the number to add
{
    while(idx<=n) {
        tree[idx]+=x;
        idx += idx & (-idx);
    }
}
int main()
{
    ll tc , n , q;
    ll arr[max] ;
    vector<ll> v ;
    scanf("%lld",&tc);

    for(ll i = 1 ; i <= tc ; i++) {
         v.clear() ;
         scanf("%lld%lld",&n,&q) ;

         for(ll j = 0 ; j < n ; j++){
            ll temp ;
            scanf("%lld",&temp);
            arr[j] = temp ;
            update(j+1,temp,n) ; // building the tree
         }

         while(q--){
            ll temp ;
            scanf("%lld",temp);

            if(temp == 1){
               ll index ;
               scanf("%lld",&index) ;
               v.push_back(arr[index]) ; // storing result
               cout <<"index = "<<  arr[index] << endl;
               arr[index] = 0 ;
               // have to build the tree again
               memset(tree,0,sizeof(tree));
               for(ll k = 1 ; k < n ; k++){
                   update(k,arr[k-1],n);
               }

            }else if(temp == 2){ // add money to sack
                ll temp , index;
                scanf("%lld%lld",&temp,&index);
                update(index,temp,n);

            }else if(temp == 3 ){ // money from i to j
                 ll in1 , in2 ;
                 scanf("%lld%lld",&in1,&in2);
                 ll temp = query(in2) - query(in1);
                 v.push_back(temp) ;
            }
         }

         printf("Case %d:\n");
         ll sz = v.size();
         for(ll p = 0 ; p < sz ; p++){
           printf("%lld\n",v[i]);
         }

    }






    return 0 ;
}
