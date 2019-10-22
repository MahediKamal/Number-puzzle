#include <stdio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
int arr[4][4];
int row=3,clm=3;
char name[31],name2[31];
int hig;
int move_count;
void DEVELOPER(int n) {
    int i,j;
    printf("\n");
    printf("00     0000000 0           0 0000000 0         0 0    000   0000000  00                    00 0  0     0         \n");
    printf("0  0   0        0         0  0       0       0     0  0   0 0        0  0                  0   0  0   0             0 \n");
    printf("0   0  0         0       0   0       0      0       0 0   0 0        0   0                 0   0   0 0               0 \n");
    printf("0   0  0000000    0     0    0000000 0      0       0 000   0000000  0   0                 00 0     0         000000000     \n");
    printf("0   0  0           0   0     0       0      0       0 0     0        0   0                 0   0    0                0 \n");
    printf("0  0   0            0 0      0       0       0     0  0     0        0  0                  0   0    0               0\n");
    printf("00     0000000       0       0000000 0000000   0 0    0     0000000  00                    00 0     0           \n");
    printf("\n\n\n\n");
    for(i=n;i>=0;i--){
             //A print
              Beep(4450,10);
             Beep(1140,10);
        for(j=n-i;j<=n;j++){
            printf(" ");
        }
        Beep(1240,10);
       // printf("00");
        printf("%c%c",4,4);

        for(j=i;j<=n;j++){
            if(i==n/2 || i==(n/2)+1){
                printf("%c",4);
            }
            else{
                printf(" ");
            }
        }
        Beep(1340,10);
        printf("%c",4);

        //print V
         Beep(2270,10);
        printf("     ");
        printf("%c%c",4,4);
        for(j=i;j>=0;j--){
           printf(" ");
        }
        Beep(2170,10);
        printf("%c%c",4,4);
        //A print
         Beep(3300,10);
        printf("        %c%c",4,4);

        for(j=i;j<=n;j++){
            if(i==n/2 || i==(n/2)+1){
                printf("%c",4);
            }
            else{
                printf(" ");
            }
        }
        Beep(3500,10);
        printf("%c%c",4,4);

        //print S
         Beep(4320,10);
        printf("  ");
        for(j=0;j<n;j++){
            if(i==0 ||i==1){
                printf("%c",4);
            }
            else if(i==n ||i==n-1){
                printf("%c",4);
            }
            else if(i==n/2 ||i==(n/2)-1){
                printf("%c",4);
            }
            else if(i<n-1 && i>(n/2)-1 && j==0){
                printf("%c",4);
            }
            else if(i>1 && i<(n/2)-1 && j==(n-1)){
                printf("%c",4);
            }
            else{
                printf(" ");
            }

        }
        Beep(4000,10);
        //print H
        printf("    ");
        for(j=0;j<=n;j++){
            if(j==0){
                printf("%c%c",4,4);
            }
            else if(j==n ){
                printf("%c%c",4,4);
            }
            else if(j>0 && j<n && (i==n/2 || i==(n/2)-1)){
                printf("%c",4);
            }
            else{
                printf(" ");
            }
        }
         Beep(2400,10);
        printf("\n");


    }


}

int check_result(){
    int i,j,k=1;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(arr[i][j]!=k){
                if(i==3 && j==3){
                    return 1;
                }
                return 0;
            }
            k++;
        }
    }


}
void move(char a){
    if(a=='w'){
        if(row>0){
            arr[row][clm]=arr[row-1][clm];
            arr[row-1][clm]=0;
            row--;move_count++;
        }
    }
    else if(a=='z'){
        if(row<3){
            arr[row][clm]=arr[row+1][clm];
            arr[row+1][clm]=0;
            row++;move_count++;
        }
    }
    else if(a=='s'){
        if(clm<3){
            arr[row][clm]=arr[row][clm+1];
            arr[row][clm+1]=0;
            clm++;move_count++;
        }
    }

    else if(a=='a'){
        if(clm>0){
            arr[row][clm]=arr[row][clm-1];
            arr[row][clm-1]=0;
            clm--;move_count++;
        }
    }


}
char make_capital(char a){
        if(a>96){
            a=a-32;
        }
    return a;
}
char scan_button(){
    char a;
    a=getch();
    a=make_capital(a);
    if(a=='W'){
        return 'w';
    }
    else if(a=='S'){
        return 's';
    }
    else if(a=='A'){
        return 'a';
    }
    if(a=='Z'){
        return 'z';
    }
    else {
        return 'o';
    }

}
void get_ramdom_num(){
    srand(time(NULL));
    int  val[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    static int  rvl[16];
    int i,n=15,j=0,k;

    while(n>0){
        int pos=rand()%n;

        rvl[j]=val[pos];
        for(k=pos;k<n;k++){
            val[k]=val[k+1];
        }
        j++;
        n--;
    }

    k=0;

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            arr[i][j]=rvl[k];
            k++;
        }
    }


}
void createbox(){
    int i,j;
    for(i=0;i<4;i++){
        printf("\n            %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
        for(j=0;j<4;j++){
            if(j==0){
                printf("            %c",221);
            }
            printf("           %c",221);
        }
        printf("\n");
        for(j=0;j<4;j++){
            if(j==0){
                printf("            %c",221);
            }
            printf("           %c",221);
        }
        printf("\n");
        for(j=0;j<4;j++){
            if(j==0){
                printf("            %c",221);
            }
            printf("           %c",221);
        }
        printf("\n");
        for(j=0;j<4;j++){
            if(j==0){
                printf("            %c",221);
            }
            printf("     %-2d    %c",arr[i][j],221);
        }
        printf("\n");
        for(j=0;j<4;j++){
            if(j==0){
                printf("            %c",221);
            }
            printf("           %c",221);
        }
        printf("\n");
        for(j=0;j<4;j++){
            if(j==0){
                printf("            %c",221);
            }
            printf("           %c",221);
        }
        printf("\n");
        for(j=0;j<4;j++){
            if(j==0){
                printf("            %c",221);
            }
            printf("           %c",221);
        }
        if(i==3){
            printf("\n            %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254,254);
        }
    }


}
void prn_move(int num){
    int x,y,z,i=1,flg=1,p;
    z=num%10;num=num/10;
    y=num%10;num=num/10;
    x=num;
    while(i<=8){
            flg=1;
             printf("            ");
        while(flg<=3){
            if(flg==1){
                p=x;
            }else if(flg==2){
                p=y;
            }else{
                p=z;
            }
            if(p==1){
                if(i==1){
                    printf("       0");
                }
                else if(i==2){
                     printf("      00");
                }
                else if(i==3){
                    printf("     0 0");
                }
                else if(i==4){
                    printf("       0");
                }
                else if(i==5){
                    printf("       0");
                }
                else if(i==6){
                    printf("       0");
                }
                else if(i==7){
                    printf("       0");
                }
                else {
                    printf("       0");
                }
                flg++;
            }

            else if(p==2){
                if(i==1){
                    printf("  000000");// printf("  000000");
                                       // printf("  0     ");
                }                      // printf("  000000");
                else if(i==2){        //  printf("       0");
                   printf("  0    0");//  printf("       0");
                }                       //printf("       0");
                else if(i==3){          //printf("  0    0");
                    printf("       0"); //printf("  000000");
                }
                else if(i==4){
                    printf("       0");
                }
                else if(i==5){
                     printf("       0");
                }
                else if(i==6){
                     printf("  000000");
                }
                else if(i==7){
                    printf("  0     ");
                }
                else {
                    printf("  000000");
                }
                flg++;
            }

            else if(p==3){
                if(i==1){
                     printf("    0000");
                }
                else if(i==2){
                    printf("   0   0");
                }
                else if(i==3){
                    printf("       0");
                }
                else if(i==4){
                     printf("    0000");
                }
                else if(i==5){
                    printf("       0");
                }
                else if(i==6){
                    printf("   0   0");
                }
                else if(i==7){
                    printf("   0   0");
                }
                else {
                     printf("    0000");
                }
                    flg++;
            }

            else if(p==4){
                if(i==1){
                     printf("       0");
                }
                else if(i==2){
                     printf("      00");
                }
                else if(i==3){
                    printf("     0 0");
                }
                else if(i==4){
                    printf("    0  0");
                }
                else if(i==5){
                    printf("    0000");
                }
                else if(i==6){
                    printf("       0");
                }
                else if(i==7){
                    printf("       0");
                }
                else {
                    printf("       0");
                }
                flg++;
            }

            else if(p==5){
                if(i==1){
                    printf("  000000");
                }
                else if(i==2){
                     printf("  0     ");
                }
                else if(i==3){
                   printf("  000000");
                }
                else if(i==4){
                   printf("       0");
                }
                else if(i==5){
                   printf("       0");
                }
                else if(i==6){
                    printf("       0");
                }
                else if(i==7){
                    printf("  0    0");
                }
                else {
                     printf("  000000");
                }
                flg++;
            }

            else if(p==6){
                if(i==1){
                    printf("   00000");
                }
                else if(i==2){
                    printf("   0   0");
                }
                else if(i==3){
                    printf("   0    ");
                }
                else if(i==4){
                    printf("   0    ");
                }
                else if(i==5){
                     printf("   00000");
                }
                else if(i==6){
                     printf("   0   0");
                }
                else if(i==7){
                     printf("   0   0");
                }
                else {
                    printf("   00000");
                }
                flg++;
            }


            else if(p==7){
                if(i==1){
                    printf("  0000000");
                }
                else if(i==2){
                    printf("       0 ");
                }
                else if(i==3){
                    printf("      0  ");
                }
                else if(i==4){
                    printf("     0   ");
                }
                else if(i==5){
                    printf("    0    ");
                }
                else if(i==6){
                    printf("   0     ");
                }
                else if(i==7){
                     printf("  0      ");
                }
                else {
                     printf(" 0       ");
                }
                flg++;
            }


            else if(p==8){
                    if(i==1){
                     printf("   00000");
                }
                else if(i==2){
                    printf("   0   0");
                }
                else if(i==3){
                    printf("   0   0");
                }
                else if(i==4){
                    printf("   0   0");
                }
                else if(i==5){
                    printf("   00000");
                }
                else if(i==6){
                    printf("   0   0");
                }
                else if(i==7){
                    printf("   0   0");
                }
                else {
                     printf("   00000");
                }
                flg++;
            }
            else if(p==9){
                if(i==1){
                    printf("   00000");
                }
                else if(i==2){
                     printf("   0   0");
                }
                else if(i==3){
                    printf("   00000");
                }
                else if(i==4){
                    printf("       0");
                }
                else if(i==5){
                    printf("       0");
                }
                else if(i==6){
                    printf("   0   0");
                }
                else if(i==7){
                    printf("   0   0");
                }
                else {
                    printf("   00000");
                }

                flg++;
            }

            else{
                if(i==1){
                    printf("   00000");
                }
                else if(i==2){
                    printf("   0   0");
                }
                else if(i==3){
                    printf("   0   0");
                }
                else if(i==4){
                    printf("   0   0");
                }
                else if(i==5){
                    printf("   0   0");
                }
                else if(i==6){
                    printf("   0   0");
                }
                else if(i==7){
                    printf("   0   0");
                }
                else {
                    printf("   00000");
                }

                flg++;
            }

        }
        printf("\n");

        i++;
    }
}
void prn_end(int d){
    printf("\n\n\n\n\n\n\n\n");
    if(d==-1){
        printf("          0        000000   0000000  00000000000 \n");
        printf("          0       0      0  0      0      0      \n");
        printf("          0       0      0  0             0      \n");
        printf("          0       0      0  000000        0      \n");
        printf("          0       0      0        0       0      \n" );
        printf("          0       0      0  0     0       0      \n");
        printf("          0       0      0  0     0       0      \n");
        printf("          0000000  000000   000000        0      \n");
    }

    else{
        printf("          0     0 0000000 0      0\n");
        printf("          0     0    0    00     0\n");
        printf("          0     0    0    0 0    0\n");
        printf("          0     0    0    0  0   0 \n");
        printf("          0  0  0    0    0   0  0 \n" );
        printf("          0 0 0 0    0    0    0 0  \n");
        printf("          00   00    0    0     00  \n");
        printf("          0     0 0000000 0      0 \n");
    }
}
void prn_move_left(){
    printf("    0     0 0           00000000              0       0000000 0000000 000000000                 \n");
    printf("    0 0 0 0  0         0 0                    0       0       0           0            00       \n");
    printf("    0  0  0   0       0  0                    0       0       0           0            00       \n");
    printf("    0     0    0     0   0000000              0       0000000 0000000     0                    \n");
    printf("    0     0     0   0    0                    0       0       0           0            00      \n");
    printf("    0     0      0 0     0                    0       0       0           0            00     \n");
    printf("    0     0       0      0000000              0000000 0000000 0           0                    \n");



}
void prn_start(){

    printf("\n");
    printf("         0     0000  00000 000000 0     0 0000  0       000000            \n");
    printf("        0 0    0  0  0   0 0      00   00 0   0 0       0      \n");
    printf("       0   0   0     0     0      0 0 0 0 0   0 0       0           \n");
    printf("       00000   00000 00000 00000  0  0  0 0000  0       00000          \n");
    printf("      0     0      0     0 0      0     0 0   0 0       0 \n");
    printf("     0       0 0   0 0   0 0      0     0 0   0 0       0                   \n");
    printf("    0         0 0000 00000 000000 0     0 0000  0000000 000000                   \n");

    //printf("\n");
    createbox();
    printf("\n");
    printf("              000000 0     0 0000000 000000 0000              0000000 00000   \n");
    printf("              0      00    0    0    0      0   0                0    0   0 \n");
    printf("              0      0 0   0    0    0      0   0                0    0   0  \n");
    printf("     press    0000   0  0  0    0    00000  0000                 0    0   0     continue  \n");
    printf("              0      0   0 0    0    0      0 0                  0    0   0   \n");
    printf("              0      0    00    0    0      0  0                 0    0   0      \n");
    printf("              000000 0     0    0    000000 0   0                0    00000      \n");



}
void hight(){
    FILE *ptr;
    ptr=fopen("C:\\Users\\admin\\Desktop\\frnds file\\highest.txt","r");
    fgets(name,30,ptr);
    fscanf(ptr,"%d",&hig);
    //printf("highest so far %s = %d\n",name,hig);
    fclose(ptr);
}

int main(){
    hight();
    for(int o=8;o<=20;o=o+4){
        system("cls");
        //PlaySound(TEXT("C:\\Users\\admin\\Documents\\Apowersoft Free Screen Recorder\\Recording\\ni.wmv"),NULL,SND_SYNC);
        DEVELOPER(o);
        for(int i=1;i<200000000;i++){
            i++;
        }
    }
    system("cls");
    char a;
    int i,j,k=1;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            arr[i][j]=k;
            k++;
        }
    }
    arr[3][3]=0;
    //printf("\n\nYOUR TASK IS TO MAKE THE NUMBER BOX LIKE THIS WITHIN 500 MOVES...\n      \n USE W,A,S,Z TO MOVE\n        \nARE YOU READY !!!!\n     PRESS ENTER...");
    prn_start();
    get_ramdom_num();
    getch();
    system("cls");
    printf("ENTER player name : ");
    gets(name2);
    //getchar();
    system("cls");
    while(move_count<500){
        printf("\n------------------------------|\n");
        printf(" highest score '%d' by %s",hig,name);
        printf("------------------------------|\n");
        printf("  move left = %d\n",500-move_count);
        printf("------------------------------|\n");
        printf(" player name ->%s\n",name2);
        printf("------------------------------|\n");
        //prn_move_left();
        prn_move(500-move_count);
        createbox();
        a=scan_button();
        Beep(2000,100);
        //Beep(1000,100);
        move(a);
        Beep(1000,100);
        int r=check_result();
        if(r==1){
            prn_end(1);
            int score=3*(500-move_count);
            printf("new highest score %d \n",score);
            FILE *ptr;
            ptr=fopen("C:\\Users\\admin\\Desktop\\frnds file\\highest.txt","w");
            fputs(name2,ptr);
            fprintf(ptr,"%d",score);
            fclose(ptr);
            getch();
            return 0;
        }
        system("cls");

    }
    prn_end(-1);
    getch();

    return 0;
}

