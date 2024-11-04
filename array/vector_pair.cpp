#include<iostream>
#include<vector>
#include <algorithm>  //for sort()
using namespace std;

int main(){

    vector<int> v;
    v.push_back(1);

    for( int i=0; i< v.size(); i++){
        cout<<v[i]<<" ";
    }
    vector<int>::iterator it;//iterator
    for(it=v.begin(); it!=v.end();it++){
        cout<<*it<<" ";
    }
    for(auto element : v){
        cout<<element<<" ";
    }

    v.pop_back();

    vector<int> v2(3,-1);  //(size, initialise with)
    swap(v, v2);

    sort(v.begin(),v.end());
    int max = *max_element(v.begin(),v.end());
    int min = *min_element(v.begin(),v.end());


    pair<int,char> p;

    p.first =3;
    p.second = 'f';


    vector<pair<int,int>> v;

    //store arr in pairs
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        pair<int,int> p;
        p.first = arr[i];
        p.second=i;

        //or

        v.push_back(make_pair(arr[i],i));
    }

    sort(v.begin(),v.end(), myCompare);     //bool myCompare(pair<int,int> p1, pair<int, int>p2{//return p1.first<p2.first;}


}