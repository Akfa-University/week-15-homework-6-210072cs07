1. Task: Write an implementation of Binary Search Tree (class/structure), which must include:
• Insertion of Tree Node
• Deletion of Tree Node
• Search an Item (BST)
• Get Max Level - function that returns the level of the leaf with minimum depth. • Get Min level - function that returns the level of the leaf with maximum depth. 
• Inorder Traversal
• Preorder Traversal 
• Postorder Traversal

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinarySearchTree {
private:
    TreeNode *root;
public:
    BinarySearchTree() {
        root = NULL;
    }

    TreeNode *getRoot() {
        return root;
    }

    void insert(int val) {
        TreeNode *newNode = new TreeNode(val);
        if (root == NULL) {
            root = newNode;
            return;
        }
        TreeNode *current = root;
        TreeNode *parent = NULL;
        while (current != NULL) {
            parent = current;
            if (val < current->val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (val < parent->val) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    TreeNode *search(int val) {
        TreeNode *current = root;
        while (current != NULL) {
            if (val == current->val) {
                return current;
            } else if (val < current->val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return NULL;
    }

    TreeNode *findMin(TreeNode *node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    TreeNode *remove(TreeNode *node, int val) {
        if (node == NULL) {
            return node;
        }
        if (val < node->val) {
            node->left = remove(node->left, val);
        } else if (val > node->val) {
            node->right = remove(node->right, val);
        } else {
            if (node->left == NULL) {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }
            TreeNode *temp = findMin(node->right);
            node->val = temp->val;
            node->right = remove(node->right, temp->val);
        }
        return node;
    }

    int getMaxLevel(TreeNode *node) {
        if (node == NULL) {
            return -1;
        }
        queue<TreeNode *> q;
        q.push(node);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left == NULL && curr->right == NULL) {
                    return level;
                }
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            level++;
        }
        return level;
    }


    int getMinLevel(TreeNode *node) {
        if (node == NULL) {
            return -1;
        }
        int minLevel = 0;
        queue<TreeNode *> q;
        q.push(node);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            if (!q.empty()) {
                minLevel++;
            }
        }
        return minLevel;
    }

    void inorderTraversal(TreeNode *node) {
        if (node == NULL) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->val << " ";
        inorderTraversal(node->right);
    }

void preorderTraversal(TreeNode *node) {
        if (node == NULL) {
            return;
        }
        cout << node->val << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(TreeNode *node) {
        if (node == NULL) {
            return;
        }
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->val << " ";
    }
};
