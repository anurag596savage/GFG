#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[1001][1001];
int Longest_Palindromic_Subsequence(string str1)
{
    string str2 = str1;
    reverse(str2.begin(),str2.end());
    for(int i=0;i<=str1.length();i++)
    {
        for(int j=0;j<=str2.length();j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i=1;i<=str1.length();i++)
    {
        for(int j=1;j<=str2.length();j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    int insertions = str1.length() - dp[str1.length()][str2.length()];
    return insertions;
}

int countMin(string str)
{
    return Longest_Palindromic_Subsequence(str);
}

int main()
{
	string s;
	cin>>s;
	
	cout<<countMin(s)<<endl;
	
	return 0;
}

