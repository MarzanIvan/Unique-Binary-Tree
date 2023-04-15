#pragma once

template <class ValueType, class KeyType = int>
	struct BinaryNode {
		ValueType Value;
		KeyType Key;
		
		BinaryNode<ValueType, KeyType>* LeftNode;
		BinaryNode<ValueType, KeyType>* RightNode;
		
		BinaryNode( ValueType &Value,
					KeyType &Key,
					BinaryNode<ValueType, KeyType>* LeftNode = nullptr, 
					BinaryNode<ValueType, KeyType>* RightNode = nullptr
				  ) {
			this->Value = Value;
			this->Key = Key;
			this->LeftNode = LeftNode;
			this->RightNode = RightNode;
		}
	};