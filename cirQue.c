#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void enqueue();
void dequeue();
void display();

int queue[MAX], front = -1, rear = -1;

int main() {
    int ch;
    printf("1. Enqueue 2. Dequeue 3. Display 4. Exit\n");
    while (1) {
        printf("==> Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

int takeAValue() {
    int en;
    printf("Enter a number: ");
    scanf("%d", &en);
    return en;
}

void enqueue() {
    if ((front - rear == MAX - 1) || (rear - front == MAX - 1)) {
        printf("Queue Is Full!\n");
    } else {
        int en = takeAValue();
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = en;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue Is Empty!\n");
    } else {
        printf("%d is removed from queue!\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Empty Queue!\n");
    } else {
        int i = front;
        printf("Queue: ");
        while (1) {
            printf("%d[%d] ", queue[i], i);
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}
