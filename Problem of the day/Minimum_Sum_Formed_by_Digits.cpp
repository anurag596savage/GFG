#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long int minSum(int arr[], int n)
{
    sort(arr,arr+n);
    long long int x = 0;
    for(int i=0;i<n;i=i+2)
    {
        x = 10*x + arr[i];
    }
    long long int y = 0;
    for(int i=1;i<n;i=i+2)
    {
        y = 10*y + arr[i];
    }
    long long int ans = x+y;
    
    return ans;
    
}

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<minSum(arr,n)<<endl;
	
	return 0;
}

