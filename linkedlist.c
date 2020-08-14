#include<stdio.h>
#include<malloc.h>
#include<string.h>
//made by kunsh manghwani 
//basic of c language linked list
struct node{
	int i;
	struct node *link;
}*first,*n,*ptr,*tptr;

void add(){
	n = (struct node*)malloc(sizeof(struct node));
	printf("\nValue : ");
	scanf("%d",&n->i);
	n->link = NULL;
	ptr = first;
	while(ptr->link!=NULL){
		ptr = ptr->link;
	}
	ptr->link = n;
}

void display(){
	ptr = first;
	if(first == NULL){
		printf("\nERROR LINK IS EMPTY !\n");
	}
	else{
		while(ptr!=NULL){
			printf("%d ",ptr->i);
			ptr = ptr->link;
		}
	}
}

int main(){
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("\nValue : ");
	scanf("%d",&ptr->i);
	ptr->link=NULL;
	first = ptr;
	
	char ch ;
	fflush(stdin);
	while(1){
		fflush(stdin);
		scanf("%c",&ch);
		if(ch != 'y'){
			break;
		}
		add();
	}
	
	display();
}
