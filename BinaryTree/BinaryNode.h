#pragma once

template <class Ttype, class KeyType = int>
	struct BinaryNode {
		Ttype Value;
		KeyType Key;
		
		BinaryNode<Ttype, KeyType>* LeftNode;
		BinaryNode<Ttype, KeyType>* RightNode;
		
		BinaryNode( Ttype &Value,
					KeyType &Key,
					BinaryNode<Ttype, KeyType>* LeftNode = nullptr, 
					BinaryNode<Ttype, KeyType>* RightNode = nullptr
				  ) {
			this->Value = Value;
			this->Key = Key;
			this->LeftNode = LeftNode;
			this->RightNode = RightNode;
		}
	};