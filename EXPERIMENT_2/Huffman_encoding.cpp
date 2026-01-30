#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node * left;
        Node * right;

        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

class cmp{
    public:
        bool operator()(Node * a , Node * b){
            return a->data > b->data;
        }
};


class Solution {
  public:

    void traverse(Node * root , vector<string> & ans , string temp){

        // base case 
        if(root->left==NULL && root->right == NULL){
            ans.push_back(temp);
            return;
        }
        traverse(root->left , ans , temp+"0"); // for the root ka left traverse
        traverse(root->right , ans , temp+"1"); // for the root ka right traverse
    }



    vector<string> huffmanCodes(string S, vector<int> f, int N) {

        priority_queue<Node * , vector<Node * >  , cmp > pq;
        int n = f.size();
        for(int i = 0 ; i < n ; i++){
            // i have to make a new node then using that i can push in the priority queue
            Node * temp = new Node(f[i]); // constructor call
            pq.push(temp);
        }



        while(pq.size() > 1){
            Node * left = pq.top();
            pq.pop();
            Node * right = pq.top();
            pq.pop();

            // hum ek new node me calulation store karke us new node se left and right ko connect kar denge
            Node * newNode = new Node(left->data+right->data);
            // kyu ki is new node ka left and right are null now then 
            newNode -> left = left;
            newNode -> right = right;
            pq.push(newNode);
        }
        Node * root = pq.top(); // get the last remaining element in the min heap as root to all the tree.....

        // just have to traverse for the huffman encoding as tree ban chuka hai 
        vector<string> ans;
        string temp="";
        traverse(root , ans ,temp);// preorder traversal//
        return ans;
    }
};

int main(){
    return 0;
}
