#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<vector>
using namespace std;

struct BTNode {
    int data;
    BTNode* lchild;
    BTNode* rchild;
    BTNode(int d) : lchild(NULL), rchild(NULL), data(d) {}
};

class BTree {
    BTNode* r;  
    vector<int> leftLeaves;  
    vector<int> rightLeaves;  
    vector<int> levelOrder;   
public:
    BTree() { r = NULL; }
    void CreatBTree(string str);
    void findLeftLeaves(BTNode* node);  
    void findRightLeaves(BTNode* node);  
    void getLevelOrder();                
    void output();                       
};

void BTree::CreatBTree(string str) {
    stack<BTNode*> st;
    BTNode* p = NULL;
    bool flag = true;
    int i = 0;
    int len = str.length();

    while (i < len) {
        if (str[i] >= '0' && str[i] <= '9') {
            int a = 0;
            while (i < len && str[i] >= '0' && str[i] <= '9') {
                a = a * 10 + (str[i] - '0');
                i++;
            }
            p = new BTNode(a);

            if (r == NULL) {
                r = p;
            }
            else {
                if (flag && !st.empty()) {
                    st.top()->lchild = p;
                }
                else if (!st.empty()) {
                    st.top()->rchild = p;
                }
            }
        }
        else {
            switch (str[i]) {
            case '(':
                st.push(p);
                flag = true;
                i++;
                break;
            case ')':
                if (!st.empty()) st.pop();
                i++;
                break;
            case ',':
                flag = false;
                i++;
                break;
            default:
                i++;
                break;
            }
        }
    }
}

void BTree::findLeftLeaves(BTNode* node) {
    if (node == NULL) return;

    if (node->lchild == NULL && node->rchild==NULL) {
        leftLeaves.push_back(node->data);
    }

    findLeftLeaves(node->lchild);
    findLeftLeaves(node->rchild);
}

void BTree::findRightLeaves(BTNode* node) {
    if (node == NULL) return;

    if (node->rchild == NULL && node->lchild == NULL) {
        rightLeaves.push_back(node->data);
    }

    findRightLeaves(node->rchild);
    findRightLeaves(node->lchild);
}

void BTree::getLevelOrder() {
    if (r == NULL) return;

    queue<BTNode*> q;
    q.push(r);

    while (!q.empty()) {
        BTNode* curr = q.front();
        q.pop();
        levelOrder.push_back(curr->data);
 
        if (curr->rchild != NULL) {
            q.push(curr->rchild);
        }
        if (curr->lchild != NULL) {
            q.push(curr->lchild);
        }
    }
}

void BTree::output() {
    findLeftLeaves(r);   
    findRightLeaves(r);  
    getLevelOrder();   

    for (size_t i = 0; i < leftLeaves.size(); i++) {
        cout << leftLeaves[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < rightLeaves.size(); i++) {
        cout << rightLeaves[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < levelOrder.size(); i++) {
        cout << levelOrder[i] << " ";
    }
    cout << endl;
}

int main() {
    string tree;
    BTree Tree;
    fstream infile("in.txt");

    infile >> tree;
    infile.close();

    Tree.CreatBTree(tree);
    Tree.output();

    return 0;
}