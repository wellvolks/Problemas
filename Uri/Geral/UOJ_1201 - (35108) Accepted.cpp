#include <map>
#include <set>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <ctime>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

set < int > pert;
set < int > :: iterator it;
bool jafoi = false, start = false;

enum {TRUE = 1,FALSE = 0};

typedef struct _node{
    int info;
    struct _node *left;
    struct _node *right;
}node;

class btree{
	private:
		node *root;
		void InsertLeft(node* & ,node*);
		void InsertRight(node* &,node*);
		void deltree(node*);
	public:
		btree();
		~btree();
		node* GetRoot(void);
		void MakeTree(int valor);
		void DeleteNode(node *,node *,int);
		int Searchnode(node*,int);
		void DisplayTree(node*,int);
		void Inorder(node* );
		void Preorder(node*);
		void Postorder(node*);
};  

btree::btree(){
    char create='Y';
    root = new node;
	root->info = -1;
    root->left = NULL;
    root->right = NULL;
}

btree::~btree(){
    deltree(root);
}

void btree::deltree(node *root){
    if(root){
        deltree(root->left);
        deltree(root->right);
        delete root;
    }
}

node* btree::GetRoot(void){
    return(root);
}

void btree::MakeTree(int valor){  
    node *newnode;
    char create;
    newnode = new node;
	newnode->info = valor;
    newnode->left=NULL;
    newnode->right=NULL;
    if(newnode->info < root->info)
        InsertLeft(newnode,root);
    else
        InsertRight(newnode,root);
}

void btree::InsertLeft(node* &newnode,node* current){
    if(current->left==NULL)
        current->left=newnode;
    else{
        current = current->left;
        if(newnode->info < current->info)
            InsertLeft(newnode,current);
        else
            InsertRight(newnode,current);
    }
}

void btree::InsertRight(node* &newnode,node* current){
    if(current->right==NULL)
        current->right=newnode;
    else{
        current = current->right;
        if(newnode->info < current->info)
            InsertLeft(newnode,current);
        else
            InsertRight(newnode,current);
    }
}

void btree::DeleteNode(node *current,node *parent,int delnode){
    if(delnode < current->info)
        DeleteNode(current->left,current,delnode);
    else if(delnode > current->info)
        DeleteNode(current->right,current,delnode);
    else if(delnode == current->info){
        if(current->left == NULL){
            if(parent->info > current->info)
                parent->left = current->right;
            else
                parent->right = current->right;
        }
        else if(current->right == NULL){
            if(parent->info > current->info)
                parent->left = current->left;
            else
                parent->right = current->left;
        }
        else{
            node *temp;
            int flag = 0;

            parent = current;
            current = current->left;
            temp = current;
            while(current->right != NULL){
                current = current->right;
                if(flag == 0)
                    flag = 1;
                else
                    temp = temp->right;
            }
            parent->info = current->info;
            if(flag == 0)
                // No right child
                parent->left = current->left;
            else
                temp->right = current->left;
        }
        delete current;
    }
}

int btree::Searchnode(node *current,int num){
    if(num<current->info && current->left!=NULL)
        Searchnode(current->left,num);
    else if(num > current->info && current->right!=NULL)
        Searchnode(current->right,num);
    else{
        if(num==current->info)
            return TRUE;
        else
            return FALSE;
    }
}

void btree::DisplayTree(node *current,int Level){
    if(current){
        DisplayTree(current->right,Level+1);
        cout<<endl;
        for(int i=0;i<Level;i++)
            cout<<"  ";
        cout<<current->info;
        DisplayTree(current->left,Level+1);
    }
}

void btree::Inorder(node *current){
    if(current!=NULL){
        Inorder(current->left);
		if(current->info != -1){
			if(jafoi) printf(" %d",current->info);//cout << " " << current->info;
			else{ jafoi = true; printf("%d",current->info); }
		}
        Inorder(current->right);
    }
}

void btree::Preorder(node *current){
    if(current!=NULL){
        if(current->info != -1){
			if(jafoi) printf(" %d",current->info);//cout << " " << current->info;
			else{ jafoi = true; printf("%d",current->info); }
		}
        Preorder(current->left);
        Preorder(current->right);
    }
}

void btree::Postorder(node *current){
    if(current!=NULL){
        Postorder(current->left);
        Postorder(current->right);
		if(current->info != -1){
			if(jafoi) printf(" %d",current->info);//cout << " " << current->info;
			else{ jafoi = true; printf("%d",current->info); }
		}
    }
}

int main(){
	int n, valor, qt, caso = 1;
	char str[100];
	btree bt;
	//ios::sync_with_stdio(false);
	while(scanf(" %s",&str) != EOF){
		if(strlen(str) == 1){
			scanf("%d",&valor);
			if(str[0] == 'I'){ bt.MakeTree(valor); pert.insert(valor); }
			else if( str[0] == 'P') (bt.Searchnode(bt.GetRoot(),valor)) ? printf("%d existe\n",valor) : printf("%d nao existe\n",valor);//cout << valor << " existe\n" : cout <<  valor << " nao existe\n";
			else if( pert.count(valor) ){  bt.DeleteNode(bt.GetRoot(),NULL,valor);  it = pert.find(valor); pert.erase(it); }
		}
		else{
			if(str[1] == 'N')  bt.Inorder(bt.GetRoot());
			else if(str[1] == 'R') bt.Preorder(bt.GetRoot());
			else  bt.Postorder(bt.GetRoot());
			printf("\n");//cout << "\n";
		}
		jafoi = false;
	}
	return 0;
}
