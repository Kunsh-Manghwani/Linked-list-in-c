#include<stdio.h>
#include<stdlib.h>
//made by kunsh manghwani 
//basic of c language linked list
struct node{
	int a;
	struct node* next;
}*head,*ptr,*tptr;

void display(){
	tptr=head;
	while(tptr!=NULL){
		printf("%d\t",tptr->a);
		tptr=tptr->next;
	}
}
void insertrear(){
	int d;
	if(head == NULL){
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("\n enter element ");
		scanf("%d",&d);
		ptr->a = d;
		ptr->next=NULL;
		head = ptr;
	}else{
		tptr = head;
		while(tptr->next != NULL){
			tptr= tptr->next;
		}
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("\n enter element ");
		scanf("%d",&d);
		ptr->a = d;
		ptr->next=NULL;
		tptr->next=ptr;
		
	}
}
void insertfront(){
	int d;
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("\n enter element ");
		scanf("%d",&d);
		ptr->a = d;
		ptr->next=head;
		head=ptr;
}
void inssertafter(){
	int x,d;
	if(head == NULL){
		printf("\nthe link list is empty ");
		return;
	}
	printf("\ninsert after element ?");
	scanf("%d",&x);
	tptr= head;
	while(tptr->a!=x || tptr== NULL){
		tptr=tptr->next;
	}	
	if(tptr==NULL){
		printf("\n element not found");
		return ;
	}
	ptr = (struct node*)malloc(sizeof(struct node));
		printf("\n enter element ");
		scanf("%d",&d);
		ptr->a = d;
		ptr->next=tptr->next;
		tptr->next=ptr;
	
}
void inssertafterpos(int x){
	int d;
	if(head == NULL){
		printf("\nthe link list is empty ");
		return;
	}
	tptr= head;
	while(tptr->a!=x || tptr== NULL){
		tptr=tptr->next;
	}	
	if(tptr==NULL){
		printf("\n element not found");
		return ;
	}
	ptr = (struct node*)malloc(sizeof(struct node));
		printf("\n enter element ");
		scanf("%d",&d);
		ptr->a = d;
		ptr->next=tptr->next;
		tptr->next=ptr;
	
}
void insertbefore(){
	int x,d;
	if(head == NULL){
		printf("\nthe link list is empty ");
		return;
	}
	printf("\ninsert before element ?");
	scanf("%d",&x);
	tptr= head;
	while(tptr->next->a!=x || tptr == NULL){
		tptr=tptr->next;
	}
	if(tptr==NULL){
		printf("\n element not found");
		return ;
	}
	ptr = (struct node*)malloc(sizeof(struct node));
		printf("\n enter element ");
		scanf("%d",&d);
		ptr->a = d;
		ptr->next= tptr->next;
		tptr->next=ptr;
}

void insertpos(){
	int x,d;
	if(head == NULL){
		printf("\nthe link list is empty ");
		return;
	}
	printf("\ninsert at position?");
	scanf("%d",&x);
	tptr= head;
	int c=1;
	while(tptr!=NULL){
		tptr=tptr->next;
		if(c==x-1){
			inssertafterpos(tptr->a);
			break;
		}
		c++;
	}
	if(tptr==NULL){
		printf("\n wrong position entered");
	}
	
}

void delrear(){
	if(head == NULL){
		printf("\nthe link list is empty ");
		return;
	}
	tptr=head;
	while(tptr->next->next!=NULL){
		tptr=tptr->next;
	}
	ptr=tptr->next;
	free(ptr);
	tptr->next=NULL;
}

void delfront(){
	if(head == NULL){
		printf("\nthe link list is empty ");
		return;
	}
	ptr=head;
	head=head->next;
	free(ptr);
}
void delelem(){
	int d;
	printf("\n enter element to be deleted");
	scanf("%d",&d);
	tptr=head;
	if(tptr->a==d){
		delfront();
		return ;
	}
	while(tptr->next->a!=d){
		tptr=tptr->next;
	}
	ptr=tptr->next;
	tptr->next=ptr->next;
	free(ptr);
}

void search(){
	int p=0,d;
	printf("enter elemenmt");
	scanf("%d",&d);
	tptr=head;
	while(tptr->a!=d){
		p++;
		tptr=tptr->next;
	}
	printf("element is at position %d",p);
}

int main(){
int c;

while(1){
	printf("\n1-- insert rear\n2-- insert front\n3--insert after\n4--insert before\n5--insert at position\n6--delete rear\n7--delete front\n8--delete element\n9-- search and get position by element\n10-- display\n11--exit");
	scanf("%d",&c);
	if(c==11){
		break;
	}
	switch(c){
	case 1:
	insertrear();
	break;
	case 2:
	insertfront();
	break;
	case 3:
	inssertafter();
	break;
	case 4:
	insertbefore();
	break;
	case 5:
	insertpos();
	break;
	case 6:
	delrear();
	break;
	case 7:
	delfront();
	break;
	case 8:
	delelem();
	break;
	case 9:
	search();
	break;
	case 10:
	display();
	break;
	}
}

}
