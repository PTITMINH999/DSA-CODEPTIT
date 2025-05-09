#include<bits/stdc++.h>
using namespace std;
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define run() int t;cin>>t;while(t--)
#define ll long long
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) {
        val = v;
        left = right = NULL;
    }
};

bool isLeaf(Node* node) {
    return node && node->left == NULL && node->right == NULL;
}

int sumRightLeaves(Node* root) {
    if (!root) return 0;
    int sum = 0;
    if (isLeaf(root->right)) {
        sum += root->right->val;
    }
    sum += sumRightLeaves(root->left);
    sum += sumRightLeaves(root->right);
    return sum;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, Node*> m;
        Node* root = NULL;
        while (n--) {
            int u, v;
            char c;
            cin >> u >> v >> c;
            Node* parent;
            if (m.count(u)) parent = m[u];
            else {
                parent = new Node(u);
                m[u] = parent;
                if (!root) root = parent;
            }

            Node* child = new Node(v);
            if (c == 'L') parent->left = child;
            else parent->right = child;
            m[v] = child;
        }

        cout << sumRightLeaves(root) << endl;
    }
}
