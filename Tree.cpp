

#include<math.h>
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
using namespace std;

	int leaf=0;int int_root=0;
	int r=20,l=90;
	float x1;
	float xcl,xl,yl,xr,yr,xl1,yl1,xr1,yr1;
	int x2;char k1[10];int yu;
	float y=50;
	char k[10];
	int w=1,flag3=0;
	int dimension[6][3]={
				{90,15,20},
				{90,15,20},
				{70,15,76},
				{60,15,13},
				{50,15,5},
				{0,20}
			};
	char leaf1[]="Number of leaf nodes are:";
	char internal1[]="Number of internal nodes are:";
	char created1[]="Tree is created";
	char search1[]="The element is found at height:";
	char root1[]="Root is created";
class node
{
	public:
	int data;
	node *left, *right;
};

class BST
{
	public:

	int max1;
	float midx;


	node *root;
	BST()
	{
		max1=getmaxx();
		midx=max1/2;

		xl=midx-(r*sin(20));
		yl=y+(r*cos(20));
		xl1=xl;yl1=yl;
		xr=(midx+(r*sin(20)));
		yr=(y+(r*cos(20)));
		yr1=yr;xr1=xr;
		root=NULL;
	}
	void create_Node();
	void insert_Node();
	void fun_l(float x,float y,float a);
	void fun_r(float x,float y,float a);
	void fun_l3(float x,float y,float a);
	void fun_r3(float x,float y,float a);
	node* delete1(int);
	void search(int key);
	void fun_r1(float x,float y,float a);
	void fun_l1(float x,float y,float a);
	void mirror(node* root);
	void inorder();
	void fun(node *t,node *k,float xl2,float yl2,float xr2,float yr2,int w2);
	void fun1(node *t,node *k,float xl2,float yl2,float xr2,float yr2,int w2);
	void display(node *t,node *k,float xl2,float yl2,float xr2,float yr2,int w2);
};
void itoaa(int c, char a[10],float x,float y)
{
    char ch; int r;
    int i=0;
    char b[10];
    while ( c > 0)
    {
       r=c%10;
       c=c/10;
       ch=r+48;
    
       a[i]=ch; i++;
    }
    a[i]='\0';
  
    int k=0;
    for(int j=i-1;j>=0;j--)
    {
        b[k]=a[j];
        k++;
    }
    b[k]='\0';
  //fontColor(5);
	//textcolor(5);
	outtextxy(x-10,y-5,b);
}

void BST::fun_l(float x,float y,float a)
{
	//setcolor(5);
	l=dimension[w][0];r=dimension[w][1];a=dimension[w][2];
    line(x,y,x-(l*sin(a)),y+(l*cos(a)));
    circle(x-((l+r)*sin(a)),y+((l+r)*cos(a)),r);
	itoaa(x2,k,x-((l+r)*sin(a)),y+((l+r)*cos(a)));

}
void BST::fun_r(float x,float y,float a)
{
	//setcolor(5);
	l=dimension[w][0];r=dimension[w][1];a=dimension[w][2];
	    line(x,y,x+(l*sin(a)),y+(l*cos(a)));
    circle(x+((l+r)*sin(a)),y+((l+r)*cos(a)),r);
	itoaa(x2,k,x+((l+r)*sin(a)),y+((l+r)*cos(a)));
}
void BST::create_Node()
{
	char abs[]="Value of root is:";

	root=new node;
	cout<<"\nEnter root Node:: ";
	cin>>root->data;
	root->left=NULL;
	root->right=NULL;
	circle(midx,50,r);
	itoaa(root->data,k,midx,50);
	cout<<"\nroot is created"<<endl;

}

void BST::insert_Node()
{

	node *p,*q;
	

	if(root==NULL)
	{
		create_Node();
	}
	xl=xl1;yl=yl1;xr=xr1;yr=yr1;
	cout<<"\nEnter the data:: ";
	cin>>x2;

	p=new node();
	p->data=x2;
	p->left=NULL;
	p->right=NULL;
	q=root;
	int m=2,n=2;
	int flagl=0,flagr=0,cnt=0;char l[]="Node inserted to the left of ";char r[]="Node inserted to the right of ";
	while(q!=NULL)
	{

		if(q->data > p->data)
		{
			if(q->left==NULL)
			{
								
				q->left=p;
				fun_l(xl,yl,20);                                             
                cout<<"\nNode Inserted to left of "<<q->data;
				
				return;
			}
			else
			{
				q=q->left;
				xl=xl-((2*dimension[w][1]+dimension[w][0])*sin(dimension[w][2]));
				yl=yl+((2*dimension[w][1]+dimension[w][0])*cos(dimension[w][2]));
				xcl=xl+(dimension[w][1]*sin(dimension[w][2]));
				xr=xcl+(dimension[w][1]*sin(dimension[w][2]));							
				yr=yl;
				w++;
				m++;
				cnt++;
			}
		}
		else if(q->data < p->data)
		{

			if(q->right==NULL)
			{
				
				q->right=p;
				fun_r(xr,yr,20);
				

				 cout<<"\nNode Inserted to Right of "<<q->data;

				return;
			}
			else
			{
				q=q->right;
				xr=xr+((2*dimension[w][1]+dimension[w][0])*sin(dimension[w][2]));
				yr=(yr+((dimension[w][0]+2*dimension[w][1])*cos(dimension[w][2])));
				xcl=xr-(dimension[w][1]*sin(dimension[w][2]));
				xl=xcl-(dimension[w][1]*sin(dimension[w][2]));
				yl=yr;
				w++;
				n++;
				cnt++;
			}
		}
		else
		{
			cout<<"\nDuplicate Node";
			return;
		}
	}
}
void BST::fun_l3(float x,float y,float a)
{
	//setcolor(5);
	l=dimension[w][0];r=dimension[w][1];a=dimension[w][2];
    line(x,y,x-(l*sin(a)),y+(l*cos(a)));
	setcolor(0);
	floodfill(x-((l+r)*sin(a)),y+((l+r)*cos(a)),0);
    circle(x-((l+r)*sin(a)),y+((l+r)*cos(a)),r);
	//setcolor(0);
	//floodfill(x-((l+r)*sin(a)),y+((l+r)*cos(a)),0);
	//itoaa(x2,k,x-((l+r)*sin(a)),y+((l+r)*cos(a)));

}
void BST::fun_r3(float x,float y,float a)
{
	//setcolor(5);
	l=dimension[w][0];r=dimension[w][1];a=dimension[w][2];
	    line(x,y,x+(l*sin(a)),y+(l*cos(a)));
	setcolor(0);
	floodfill(x+((l+r)*sin(a)),y+((l+r)*cos(a)),0);
    circle(x+((l+r)*sin(a)),y+((l+r)*cos(a)),r);

	//itoaa(x2,k,x+((l+r)*sin(a)),y+((l+r)*cos(a)));
}


// function to delete a node from BST
node *BST :: delete1(int deldata)
{
	xl=xl1;xr=xr1;yl=yl1;yr=yr1;
int found = 0;
int flag;
node *temp = root, *parent, *x;
if(root == NULL)
{
cout << endl << "\t BST is empty";
return NULL;
}

else
{
parent = temp;
//Search a BST node to be deleted & its parent
while(temp != NULL)
{
if(temp->data == deldata )
break; // found
if(deldata < temp->data)
{
parent = temp;
temp = temp->left;
				/*xl=xl-((2*dimension[w][1]+dimension[w][0])*sin(dimension[w][2]));
				yl=yl+((2*dimension[w][1]+dimension[w][0])*cos(dimension[w][2]));
				xcl=xl+(dimension[w][1]*sin(dimension[w][2]));
				xr=xcl+(dimension[w][1]*sin(dimension[w][2]));							
				yr=yl;
				w++;*/
}
else
{
parent = temp;
temp = temp->right;
				/*xr=xr+((2*dimension[w][1]+dimension[w][0])*sin(dimension[w][2]));
				yr=(yr+((dimension[w][0]+2*dimension[w][1])*cos(dimension[w][2])));
				xcl=xr-(dimension[w][1]*sin(dimension[w][2]));
				xl=xcl-(dimension[w][1]*sin(dimension[w][2]));
				yl=yr;
				//fun_r(xr,yr,10);
				w++;*/
}
} // end of search
if(temp == NULL)
return(NULL);
else
{
//case of BST node having right children
if(temp->right != NULL)
{
//fi nd leftmost of right BST node
//cout << "\n Temp is having right child";
parent = temp;
x = temp->right;
//float wex=xr-10;float wey=yr-10;
//float xrv=xr;float yrv=yr;
//setcolor(0);

//floodfill(xr-(dimension[w-1][1]*sin(dimension[w-1][2])),yr-(dimension[w-1][1]*cos(dimension[w-1][2])),0);
//setcolor(15);
//circle(xr-(dimension[w-1][1]*sin(dimension[w-1][2])),yr-(dimension[w-1][1]*cos(dimension[w-1][2])),dimension[w-1][1]);
/*xr=xr+((2*dimension[w][1]+dimension[w][0])*sin(dimension[w][2]));
				yr=(yr+((dimension[w][0]+2*dimension[w][1])*cos(dimension[w][2])));
				xcl=xr-(dimension[w][1]*sin(dimension[w][2]));
				xl=xcl-(dimension[w][1]*sin(dimension[w][2]));
yl=yr;w++;*/
//circle(xrv-(dimension[w][1]*sin(dimension[w][2])),yrv-(dimension[w][1]*cos(dimension[w][2])),dimension[w][1]);				
while(x->left != NULL)
{
	parent = x;
	x = x->left;
	/*xl=xl-((2*dimension[w][1]+dimension[w][0])*sin(dimension[w][2]));
				yl=yl+((2*dimension[w][1]+dimension[w][0])*cos(dimension[w][2]));
				xcl=xl+(dimension[w][1]*sin(dimension[w][2]));
				xr=xcl+(dimension[w][1]*sin(dimension[w][2]));							
				yr=yl;w++;*/

}
temp->data = x->data;
//circle(midx,50,r);
	//itoaa(temp->data,k,xrv-10,yrv-8);

temp = x;
}
//case of BST node being a leaf Node
if(temp->left == NULL && temp->right == NULL)
{
//cout << "\n Leaf node";
if(temp != root)
{
if(parent->left == temp)
{	//xl=xl1;yl=yl1;xr=xr1;yr=yr1;
	parent->left = NULL;	w--;
	/*xl=xl+((2*dimension[w][1]+dimension[w][0])*sin(dimension[w][2]));
				yl=yl-((2*dimension[w][1]+dimension[w][0])*cos(dimension[w][2]));w--;
				xcl=xl+(dimension[w][1]*sin(dimension[w][2]));
				xr=xcl+(dimension[w][1]*sin(dimension[w][2]));							
				yr=yl;
				w++;
			setcolor(0);flag3=1;
			fun_l3(xl,yl,20);
			setcolor(15);*/
}
else
				{parent->right = NULL;w--;
				/*xr=xr-((2*dimension[w][1]+dimension[w][0])*sin(dimension[w][2]));
				yr=(yr-((dimension[w][0]+2*dimension[w][1])*cos(dimension[w][2])));w--;
				xcl=xr-(dimension[w][1]*sin(dimension[w][2]));
				xl=xcl-(dimension[w][1]*sin(dimension[w][2]));
				yl=yr;w++;
				//w--;
			setcolor(0);flag3=1;
			fun_r3(xr,yr,20);
			setcolor(15);*/
}}
else
root = NULL;
delete temp;
return(root);
}
else if(temp->left!=NULL&&temp->right ==
NULL)
//case of BST node having left children
{
//cout << “\n only left”;
if(temp != root)
{
if(parent->left == temp)
{
	parent->left = temp->left;
	//delete_diff(temp->left);
}
else
{
	parent->right = temp->left;
}
}
else
root = temp->left;
delete temp;
return(root);
}
}
}
}
void BST :: mirror(node* root)
{
	node* temp;
	if(root!=NULL)
	{
		temp=root->left;
		root->left=root->right;
		root->right=temp;
		mirror(root->left);
		mirror(root->right);
	}
} 

void BST::fun_l1(float x,float y,float a)
{
	//setcolor(5);
	l=dimension[w][0];r=dimension[w][1];a=dimension[w][2];
    line(x,y,x-(l*sin(a)),y+(l*cos(a)));
    circle(x-((l+r)*sin(a)),y+((l+r)*cos(a)),r);
	//itoaa(x2,k,x-((l+r)*sin(a)),y+((l+r)*cos(a)));

}
void BST::fun_r1(float x,float y,float a)
{
	//setcolor(5);
	l=dimension[w][0];r=dimension[w][1];a=dimension[w][2];
	    line(x,y,x+(l*sin(a)),y+(l*cos(a)));
    circle(x+((l+r)*sin(a)),y+((l+r)*cos(a)),r);
	//itoaa(x2,k,x+((l+r)*sin(a)),y+((l+r)*cos(a)));
}
void BST :: search(int key)
{
node *temp=root;w=1;
	xl=xl1;yl=yl1;xr=xr1;yr=yr1;
	int var1=0;
	while(temp!=NULL)
	{
		if(temp->data > key)
		{
			
			temp=temp->left;
			
		}
		else if(temp->data < key)
		{
		temp=temp->right;

		}
		else if(temp->data == key)
		{
			var1=1;break;
		
		}
	}
 temp=root;w=1;node *k;
	xl=xl1;yl=yl1;xr=xr1;yr=yr1;
if(var1==1)
{
	
	if(root->data == key)
	{
		//floodfill(midx,50,14);
		//delay(2000);
		//floodfill(midx,50,0);
		setcolor(14);
		circle(midx,50,15);
		delay(2000);
		setcolor(15);
		circle(midx,50,15);
		cout<<"Value found:"<<endl;		
		return;
	}
	node *ret=temp;
	setcolor(14);
	while(temp!=NULL)
	{
		if(temp->data > key)
		{
			fun_l1(xl,yl,10);
			xl=xl-((2*dimension[w][1]+dimension[w][0])*sin(dimension[w][2]));
				yl=yl+((2*dimension[w][1]+dimension[w][0])*cos(dimension[w][2]));
				xcl=xl+(dimension[w][1]*sin(dimension[w][2]));
				xr=xcl+(dimension[w][1]*sin(dimension[w][2]));
				yr=yl;w++;
			k=temp;
			temp=temp->left;
			
		}
		else if(temp->data < key)
		{fun_r1(xr,yr,10);
		xr=xr+((2*dimension[w][1]+dimension[w][0])*sin(dimension[w][2]));
				yr=(yr+((dimension[w][0]+2*dimension[w][1])*cos(dimension[w][2])));
				xcl=xr-(dimension[w][1]*sin(dimension[w][2]));
				xl=xcl-(dimension[w][1]*sin(dimension[w][2]));
				yl=yr;w++;
		k=temp;		
		temp=temp->right;

		}
		else if(temp->data == key)
		{
		cout<<"Value found:"<<endl;
		if(k->left==temp)
		{			
		//floodfill(xl+6,yl-6,5);
		delay(2000);
		break;
		}
		else
		{		

		//floodfill(xr-6,yr-6,5);
		delay(2000);
		break;
		}
		
		}
	}
	temp=ret;xl=xl1,yl=yl1,xr=xr1,yr=yr1;setcolor(15);w=1;
	while(temp!=NULL)
	{
		if(temp->data > key)
		{fun_l1(xl,yl,10);
			xl=xl-((2*dimension[w][1]+dimension[w][0])*sin(dimension[w][2]));
				yl=yl+((2*dimension[w][1]+dimension[w][0])*cos(dimension[w][2]));
				xcl=xl+(dimension[w][1]*sin(dimension[w][2]));
				xr=xcl+(dimension[w][1]*sin(dimension[w][2]));yr=yl;w++;
			k=temp;
			temp=temp->left;
			
		}
		else if(temp->data < key)
		{fun_r1(xr,yr,10);
		xr=xr+((2*dimension[w][1]+dimension[w][0])*sin(dimension[w][2]));
				yr=(yr+((dimension[w][0]+2*dimension[w][1])*cos(dimension[w][2])));
				xcl=xr-(dimension[w][1]*sin(dimension[w][2]));
				xl=xcl-(dimension[w][1]*sin(dimension[w][2]));
				yl=yr;w++;
		k=temp;		
		temp=temp->right;

		}
		else if(temp->data == key)
		{
		setcolor(0);
		if(k->left==temp)
		floodfill(xl+6,yl-6,10);
		else
		floodfill(xr-6,yr-6,10);
		//cout<<"Value found:"<<endl;
		setcolor(15);
		return;
		}
	}

}
else
{
	cout<<"Value not found"<<endl;
}
}

void BST :: fun1(node *t,node *k,float xl2,float yl2,float xr2,float yr2,int w2)
{
	if(t==NULL)
	{
		
		return;
	}
	if((t->left==NULL && t->right==NULL) && (t==k->left))
	{
		int w2k=w2-1;
		float xl21=xl2+((2*dimension[w2k][1]+dimension[w2k][0])*sin(dimension[w2k][2]));
				float yl21=yl2-((2*dimension[w2k][1]+dimension[w2k][0])*cos(dimension[w2k][2]));
				xcl=xl21+(dimension[w2k][1]*sin(dimension[w2k][2]));
				float xr21=xcl+(dimension[w2k][1]*sin(dimension[w2k][2]));
				float yr21=yl21;w=w2k;
		fun_l1(xl21,yl21,10);
	
		return;
	}
	else if((t->left==NULL && t->right==NULL) && (t==k->right))
	{
		int w2k=w2-1;;
		float xr21=xr2-((2*dimension[w2k][1]+dimension[w2k][0])*sin(dimension[w2k][2]));
				float yr21=(yr2-((dimension[w2k][0]+2*dimension[w2k][1])*cos(dimension[w2k][2])));
				xcl=xr21-(dimension[w2k][1]*sin(dimension[w2k][2]));
				float xl21=xcl-(dimension[w2k][1]*sin(dimension[w2k][2]));
				float yl21=yr21;w=w2k;
		fun_r1(xr21,yr21,10);
	
		return;
	}
	else if(t->left==NULL && t->right!=NULL)
	{	//fun_r1(xr2,yr2,10);
		
		float xr21=xr2+((2*dimension[w2][1]+dimension[w2][0])*sin(dimension[w2][2]));
				float yr21=(yr2+((dimension[w2][0]+2*dimension[w2][1])*cos(dimension[w2][2])));
				xcl=xr21-(dimension[w2][1]*sin(dimension[w2][2]));
				float xl21=xcl-(dimension[w2][1]*sin(dimension[w2][2]));
				float yl21=yr21;
		int w2k=w2+1;
		fun(t->right,t,xl21,yl21,xr21,yr21,w2k);
	
		if(t!=root && t==k->left){
circle(xl2+(dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xl2+(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xl2+((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yl2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
	if(t!=root && t==k->right){
circle(xr2-(dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xr2-(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
if(t==root){circle(midx,50,r);}
		//fun_r1(xr2,yr2,10);
	}
	else if(t->right==NULL && t->left!=NULL)
	{	//fun_r1(xr2,yr2,10);
		
		float xl21=xl2-((2*dimension[w2][1]+dimension[w2][0])*sin(dimension[w2][2]));
				float yl21=yl2+((2*dimension[w2][1]+dimension[w2][0])*cos(dimension[w2][2]));
				xcl=xl21+(dimension[w2][1]*sin(dimension[w2][2]));
				float xr21=xcl+(dimension[w2][1]*sin(dimension[w2][2]));
				float yr21=yl21;
				
		int w2k=w2+1;
		fun(t->left,t,xl21,yl21,xr21,yr21,w2k);delay(1000);
if(t!=root && t==k->left){
circle(xl2+(dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xl2+(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xl2+((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yl2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
	if(t!=root && t==k->right){
circle(xr2-(dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xr2-(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
if(t==root){circle(midx,50,r);}
	}
	else
	{
				float xl21=xl2-((2*dimension[w2][1]+dimension[w2][0])*sin(dimension[w2][2]));
				float yl21=yl2+((2*dimension[w2][1]+dimension[w2][0])*cos(dimension[w2][2]));
				xcl=xl21+(dimension[w2][1]*sin(dimension[w2][2]));
				float xr21=xcl+(dimension[w2][1]*sin(dimension[w2][2]));
				float yr21=yl21;int w2k=w2+1;
				fun(t->left,t,xl21,yl21,xr21,yr21,w2k);
				
				if(t!=root && t==k->left){
circle(xl2+(dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xl2+(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xl2+((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yl2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
	if(t!=root && t==k->right){
circle(xr2-(dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xr2-(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
	if(t==root)
{circle(midx,50,r);}
				xr21=xr2+((2*dimension[w2][1]+dimension[w2][0])*sin(dimension[w2][2]));
				yr21=(yr2+((dimension[w2][0]+2*dimension[w2][1])*cos(dimension[w2][2])));
				xcl=xr21-(dimension[w2][1]*sin(dimension[w2][2]));
				xl21=xcl-(dimension[w2][1]*sin(dimension[w2][2]));
				yl21=yr21;w2k=w2+1;
				fun(t->right,t,xl21,yl21,xr21,yr21,w2k);
	}
}
void BST :: fun(node *t,node *k,float xl2,float yl2,float xr2,float yr2,int w2)
{
	if(t==NULL)
	{
		delay(1000);
		return;
	}
	if((t->left==NULL && t->right==NULL) && (t==k->left))
	{
		int w2k=w2-1;
		float xl21=xl2+((2*dimension[w2k][1]+dimension[w2k][0])*sin(dimension[w2k][2]));
				float yl21=yl2-((2*dimension[w2k][1]+dimension[w2k][0])*cos(dimension[w2k][2]));
				xcl=xl21+(dimension[w2k][1]*sin(dimension[w2k][2]));
				float xr21=xcl+(dimension[w2k][1]*sin(dimension[w2k][2]));
				float yr21=yl21;w=w2k;
		fun_l1(xl21,yl21,10);
		delay(1000);
		return;
	}
	
	else if((t->left==NULL && t->right==NULL) && (t==k->right))
	{
		int w2k=w2-1;;
		float xr21=xr2-((2*dimension[w2k][1]+dimension[w2k][0])*sin(dimension[w2k][2]));
				float yr21=(yr2-((dimension[w2k][0]+2*dimension[w2k][1])*cos(dimension[w2k][2])));
				xcl=xr21-(dimension[w2k][1]*sin(dimension[w2k][2]));
				float xl21=xcl-(dimension[w2k][1]*sin(dimension[w2k][2]));
				float yl21=yr21;w=w2k;
		fun_r1(xr21,yr21,10);
		delay(1000);
		return;
	}
	else if(t->left==NULL && t->right!=NULL)
	{	//fun_r1(xr2,yr2,10);
		if(t==root){circle(midx,50,r);}
if(t!=root && t==k->left){
circle(xl2+(dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xl2+(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xl2+((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yl2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
	if(t!=root && t==k->right){
circle(xr2-(dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xr2-(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}

		float xr21=xr2+((2*dimension[w2][1]+dimension[w2][0])*sin(dimension[w2][2]));
				float yr21=(yr2+((dimension[w2][0]+2*dimension[w2][1])*cos(dimension[w2][2])));
				xcl=xr21-(dimension[w2][1]*sin(dimension[w2][2]));
				float xl21=xcl-(dimension[w2][1]*sin(dimension[w2][2]));
				float yl21=yr21;delay(1000);
		int w2k=w2+1;
		fun(t->right,t,xl21,yl21,xr21,yr21,w2k);
		delay(1000);
		
		//fun_r1(xr2,yr2,10);
	}
	else if(t->right==NULL && t->left!=NULL)
	{	//fun_r1(xr2,yr2,10);
		//if(t==root){circle(midx,50,r);}
		float xl21=xl2-((2*dimension[w2][1]+dimension[w2][0])*sin(dimension[w2][2]));
				float yl21=yl2+((2*dimension[w2][1]+dimension[w2][0])*cos(dimension[w2][2]));
				xcl=xl21+(dimension[w2][1]*sin(dimension[w2][2]));
				float xr21=xcl+(dimension[w2][1]*sin(dimension[w2][2]));
				float yr21=yl21;
				
		int w2k=w2+1;
		fun(t->left,t,xl21,yl21,xr21,yr21,w2k);delay(1000);
if(t!=root && t==k->left){
circle(xl2+(dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xl2+(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xl2+((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yl2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
	if(t!=root && t==k->right){
circle(xr2-(dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xr2-(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}delay(1000);

	}
	else
	{
				float xl21=xl2-((2*dimension[w2][1]+dimension[w2][0])*sin(dimension[w2][2]));
				float yl21=yl2+((2*dimension[w2][1]+dimension[w2][0])*cos(dimension[w2][2]));
				xcl=xl21+(dimension[w2][1]*sin(dimension[w2][2]));
				float xr21=xcl+(dimension[w2][1]*sin(dimension[w2][2]));
				float yr21=yl21;delay(1000);int w2k=w2+1;
				fun(t->left,t,xl21,yl21,xr21,yr21,w2k);
				
				if(t!=root && t==k->left){
circle(xl2+(dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xl2+(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xl2+((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yl2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
	if(t!=root && t==k->right){
circle(xr2-(dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xr2-(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
	if(t==root)
{circle(midx,50,r);}
				xr21=xr2+((2*dimension[w2][1]+dimension[w2][0])*sin(dimension[w2][2]));
				yr21=(yr2+((dimension[w2][0]+2*dimension[w2][1])*cos(dimension[w2][2])));
				xcl=xr21-(dimension[w2][1]*sin(dimension[w2][2]));
				xl21=xcl-(dimension[w2][1]*sin(dimension[w2][2]));
				yl21=yr21;delay(1000);w2k=w2+1;
				fun(t->right,t,xl21,yl21,xr21,yr21,w2k);
	}
}

void BST :: display(node *t,node *k,float xl2,float yl2,float xr2,float yr2,int w2)
{
	
	if(t==NULL)
	{
		
		return;
	}
	if((t->left==NULL && t->right==NULL) && (t==k->left))
	{
		int w2k=w2-1;
		float xl21=xl2+((2*dimension[w2k][1]+dimension[w2k][0])*sin(dimension[w2k][2]));
				float yl21=yl2-((2*dimension[w2k][1]+dimension[w2k][0])*cos(dimension[w2k][2]));
				xcl=xl21+(dimension[w2k][1]*sin(dimension[w2k][2]));
				float xr21=xcl+(dimension[w2k][1]*sin(dimension[w2k][2]));
				float yr21=yl21;w=w2k;x2=t->data;
		fun_l(xl21,yl21,10);
	
		return;
	}
	else if((t->left==NULL && t->right==NULL) && (t==k->right))
	{
		int w2k=w2-1;;
		float xr21=xr2-((2*dimension[w2k][1]+dimension[w2k][0])*sin(dimension[w2k][2]));
				float yr21=(yr2-((dimension[w2k][0]+2*dimension[w2k][1])*cos(dimension[w2k][2])));
				xcl=xr21-(dimension[w2k][1]*sin(dimension[w2k][2]));
				float xl21=xcl-(dimension[w2k][1]*sin(dimension[w2k][2]));
				float yl21=yr21;w=w2k;x2=t->data;
		fun_r(xr21,yr21,10);
	
		return;
	}
	else if(t->left==NULL && t->right!=NULL)
	{	//fun_r1(xr2,yr2,10);
		

		if(t!=root && t==k->left){
		itoaa(t->data,k1,xl2+(dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(dimension[w2-1][1]*cos(dimension[w2-1][2])));
circle(xl2+(dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xl2+(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xl2+((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yl2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
	if(t!=root && t==k->right){itoaa(t->data,k1,xr2-(dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(dimension[w2-1][1]*cos(dimension[w2-1][2])));
circle(xr2-(dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xr2-(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
if(t==root){circle(midx,50,r);itoaa(root->data,k1,midx,50);}
		//fun_r1(xr2,yr2,10);
		float xr21=xr2+((2*dimension[w2][1]+dimension[w2][0])*sin(dimension[w2][2]));
				float yr21=(yr2+((dimension[w2][0]+2*dimension[w2][1])*cos(dimension[w2][2])));
				xcl=xr21-(dimension[w2][1]*sin(dimension[w2][2]));
				float xl21=xcl-(dimension[w2][1]*sin(dimension[w2][2]));
				float yl21=yr21;
		int w2k=w2+1;
		display(t->right,t,xl21,yl21,xr21,yr21,w2k);
	
		
	}
	else if(t->right==NULL && t->left!=NULL)
	{	//fun_r1(xr2,yr2,10);
		
		float xl21=xl2-((2*dimension[w2][1]+dimension[w2][0])*sin(dimension[w2][2]));
				float yl21=yl2+((2*dimension[w2][1]+dimension[w2][0])*cos(dimension[w2][2]));
				xcl=xl21+(dimension[w2][1]*sin(dimension[w2][2]));
				float xr21=xcl+(dimension[w2][1]*sin(dimension[w2][2]));
				float yr21=yl21;
				
		int w2k=w2+1;
		display(t->left,t,xl21,yl21,xr21,yr21,w2k);delay(1000);

		if(t!=root && t==k->left){itoaa(t->data,k1,xl2+(dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(dimension[w2-1][1]*cos(dimension[w2-1][2])));
circle(xl2+(dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xl2+(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xl2+((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yl2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
	if(t!=root && t==k->right){itoaa(t->data,k1,xr2-(dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(dimension[w2-1][1]*cos(dimension[w2-1][2])));
circle(xr2-(dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);
				line(xr2-(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
if(t==root){circle(midx,50,r);itoaa(root->data,k1,midx,50);}
	}
	else
	{
				float xl21=xl2-((2*dimension[w2][1]+dimension[w2][0])*sin(dimension[w2][2]));
				float yl21=yl2+((2*dimension[w2][1]+dimension[w2][0])*cos(dimension[w2][2]));
				xcl=xl21+(dimension[w2][1]*sin(dimension[w2][2]));
				float xr21=xcl+(dimension[w2][1]*sin(dimension[w2][2]));
				float yr21=yl21;int w2k=w2+1;
				display(t->left,t,xl21,yl21,xr21,yr21,w2k);
				if(t!=root && t==k->left){
circle(xl2+(dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);itoaa(t->data,k1,xl2+(dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(dimension[w2-1][1]*cos(dimension[w2-1][2])));
				line(xl2+(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yl2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xl2+((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yl2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
	if(t!=root && t==k->right){
circle(xr2-(dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(dimension[w2-1][1]*cos(dimension[w2-1][2])),dimension[w2-1][1]);itoaa(t->data,k1,xr2-(dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(dimension[w2-1][1]*cos(dimension[w2-1][2])));
				line(xr2-(2*dimension[w2-1][1]*sin(dimension[w2-1][2])),yr2-(2*dimension[w2-1][1]*cos(dimension[w2-1][2])),xr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*sin(dimension[w2-1][2])),yr2-((2*dimension[w2-1][1]+dimension[w2-1][0])*cos(dimension[w2-1][2])));}
if(t==root){circle(midx,50,r);itoaa(root->data,k1,midx,50);}
				
				xr21=xr2+((2*dimension[w2][1]+dimension[w2][0])*sin(dimension[w2][2]));
				yr21=(yr2+((dimension[w2][0]+2*dimension[w2][1])*cos(dimension[w2][2])));
				xcl=xr21-(dimension[w2][1]*sin(dimension[w2][2]));
				xl21=xcl-(dimension[w2][1]*sin(dimension[w2][2]));
				yl21=yr21;w2k=w2+1;
				display(t->right,t,xl21,yl21,xr21,yr21,w2k);
	}
}

void BST :: inorder()
{		setcolor(RED);
		node* t=root;node* k=t;int w2=1;float xl2=xl1;float yl2=yl1;float xr2=xr1;float yr2=yr1;
		fun(t,k,xl2,yl2,xr2,yr2,w2);
		setcolor(15);
		t=root;k=t;w2=1;xl2=xl1;yl2=yl1;xr2=xr1;yr2=yr1;
		fun1(t,k,xl2,yl2,xr2,yr2,w2);
}

/*
do
		{
			cout<<"\n1.Insert\n2.Search";cout<<endl;
			cout<<"3.Delete"<<endl;
			cout<<"\nEnter your choice:: ";
			cin>>ch1;

/*			switch(ch1)
			{
				case 1:


break;
				case 2: 


break;

				
				case 3:	



break;
				case 4:


}

			cout<<"Do you want to continue:"<<endl;
			cin>>last;
		}while(last=='y');

*/

int main()
{
	//system("COLOR FC");
	//setcolor(8);
	int gd=DETECT,gm,h,key1;
	initgraph(&gd,&gm,NULL);
	char ans,ch,last,ch1;
		//rectangle(20,325,570,450);
		BST t;
		
				do
				{
				w=1;l=dimension[1][0];r=dimension[1][1];
				t.insert_Node();

				cout<<"\nDo you want to insert node:: ";
		   		cin>>ans;
				}while(ans=='Y'||ans=='y');
				
				t.inorder();
				
				t.mirror(t.root);
				cleardevice();
				t.display(t.root,t.root,xl1,yl1,xr1,yr1,1);
				delay(4000);
				cleardevice();
				t.mirror(t.root);
				t.display(t.root,t.root,xl1,yl1,xr1,yr1,1);
				delay(1000);
				do
				{
					cout<<"Enter value to be searched:"<<endl;
					cin>>key1;
					w=1;
					t.search(key1);
					cout<<"Do you want to search again:"<<endl;
					cin>>ch;  
				}while(ch=='y'|| ch=='Y');
					
				do
				{
					cout<<"Enter value to be deleted:"<<endl;
					cin>>h;
					w=1;
					t.root=t.delete1(h);cleardevice();
					t.display(t.root,t.root,xl1,yl1,xr1,yr1,1);
					cout<<"Do you want to delete again:"<<endl;
					cin>>ch;  
				}while(ch=='y'|| ch=='Y');
				
				
		
			
		
		


	delay(1000);
	closegraph();


    return 0;
}
