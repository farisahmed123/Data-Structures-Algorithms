#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node{
		int movieID;
		string title;
		string genre;
		int ratings;
		Node* left;
		Node* right;
Node()
{
	left = NULL;
	right = NULL;
}
};
class Array
{
	public:
	int movie;           // Declareing in public is easy to acces and compare these data thats why i use it into as a public member of classn
	string Title;
	string Genre;
	int Rating;
		Array(int movie,string tittle,string Genre,int rating)
		{
			this->movie=movie;
			this->Genre=Genre;
			this->Rating=rating;
			this->Title=tittle;
		}
};
class MovieRecommendationSystem {
	public:
		vector<Array> obj;
		int arr1[5];
//		int arr2[5];
		 MovieRecommendationSystem()
		 {
		 	root=NULL;
		 }
		Node* root;
		int movieID;
		string genre;
		string title;
		int ratings;
		void insertMovie(Node* temp) 
		{
			cout<<"ASDSD";
			if (root == NULL) 
			{
			    temp = new Node;
			    root=temp;
				temp->movieID=movieID;
				temp->genre=genre;
				temp->ratings=ratings;
				temp->title=title;
				temp->left=NULL;
				temp->right=NULL;
				return;
					
			}
			if(movieID == temp->movieID)
			{
				cout<<"Repeated Movie Cant be ADD\n";
				return;
			}
			  if (movieID < temp->movieID) 
			{
			if(temp->left!=NULL)
			{
				insertMovie(temp->left);
				return;
			}
			else
			{
			temp->left=new Node;
			temp->left->movieID=movieID;
			temp->left->title=title;
			temp->left->genre=genre;
			temp->left->ratings=ratings;
			temp->left->left=NULL;
			temp->left->right=NULL;
			return;
		}
		}
		 if(movieID > temp->movieID)
		{
			if(temp->right!=NULL)
			{
				insertMovie(temp->right);
				return;
			}
			else
			{
			temp->right=new Node;
			temp->right->movieID=movieID;
			temp->right->title=title;
			temp->right->genre=genre;
			temp->right->ratings=ratings;
			temp->right->right=NULL;
			temp->right->left=NULL;
			return;
			}
		}
	}
				
		void recommendMoviesByGenre(Node *root,string genre) 
		{
        if(root==NULL)
        {
        	cout<<"Tree is Empty\n";
        	return;
		}
		if(root->left!=NULL)
		{
			recommendMoviesByGenre(root->left,genre);
		}
		if(root->genre==genre)
		{
			cout<<"Movie ID : "<<root->movieID<<endl;
			cout<<"Movie Tittle : "<<root->title<<endl;
			cout<<"Movie Rating : "<<root->ratings<<endl;
			cout<<"Movie Genre : "<<root->genre<<endl;
		}
		if(root->right!=NULL)
		{
		recommendMoviesByGenre(root->right,genre);	
		}
		}
		
		void display(Node *temp)
		{
			if(temp->left!=NULL)
			{
				display(temp->left);
			}
cout<<"Movie ID : "<<temp->movieID<<endl;
cout<<"Movie Tittle : "<<temp->title<<endl;
cout<<"Movie Genre : "<<temp->genre<<endl;
cout<<"Movie Rating : "<<temp->ratings<<endl;
			if(temp->right!=NULL)
			{
				display(temp->right);
			}
		}
		
		void deletee(Node* temp)
{
if(root == NULL)
{
	cout<<"Tree is Empty\n";
	return;	
}
if(movieID<temp->movieID)
{
	if(temp->movieID==movieID && temp->left!=NULL && temp->right != NULL)
  {
  	cout<<"A\n";
  	Node *temp1 = temp->right;
  	while(temp1->left!=NULL)
  	{
  	temp1 = temp1->left;	
	}
	cout<<"Temp1-> data == "<<temp1->movieID<<endl;
	temp->movieID=temp1->movieID;
	delete temp1;
	return;
  }
 else if(temp->left->movieID==movieID && temp->left->left==NULL && temp->left->right==NULL)
  {
  	Node *temp1=temp->left;
  	temp->left=temp->left->left;
  	delete temp1;
  	return;
   }
  else if (temp->left->movieID==movieID && temp->left->right==NULL && temp->left->left!=NULL)
  {
  	Node *temp1 = temp->left;
  	temp->left=temp->left->left;
  	delete temp1;
  	return;
  }
  else if(temp->left->movieID==movieID && temp->left->left==NULL && temp->left->right!=NULL)
  {
  	Node *temp1=temp->left;
  	temp->left=temp->left->right;
  	delete temp1;
  	return;
  }
  else 
  {
  	deletee(temp->left);
  	return;
  }}
  else
  {
    if(temp->movieID==movieID && temp->right!=NULL && temp->left!=NULL)
     {
     	
     	Node *temp1 = temp->right;
     	while(temp1->left!=NULL)
     	{
     		temp =temp->left;
		}
		 temp->movieID=temp1->movieID;	
		 delete temp1;
		 return;
	 }
	 else if(temp->right->movieID==movieID && temp->right->right==NULL)
	 {
	 	Node *temp1 = temp->right;
	 	temp->right=temp->right->left;
	 	delete temp1;
	 	return;
}
else if (temp->right->movieID==movieID && temp->right->left==NULL)
{
	Node *temp1 = temp->right;
	temp->right=temp->right->right;
	delete temp1;
	return;
}
	 else
	 {
	 	deletee(temp->right);
	 	return;	
	 }
  }		
	}
	

};

int main() {
	MovieRecommendationSystem engine;
	int choice;
    do{
		cout << "Menu:\n";
		cout << "1. Add a Movie\n";
		cout << "2. Delete a Movie by ID\n";
		cout << "3. Recommend Movies by Genre\n";
		cout << "4. Display Movies Sorted by Ratings\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if(choice == 1)
		{
		
				cout << "Enter Movie ID: ";
				cin >> engine.movieID;
				cout << "Enter Movie Title: ";
				cin>>engine.title;

				cout << "Enter Movie Genre: ";
				cin>>engine.genre;
				cout << "Enter Ratings: ";
				cin >> engine.ratings;
				engine.insertMovie(engine.root);
				cout << "Movie added successfully!" << endl;

			}
			 if(choice == 2){
			
				cout << "Enter Movie ID to delete: ";
				cin >> engine.movieID;
				engine.deletee(engine.root);

			}
		 if(choice == 3) {
				string genre;
				cout << "Enter your favorite genre: ";
				cin>>genre; 
				engine.recommendMoviesByGenre(engine.root,genre);
				cout<<endl;
			}
			 if(choice == 4){
			
				engine.display(engine.root);
cout<<endl;
		}
	}
	while(choice != 5);
}

