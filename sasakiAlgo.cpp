#include<bits/stdc++.h>
using namespace std;
void loop(vector<pair<int,int>>&arr, vector<pair<char,char>>&keep, vector<int>&area){
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        if(arr[i].second>arr[i+1].first)
        {
            swap(arr[i].second, arr[i+1].first);
            if(keep[i].second=='u'){
                keep[i].second='a';
                keep[i+1].first='u';
                area[i+1]--;
            }
            else if(keep[i+1].first=='u'){
                keep[i].second='u';
                keep[i+1].first = 'a';
                area[i+1]++;
            }
        }
    }
    for(int j=0;j<n;j++)
    {
        if(arr[j].first>arr[j].second){
            swap(arr[j].first, arr[j].second);
            if(j!=0 && j!=n-1){
                swap(keep[j].first, keep[j].second);
            }
        }
    }
}
void sasakiAlgoSort(vector<pair<int, int>>&arr, vector<pair<char,char>>&keep, vector<int>&area){
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        loop(arr, keep, area);
        for(int j=0;j<n;j++)
        {
            cout<<arr[j].first<<"|"<<arr[j].second<<" ";
        }
        cout<<endl;
        for(int j=0;j<n;j++)
        {
            cout<<keep[j].first<<"|"<<keep[j].second<<" ";
        }
        cout<<endl;
        for(int j=0;j<n;j++)
        {
            cout<<area[j]<<" ";
        }
        cout<<endl;
        cout<<endl;
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<pair<int, int>>arr(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(i==0)
        {
            arr[i].first = INT_MIN;
            arr[i].second = x;
        }
        else if(i==n-1)
        {
            arr[i].first = x;
            arr[i].second = INT_MAX;
        }
        else{
            arr[i].first = x;
            arr[i].second = x;
        }
    }
    vector<pair<char, char>>keep(n,{'a','a'});
    vector<int>area(n,0);
    area[0]=-1;
    keep[0].second = 'u';
    keep[n-1].first = 'u';
    sasakiAlgoSort(arr, keep, area);

    // Final ans
    cout<<"Ans after Solution selection: ";
    for(int i=0;i<n;i++)
    {
        if(area[i]==-1){
            cout<<arr[i].second<<" ";
        }
        else{
            cout<<arr[i].first<<" ";
        }
    }
    cout<<endl;
    return 0;
}