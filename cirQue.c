#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void enqueue();
void dequeue();
void display();

int queue[MAX], front = -1, rear = -1;

int main()
{
    int ch;
    printf("\n1.enqueue 2.dequeue 3.display 4.exit \n");
    while (1)
    {
        printf("==> Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid choice\n");
        }
    }
}

int takeAValue () {
    int en = 0 ;
    printf("Enter a number: ");
    scanf("%d",&en);
    return en ;
}

void enqueue(){

    if ( front - rear == MAX-1 || rear - front == MAX-1 ) {
        printf("Queue Is Full !\n");
    } else {
        int en = takeAValue();
        if (front == -1 && rear == -1)
            front = (front+1)%MAX;
        rear = (rear+1)%MAX;
        queue[rear] = en ;
    } 
}
void dequeue(){

    if (front == -1 && rear == -1) {
        printf("Queue Is Empty !\n");   
    } else if ( front - rear != 0 ) {
        printf("%d is removed from queue!\n",queue[front]);
        front = (front+1)%MAX ;
    } else if ( front == rear ) {
        printf("%d is removed. Queue Became Empty !\n",queue[front]);   
        front = -1 ;
        rear = -1 ;
    }

}
void display(){

    if (front == -1 && rear == -1){
        printf("Empty Queue Hai ?\n");
    } else { 
        int i = front ;

        while (1) { // infinite looop !
            printf("%d[%d] ", queue[i],i);
            if (i == rear) { 
                break; // controller
            }
            if ( i == MAX-1 ){
                i = 0 ;
            } else {
                i++ ;
            }
        }
        printf("\n");
    }
}
