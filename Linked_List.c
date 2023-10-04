#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node {
  int data ;
  struct node* next ;
} *start ;

void create () {
	struct node *newNode ;
	struct node *temp ;
	int num , i , newData ;
	printf("Enter Number of nodes: ");
	scanf("%d",&num);
	for (i = 0 ; i < num ; i++){
		temp = start ;
		newNode = (struct node*)malloc(sizeof(struct node));
		printf("Enter a number: ");
		scanf("%d",&newData);
		newNode->data = newData ;
		if (start == NULL){
			start = newNode;
		}
		else {
			while (temp->next != NULL){
				temp = temp->next ;
			}
			temp->next = newNode ;
		}
		newNode->next = NULL;
	}
	printf(" LinkedList Created! ");

}
void insertBefore () {
	int bef , val ;
	struct node *newNode ;
	struct node *temp ;
	printf("Before: ");
	scanf("%d",&bef);
	printf("Number: ");
	scanf("%d",&val);
	newNode = (struct node *)malloc(sizeof(struct node));

}
void insertAfter () {
	int given,val ;

	struct node *temp ;
	struct node *toAddNode ;

	temp = start ;
	printf("After: ");
	scanf("%d",&given);

	printf("Number to insert: ");
	scanf("%d",&val);

	while (temp->data != given){

		temp = temp->next;


	}

	toAddNode = (struct node*)malloc(sizeof(struct node));
	toAddNode->next = temp->next ;
	toAddNode->data = val ;


}
void del () {
	int dele ;
	struct node *pre ;
	struct node *post ;
	struct node *temp ;
	temp = start;
	printf("Element To be deleted: ");
	scanf("%d",&dele);
	while ( temp!=NULL && temp->data != dele){
		// 1 2 3
		pre = temp;
		temp = temp->next;
	}
	if (temp == NULL){
		printf("Value Not Found");
	} else if (temp == start) {
		start = start->next ;
		free(temp);
	} else if (temp->next != NULL){
		post = temp->next ;
		pre->next = post ;
		free (temp);
	} else {
		post = temp->next;
		pre->next = post ;
		free(temp);
	}

}
void display () {

	struct node *temp;
	temp = start ;

	while (temp->next != NULL) {

		printf("%d->",temp->data);
		temp = temp->next ;
	}
	printf("%d",temp->data);

}

void main () {

	int condition ;
	clrscr();
	start = NULL ;
	while(1){
	printf("\n1.Insert After 2.Insert Before 3.Create 4.Delete 5.Display 6.Exit\n");
	printf("==> Enter Choice: ");
	scanf("%d",&condition);
	switch(condition){
		case 1 :
		insertAfter();
		break;
	//	case 2 :
	//	insertBefore();
	//	break;
		case 3 :
		create();
		break;
		case 4 :
		del();
		break;
		case 5 :
		display();
		break;
		case 6 :
		exit(0);
		default :
		printf("Invalid Input Read the menu once again!\n");
		printf("\n1.Insert After 2.Insert Before 3.Create 4.Delete 5.Display 6.Exit\n");
		}
	}

}
