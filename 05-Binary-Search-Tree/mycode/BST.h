/****************************************
   >File Name:BST.h
   >Author:Ju Wei
   >Mail:949413827@qq.com
   >Created Time: Wed 05 Dec 2018 03:26:34 PM CST
****************************************/

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

template<typename Key, typename Value>
class BST{
	private:
		struct Node{
			Key key;
			Value value;
			Node *left;
			Node *right;

			Node(Key key,Value value){
				this->key = key;
				this->value = value;
				this->left = this->right = NULL;
			}
			Node(Node *node){
				this->key = node->key;
				this->value = node->value;
				this->left = node->left;
				this->right = node->right;
			}
		};
		Node *root;
		int count;
	public:
		BST(){
			root == NULL;
			count = 0;
		}
		~BST(){
			destroy(root);
		}
		int size(){
			return count;
		}
		bool isempty(){
			return count==0;
		}
		void insert(Key key,Value value){
			root = insert(root,key,value);
		}
		bool contain(Key key){
			return contain(root,key);
		}
		Value* search(Key key){
			return search(root,key);
		}
		// preorder && inorder && postorder
		void preOrder(){
			preOrder(root);
		}
		void inOrder(){
			inOrder(root);
		}
		void postOrder(){
			postOrder(root);
		}
		// guangdu youxian
		void levelOrder(){
			queue<Node*> q;
			q.push(root);
			while(!q.empty()){
				Node* node = q.front();
				q.pop();
				cout<<node->key<<endl;
				if(node->left)
					q.push(node->left);
				if(node->right)
					q.push(node->right);
			}
		}
		Key minimum(){
			assert(count!=0);
			Node* minNode = minimum(root);
			return minNode->key;
		}
		Key maximum(){
			assert(count!=0);
			Node* maxNode = maximum(root);
			return maxNode->key;
		}
		void rmMin(){
			if(root)
				root = rmMin(root);
		}
		void rmMax(){
			if(root)
				root = rmMax(root);
		}
		void remove(Key key){
			root = remove(root,key);
		}
<<<<<<< HEAD
		void printfunc(){
			cout<<" .... "<<endl;
		}
=======
>>>>>>> upload local data dtructure to merge
	private:
		Node* remove(Node* node,Key key){
			if(node == NULL)
				return NULL;
			if(key<node->key){
				node->left = remove(node->left,key);
				return node;
			}
			else if(key>node->key){
				node->right = remove(node->right,key);
				return node;
			}
			else{     //key == node->key
				if(node->left == NULL){
					Node *rightnode = node->right;
					delete node;
					count--;
					return rightnode;
				}
				if(node->right == NULL){
					Node *leftnode = node->left;
					delete node;
					count--;
					return leftnode;
				}
				//node->left != NULL && node->right != NULL
				Node *successor = new Node(minimum(node->right));
				count++;
<<<<<<< HEAD

=======
 
>>>>>>> upload local data dtructure to merge
				successor->right = rmMin(node->right);
				successor->left = node->left;
				delete node;
				count--;
				return successor;
			}

		}
		Node* rmMax(Node* node){
			if(node->right == NULL){
				Node* leftnode = node->left;
				delete node;
				count--;
				return leftnode;
			}
			node->right = rmMax(node->right);
			return node;
		}
		Node* rmMin(Node* node){
			if(node->left == NULL){
				Node* rightnode = node->right;
				delete node;
				count--;
				return rightnode;
			}
			node->left = rmMin(node->left);
			return node;
		}
		Node* maximum(Node* node){
			if(node->right == NULL)
				return node;
			return maximum(node->right);
		}
		Node* minumum(Node* node){
			if(node->left == NULL)
				return node;
			return minimum(node->left);
		}
		void destroy(Node* node){
			if(node!=NULL){
				destroy(node->left);
				destroy(node->right);
				delete node;
				count--;
			}
		}
		void postOrder(Node* node){
			if(node != NULL){
				postOrder(node->left);
				postOrder(node->right);
				cout<<node->key<<endl;
			}
		}
		void inOrder(Node* node){
			if(node != NULL){
				inOrder(node->left);
				cout<<node->key<<endl;
				inOrder(node->right);
			}
		}
		void preOrder(Node* node){
			if(node != NULL){
				cout<<node->key<<endl;
				preOrder(node->left);
				preOrder(node->right);
			}
		}
		Value* search(Node* node,Key key){
			if(node == NULL)
				return NULL;
			if(key==node->key)
				return &(node->value);
			else if(key>node->key)
<<<<<<< HEAD

				return search(node->right,key);

			else

=======
				return search(node->right,key);
			else
>>>>>>> upload local data dtructure to merge
				return search(node->left,key);
		}
		bool contain(Node* node,Key key){
			if(node==NULL)
				return false;
			if(key == node->key)
				return true;
			else if(key>node->key)
				return contain(node->right,key);
			else
				return contain(node->left,key);
		}
		Node* insert(Node *node,Key key,Value value){
			if(node == NULL){
				count++;
				return new Node(key,value);
			}
			if(key == node->key)
				node->value = value;
			else if(key < node->key)
				node->left = insert(node->left,key,value);
			else
				node->right = insert(node->right,key,value);
			return node;
		}
};
