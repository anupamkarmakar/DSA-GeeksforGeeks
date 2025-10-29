// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int,int>> vec;
        if(!head || !head->next) return vec;
        
        Node *left=head;
        Node *right=head;
        
        while(right->next){
            right=right->next;
        }
        
        while(left!=right && right->next!=left && left && right){
            int sum=left->data + right->data;
            
            if(target==sum){
                vec.push_back({left->data,right->data});
                right=right->prev;
                left=left->next;
            }
            else if(target<sum) right=right->prev;
            else left=left->next;
        }
        return vec;
    }
};