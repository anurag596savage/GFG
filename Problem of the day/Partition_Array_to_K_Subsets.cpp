#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

bool isKPartitionPossible(int* arr,int n,int k,int current_sum,int required_sum,bool* output,int i)
{
	if(k==0)
	{
		return true;
	}
	if(current_sum==required_sum)
	{
		return isKPartitionPossible(arr,n,k-1,0,required_sum,output,0);
	}
	if(i==n)
	{
		return false;
	}
	
	if(!output[i] && current_sum+arr[i]<=required_sum)
	{
		output[i] = true;
		if(isKPartitionPossible(arr,n,k,current_sum+arr[i],required_sum,output,i+1))
		{
			return true;
		}
		output[i] = false;
	}
	
	return isKPartitionPossible(arr,n,k,current_sum,required_sum,output,i+1);
	
	
}

bool isKPartitionPossible(int* arr,int n,int k)
{
	if(k==1)
	{
		return true;
	}
	if(k>n || k==0)
	{
		return false;
	}
	int sum = accumulate(arr,arr+n,0);
	if(sum%k)
	{
		return false;
	}
	int required_sum = sum/k;
	bool* output = new bool[n];
	for(int i=0;i<n;i++)
	{
		output[i] = false;
	}
	return isKPartitionPossible(arr,n,k,0,required_sum,output,0);
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
	
	int k;
	cin>>k;
	
	bool ans = isKPartitionPossible(arr,n,k);
	cout<<ans<<endl;
	
	return 0;
}

