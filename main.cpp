#include <iostream>
#include <string>

template <typename type>
class bintree;

template <typename type>
struct node {
	type value;
	node *left;
	node *right;
};

template <typename type>
class bintree {
public:
	bintree();
	void push(type item);
	std::string print();

private:
    node<type> *root;
	int lol = 2;
	void push(type item, node<type> *leaf);
	std::string print(node<type> *leaf, std::string s);
};

template <typename type>
bintree<type>::bintree() {
	root = NULL;
}

template <typename type>
void bintree<type>::push(type item, node<type> *leaf) {
	if (item < leaf->value) {
		if (leaf->left != NULL) {
			push(item, leaf->left);
		} else {
			leaf->left = new node<type>;
			leaf->left->value = item;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	} else if (item >= leaf->value) {
		if (leaf->right != NULL) {
			push(item, leaf->right);
		} else {
			leaf->right = new node<type>;
			leaf->right->value = item;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

template <typename type>
void bintree<type>::push(type item) {
	if (root != NULL) {
		push(item, root);
	} else {
		root = new node<type>;
		root->value = item;
		root->left = NULL;
		root->right = NULL;
	}
}

template <typename type>
std::string bintree<type>::print() {
	std::string s = "";
	s += print(root, s);
	return s;
} 

template <typename type>
std::string bintree<type>::print(node<type> *leaf, std::string s) {
	if (leaf != NULL) {
        s = print(leaf->left, s);
        s += std::to_string(leaf->value) + ", ";
        s = print(leaf->right, s);
	}
	return s;
}

//перегрузка <<
template <typename type> 
std::ostream& operator<< (std::ostream& out, bintree<type> &tree) {
	std::string s;
    s = tree.print();
	out << s;
    return out;
} 

int main() {
    //int
	bintree<int> *tree = new bintree<int>();

	tree->push(10);
	tree->push(6);
	tree->push(14);
	tree->push(5);
	tree->push(8);
	tree->push(11);
	tree->push(18);

    std::cout << *tree << std::endl; 

    //double
    bintree<double> *ctree = new bintree<double>();

    ctree->push(2.12);
    ctree->push(1.03);
    ctree->push(2.99);
    ctree->push(10);
    ctree->push(5.87);
    ctree->push(7.6);
    ctree->push(12.67);

	std::cout << *ctree << std::endl;
}