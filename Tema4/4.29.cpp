#include <iostream>
using namespace std;

const int N = 9;

void maxMeseta(int v[], int n, int& actual, int& max);
int maxMeseta(int v[], int n);

void maxMeseta(int v[], int n, int& actual, int& max){

   if (n == 0){
      actual = 1;
      max = 1;
   }
   else{
      maxMeseta(v,n-1,actual, max);
      if(v[n-1] == v[n]){
         actual++;
         if(actual > max)
            max = actual;
      }
      else
         actual = 1;

   }
}
int maxMeseta(int v[], int n){
   int max, actual;
   maxMeseta(v, N-1, actual, max);

   return max;
}

int main(){
   int v[N] = {0,1,2,3,4,5,6,7,8};

   cout << maxMeseta(v, N);

   return 0;
}
