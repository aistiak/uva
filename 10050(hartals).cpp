/// error
/// not done

#include<bits/stdc++.h>
#define max 4000
using namespace std ;
int arr[max] ;
int h[200];
int main()
{

    // freopen("out.txt","w",stdout);
    int tc , day , parties ;

    cin >> tc ;

    while(tc--)
    {
        int counter = 0;
        memset(arr,0,sizeof(arr));
        memset(h,0,sizeof(h));
        cin >> day >> parties;
        for(int i = 0 ; i<parties ; i+=1) cin >> h[i] ;

        for(int i = 0 ; i < parties ; i++)
        {

            for(int k = 1 ; k<=day; k+=h[i])
            {
                if(k%7!=0 and arr[k]!=1 and k!=1 and k<=day)
                {
                   // cout << " day = " << k << endl;
                    arr[k] = 1;
                    counter++ ;
                }
            }
        }

        cout << counter << endl;
    }


    return 0 ;
}
