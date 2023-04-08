#pragma once

template <class Ttype>
	struct BinaryNode {
		Ttype Data;
		BinaryNode<Ttype>* Parent;
		BinaryNode<Ttype>* LeftNode;
		BinaryNode<Ttype>* RightNode;
		
		BinaryNode(	Ttype& Data, 
					BinaryNode<Ttype>* Parent = nullptr, 
					BinaryNode<Ttype>* LeftNode = nullptr, 
					BinaryNode<Ttype>* RightNode = nullptr
				  ) {
			this->Data = Data;
			this->Parent = Parent;
			this->LeftNode = LeftNode;
			this->RightNode = RightNode;
		}
	};

template<class Ttype>
	class BinaryTree {
		
	};