#include "tree.hh"
#include <iostream>
#include <string>


//A function for creating new subtrees
tree_ptr_t create_tree(const key_t& key,
                       const value_t& value,
                       tree_ptr_t left,
                       tree_ptr_t right)
{

	tree_ptr_t node_ptr = new Tree(); // create pointer to a new tree

	//place values as attributes to be part of tree
	node_ptr -> key_ = key;
	node_ptr -> value_ = value;
	node_ptr -> left_ = left;
	node_ptr -> right_ = right;

	return node_ptr;

}

//destroys tree and its subtrees
void destroy_tree(tree_ptr_t tree) {

	//iterate through the tree until we reach the end
	while ((tree -> left_ != nullptr) or (tree -> right_ != nullptr)) {
		if (tree -> left_ == nullptr) {
			destroy_tree(tree -> right_);			
		}
		else if (tree -> right_ == nullptr) {
			destroy_tree(tree -> left_);
		}
		else {
			destroy_tree(tree -> right_);
			destroy_tree(tree -> left_);
		}

		//delete each node as we go along
		delete tree;
	}
}

//a helper function to determine whether a given subtree has the desired key
bool _hasKey(tree_ptr_t tree, key_t key) {
	
	//base case: reaches end of tree
	if ((tree -> left_ == nullptr) and (tree -> right_ == nullptr)) {
		return false;
	}

	if (tree -> key_ == key) {
		return true;
	}

	//recursively iterates through tree until it finds key 
	if (key != tree -> key_) {
		_hasKey(tree -> left_, key);
		_hasKey(tree -> right_,key);
	}

	//default
	return false;

}

//utilizes helper function to iterate through tree in the right direction
//and adds the direction to path
std::string path_to(tree_ptr_t tree, key_t key) {

	std::string path = "";
	//iterate through until we've found the node with the key
	while (tree->key_ != key) {


		if (_hasKey(tree -> left_,key)) {
			path += "L";
			tree = tree->left_;
		}

		if (_hasKey(tree -> right_,key)) {
			path += "R";
			tree = tree->right_;
		}

	}
	return path;

}


//takes a path and returns a pointer to the node at the end of that path
tree_ptr_t node_at(tree_ptr_t tree, std::string path) {

	//recursively call self, going down the path
	if (path.at(0) == 'L') {
		tree = tree->left_;
		node_at(tree,path.substr (1));
	}

	else if (path.at(0) == 'R') {
		tree = tree->right_;
		node_at(tree,path.substr (1));
	}

	if (path == "") {
		return tree;
	}

	return nullptr;

}
