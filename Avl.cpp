#include <iostream>
	using namespace std;
	
	struct bts {
	    int dats;
	    bts* left;
	    bts* right;
	    int height = 1;
	};
	
	
	//height funcy
	
	int getHeight(bts* node){
		if (node == nullptr)
		{
			return 0;
		}
		
		return node->height;
		
	}

	int getBalance(bts* node){
		if (node == nullptr)
		{
			return 0;
		}

		return getHeight(node->left) - getHeight(node->right); 

	}

    bts* rightShift(bts* node){
        bts* child = node->left;
        bts* childRight = child->right;
        child->right = node;
        node->left = childRight;

        node->height = 1 + max(getHeight(node->left) , getHeight(node->right));
        child->height = 1 + max(getHeight(child->left) , getHeight(child->right));

        return child;

    }

    bts* leftShift(bts* node){
        bts* child = node->right;
        bts* childLeft = child->left;

        child->left = node;
        node->right = childLeft;

        node->height = 1 + max(getHeight(node->left) , getHeight(node->right));
        child->height = 1 + max(getHeight(child->left) , getHeight(child->right));

        return child;
    }



	// Insert function for BST
	bts* insert(bts* node, int value) {
	    if (node == nullptr) {
	        bts* temp = new bts();
	        temp->dats = value;
	        temp->left = temp->right = nullptr;
	        return temp;
	    }
	    if (value > node->dats) {
	        node->right = insert(node->right, value);
	    } else if (value < node->dats) {
	        node->left = insert(node->left, value);

	    }else return node;

		// update height

		node->height = 1 + max(getHeight(node->left),getHeight(node->right));

        // Balance Factor

        int balance = getBalance(node);

        // Left Left
        if(balance > 1 && value < node->left->dats){
            return rightShift(node);
        }

        // Right Right
        else if(balance < -1 && value > node->right->dats){
            return leftShift(node);
        }

        // Left Right
        else if(balance > 1 && value > node->left->dats){
            node->left = leftShift(node->left);
            return rightShift(node);
        }

        // Right Left
        else if(balance < -1 && value < node->right->dats){
            node->right =  rightShift(node->right);
            return leftShift(node);
        }

        else return node;
	}
	
	// Search function
	bool search(bts* node, int value) {
	    if (node == nullptr) {
	        return false;
	    }
	    if (node->dats == value) {
	        return true;
	    }
	    if (value > node->dats) {
	        return search(node->right, value);
	    }
	    return search(node->left, value);
	}
	
	// Preorder traversal
	void preOrder(bts* node) {
	    if (node == nullptr) return;
	    cout << node->dats << " ";
	    preOrder(node->left);
	    preOrder(node->right);
	}
	// Postorder traversal
	void postOrder(bts* node) {
	    if (node == nullptr) return;
	    postOrder(node->left);
	    postOrder(node->right);
	    cout << node->dats << " ";
	}
	//teesra wala
	void midOrder(bts* node){
		if(node  == nullptr){
			return;
		}
		midOrder(node->left);
		cout<<node->dats<<" ";
		midOrder(node->right);
	}
	
	
	int main() {
	    bts* root = nullptr;
	    int choice, value;
	    bool flag = false;


        cout<<"Welcome AVL Tree"<<endl;
	
	    while (true) {
	        cout << "\nChoose an operation: \n1. Insert\n2. Search\n3. Pre-Order\n4. Inorder\n5. Post-Oreder \n\n";
	        cin >> choice;
	
	        switch (choice) {
	            case 1:
	                cout << "Enter a value: ";
	                cin >> value;
	                root = insert(root, value);
	                
	                break;
	            case 2:
	                cout << "Search a value: ";
	                cin >> value;
	                if (search(root, value)) {
	                    cout << value << " found in the BST.\n";
	                } else {
	                    cout << value << " not found in the BST.\n";
	                }
	                break;
	            case 3:
	                cout << "Preorder Traversal: ";
	                preOrder(root);
	                cout << endl;
	                break;
	            case 4:
	                cout << "Inorder Traversal: ";
	                midOrder(root);
	                cout << endl;
	                break;
	            case 5:
	                cout << "Postorder Traversal: ";
	                postOrder(root);
	                cout << endl;
	                break;
	           
	            default:
	                cout << "Invalid choice. Try again.\n";
	        }
	    }
	}