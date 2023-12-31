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

    

    if ( rear == MAX-1 ) {
        printf("Queue Is Full !\n");
    }else if (front == -1 && rear == -1) {
        int en = takeAValue();
        front++;
        rear++;
        queue[rear] = en ;
    } else if ( rear != MAX-1 ) {
        int en = takeAValue();
        rear++;
        queue[rear] = en ;
    } 

}
void dequeue(){

    if (front == -1 && rear == -1) {
        printf("Queue Is Empty !\n");   
    } else if ( front < rear ) {
        printf("%d is removed from queue!\n",queue[front]);
        front++ ;
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
        for (int i = front; i < rear + 1; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}