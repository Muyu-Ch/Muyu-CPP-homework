#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

struct Node {
    int val;         
    Node* lchild;
    Node* rchild;
    Node(int x) : val(x), lchild(nullptr), rchild(nullptr) {}
};

vector<string> split(const string& s) {
    vector<string> res;
    stringstream ss(s);
    string token;
    while (ss >> token) {
        res.push_back(token);
    }
    return res;
}

Node* buildTree(const vector<string>& nodes, int index) {
    if (index >= nodes.size() || nodes[index] == "null") {
        return nullptr; 
    }
    Node* root = new Node(stoi(nodes[index])); 
    root->lchild = buildTree(nodes, 2 * index + 1); 
    root->rchild = buildTree(nodes, 2 * index + 2); 
    return root;
}

int getHeightAndCheck(Node* node) {
    if (node == nullptr) {
        return 0; 
    }

    int leftH = getHeightAndCheck(node->lchild);
    if (leftH == -1) return -1;

    int rightH = getHeightAndCheck(node->rchild);
    if (rightH == -1) return -1;

    if (abs(leftH - rightH) > 1) {
        return -1; 
    }

    return max(leftH, rightH) + 1;
}

bool isBalanced(Node* root) {
    return getHeightAndCheck(root) != -1;
}

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->lchild);
    deleteTree(root->rchild);
    delete root;
}

int main() {
    ifstream inFile("in.txt");
    if (!inFile.is_open()) {
        cerr << "无法打开输入文件 in.txt" << endl;
        return 1;
    }
    ofstream outFile("out.txt");
    if (!outFile.is_open()) {
        cerr << "无法打开输出文件 out.txt" << endl;
        inFile.close();
        return 1;
    }

    string inputLine;
    getline(inFile, inputLine);
    vector<string> nodes = split(inputLine);

    Node* root = buildTree(nodes, 0);

    bool result = isBalanced(root);
    outFile << (result ? "True" : "False") << endl;

    deleteTree(root);
    inFile.close();
    outFile.close();

    return 0;
}