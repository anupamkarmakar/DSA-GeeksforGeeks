/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
    int solve(Node* root, int k, long long currSum, unordered_map<long long,int> &mp){
        
        if(root == NULL) return 0;
        
        currSum += root->data;
        
        int count = 0;
        
        if(currSum == k)
            count++;
        
        if(mp.find(currSum - k) != mp.end())
            count += mp[currSum - k];
        
        mp[currSum]++;
        
        count += solve(root->left, k, currSum, mp);
        count += solve(root->right, k, currSum, mp);
        
        mp[currSum]--;   // backtrack
        
        return count;
    }
  
    int countAllPaths(Node *root, int k) {
        
        unordered_map<long long,int> mp;
        return solve(root, k, 0, mp);
    }
};