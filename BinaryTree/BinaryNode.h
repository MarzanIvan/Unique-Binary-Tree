#pragma once

template <class ValueType, class KeyType=ValueType>
	struct binarynode {
		ValueType value;
		KeyType key;
		
		binarynode<ValueType, KeyType>* left_node;
		binarynode<ValueType, KeyType>* right_node;
		
		void operator=(const binarynode<ValueType, KeyType> &) = delete;
		
		binarynode( ValueType value,
					KeyType key,
					binarynode<ValueType, KeyType>* left_node = nullptr, 
					binarynode<ValueType, KeyType>* right_node = nullptr
				  ) {
			this->value = value;
			this->key = key;
			this->left_node = left_node;
			this->right_node = right_node;
		}
	};