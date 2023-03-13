
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int width=20, height=20,gameover;
int x,y,fruitx,fruity,score,flag;
int tailx[100],taily[100];
int counttail=0;
void setup(){
    gameover=0;
    x=width/2;
    y=height/2;

    label1:
    fruitx=rand()%20;
    if(fruitx==0){
        goto label1;
    }

    label2:
    fruity=rand()%20;
    if(fruity==0){
        goto label2;
        score=0;
    }


}
void draw(){
    int i,j,k;
    system("cls");
    for(i=0;i<=width;i++){
        for(j=0;j<=height;j++){
            if(i==0|| i==height||j==0||j==width){
            printf("*");
            }
            else{
             if(i==x && j==y){
                printf("0");
             }
             else if(i==fruitx && j==fruity){
                printf("F");
             }
             else{
                int ch=0;
             for(k=0;k<counttail;k++){
                if(i==tailx[k]&&j==taily[k]){
                    printf("0");
                    ch=1;
                }
             } 
             if(ch==0)
             printf(" ");
              }
            }
        }
        printf("\n");
    }
}
void input(){
    if(kbhit()){
        switch (getch())
        {
        case 'a':
           flag=1;  
            break;
        case 's':
           flag=2;
           break;
        case 'w':
           flag=3;
           break;
        case 'z':
           flag=4;
           break;
        case 'x':
           flag=5;
           break;      
        
        }
    }
    
}
void makelogic()
{
    int i;
 int prevx=tailx[0];
 int prevy=taily[0];
 int prev2x,prev2y;
 tailx[0]=x;
 taily[0]=y;
   
   for(i=1;i<counttail;i++){
    prev2x=tailx[i];
    prev2y=taily[i];
    tailx[i]=prevx;
    taily[i]=prevy;
    prevx=prev2x;
    prevy=prev2y;
   }
    switch (flag)
 {
    case 1:
     y--;
     break;

    case 2:
     y++;
     break;

    case 3:
     x--;
     break;

    case 4:
     x++;
     break;

    default:
     break;
 }
 if(x<0||x>width||y<0||y>height){
        gameover=1;
    }

    if(x==fruitx && y==fruity){
         label3:
    fruitx=rand()%20;
    if(fruitx==0){
        goto label3;
    }

    label4:
    fruity=rand()%20;
    if(fruity==0){
        goto label4;
        score+=10;
        counttail++;
    }

    }
}
int main(){

    setup();
    
    while(!gameover){
    draw();
    input();
    makelogic();
    }
    return 0;
}