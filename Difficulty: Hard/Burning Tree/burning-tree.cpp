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

    Node* markParents(Node* root, map<Node*, Node*> &parent, int target, Node* &targetNode){
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            if(curr->data == target)
                targetNode = curr;
                
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        return targetNode;
    }

    int minTime(Node* root, int target) {
        
        map<Node*, Node*> parent;
        Node* targetNode = NULL;
        
        markParents(root, parent, target, targetNode);
        
        map<Node*, bool> visited;
        queue<Node*> q;
        
        q.push(targetNode);
        visited[targetNode] = true;
        
        int time = 0;
        
        while(!q.empty()){
            
            int size = q.size();
            bool flag = false;
            
            for(int i=0;i<size;i++){
                
                Node* curr = q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left]){
                    flag = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                
                if(curr->right && !visited[curr->right]){
                    flag = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                
                if(parent[curr] && !visited[parent[curr]]){
                    flag = true;
                    visited[parent[curr]] = true;
                    q.push(parent[curr]);
                }
            }
            
            if(flag) time++;
        }
        
        return time;
    }
};