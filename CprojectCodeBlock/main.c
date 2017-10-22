
#include<stdio.h>
#include<stdlib.h>
int main(void){
int choice;
while(1){
    printf("you have the following option\n");
    printf("entre 1 for push\n");
    printf("enter 2 for pop\n");
    printf("enter 3 for diplay(traverse)\n");
    printf("entre 4 for exit\n");
    printf("entre your choice");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:push();
                break;
        case 2:pop();
                break;
        case 3:traverse();
                break;
        case 4:exit(1);
        default:
            printf("wrong choice");
    }
}
}

