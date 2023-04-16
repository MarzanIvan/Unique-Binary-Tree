#pragma once

#include "BinaryNode.h"

template <class ValueType, class KeyType>
struct BinaryTree {
	BinaryNode<ValueType, KeyType> *Root;
	unsigned int Size;

	BinaryTree(ValueType *Array, int SizeOfArray);
	BinaryTree();
	~BinaryTree() {
		
	}

	bool Add(KeyType Key, ValueType Value);
	bool Remove(KeyType Key, ValueType Value);
	ValueType *Search(KeyType Key);
	ValueType *ConvertToArray();
	BinaryNode<ValueType, KeyType> *GetMax();
	BinaryNode<ValueType, KeyType> *GetMin();

public:
	BinaryNode<ValueType, KeyType> *Search(BinaryNode<ValueType, KeyType> *node, KeyType *Key);
	bool Remove(BinaryNode<ValueType, KeyType> **node, KeyType *Key, ValueType *Value);
	void ConvertToArray(BinaryNode<ValueType, KeyType> *node, ValueType *Array);
	BinaryNode<ValueType, KeyType>* CutMax(BinaryNode<ValueType, KeyType>** node);
};

template <class ValueType, class KeyType>
BinaryTree<ValueType, KeyType>::BinaryTree() {
	Root = nullptr;
	Size = 0;
}

template <class ValueType, class KeyType>
BinaryTree<ValueType, KeyType>::BinaryTree(ValueType *Array, int SizeOfArray) {
	for (int i = 0; i < SizeOfArray; i++)
		Add(Array[i], Array[i]);
}

template <class ValueType, class KeyType>
ValueType *BinaryTree<ValueType, KeyType>::Search(KeyType Key) {
	return &Search(Root, &Key)->Value;
}

template <class ValueType, class KeyType>
BinaryNode<ValueType, KeyType> *BinaryTree<ValueType, KeyType>::Search(BinaryNode<ValueType, KeyType> *node, KeyType *Key) {
	if (!node) throw("search error");
	if (node->Key == *Key) return node;
	*Key < node->Key ? Search(node->LeftNode, Key) : Search(node->RightNode, Key);
}

template <class ValueType, class KeyType>
bool BinaryTree<ValueType, KeyType>::Add(KeyType Key, ValueType Value) {
	if (!Size) {
		this->Root = new BinaryNode<ValueType, KeyType>(Value, Key);
		Size++;
		return true;
	}
	BinaryNode<ValueType, KeyType> **NodeToSwitch = &Root;
	while (*NodeToSwitch) {
		if ((*NodeToSwitch)->Value == Value || (*NodeToSwitch)->Key == Key) {
			return false;
		}
		NodeToSwitch = Key < (*NodeToSwitch)->Key ? &(*NodeToSwitch)->LeftNode : &(*NodeToSwitch)->RightNode;
	}
	*NodeToSwitch = new BinaryNode<ValueType, KeyType>(Value, Key);
	Size++;
}

template <class ValueType, class KeyType>
bool BinaryTree<ValueType, KeyType>::Remove(KeyType Key, ValueType Value) {
	return Remove(&Root, &Key, &Value);
}

template <class ValueType, class KeyType>
bool BinaryTree<ValueType, KeyType>::Remove(BinaryNode<ValueType, KeyType> **node, KeyType *Key, ValueType *Value) {
	if (!(*node)) return false;
	if ((*node)->Value == *Value) {
		Size--;
		if (!(*node)->RightNode) {
			*node = (*node)->LeftNode;
			return true;
		}
		if (!(*node)->LeftNode) {
			*node = (*node)->RightNode;
		} else {
			auto NodeToRemove = *node;
			*node = CutMax(&((*node)->LeftNode));
			(*node)->LeftNode = NodeToRemove->LeftNode;
			(*node)->RightNode = NodeToRemove->RightNode;
			delete NodeToRemove;
		}
		return true;
	}
	if (*Key < (*node)->Key) {
		Remove(&((*node)->LeftNode),Key,Value);
	} else {
		Remove(&((*node)->RightNode), Key, Value);
	}
}

template<class ValueType, class KeyType>
BinaryNode<ValueType,KeyType>* BinaryTree<ValueType, KeyType>::CutMax(BinaryNode<ValueType, KeyType>** node) {
	while ((*node)->RightNode) {
		node = &((*node)->RightNode);
	}
	BinaryNode<ValueType, KeyType>* NodeToCut = *node;
	*node = (*node)->LeftNode;
	Size--;
	return NodeToCut;
}

template <class ValueType, class KeyType>
ValueType *BinaryTree<ValueType, KeyType>::ConvertToArray() {
	ValueType *Array = new ValueType[Size];
	ConvertToArray(Root, Array);
	return Array;
}

template <class ValueType, class KeyType>
void BinaryTree<ValueType, KeyType>::ConvertToArray(BinaryNode<ValueType, KeyType> *node, ValueType *Array) {
	if (node) {
		ConvertToArray(node->LeftNode, Array);
		*(Array++) = node->Value;
		ConvertToArray(node->RightNode, Array);
	}
}

template <class ValueType, class KeyType>
BinaryNode<ValueType, KeyType> *BinaryTree<ValueType, KeyType>::GetMax() {
	if (!Size) {
		throw("Error has been happened to get max value.\nThe binary tree doesn't have any node");
	}
	auto NodeToSwitch = Root;
	while (NodeToSwitch->RightNode) {
		NodeToSwitch = NodeToSwitch->RightNode;
	}
	return NodeToSwitch;
}

template <class ValueType, class KeyType>
BinaryNode<ValueType, KeyType> *BinaryTree<ValueType, KeyType>::GetMin() {
	if (!Size) {
		throw("Error has been happened to get min value from the binary tree.\nThe binary tree doesn't have any node");
	}
	auto NodeToSwitch = Root;
	while (NodeToSwitch->LeftNode) {
		NodeToSwitch = NodeToSwitch->LeftNode;
	}
	return NodeToSwitch;
}
