/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
public:
    struct Info {
        int size;      // size of subtree
        int minVal;    // minimum value in subtree
        int maxVal;    // maximum value in subtree
        bool isBST;    // is subtree BST
    };

    int maxSize = 0;

    Info solve(Node* root) {
        if (!root) {
            return {0, INT_MAX, INT_MIN, true};
        }

        Info left = solve(root->left);
        Info right = solve(root->right);

        Info curr;

        // Check BST condition
        if (left.isBST && right.isBST &&
            root->data > left.maxVal &&
            root->data < right.minVal) {
            
            curr.size = left.size + right.size + 1;
            curr.minVal = min(root->data, left.minVal);
            curr.maxVal = max(root->data, right.maxVal);
            curr.isBST = true;

            maxSize = max(maxSize, curr.size);
        } else {
            curr.size = 0;
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
            curr.isBST = false;
        }

        return curr;
    }

    int largestBst(Node *root) {
        maxSize = 0;
        solve(root);
        return maxSize;
    }
};