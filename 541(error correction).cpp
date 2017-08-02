#include<bits/stdc++.h>

using namespace std ;

int main()
{
    //freopen("out.txt","w",stdout);
    int row[101] , col[101] , n , temp ;

    while(cin >> n , n) {
        for(int i = 1 ; i<=n ; i++) {
            row[i] = 0 ;
            col[i] = 0 ;
        }
        /// input
        for(int i = 1 ; i<=n ; i++) {
            for(int j = 1 ; j<=n ; j++) {
                cin >> temp ;
                row[i]+=temp;
                col[j]+=temp;
            }
        }


        ///processing
        int counter1 = 0, counter2 = 0;
        int colPosition , rowPosition ;
        for(int i = 1 ; i<=n ; i++) {

            if(row[i]%2!=0) { /// if odd sum
                counter1++;
                rowPosition = i ;
            }
            if(col[i]%2!=0) {
                counter2++;
                colPosition = i ;
            }
        }


        /// result
        if(counter1 == 0 and counter2 == 0) {
            cout << "OK" << endl;
        } else if(counter1 >1 or counter2>1) {
            cout << "Corrupt" << endl;
        } else {
            cout << "Change bit " << "(" << rowPosition<< "," <<  colPosition <<")"<<endl;
        }

    }


    return 0 ;
}
