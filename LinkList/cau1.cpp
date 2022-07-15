#include<iostream>
#include<stdlib.h>
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

int countNegative(node *p){
    node *temp=p;
    int num=0;
    while(temp!=NULL){
        if(temp->data < 0){
            num++;
        }
        temp= temp->next;
    }
    return num;
}

node* addressOfMax(node *p){
    node *temp=p;
    node  *index=0;
    int max= temp->data;
    while(temp!=NULL){
        if(temp->data > max) {
            max= temp->data;
            index= temp;
        }
        temp= temp->next;

    }
    return index;
}

int indexOfMax(node *p){
    node *temp=p;
    int i=0, index=0;
    int max= temp->data;
    while(temp!=NULL){
        if(temp->data > max) {
            max= temp->data;
            index =i;
        }
        i++;
        temp= temp->next;

    }
    return index;
}

void menu(){
    printf("------------------Link List--------------------\n");
	printf("1. Nhap danh sach lien ket\n");
	printf("2. In danh sach lien ket\n");
	printf("3. Dem so luong gia tri am\n");
	printf("4. Dia chi node lon nhat\n");
	printf("5. Vi tri node lon nhat\n");
    printf("6. Xen lai menu\n");
	printf("0. Exit\n");
}

int main(){
    node *p=NULL;
    menu();
    while(1){
        printf("Chon nhap chuc nang: ");
        int chocie;
        int n;
        cin>>chocie;
        switch(chocie){
            case 0:
                exit(0);
            case 1:
                cout<<"Nhap so luong phan tu: ";
                cin>>n;
                p=inputList(p, n);
                break;
            case 2:
                printfList(p);
                break;
            case 3:
                cout<<"so phan node am: "<<countNegative(p)<<endl;
                break;
            case 4:
                cout<<"Dia chi node lon nhat: "<<addressOfMax(p)<<endl;
                break;
            case 5:
                cout<<"Vi tri node lon nhat:" <<indexOfMax(p)<<endl;
                break;
            case 6:
                menu();
                break;
            default:
                printfList(p);
        }
    }
    return 0;
}