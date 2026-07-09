class Node {
public:
    char op;
    int val;
    Node *left, *right;

    
    Node(int x) {
        val = x;
        op = '#';
        left = right = nullptr;
    }

    
    Node(char c, Node* l, Node* r) {
        op = c;
        left = l;
        right = r;
    }
};

class Solution {
public:

    int evaluate(Node* root) {
        if (root->op == '#')
            return root->val;

        int left = evaluate(root->left);
        int right = evaluate(root->right);

        if (root->op == '+')
            return left + right;

        return 0;
    }

    int sum(int num1, int num2) {
        Node* left = new Node(num1);
        Node* right = new Node(num2);

        Node* root = new Node('+', left, right);

        return evaluate(root);
    }
};