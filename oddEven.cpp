#include<bits/stdc++.h>
using namespace std;
void oddEvenSort(vector<int>arr)
{
    int n = arr.size();
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<n-1;j+=2)
            {
                if(j+1<n)
                {
                    if(arr[j]>arr[j+1])
                    {
                        swap(arr[j], arr[j+1]);
                    }
                }
            }
            cout<<"Round "<<i+1<<"-> ";
            for(int j=0;j<n;j++)
            {
                cout<<arr[j]<<" ";
            }
            cout<<endl;
        }
        else
        {
            for(int j=1;j<n-1;j+=2)
            {
                if(j+1<n)
                {
                    if(arr[j]>arr[j+1])
                    {
                        swap(arr[j], arr[j+1]);
                    }
                }
            }
            cout<<"Round "<<i+1<<"-> ";
            for(int j=0;j<n;j++)
            {
                cout<<arr[j]<<" ";
            }
            cout<<endl;
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    oddEvenSort(arr);
    return 0;
}