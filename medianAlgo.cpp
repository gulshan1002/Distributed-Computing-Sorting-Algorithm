#include<bits/stdc++.h>
using namespace std;
void loop(int l, int n, vector<pair<int, int>>&arr)
{
    for(int j=l;j<n;j+=3)
    {
        int x, y, z;
        x = y = z = INT_MAX;
        if(j-1<0)
        {
            if(arr[j].second>arr[j+1].second)
            {
                swap(arr[j].second, arr[j+1].second);
            }
            arr[j].first+=2;
            arr[j+1].first+=2;
        }
        else if(j-1>=0 && j+1<n)
        {
            int x, y, z;
            x = arr[j-1].second;
            y = arr[j].second;
            z= arr[j+1].second;
            int total = x+y+z;
            arr[j-1].second = min(x,min(y,z));
            arr[j+1].second = max(x,max(y,z));
            arr[j].second = total-(arr[j-1].second+arr[j+1].second);
            arr[j-1].first+=2;
            arr[j].first+=2;
            arr[j+1].first+=2;
        }
        else if(j+1>=n)
        {
            if(arr[j-1].second>arr[j].second)
            {
                swap(arr[j-1].second, arr[j].second);
            }
            arr[j-1].first+=2;
            arr[j].first+=2;
        }
    }
}
void medianAlgoSort(vector<pair<int,int>>arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++)
    {
        if(i%3==0)
        {
            loop(1, n, arr);
        }
        else if(i%3==1)
        {
            loop(2, n, arr);
        }
        else if(i%3==2)
        {
            loop(0, n, arr);
        }
        cout<<"Round "<<(i+1)<<" -> ";
        for(int j=0;j<n;j++)
        {
            cout<<arr[j].second<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<pair<int,int>>arr(n);
    for(int i=0;i<n;i++)
    {
        arr[i].first = i%3;
        cin>>arr[i].second;
    }
    medianAlgoSort(arr);
    return 0;
}