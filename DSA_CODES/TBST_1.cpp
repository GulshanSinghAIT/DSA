
#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	Node *left, *right; 
	int info; 
	bool lthread; 
	bool rthread; 
}; 


Node *insert(Node *root, int ikey) 
{ 
	Node *ptr = root; 
	Node *par = NULL; 
	while (ptr != NULL) 
	{ 
		if (ikey == (ptr->info)) 
		{ 
			cout<<"Duplicate Key"<<endl;
			return root; 
		} 
		par = ptr; 
		if (ikey < ptr->info) 
		{ 
			if (ptr -> lthread == false) 
				ptr = ptr -> left; 
			else
				break; 
		} 
		else
		{ 
			if (ptr->rthread == false) 
				ptr = ptr -> right; 
			else
				break; 
		} 
	} 
	Node *tmp = new Node; 
	tmp -> info = ikey; 
	tmp -> lthread = true; 
	tmp -> rthread = true; 

	if (par == NULL) 
	{ 
		root = tmp; 
		tmp -> left = NULL; 
		tmp -> right = NULL; 
	} 
	else if (ikey < (par -> info)) 
	{ 
		tmp -> left = par -> left; 
		tmp -> right = par; 
		par -> lthread = false; 
		par -> left = tmp; 
	} 
	else
	{ 
		tmp -> left = par; 
		tmp -> right = par -> right; 
		par -> rthread = false; 
		par -> right = tmp; 
	} 

	return root; 
} 

Node *inorderSuccessor(Node *ptr) 
{ 
	
	if (ptr -> rthread == true) 
		return ptr->right; 


	ptr = ptr -> right; 
	while (ptr -> lthread == false) 
		ptr = ptr -> left; 
	return ptr; 
} 


void inorder(Node *root) 
{ 
	if (root == NULL) 
		cout<<"tree is empty"<<endl;


	Node *ptr = root; 
	while (ptr -> lthread == false) 
		ptr = ptr -> left; 

	
	while (ptr != NULL) 
	{ 
		cout<<ptr->info<<" "; 
		ptr = inorderSuccessor(ptr); 
	} 
} 


int main() 
{ 
	 Node *root = NULL; 

	root = insert(root, 20); 
	root = insert(root, 10); 
	root = insert(root, 30); 
	root = insert(root, 5); 
	root = insert(root, 16); 
	root = insert(root, 14); 
	root = insert(root, 17); 
	root = insert(root, 13); 

	inorder(root); 

	return 0; 
} 
