#include<bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace std;

struct node {
	int childCount;
	string data;
	vector<node*> child;
};

struct node* newNode(string data) 
{ 
  // Allocate memory for new node  
  struct node* Node = new node; 
  
  // Assign data to this node 
  Node->data = data; 
  
  // Initialize the children as NULL 
//  Node->left = NULL; 
//  Node->right = NULL; 
  return(Node); 
} 

class lin
{
	node* root;
	vector<node*> pwd;
	
	public:
	
	lin()
	{
		pwd.push_back(newNode("root"));
	}
	
	void workingdir()
	{	
		cout<<"PATH: "<<endl;
		for(int i=0;i<pwd.size();i++)
		{			
			cout<<pwd[i]->data<<"/";
		}
		cout<<endl;
	}
	
	bool cd(vector<node*> path)
	{
			node* temp = root;
			int flag=0;
			if(temp->data!=path[0]->data)
			{
					return false;
			}
			for(int i=1;i<path.size();i++)
			{	
				int flag = 0;
				for(int j=0;j<(temp->child).size();j++)
				{
					if(path[i]->data == ((temp->child)[j])->data)
					{
						temp = (temp->child)[j];
						flag=1;
						break;
					}
						
				}
				// node* x = (temp->child).find(path[i]);
				if(flag == 0)
					return false;
			}
			pwd=path;
			cout<<"SUCC: REACHED"<<endl;
			return true;
			
	}
	
	void mkdir(vector <node*> path)
	{		node* temp = path.back();
			if(cd(path))
			{
				cout<<"DIRECTORY ALREADY EXISTS"<<endl;
				return;
			}
			
			path.pop_back(); 
			vector<node*> v = pwd;
			bool x = cd(path);
			pwd = v;
			if(!x)
			{
				cout<<"DIRECTORY DOESN'T EXIST"<<endl;
			}
			else
			{	cout<<"SUCC: CREATED";
				(path[path.size()-1]->child).push_back(temp);
			}
	}
	void ls()
	{
			for(int i=0;i<((pwd[pwd.size()-2])->child).size();i++)
			{
				cout<<(((pwd[pwd.size()-2])->child)[i])->data<<" ";
			}
			cout<<endl;
	}
	void rm(vector <node*> path)
	{
			node* temp = path.back();
			path.pop_back();
			vector<node*> v = pwd;
			bool x = cd(path);
			if(!x)
			{
				cout<<"INVALID PATH"<<endl;
			}
			else
			{	
				
				for(i=0;i<((pwd[pwd.size()-1])->child).size();i++)
				{
					if((temp->data==((pwd[pwd.size()-1])->child)[i])->data)
					{
						(pwd[pwd.size()-1]).erase((pwd[pwd.size()-1])->child)[i]);
					}
				}
				cout<<"SUCCESS: DELETED"<<endl;
				pwd = v;
			}
	}
};


int main(){
	lin obj;
	while(1){
		string str;
		getline(cin,str);
		istringstream ss(str); 
	  	string cmd, path;
	  	int count=0;
	  	string word;
	    // Traverse through all words 
	    while(ss>>word){ 
	        // Read a word 
	        // Print the read word 
	//        cout << word << endl;
			if(count==0)
			{
				cmd = word;
				count++;
			}
			else
				path = word;
	        // While there is more to read 
	    }
	    
	    cout<<cmd<<" "<<path<<endl;
	    vector<string> v;
	    boost::split(v, path, boost::is_any_of("/"));
//	    for (int i = 0; i < v.size(); i++) 
//	        cout << v[i] << endl;
		vector<node*> pathVector;
		for(int i=0;i<v.size();i++){
			pathVector(push_back(newNode(v[i])));	
		}
		switch(cmd)
		{
			case "cd":
				cd(pathVector);
				break;
			case "mkdir":
				mkdir(pathVector);
				break;
			case "pwd":
				workingdir();
				break;
			case "ls":
				ls();
				break;
			case "rm":
				rm(pathVector);
				break;
			default:e
				cout<<"Invalid arguments";
				break;
		}			
	}        
    return 0;
	
}
