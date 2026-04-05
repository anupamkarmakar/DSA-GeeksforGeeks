#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int freq;
    int idx;
    Node* left;
    Node* right;

    Node(int f, int i) {
        freq = f;
        idx = i;
        left = right = NULL;
    }
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        if (a->freq == b->freq)
            return a->idx > b->idx;
        return a->freq > b->freq;
    }
};

class Solution {
public:

    void preorder(Node* root, string temp, vector<string>& ans) {
        if (!root) return;

        if (!root->left && !root->right) {
            ans.push_back(temp);
            return;
        }

        preorder(root->left, temp + "0", ans);
        preorder(root->right, temp + "1", ans);
    }

    vector<string> huffmanCodes(string &s, vector<int> f) {
        
        int n = f.size();
        priority_queue<Node*, vector<Node*>, cmp> pq;

        for (int i = 0; i < n; i++) {
            pq.push(new Node(f[i], i));
        }

        if (pq.size() == 1) return {"0"};

        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();

            Node* newNode = new Node(
                left->freq + right->freq,
                min(left->idx, right->idx)   // 🔥 FIX HERE
            );

            newNode->left = left;
            newNode->right = right;

            pq.push(newNode);
        }

        vector<string> ans;
        preorder(pq.top(), "", ans);

        return ans;
    }
};