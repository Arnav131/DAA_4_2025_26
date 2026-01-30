#include <bits/stdc++.h>
using namespace std;


void complexRec(int n , int & count) {
    count++;

   if (n <= 2) {
       return;
   }// 1 time 


   int p = n;
   while (p > 0) {
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {// n times
           temp[i] = i ^ p;
       }
       p >>= 1;// logn times 
   }// nlogn times


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       small[i] = i * i;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());// t()
   } else {
       reverse(small.begin(), small.end());
   }


   complexRec(n / 2,count);// n/2 times
   complexRec(n / 2,count);// n/2 times
   complexRec(n / 2,count);// n/2 times
}


int main(){
    int count=0;
    complexRec(5,count);
}

// // recurrance relation -  T(n) = 3T(n/2) + O(nlogn)
// time coplexity - O(n^log2(3)) // 2 in base , and 3 in main