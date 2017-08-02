#include<bits/stdc++.h>

using namespace std ;
char arr[101][101] ;
int m , n ;
void fun(char arr[][101], int i , int j)  // i and j are the positions
{
    arr[i][j] = '*' ;
    if(i+1<m and i+1>=0 and j+1<n and j+1>=0)
        if(arr[i+1][j+1] == '@') {
            fun(arr,i+1,j+1);    //1
        }

    if(i+1<m and i+1>=0 and j<n and j>=0)
        if(arr[i+1][j] == '@') {
            fun(arr,i+1,j);    //2
        }
    if(i<m and i>=0 and j+1<n and j+1>=0)
        if(arr[i][j+1] == '@') {
            fun(arr,i,j+1);    //3
        }
    if(i-1<m and i-1>=0 and j-1<n and j-1>=0)
        if(arr[i-1][j-1]== '@') {
            fun(arr,i-1,j-1);    //4
        }
    if(i-1<m and i-1>=0 and j<n and j>=0)
        if(arr[i-1][j] == '@') {
            fun(arr,i-1,j);    //5
        }
    if(i<m and i>=0 and j-1<n and j-1>=0)
        if(arr[i][j-1] == '@') {
            fun(arr,i,j-1);    //6
        }

    if(i+1<m and i+1>=0 and j-1<n and j-1>=0)
        if(arr[i+1][j-1] == '@') { // 7
            fun(arr,i+1,j-1);
        }
    if(i-1<m and i-1>=0 and j+1<n and j+1>=0)
        if(arr[i-1][j+1] == '@') { // 8
            fun(arr,i-1,j+1);
        }

    return ;
}
int main()
{

    //freopen("out.txt","w",stdout);
    int counter = 0;
    while(cin >> m >> n , m ) {

        /// input section
        for(int i = 0 ; i<m ; i++)
            for(int j = 0 ; j<n ; j++) {
                cin >> arr[i][j];
            }

        /// process
        for(int i = 0 ; i<m ; i++)
            for(int j = 0 ; j<n ; j++) {
                if(arr[i][j] == '@') {
                    counter++;
                    fun(arr,i,j);
                }
            }


////        for(int i = 0 ; i<m ; i++){
////            for(int j = 0 ; j<n ; j++) {
////                cout  << arr[i][j] ;
////            }
////            cout << endl;
////        }

       cout << counter << endl;
       counter = 0;
    }
    return 0 ;
}
