// DEQue

#include<stdio.h>
#include<conio.h>

int MAX = 5 , queue[5] , front = -1 , rear = -1 ;

void dequeUsingFront () {
	if ( front == -1 ){
		printf("Queue is Empty !\n");
	} else {
		int temp = queue[front];
		front = (front+1) % MAX ;
		printf("%d is removed", temp);
	}
}
void dequeUsingRear () {
	if ( front == -1 ){
		printf("Queue is Empty !\n");
	} else {
		int temp = queue[front];
		front = (front+1) % MAX ;
		if ( front == rear ){
			front = -1 ;
			rear = -1 ;
		}
		printf("%d is removed", temp);
	}
}
void enqueUsingRear () {
	if ( rear - front == -1 || ( rear == 4 && front == 0 ) ){
		printf("Queue is full !\n");
	} else {
		int ar ;
		printf("Enter a number: ");
		scanf("%d",&ar);
		if (front == -1)
			front = 0 ;
		rear = (rear+1)%MAX ;
		queue[rear] = ar ;
		printf("Done!\n");
	}
}
void enqueUsingFront () {
	if ( rear - front == -1 || ( rear == 4 && front == 0 ) ){
		printf("Queue is full !\n");
	} else {
		int ar ;
		printf("Enter a number: ");
		scanf("%d",&ar);
		if (front == -1) {
			rear = MAX-1 ;
			front = MAX-1 ;
			queue[front] = ar ;
			printf("Done!\n");
		} else {
		front = (front - 1)%MAX ;
		queue[front] = ar ;
		printf("Done!\n");
		}
	}
}
void display () {
	if (front == -1){
		printf("Queue is Empty! Cannot display .");
	} else {
		int i = front ;
		printf("Queue: ");
		if (front <= rear){
			for ( i=front ; i<=rear ; i++ ){
				printf("%d ",queue[i]);
			}
		} else {
			for ( i = front ; i <= MAX-1 ; i++){
				printf("%d ",queue[i]);
			}
			for ( i = 0 ; i <= rear ; i++ ){
				printf("%d ",queue[i]);
			}
		}
	}
}
void inpRes() {
	int back = 0 , cond ;
	printf("1.Deque Using Front 2.Enque Using Rear 3.Deque Using Front 4.Back\n");
	while(back != 1){
	printf("==> Enter Choice: ");
	scanf("%d",&cond);
	switch(cond){
		case 1 :
		dequeUsingFront();
		break;
		case 2 :
		enqueUsingRear();
		break;
		case 3 :
		dequeUsingFront();
		case 4 :
		back = 1 ;
		break;
		default :
		printf("Invalid Input Read the menu once again!\n");
		printf("1.Enque Using Front 2.Enque Using Rear 3.Back\n");
		}
	}
}
void outRes() {
	int back = 0 , cond;
	printf("1.Deque Using Front 2.Enque Using Rear 3.Enque Using Front 4.Back\n");
	while(back != 1){
	printf("==> Enter Choice: ");
	scanf("%d",&cond);
	switch(cond){
		case 1 :
		dequeUsingFront();
		break;
		case 2 :
		enqueUsingRear();
		break;
		case 3 :
		enqueUsingFront();
		case 4 :
		back = 1 ;
		break;
		default :
		printf("Invalid Input Read the menu once again!\n");
		printf("1.Enque Using Front 2.Enque Using Rear 3.Back\n");
		}
	}
}
void main () {

	int cond ;
	clrscr();
	while(1){
	printf("\n1.Input Res 2.Output Res 3.Display 4.Exit\n");
	printf("==> Enter Choice: ");
	scanf("%d",&cond);
	switch(cond){
		case 1 :
		inpRes();
		break;
		case 2 :
		outRes();
		break;
		case 3 :
		display();
		break;
		case 4 :
		exit(0);
		default :
		printf("Invalid Input Read the menu once again!\n");
		printf("1.Enque 2.Deque 3.Display 4.Exit\n");
		}
	}

}
