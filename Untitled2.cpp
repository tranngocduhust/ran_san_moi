#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<stdio.h>
#define ox 112
#define oy 22
#include<conio.h>
int sl=4;
int x=0,y=0,moito=0;//toa do cua moi
void xoacontro()
{
 CONSOLE_CURSOR_INFO Info;
 Info.bVisible = FALSE;
 Info.dwSize = 20;
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void TextColor(int x){
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}
void ToaDo(int x,int y){
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD tinh = {x,y} ;
	SetConsoleCursorPosition(mau,tinh ) ;
}
void vetuong(){
	TextColor(14);
	int x,y;
    for(x=4;x<=ox;x++){
    	ToaDo(x,2);
    	printf("=");
	}
	for(y=3;y<oy;y++){
		ToaDo(4,y);
		printf("||");
	}
	for(y=3;y<oy;y++){
		ToaDo(111,y);
		printf("||");
	}
	for(x=4;x<=ox;x++){
    	ToaDo(x,oy);
    	printf("=");
	}

}
void bo(){
	ToaDo(0,23);
    printf("");
}
void khoitao(int toadox[],int toadoy[],int x,int y){
	for(int i=0;i<sl;i++){
		toadox[i]=x-1;
		toadoy[i]=y;
		x--;
	}
}
void veran(int toadox[],int toadoy[]){
	for(int i=0;i<sl;i++){
		ToaDo(toadox[i],toadoy[i]);
		if(i==0){
			printf("@");
		}
		else{
			printf("o");
		}
			
	}
}
int kiemtra(int toadox[],int toadoy[]){
	int i=1;
	int a=toadox[0],b=toadoy[0];
	for(i;i<sl;i++){
		if(a==toadox[i]&&b==toadoy[i]){
			return 1;
			break;
		}
	}
}
void moi(int toadox[],int toadoy[]){
	srand(time(NULL));
    do{
    x=6+rand()%105;
    y=3+rand()%19;
	}while(x==toadox[0]||y==toadoy[0]);
	ToaDo(x,y);
	TextColor(6);
	if(moito%8==0&&moito!=0)
    	printf("#");
    else
	    printf("$");	
}

void them(int a[],int x){
	a[sl]=a[sl-1];
	int i=sl-1;
	for(i;i>0;i--){
		a[i]=a[i-1];
	}
	a[0]=x;
}
void xulyran(int toadox[],int toadoy[],int x,int y){
	//them toa do x
	them(toadox,x);
	//them toa do y
	them(toadoy,y);
	//ve ran
	veran(toadox,toadoy);
	ToaDo(toadox[sl],toadoy[sl]);
	printf(" ");
}
int a=0,diem=0;
void tinhdiem(int toadox[],int toadoy[]){
	a=sl;
	if(toadox[0]==x &&toadoy[0]==y){
		if(moito%8==0&&moito!=0){
			 diem=diem+5;
			  printf("\a");
		}
		 
		else if(moito%8!=0||moito==0){
			diem=diem+1;
			 printf("\a");
		}
		  
	    ToaDo(105,1);
		TextColor(6);
		moito=moito+1;
		printf("Diem:%d",diem);
		sl=sl+1;
	}
	
}

int main(){
	int e;
	do{
		x=0,y=0,moito=0,sl=4,diem=0,a=0;
	int x0=44,y0=12,thu=0,toadox[100],toadoy[100];
	char kitu;
	int m,b;
	TextColor(11);
	ToaDo(48,3);
	printf("Hello ae den voi ran truy kich");
	ToaDo(48,4);
	printf("(1)game de");
	ToaDo(48,5);
	printf("(2)game vua");
	ToaDo(48,6);
	printf("(3)game kho");
	ToaDo(48,7);
	printf("chon cap do choi:");
	scanf("%d",&m);
	if(m==1){
		b=100;
	}
	else if(m==2){
		b=50;
	}
	else if(m==3){
		b=30;
	}
	system("cls");
	ToaDo(50,1);
	printf("Ran truy kich");
	ToaDo(105,1);
	TextColor(6);
	printf("Diem:%d",0);
    vetuong();
    xoacontro();
    khoitao(toadox,toadoy,x0,y0);
    veran(toadox,toadoy);
    moi(toadox,toadoy);//moi
    while(1){
    	
    	tinhdiem(toadox,toadoy);
    	if(a+1==sl){
    		 moi(toadox,toadoy);//moi
		}
    	Sleep(b);
    	if(kbhit()){
    		kitu=getch();
    		if(kitu==-32){
    			kitu=getch();
    			if(kitu==72&&thu!=3){
    				//di len
    				thu=2;
				}
				else if(kitu==80&&thu!=2){
					//di xuong
					thu=3;
				}
				else if(kitu==75&&thu!=0){
					//sang trai
					thu=1;
				}
				else if(kitu==77&&thu!=1){
					//sang phai
					thu=0;
				}
			}
		}
		if(thu==0){//sang phai
		 xulyran(toadox,toadoy,x0,y0);
		 x0++;
		}
		else if(thu==1){//sang trai
		  xulyran(toadox,toadoy,x0,y0);
		   x0--;
		}
		else if(thu==2){//len tren
		   xulyran(toadox,toadoy,x0,y0);
		   y0--;
		}
		else if(thu==3){//xuong duoi
		  xulyran(toadox,toadoy,x0,y0);
		   y0++;
		}
    	if(toadox[0]==111||toadoy[0]==2||toadox[0]==5||toadoy[0]==22||kiemtra(toadox,toadoy)==1)
		{
    		system("cls");
    		TextColor(12);
    		ToaDo(48,12);
    		printf("thua roi nhe !");
    		ToaDo(48,13);
    		printf("So diem:%d",diem);
    		if(diem<10){
    		   ToaDo(48,14);
    		   printf("Choi ga qua ! bam 5 de choi lai hoac 7 de thoat :");
    		   scanf("%d",&e);
			}
			else if(diem>=10&&diem<30){
			   ToaDo(48,14);
    		   printf("Choi tam duoc day! hay bam 5 de choi lai muc do kho hon hoac bam 7 de thoat :");
    		   scanf("%d",&e);
			}
			else if(diem>=30){
				ToaDo(48,14);
    		   printf("Choi dinh day! bam 5 de choi duoc diem cao hon hoac bam 7 de thoat:");
    		   scanf("%d",&e);
			}
    		break;
		}		
	}
}while(e==5);
    bo();
    getch();
}
