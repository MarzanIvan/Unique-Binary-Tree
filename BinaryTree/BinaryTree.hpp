#pragma once

template <class Ttype>
	struct BinaryNode {
		Ttype Data;
		Ttype Key;
		
		BinaryNode<Ttype>* Parent;
		BinaryNode<Ttype>* LeftNode;
		BinaryNode<Ttype>* RightNode;
		
		BinaryNode(	Ttype &Data,
					Ttype &Key,
					BinaryNode<Ttype>* Parent = nullptr, 
					BinaryNode<Ttype>* LeftNode = nullptr, 
					BinaryNode<Ttype>* RightNode = nullptr
				  ) {
			this->Data = Data;
			this->Key = Key;
			this->Parent = Parent;
			this->LeftNode = LeftNode;
			this->RightNode = RightNode;
		}
	};

template<class Ttype>
	struct BinaryTree {
		BinaryNode<Ttype>* Root;
		unsigned int Size;
		
		BinaryTree();
		BinaryTree(Ttype* Array);
		~BinaryTree();
		
		Ttype& GetMax();
		Ttype& GetMin();
		
		Ttype* Search(Ttype& Key);
		bool Add(Ttype &Key, Ttype& Value);
		void Remove(Ttype &Key, Ttype& Value);
		
		Ttype* ConvertToArray();
	};