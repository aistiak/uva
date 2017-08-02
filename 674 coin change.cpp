// 674 coin change
#include<bits/stdc++.h>
using namespace std  ;

int main(){
    //freopen("out.txt","w",stdout);
    int dp[8000] ={} , n ;

    int coins[] = {1 , 5 , 10 , 25 , 50 };
    dp[0] = 1 ;
    for(int i = 0 ; i<5 ;i++){
        for(int j = coins[i] ; j< 8000 ; j++){
             dp[j] += dp[j - coins[i]];
        }
    }

    while(cin >> n){
        cout << dp[n] << endl;
    }

    return 0 ;
}

