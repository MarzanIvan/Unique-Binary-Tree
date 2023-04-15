#pragma once

#include "BinaryNode.h"

template<class Ttype, class KeyType>
	struct BinaryTree {
		BinaryNode<Ttype, KeyType>* Root;
		unsigned int Size;
		
		BinaryTree(Ttype* Array, int SizeOfArray);
		BinaryTree();
		~BinaryTree() {
			
		}
		
		bool Add(KeyType Key, Ttype Value);
		bool Remove(KeyType Key, Ttype Value);
		Ttype* Search(KeyType Key);
		Ttype* ConvertToArray();
		BinaryNode<Ttype, KeyType>* GetMax();
		BinaryNode<Ttype, KeyType>* GetMin();
	private:
		BinaryNode<Ttype, KeyType>* Search(BinaryNode<Ttype, KeyType>* node, KeyType* Key);
		BinaryNode<Ttype, KeyType>* Remove(BinaryNode<Ttype, KeyType>* node, KeyType* Key, Ttype* Value);
		Ttype* ConvertToArray(BinaryNode<Ttype, KeyType>* node, Ttype* ArrayItem);
	};

template<class Ttype, class KeyType>
BinaryTree<Ttype, KeyType>::BinaryTree() {
	Root = nullptr;
	Size = 0;
}

template<class Ttype, class KeyType>
BinaryTree<Ttype, KeyType>::BinaryTree(Ttype* Array, int SizeOfArray) {
	for (int i = 0; i < SizeOfArray; i++) 
		Add(Array[i],Array[i]);
}

template<class Ttype, class KeyType>
	Ttype* BinaryTree<Ttype, KeyType>::Search(KeyType Key) {		
	return &Search(Root,&Key)->Value;
}

template<class Ttype, class KeyType>
	BinaryNode<Ttype, KeyType>* BinaryTree<Ttype, KeyType>::Search(BinaryNode<Ttype, KeyType>* node, KeyType* Key) {
	if (!node) throw ("search error");
	if (node->Key == *Key) return node;
	*Key < node->Key ? Search(node->LeftNode, Key) : Search(node->RightNode, Key);
}

template<class Ttype, class KeyType>
bool BinaryTree<Ttype, KeyType>::Add(KeyType Key, Ttype Value) {
	if (!Size) {
		this->Root = new BinaryNode<Ttype, KeyType>(Value, Key);
		Size++;
		return true;
	}
	BinaryNode<Ttype, KeyType>** NodeToSwitch = &Root;
	while (*NodeToSwitch) {
		if ((*NodeToSwitch)->Value == Value || (*NodeToSwitch)->Key == Key) {
			return false;
		}
		NodeToSwitch = Key < (*NodeToSwitch)->Key ? &(*NodeToSwitch)->LeftNode : &(*NodeToSwitch)->RightNode;
		}
	*NodeToSwitch = new BinaryNode<Ttype, KeyType>(Value, Key);
	Size++;
}

template<class Ttype, class KeyType>
bool BinaryTree<Ttype, KeyType>::Remove(KeyType Key, Ttype Value) {
	//TODO
}

template<class Ttype, class KeyType>
BinaryNode<Ttype, KeyType>* BinaryTree<Ttype, KeyType>::Remove(BinaryNode<Ttype, KeyType>* node, KeyType *Key, Ttype* Value) {
	//TODO
}

template<class Ttype, class KeyType>
	Ttype* BinaryTree<Ttype, KeyType>::ConvertToArray() {
		//TODO
	}


template<class Ttype, class KeyType>
Ttype* BinaryTree<Ttype, KeyType>::ConvertToArray(BinaryNode<Ttype, KeyType>* node, Ttype* ArrayItem) {
	//TODO
}

template<class Ttype, class KeyType>
	BinaryNode<Ttype, KeyType>* BinaryTree<Ttype, KeyType>::GetMax() {
		if (!Size) {
			throw ("Error has been happened to get max value.\nThe binary tree doesn't have any node");
		}
		auto NodeToSwitch = Root;
		while (NodeToSwitch->RightNode) {
			NodeToSwitch = NodeToSwitch->RightNode;
		}
		return NodeToSwitch;
	}

template<class Ttype, class KeyType>
	BinaryNode<Ttype, KeyType>* BinaryTree<Ttype, KeyType>::GetMin() {
		if (!Size) {
			throw ("Error has been happened to get min value from the binary tree.\nThe binary tree doesn't have any node");
		}
		auto NodeToSwitch = Root;
		while (NodeToSwitch->LeftNode) {
			NodeToSwitch = NodeToSwitch->LeftNode;
		}
		return NodeToSwitch;
	}
