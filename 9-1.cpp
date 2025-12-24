//1. 二叉排序树的应用
//【问题描述】
//给定n个关键字（整数），设计算法依次将关键字插入到初始为空树的二叉排序树中，并在创建好的二叉排序树中，
// 删除m(m < n)个给定的关键字后，输出二叉排序的先序遍历序列。
// （注意：若被删除结点为双分支结点，则统一采用左子树中的最大值关键字替代被删除结点）
//	【输入形式】
//	第一行，待插入关键字的个数n；
//	第二行，待插入的关键字，用空格隔开；
//	第三行，待删除关键字的个数m；
//	第四行，待删除的关键字，用空格隔开；
//	【输出形式】
//	输出二叉排序树的先序遍历序列，整数间用空格隔开；

#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int data;
	Node* lchild;
	Node* rchild;
	Node(int val) : data(val), lchild(nullptr), rchild(nullptr) {}
};

Node* insert(Node* root, int val) {
	if (!root) return new Node(val);
	if (val < root->data) {
		root->lchild = insert(root->lchild, val);
	} else {
		root->rchild = insert(root->rchild, val);
	}
	return root;
}

Node* buildBST(const vector<int>& keys) {
	Node* root = nullptr;
	for (int key : keys) {
		root = insert(root, key);
	}
	return root;
}

Node* deleteNode(Node* root, int key) {
	if (!root) return nullptr;
	if (key < root->data) {
		root->lchild = deleteNode(root->lchild, key);
	} 
	else if (key > root->data) {
		root->rchild = deleteNode(root->rchild, key);
	}
	else {
		if (!root->lchild) {
			Node* temp = root->rchild;
			delete root;
			return temp;
		} else if (!root->rchild) {
			Node* temp = root->lchild;
			delete root;
			return temp;
		} else {
			Node* maxNode = root->lchild;
			while (maxNode->rchild) {
				maxNode = maxNode->rchild;
			}
			root->data = maxNode->data;
			root->lchild = deleteNode(root->lchild, maxNode->data);
		}
	}
	return root;
}

Node* deleteKeysFromBST(Node* root, const vector<int>& deleteKeys) {
	for (int key : deleteKeys) {
		root = deleteNode(root, key);
	}
	return root;
}	

void preorderPrint(Node* root) {
	if (!root) return;
	cout << root->data << " ";
	preorderPrint(root->lchild);
	preorderPrint(root->rchild);
}

int main() {
	int n;
	cin >> n;	
	vector<int>keys(n);
	for (int i = 0; i < n; i++) {
		cin >> keys[i];
	}

	int m;
	cin >> m;
	vector<int>deleteKeys(m);
	for (int i = 0; i < m; i++) {
		cin >> deleteKeys[i];
	}

	Node* r = buildBST(keys);
	r = deleteKeysFromBST(r, deleteKeys);

	preorderPrint(r);
	return 0;
}