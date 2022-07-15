#include<iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

node *createNode(int x){
    node *temp = new node();
	temp->data=x;
	temp->next=NULL;
	return temp;
}

node *addEnd(node *p, int x){
	node *temp=createNode(x);
	node *ptr=p;
    if(p==NULL){
        ptr= temp;
        return ptr;
    }
	while((ptr->next)!=NULL){
		ptr=ptr->next;
	}
	ptr->next=temp;
	return p;
}

node *inputList(node *p, int n ){
    int data;
    for(int i=0; i<n; i++){
        cout<<"Nhap gia tri data= ";
        cin>>data;
        p= addEnd(p, data);
    }
    return p;
}

void printfList(node *p){
	node *temp=p;
	while(temp!=NULL){
        cout<<temp->data<<" ";
		temp=temp->next;
	}
    cout<<endl;
}

void split(node *p, node **pos, node **neg){
    node *ptr=p;
    while(ptr!=NULL){
        if(ptr->data %2==0){   
            *pos = addEnd(*pos, ptr->data);
        }else{
            *neg= addEnd(*neg, ptr->data);
        }
        ptr= ptr->next;
    }
}


int main(){
    node *p=NULL, *pos=NULL, *neg=NULL;
    int n;
    cout<<"Nhap so luong phan tu: ";
    cin>>n;
    p=inputList(p, n);
    cout<<"Danh sach: ";
    printfList(p);
    split(p, &pos, &neg);
    cout<<"Chan: ";
    printfList(pos);
    cout<<"Le: ";
    printfList(neg);
    return 0;
}