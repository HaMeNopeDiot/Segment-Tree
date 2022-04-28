#pragma once
#include <cmath>
#include <iostream>
#include <string>

class SegmentTree {
	struct Node {
		int data;
		Node* left;
		Node* right;
	};
	typedef Node* STree;
	typedef void(*FunctionType) (int& node);
	int totwo = 0;
public:
	STree main_root;

	SegmentTree(int lenght)
	{
		while (pow(2, totwo) < lenght)
			totwo++;
		initSegmentTree(main_root, totwo);
	}

	void initSegmentTree(STree& root, int totwo)
	{
		root = new Node;
		root->data = 1;
		root->left = nullptr;
		root->right = nullptr;
		if (totwo)
		{
			initSegmentTree(root->right,totwo-1);
			initSegmentTree(root->left, totwo-1);
		}
	}

	void regStable(std::string word)
	{
		int* arr = new int[pow(2,totwo)];
		if (word[0] == '(')
			arr[0] = 1;
		else
			arr[0] = -1;
		for (int i = 1; i < word.size(); i++)
		{
			if (word[i] == '(')
				arr[i] = arr[i - 1] + 1;
			else
				arr[i] = arr[i - 1] - 1;

		}
		for (int i = word.size(); i < pow(2, totwo); i++)
			arr[i] = 1;
		int j = 0;
		searchStablePlace(main_root, arr, j);
		if (main_root->data == 0)
			std::cout << "Answer: +" << '\n';
		else
			std::cout << "Answer: -" << '\n';
		std::cout << "Prefix print Tree:";
		preorder(main_root);
		std::cout << '\n';

	}
	
	void searchStablePlace(STree root, int* arr, int& i)
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			root->data = arr[i++];
		}
		else
		{
			searchStablePlace(root->left, arr, i);
			searchStablePlace(root->right, arr, i);
			int a = root->right->data;
			int b = root->left->data;
			root->data = a > b ? b : a;
		}
	}

	void preorder(STree root)
	{
		if (root != nullptr) {
			//std::cout << root->data << std::endl;
			printNode(root->data);
			preorder(root->left);
			preorder(root->right);
			
		}
	}

	void printNode(int& elem)
	{
		std::cout << elem << " ";
	}


	//void initTree(STree& root, int elem=0)
	//{
	//	root = new Node;
	//	root->data = elem;
	//	root->left = nullptr;
	//	root->right = nullptr;
	//}

	//void initTree(STree& root, STree leftTree, STree rightTree, int elem=0)
	//{
	//	initTree(root, elem);
	//	attachLeftSubtree(root, leftTree);
	//	attachRightSubtree(root, rightTree);
	//}

	//void attachLeftSubtree(STree root, STree subTree)
	//{
	//	if (isEmpty(root))
	//		std::cout << "The tree is empty" << std::endl;
	//	else
	//		if (root->left != nullptr)
	//			std::cout << "Left subtree is not empty" << std::endl;
	//		else
	//			root->left = subTree;
	//}

	//void attachRightSubtree(STree root, STree subTree)
	//{
	//	if (isEmpty(root))
	//		std::cout << "The tree is empty" << std::endl;
	//	else
	//		if (root->right != nullptr)
	//			std::cout << "Left subtree is not empty" << std::endl;
	//		else
	//			root->right = subTree;
	//}

	//bool isEmpty(STree root)
	//{
	//	return root == nullptr;
	//}

	//void copyTree(STree root, STree& newRoot)
	//{
	//	if (root != nullptr) {
	//		newRoot = new Node;
	//		newRoot->data = root->data;
	//		newRoot->left = nullptr;
	//		newRoot->right = nullptr;

	//		copyTree(root->left, newRoot->left);
	//		copyTree(root->right, newRoot->right);
	//	}
	//	else
	//		newRoot = nullptr;
	//}

	//void attachLeftSubtree(STree root, STree subTree) 
	//{
	//	if (isEmpty(root))
	//		std::cout << "The tree is empty" << std::endl;
	//	else
	//		if (root->left != nullptr)
	//			std::cout << "Left subtree is not empty" << std::endl;
	//		else
	//			root->left = subTree;
	//}

	//void attachRightSubtree(STree root, STree subTree)
	//{
	//	if (isEmpty(root))
	//		std::cout << "The tree is empty" << std::endl;
	//	else
	//		if (root->right != nullptr)
	//			std::cout << "Left subtree is not empty" << std::endl;
	//		else
	//			root->right = subTree;
	//}

};