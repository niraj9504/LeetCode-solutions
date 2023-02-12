//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    bool isPrime(int x){
        if(x<=1)return false;
        for(int i=2;i<=sqrt(x);i++){
            if(x%i==0)return false;
        }
        return true;
    }
    int find(int x){
        for(int i=1;i<=1e4;i++){
            if(x-i>0 && isPrime(x-i))return x-i;
            else if(isPrime(x+i))return x+i;
        }
        return -1;
    }
    Node *primeList(Node *head){
        Node* temp=head;
        while(temp){
            if(isPrime(temp->val)==false){
                int x=find(temp->val);
                temp->val=x;
            }
            temp=temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends