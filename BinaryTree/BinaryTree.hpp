#pragma once

template <class Ttype, class KeyType = int>
	struct BinaryNode {
		Ttype Data;
		KeyType Key;
		
		BinaryNode<Ttype, KeyType>* Parent;
		BinaryNode<Ttype, KeyType>* LeftNode;
		BinaryNode<Ttype, KeyType>* RightNode;
		
		BinaryNode( Ttype &Data,
					KeyType &Key,
					BinaryNode<Ttype, KeyType>* Parent = nullptr, 
					BinaryNode<Ttype, KeyType>* LeftNode = nullptr, 
					BinaryNode<Ttype, KeyType>* RightNode = nullptr
				  ) {
			this->Data = Data;
			this->Key = Key;
			this->Parent = Parent;
			this->LeftNode = LeftNode;
			this->RightNode = RightNode;
		}
	};

template<class Ttype, class KeyType>
	struct BinaryTree {
		BinaryNode<Ttype, KeyType>* Root;
		unsigned int Size;
		
		BinaryTree() {
			Root = nullptr;
			Size = 0;
		}
		BinaryTree(Ttype* Array, int SizeOfArray);
		~BinaryTree() {
			
		}
		
		BinaryNode<Ttype, KeyType>* GetMax();
		BinaryNode<Ttype, KeyType>* GetMin();
		
		Ttype* Search(Ttype& Key);
		bool Add(Ttype &Key, Ttype& Value);
		void Remove(Ttype &Key, Ttype& Value);
		Ttype* ConvertToArray();
	private:
		BinaryNode<Ttype, KeyType>* Search(BinaryNode<Ttype, KeyType>* node, Ttype* Key);
		Ttype* ConvertToArray(BinaryNode<Ttype, KeyType>* node, Ttype* ArrayItem);
		BinaryNode<Ttype, KeyType>* GetMax(BinaryNode<Ttype, KeyType>* Node);
		BinaryNode<Ttype, KeyType>* GetMin(BinaryNode<Ttype, KeyType>* Node);
	};

template<class Ttype, class KeyType>
	BinaryTree<Ttype, KeyType>::BinaryTree(Ttype* Array, int SizeOfArray) {
		for (int i = 0; i < SizeOfArray; i++) 
			 Add(Array[i],Array[i]);
	}

template<class Ttype, class KeyType>
Ttype* BinaryTree<Ttype, KeyType>::Search(Ttype& Key) {		
	return Search(Root,&Key);
}

template<class Ttype, class KeyType>
BinaryNode<Ttype, KeyType>* BinaryTree<Ttype, KeyType>::Search(BinaryNode<Ttype, KeyType>* node, Ttype* Key) {
	if (!node) throw ("search error");
	if (node->Key == *Key) return node;
	Key < node->Key ? Search(node->LeftNode, Key) : Search(node->RightNode, Key);
}

template<class Ttype, class KeyType>
	bool BinaryTree<Ttype, KeyType>::Add(Ttype &Key, Ttype& Value) {
		if (!Size) {
			Root = new BinaryNode<Ttype, KeyType>(Value, Key);
			Size++;
			return true;
		}
		auto NodeToSwitch = Root;
		while (NodeToSwitch) {
			if (NodeToSwitch->Data == *Value || NodeToSwitch->Key == *Key) {
				return false;
			}
			NodeToSwitch = Key < NodeToSwitch.Key ? NodeToSwitch->LeftNode : NodeToSwitch->RightNode;
		}
		NodeToSwitch = new BinaryNode<Ttype, KeyType>(Key, Value);
		Size++;
		return true;
	}


template<class Ttype, class KeyType>
	void BinaryTree<Ttype, KeyType>::Remove(Ttype &Key, Ttype& Value) {
		//TODO
	}


//симметричный обход
template<class Ttype, class KeyType>
	Ttype* BinaryTree<Ttype, KeyType>::ConvertToArray() {
		//TODO
	}


template<class Ttype, class KeyType>
Ttype* BinaryTree<Ttype, KeyType>::ConvertToArray(BinaryNode<Ttype, KeyType>* node, Ttype* ArrayItem) {
		
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
