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
public:
    BTree() { r = NULL; }
    void CreatBTree(string str);
    void ifCompleteBtree();      
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

void BTree::ifCompleteBtree() {
    if (r == NULL) {
        cout << "1" << endl; 
        return;
    }

    queue<BTNode*> q;
    q.push(r);
    bool hasNull = false; 

    while (!q.empty()) {
        BTNode* curr = q.front();
        q.pop();

        if (curr == NULL) {
            hasNull = true;
        }
        else {
            if (hasNull) {
                cout << "0" << endl;
                return;
            }

            q.push(curr->lchild);
            q.push(curr->rchild);
        }
    }

    cout << "1" << endl;
}

int main() {
    ifstream fin("in.txt");
  
    string str;
    fin >> str;
    fin.close();

    BTree tree;
    tree.CreatBTree(str);   // 构建二叉树
    tree.ifCompleteBtree(); // 判断并输出结果

    return 0;
}