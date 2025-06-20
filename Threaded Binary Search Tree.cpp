#include<iostream>
using namespace std;
struct node{
	node *right;
	node *left;
	string LTH;
	string RTH;
	public:
	int data;
	string name;
		node()
		{
			
			right=left=NULL;
		}
};
class Tree{
	node *temp;
	public:
	int key;
	int key2;
	int n;
	node *root;
	node *dummy;
	Tree(int Data)
	{
		root=temp=NULL;
		dummy = new node;
		dummy->LTH="child";
		dummy->RTH="child";
		dummy->data = Data;
		dummy->left=dummy;
		dummy->right=dummy;
	}
void insert(node* temp) {
    if (root == NULL) {
        temp = new node;
        root = temp;
        temp->data = n;
        temp->left = dummy;
        temp->right = dummy;
        temp->LTH = "thread";
        temp->RTH = "thread";
        dummy->left = root;
        return ;
    }
    if (n == temp->data) 
	{
        cout << "Repeated Element\n";
        return ;
    }
    if (n < temp->data) 
	{
        if (temp->LTH == "thread")
		 {
        	node *newnode = new node;
        	newnode->data=n;
        	newnode->left=temp->left;
        	newnode->right=temp;
        	temp->left=newnode;
            newnode->LTH = "thread";
            newnode->RTH = "thread"; 
            temp->LTH = "child";
            return;
        } else {
            insert(temp->left);
        }
    } else if(n>temp->data){
        if (temp->RTH == "thread") 
		{
            node* newNode = new node;
            newNode->data = n;
            newNode->left = temp;
            newNode->right = temp->right;
            temp->right = newNode;
            temp->RTH = "child";
            temp->right->LTH = "thread";
            temp->right->RTH = "thread";
            temp->RTH = "child";
return ;
        } else {
            insert(temp->right);
        }
    }
}
	node* deletee(node *temp)
	{
//		if(root->)
		if(root->data==key2 && root->LTH=="thread" && root->RTH=="thread")
		{
//			cout<<"AAA";
//root->right=NULL
			root=dummy;
			node *temp1 = root->right;
			while(temp1->left!=NULL)
			{
				temp1=temp1->left;
			}
			root->data=temp1->data;
			delete temp1;
			return temp;
//			dummy->left=/dummy;
//			dummy->right=dummy;
//			dummy->LTH="thread";
		}
		if(key2 < temp->data)
		{	
			if(temp->left->data==key2 && temp->left->LTH!="thread" && temp->left->RTH!= "thread")   // two child
  {
  	node *temp1 = temp->left->right;
  	node *p;
  	while(temp1->LTH=="child")
  	{
  	p=temp1;
  	temp1 = temp1->left;	
	}
	cout<<"Temp1-> data == "<<temp1->data<<endl;
	if(temp->left->right==temp1)
	{
	temp->left->data=temp1->data;
	temp->left->right=temp;
	temp->left->RTH="thread";
}
else
{
	temp->left->data=temp1->data;
	p->left=temp->left;
	p->LTH="thread";
	p->RTH="thread";
}
	delete temp1;
	return temp;
  }
	else if(temp->left->data == key2 && temp->left->LTH =="thread" && temp->left->RTH=="thread")      // leaf node
		{
				node *temp1 = temp->left;
				temp->left = temp->left->left;
				temp->LTH="thread";
				temp->RTH="thread";
				delete temp1;
				return temp;
			}
		else if(temp->left->data == key2 && temp->left->LTH=="thread" && temp->left->RTH=="child")     // right child only
			{
				node *temp1 = temp->left;
				temp->left=temp->left->right;
				temp->left->LTH="thread";
				temp->left->RTH="thread";
				temp->left->right=temp;
				delete temp1;
				return temp;
			}
			else if(temp->left->data == key2 && temp->left->LTH == "child" && temp->left->RTH == "thread")      // left child only
			{
	node *temp1 = temp->left;
	temp->left=temp->left->left;
	temp->left->right=temp;
if(temp->left->LTH=="child" && temp->left->RTH=="thread")
					{
					temp->left->LTH="child";
					temp->left->RTH="thread";
				}
				else
				{
					temp->left->LTH="thread";
					temp->left->RTH="thread";
				}
	delete temp1;
	return temp;
		}
		else
		{
			deletee(temp->left);
		}
		}
		
		 if(key2 > temp->data)
		{
			if(temp->right->data==key2 && temp->right->LTH!="thread" && temp->right->RTH!= "thread")  // two child
  {
  	node *temp1 = temp->right->right;
  	node *p;
  	while(temp1->LTH=="child")
  	{
  	p=temp1;
  	temp1 = temp1->left;	
	}
	cout<<"Temp1-> data == "<<temp1->data<<endl;
	if(temp->right->right==temp1)
	{
	temp->right->data=temp1->data;
	temp->right->right=temp;
	temp->right->RTH="thread";
}
else
{
	temp->right->data=temp1->data;
	p->left=temp->right;
	p->LTH="thread";
	p->RTH="thread";
}
	delete temp1;
	return temp;
  }
			
			
		else if(temp->right->data==key2 && temp->right->LTH=="thread" && temp->right->RTH=="thread")      // lead node 
			{
					node *temp1 = temp->right;
					temp->right=temp->right->right;
					temp->LTH="thread";
					temp->RTH="thread";
					delete temp1;
					return temp;
			}
			
		else if(temp->right->data==key2 && temp->right->LTH=="child" && temp->right->RTH=="thread")       // one child on left side
				{
					node *temp1 = temp->right;
					temp->right=temp->right->left;
				    temp->right->right=dummy;
				    temp->right->left=temp;
				    temp->right->LTH="thread";
				    temp->right->RTH="thread";
				    delete temp1;
				    return temp;
}
else if(temp->right->data==key2 && temp->right->LTH=="thread"&&temp->right->RTH=="child")          // When there is one child or right side
{
	node *temp1 = temp->right;
	temp->right=temp->right->right;
	temp->right->LTH="thread";
	temp->right->RTH="thread";
	delete temp1;
	return temp;
}
			else
			{
				 deletee(temp->right);
			}
		}
	
	
	}
 void findmin(node *temp)         // Find Minimum
 {
 	while(temp->LTH=="child")
 	{
 		temp=temp->left;
	}
	cout<<temp->data<<endl;
 }
 void findmax(node *temp)    // Find Maximum
 {
 	while(temp->RTH == "child")
 	{
 		temp=temp->right;
	 }
	 cout<<temp->data<<endl;
 }
	node *nextorder(node *p)
	{
		if(p->RTH=="thread")
		{
			return p->right;
		}
		else
		{
			p=p->right;
			while(p->LTH=="child")
		{
			p=p->left;		
		}	
		return p;
		}
	}
	void  ST(node *n)
	{
//	if(n==NULL)
		while((n=nextorder(n)) != dummy)
		{
			cout<<n->data<<"  ";
		}
	}	
	void serach(node *temp)         // Seraching Code
	{
		if(key<temp->data)
		{
			if(temp->left!=NULL)
			{
				if(temp->data==key)
				{
					cout<<"Value Searched : ";
					cout<<temp->data<<"\n";
					return;
				}
				serach(temp->left);
				return;
			}
		}
		else 
		{
			if(temp->data==key)
			{cout<<"Value Searched : ";
				cout<<temp->data<<"\n";
					return;
			}
			serach(temp->right);
			return;
		}
	}

};
int main()
{
	Tree Obj(21);       // Dummy Node
	int n;
	do{
		cout<<"1)  Insert\n";
		cout<<"2)  Display\n";
		cout<<"3)  Delete\n";
		cout<<"4)  Maximum\n";
		cout<<"5)  Minimum\n";
		cout<<"6)  Search\n";
		cout<<"7)  Update\n";
		cin>>n;
		cout<<endl;

if(n==1)
{	cout<<"Enter number : ";
	cin>>Obj.n;
	Obj.insert(Obj.root);
}
if(n==2)
{
	Obj.ST(Obj.dummy);
	cout<<endl;
}
if(n==3)
{
	cout<<"Enter Element Delete : ";
	cin>>Obj.key2;
	Obj.deletee(Obj.root);
}
if(n==4)
{
	Obj.findmax(Obj.root);
}
if(n==5)
{
	Obj.findmin(Obj.root);
}
if(n==6)
{
	cout<<"Enter the Value to be Serached : ";
	cin>>Obj.key;
	Obj.serach(Obj.root);
}
if(n==7)     // Update
{
	cout<<"Enter Value to be Update : ";
	cin>>Obj.key2;
	cout<<"Enter new value : ";
	cin>>Obj.n;
	Obj.deletee(Obj.root);
	Obj.insert(Obj.root);
}
}while(n!=0);
}


