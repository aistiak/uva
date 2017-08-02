#include<bits/stdc++.h>

using namespace std ;

int main()
{
//    freopen("out.txt","w",stdout);

    map<string,int> m ;

    string arr[26] , in ;
    int i , j , k , l, c = 0;

    for(char ch = 'a' ,  i = 0; ch<='z' ; ch++, i++) {
        arr[i]+=ch;
    }

    for(int i = 0 ; i<26 ; i++) {
        m[arr[i]] = ++c;
    }

    for(int i = 0 ; i < 25 ; i++) {
        for(int j = i+1 ; j<26 ; j++) {
            string temp = arr[i] + arr[j] ;
            m[temp] = ++c ;
        }
    }

    for(int i = 0 ; i<24 ; i++)
        for(int j = i+1 ; j<25 ; j++)
            for(int k = j+1 ; k <26 ; k++) {
                string temp = arr[i] + arr[j] + arr[k] ;
                m[temp] = ++c ;
            }

    for(int i = 0 ; i<23 ; i++)
        for(int j = i+1 ; j<24 ; j++)
            for(int k = j+1 ; k<25 ; k++)
                for(int l = k + 1 ; l <26 ; l++) {
                    string temp = arr[i] + arr[j] + arr[k] + arr[l];
                    m[temp] = ++c ;
                }


    for(int i = 0 ; i<23 ; i++)
        for(int j = i+1 ; j<24 ; j++)
            for(int k = j+1 ; k<25 ; k++)
                for(int l = k + 1 ; l <26 ; l++)
                    for(int p = l + 1 ; p <26 ; p++) {
                        string temp = arr[i] + arr[j] + arr[k] + arr[l] + arr[p];
                        m[temp] = ++c;
                    }


    while(cin >> in) {
        cout << m[in] << endl;
    }

    return 0 ;
}
