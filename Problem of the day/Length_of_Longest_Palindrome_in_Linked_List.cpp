#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

int dp[101][101];

int is_Palindrome(vector<int>v,int i,int j)
{
    if(i==j)
    {
        return true;
    }
    else if(j-i==1)
    {
        return v[i]==v[j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(v[i]==v[j])
    {
        return dp[i][j] = is_Palindrome(v,i+1,j-1);
    }
    else
    {
        return dp[i][j] = 0;
    }
}

int maxPalindrome(Node *head)
{
    //Your code here
    if(head==NULL)
    {
        return 0;
    }
    vector<int>v;
    Node* temp = head;
    while(temp!=NULL)
    {
        v.push_back(temp->data);
        temp=temp->next;
    }
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(is_Palindrome(v,i,j))
            {
                ans = max(ans,j-i+1);
            }
        }
    }
    
    return ans;
}

int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}