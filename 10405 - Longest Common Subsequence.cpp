//10405 - Longest Common Subsequence
#include<bits/stdc++.h>
using namespace std ;
int n , m ;
int dp[2000][2000];
string s1 , s2 ;
int lcs(int i , int j)
{
    int x1 , x2 ;

    if(i>=s1.length() or j >=s2.length()) {
        return 0 ;
    }

    else if(s1[i] == s2[j]) {


        if(dp[i][j] !=0) {
            return dp[i][j];
        } else {

            dp[i][j] = lcs(i+1,j+1) + 1;
            return dp[i][j];

        }
    }

    else {




        if(dp[i][j+1]!=0) {
            x1= dp[i][j+1];
        } else {
            dp[i][j+1] = lcs(i,j+1);
            x1 = dp[i][j+1];
        }
        if(dp[i+1][j]!=0) {
            x2 = dp[i+1][j] ;
        } else {
            dp[i+1][j] = lcs(i+1,j);
            x2 = dp[i+1][j]  ;
        }
        //int x2 = lcs(i+1,j);
        int x = max(x1,x2);

        return x ;
    }


}
int main()
{

    //i = j = 0 ;
    //freopen("out.txt","w",stdout);
    while(getline(cin,s1)) {
        getline(cin,s2);
//        int sz = max(s1.length(),s2.length());
        for(int i = 0 ; i<2000 ; i++)
            for(int j = 0 ; j<2000 ; j++) {
                dp[i][j] = 0;
            }
        n = m = 0 ;

        int rs = lcs(n,m);

        cout << rs   << endl;


    }


    return 0 ;
}

