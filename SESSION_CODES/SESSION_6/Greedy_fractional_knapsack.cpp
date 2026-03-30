#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>a,pair<int,int>b){
    double r1 = (double)a.first/a.second;
    double r2 = (double)b.first/b.second;
    return r1>r2;
}


double solve_kanapsack(vector<pair<int,int>>&vec,int & bag){
    sort(vec.begin(),vec.end(),cmp);
    double profit=0.0;
    for(auto & it:vec){
        int value = it.first;
        int weight = it.second;

        if(weight<=bag){
            profit+=value;
            bag-=weight;
        }
        else{
            // add and calculate the fractional weight
            profit+=(double)value*bag/weight;// double is add to explictly convert the int value to fractions 
            break;
        }
    }
    return profit;
}
int main(){

    vector<pair<int,int>> wight_value;
    int bag;
    cout<<"enter the wieght of the bag : ";
    cin>>bag;
    int n;
    cout<<"enter the number of items for sale : ";
    cin>>n;
    for(int i=0 ; i<n ; i++){
        int a,b;
        cin >>a>>b;
        auto it = make_pair(a,b);
        wight_value.push_back(it);
    }
    double ans = solve_kanapsack(wight_value , bag);
    cout<<"\n Max profit is : "<<ans<<endl;
    return 0;
}
