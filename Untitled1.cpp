// created By michael Ade.
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<ctype.h>
#include<stdio.h>
void main()
{
char option,ch[1];
int mine[9],computer[9],ptr[9],list[10],player1[9],player2[9];
int player,turn=0,color,i,j;
int driver=9,mode=2;
void computer_turn(int list[10],int ptr[10],int computer[10], int i);
void mine_turn(int list[10],int ptr[10],int mine[10],int i,int player);
void display(int list[10],int i, char ch[1]);
int result(int ptr[10],int i,int player);
initgraph(&driver,&mode,"");
cleardevice();
setcolor(LIGHTBLUE);
settextstyle(8,HORIZ_DIR,9);
outtext("TIC TAC TOE");
int midx=getmaxx()/2;
int midy=getmaxy()/2;
settextstyle(8,HORIZ_DIR,5);
outtextxy(midx-90,midy,"Loading");
for(int pass=1;pass<=6;pass++)
for(j=-90;j<=90;j=j+30)
{
setcolor(BLUE);
setfillstyle(SOLID_FILL,BLUE);
circle(midx+j,midy+100,12);
circle(midx+j,midy+100,10);
floodfill(midx+j,midy+100,BLUE);
setcolor(BLACK);
setfillstyle(SOLID_FILL,BLACK);
delay(150);
floodfill(midx+j,midy+100,BLACK);
}
again:cleardevice();
setcolor(LIGHTBLUE);
settextstyle(8,HORIZ_DIR,9);
outtext("Select Game");
settextstyle(8,HORIZ_DIR,6);
outtextxy(20,160,"1 - Single Player");
outtextxy(20,260,"2 - Double Player");
outtextxy(20,360,"Q - Quit");
player=getche();
if(player=='q' || player=='Q')exit(0);
else if(player!=49 && player!=50 && (player!='q' || player!='Q'))goto again;
cleardevice();
game:clrscr();
cleardevice();
setbkcolor(BLACK);
settextstyle(1,0,6);
setlinestyle(0,3,3);
setcolor(BLUE);
line(200,140,200,getmaxy());
line(400,140,400,getmaxy());
line(50,250,getmaxx()-50,250);
line(50,370,getmaxx()-50,370);
outtextxy(174,188,"1      2      3");
outtextxy(174,308,"4      5      6");
outtextxy(174,428,"7      8      9");
for(i=1;i<=9;i++)
list[i]=10,player1[i]=player2[i]=ptr[i]=mine[i]=computer[i]=20*i;
settextstyle(1,0,10);
for(i=1;i<=9;i++)
{
if(player=='1')
{
if(turn%2==0)
if(i%2!=0)
goto my;
else
goto com;
else
if(i%2!=0)
goto com;
else
goto my;
my:mine_turn(list,ptr,mine,i,player);
setcolor(RED);
display(list,i,"0");
if(result(mine,i,player))
break;
continue;
com:computer_turn(list,ptr,computer,i);
setcolor(GREEN);
display(list,i,"X");
if(result(computer,i,player))
break;
continue;
}
else
{
if(i%2!=0)
{
mine_turn(list,ptr,player1,i,player);
setcolor(RED);
display(list,i,"0");
if(result(player1,i,player))
break;
}
else
{
mine_turn(list,ptr,player2,i,player);
setcolor(GREEN);
display(list,i,"X");
if(result(player2,i,player))
break;
}
}
}
sleep(2);
cleardevice();
cout<<"









               Play again     PRESS      y";
cout<<"



                Main Menu     PRESS      m";
cout<<"



                  Quit        PRESS      q";
wrong:flushall();
option=getche();
if(option=='y' || option=='Y')
{
turn++;
goto game;
}
else if(option=='m' || option=='M')
{
goto again;
}
else if(option=='q' || option=='Q')
{
exit(0);
}
else goto wrong;
}
int result(int ptr[10],int i,int player)
{
void line_draw(int ptr[10]);
clearviewport();
settextstyle(1,0,9);
setcolor(5);
if(ptr[1]==ptr[2]&&ptr[1]==ptr[3] || ptr[4]==ptr[5]&&ptr[4]==ptr[6] ||
ptr[7]==ptr[8]&&ptr[7]==ptr[9] || ptr[1]==ptr[4]&&ptr[1]==ptr[7] ||
ptr[2]==ptr[5]&&ptr[2]==ptr[8] || ptr[3]==ptr[6]&&ptr[3]==ptr[9] ||
ptr[1]==ptr[5]&&ptr[1]==ptr[9] || ptr[3]==ptr[5]&&ptr[3]==ptr[7])
if(ptr[5]==0||ptr[1]==0||ptr[9]==0)
{
delay(80);
if(player=='1')
outtextxy(150,0,"Victory");
else
outtext("Player1 WINS");
line_draw(ptr);
return 1;
}
else
{
delay(80);
if(player=='1')
outtextxy(160,0,"Defeat");
else
outtext("Player2 WINS");
line_draw(ptr);
return 1;
}
else
{
if(i==9)
{
delay(80);
outtextxy(110,0,"Try Again");
}
return 0;
}
}
void mine_turn(int list[10],int ptr[10],int mine[10],int i, int player)
{
char temp;
again:setviewport(0,0,638,120,0);
clearviewport();
setcolor(LIGHTBLUE);
settextstyle(1,0,6);
if(player=='1')
outtext("      Your Turn");
else if(i%2!=0)
outtext("        Player 1");
else
outtext("        Player 2");
outtextxy(0,50,"Make your Move 1 to 9");
temp=getche();
if(temp=='q' || temp=='Q')
exit(0);
else if(isdigit(temp) && temp!='0')
list[i]=toascii(temp)-48;
else
goto again;
if(i!=1)
for(int j=1;j<i;j++)
if(list[i]==list[j])
goto again;
if(player=='1')
mine[list[i]]=0;
else if(i%2!=0)
mine[list[i]]=0;
else
mine[list[i]]=1;
if(player=='1')
ptr[list[i]]=0;
else if (i%2!=0)
ptr[list[i]]=0;
else
ptr[list[i]]=1;
}
void computer_turn(int list[10],int ptr[10],int computer[10], int i)
{
com_again:
if(ptr[1]!=0 && ptr[1]!=1 && (ptr[2]==ptr[3] || ptr[4]==ptr[7] ||ptr[5]==ptr[9]))
list[i]=1;
else if(ptr[2]!=0 && ptr[2]!=1 && (ptr[1]==ptr[3] || ptr[5]==ptr[8]))
list[i]=2;
else if(ptr[3]!=0 && ptr[3]!=1 && (ptr[1]==ptr[2] || ptr[6]==ptr[9] ||ptr[5]==ptr[7]))
list[i]=3;
else if(ptr[4]!=0 && ptr[4]!=1 && (ptr[1]==ptr[7] || ptr[5]==ptr[6]))
list[i]=4;
else if(ptr[5]!=0 && ptr[5]!=1 && (ptr[1]==ptr[9] || ptr[3]==ptr[7] || ptr[4]==ptr[6] || ptr[2]==ptr[8]))
list[i]=5;
else if(ptr[6]!=0 && ptr[6]!=1 && (ptr[4]==ptr[5] || ptr[3]==ptr[9]))
list[i]=6;
else if(ptr[7]!=0 && ptr[7]!=1 && (ptr[1]==ptr[4] || ptr[8]==ptr[9] ||ptr[5]==ptr[3]))
list[i]=7;
else if(ptr[8]!=0 && ptr[8]!=1 && (ptr[5]==ptr[2] || ptr[7]==ptr[9]))
list[i]=8;
else if(ptr[9]!=0 && ptr[9]!=1 && (ptr[1]==ptr[5] || ptr[7]==ptr[8] ||ptr[3]==ptr[6]))
list[i]=9;
else
list[i]=random(9)+1;
if(i!=1)
for(int j=1;j<i;j++)
if(list[i]==list[j])
goto com_again;
computer[list[i]]=1;
ptr[list[i]]=1;
}
void display(int list[10],int i, char ch[1])
{
settextstyle(1,0,10);
switch(list[i])
{
case 1:outtextxy(100,110,ch);
 break;
case 2:outtextxy(270,110,ch);
 break;
case 3:outtextxy(460,110,ch);
 break;
case 4:outtextxy(100,230,ch);
 break;
case 5:outtextxy(270,230,ch);
 break;
case 6:outtextxy(460,230,ch);
 break;
case 7:outtextxy(100,350,ch);
 break;
case 8:outtextxy(270,350,ch);
 break;
case 9:outtextxy(460,350,ch);
 break;
 }
}
void line_draw(int ptr[10])
{
setcolor(BROWN);
setlinestyle(SOLID_LINE,1,3);

if(ptr[1]==ptr[2] && ptr[2]==ptr[3])
line(80,190,getmaxx()-100,190);
else if(ptr[4]==ptr[5] && ptr[5]==ptr[6])
line(80,310,getmaxx()-100,310);
else if(ptr[7]==ptr[8] && ptr[8]==ptr[9])
line(80,430,getmaxx()-100,430);
else if(ptr[1]==ptr[4] && ptr[4]==ptr[7])
line(130,137,130,getmaxy());
else if(ptr[2]==ptr[5] && ptr[5]==ptr[8])
line(300,137,300,getmaxy());
else if(ptr[3]==ptr[6] && ptr[6]==ptr[9])
line(487,137,487,getmaxy());
else if(ptr[1]==ptr[5] && ptr[5]==ptr[9])
line(80,148,550,getmaxy());
else if(ptr[3]==ptr[5] && ptr[5]==ptr[7])
line(530,148,80,getmaxy());
}

