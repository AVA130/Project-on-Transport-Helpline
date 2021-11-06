#include<graphics.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void user();
void inside_city();
void outside_city();
void Bus_Company(char *,char *);
void Admin();
void menu();
void output();
void pass();
void password();
void slow();
void add();
void see(char *,char *);
void seeAdmin();
void getString(char *);
void doCursor(int);
void useroutput(char *,char *,char *);
void route(char *,char *);
int cnt;
int a=250;
int main()
{
    int n;
    int screenwidth=GetSystemMetrics(SM_CXSCREEN);
    int screenheight=GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenwidth,screenheight,"",-3,-3);
    setbkcolor(RED);
    menu();
    cleardevice();
    closegraph();
    return 0;
}
void getString(char *inputString)
{
    int stringIndex=0;
    int xVal[255];
    char inputChar, outString[2];
    int oldColor;
    outString[1]=0;
    xVal[0]=getx();
    do
    {
        doCursor(1);
        inputChar=getch();
        doCursor(0);
        if (inputChar==0) getch();
        else
        {
            if (inputChar==8)   /* backspace */
            {
                oldColor=getcolor();
                stringIndex--;
                if (stringIndex<0) stringIndex=0;
                moveto(xVal[stringIndex],gety());
                setcolor(getbkcolor());
                outString[0]=inputString[stringIndex];
                if(cnt==1)
                    outtext("*");
                else
                    outtext(outString);
                moveto(xVal[stringIndex],gety());
                setcolor(oldColor);
            }
            else
            {
                if(inputChar!=13)//enter
                {
                    inputString[stringIndex]=inputChar;
                    outString[0]=inputChar;
                    if(cnt==1)
                        outtext("*");
                    else
                        outtext(outString);
                    stringIndex++;
                    xVal[stringIndex]=getx();
                }
            }
        }
    }
    while(inputChar!=13);
    inputString[stringIndex]=0;
}
void doCursor(int on)
{
    int curX,oldColor;

    char uBarStr[2] = { '_',0 };
    if (!on)
    {
        oldColor=getcolor();
        setcolor(getbkcolor());
    }

    curX=getx();
    outtext(uBarStr);
    moveto(curX,gety());
    if (!on) setcolor(oldColor);
}
void slow()
{
    int i;
    for(i=0; i<100000000; i++)
    {
    }
}
void pass()
{
    while(1)
    {
        int i,n,m,chk=0;
        char ar[10]= {"123456"};
        char input;
        cleardevice();
        setcolor(14);
        settextstyle(6,0,7);
        outtextxy(45 ,45,"     TRANSPORT HELPLINE");
        setcolor(10);
        settextstyle(8,0,5);
        outtextxy(100,180,"    ##Enter the password for access...");
        n=520;
        setcolor(WHITE);
        settextstyle(8,0,4);
        for(i=0; i<6; i++)
        {
            outtextxy(n,360,"_");
            n+=40;
        }
        n=520;
        for(i=0; i<6; i++)
        {
            input=getch();
            if(input==ar[i]) chk++;
            outtextxy(n,350,"*");
            n+=40;
        }
        if(chk==6)
        {
            settextstyle(6,0,5);
            outtextxy(40,570,"  Password correct!!!");
            slow();
            outtextxy(40,620,"  Loading");
            n=280;
            for(i=0; i<8; i++)
            {
                slow();
                outtextxy(n,620,".");
                n+=25;
            }
            slow();
            Admin();
        }
        else
        {
            settextstyle(6,0,4);
            outtextxy(40,565," Password Incorret :(");
            outtextxy(40,615," Press 0 to go to the Main Menu or any other key to Try Again:");
            char ee=getch();
            if(ee=='0')
                menu();
        }
    }
}
void password()
{
    while(1)
    {
        int i,n,m,chk=0,ans=0;
        char input;
        cleardevice();
        setcolor(14);
        settextstyle(6,0,7);
        outtextxy(45 ,45,"     TRANSPORT HELPLINE");
        setcolor(10);
        settextstyle(8,0,5);
        outtextxy(100,180,"    ##Enter the password for access...");
        outtextxy(100,400,"Password:");
        outtextxy(100,300,"Name:");
        settextstyle(8,0,4);
        setcolor(WHITE);
        rectangle(350,350,700,300);
        rectangle(350,450,700,400);
        moveto(370,310);
        n=520;
        setcolor(WHITE);
        settextstyle(8,0,4);
        char pass[50];
        char name[50];
        getString(name);
        moveto(370,410);
        cnt=1;
        getString(pass);
        cnt=0;
        ifstream read;
        read.open("excel.csv");
        string line;
        char ip[50];
        while(read.good())
        {
            getline(read,line,',');
            strcpy(ip,line.c_str());
            if(strcmp(ip,name)==0)
            {
                ans=1;
                //cout<<ip<<" "<<name<<" "<<ans<<endl;
                getline(read,line,',');
                strcpy(ip,line.c_str());
                if(strcmp(ip,pass)==0)chk=1;
                //cout<<ip<<" ABAB "<<pass<<" "<<chk<<endl;

            }
            else
                getline(read,line,',');
            getline(read,line,',');
            getline(read,line,',');
            getline(read,line,',');
            getline(read,line,'\n');
            if(chk==1 && ans==1) break;
        }

        if(chk==1 && ans==1)
        {
            settextstyle(6,0,5);
            outtextxy(40,570,"  Password correct!!!");
            slow();
            outtextxy(40,620,"  Loading");
            n=280;
            for(i=0; i<8; i++)
            {
                slow();
                outtextxy(n,620,".");
                n+=25;
            }
            slow();
            Bus_Company(name,pass);
        }
        else
        {
            settextstyle(6,0,4);
            outtextxy(40,565," Password Incorret :(");
            outtextxy(40,615," Press 0 to go to the Main Menu or any other key to Try Again");
            char ee=getch();
            if(ee=='0')
                menu();
        }
    }
}
void Admin()
{
    cleardevice();
    setcolor(14);
    settextstyle(6,0,7);
    outtextxy(45 ,40,"     TRANSPORT HELPLINE");
    setcolor(10);
    settextstyle(8,0,6);
    outtextxy(55,130,"         WELCOME TO Admin              ");
    settextstyle(6,0,4);
    outtextxy(155,255," See all Company");
    outtextxy(155,310," Main Menu");
    //outtextxy(155,365," Remove Company");
    settextstyle(6,0,5);
    setcolor(WHITE);
    outtextxy(70,640," Press your choice.......");
    setcolor(11);
    settextstyle(6,0,4);
    //outtextxy(90,365,"(2)");
    outtextxy(90,310,"(*)");
    outtextxy(90,255,"(1)");

    moveto(650,645);
    char input=getch();
    if(input=='*') menu();
    else if (input=='1')
        seeAdmin();
    else exit(0);
}
void seeAdmin()
{
    cleardevice();
    setcolor(14);
    settextstyle(6,0,7);
    outtextxy(45 ,40,"     TRANSPORT HELPLINE");
    setcolor(10);
    settextstyle(6,0,6);
    setcolor(WHITE);
    outtextxy(308,118,"Available Transport list:");
    ifstream read;
    read.open("excel.csv");
    string line;
    int n=250,j=1;
    char ip[50],i[2];
    settextstyle(6,0,4);
    char name[50];
    setcolor(10);
    settextstyle(6,0,4);
    outtextxy(55,200,"Bus Name");
    outtextxy(325,200,"Arrival Time");
    outtextxy(630,200," From");
    outtextxy(875,200," To");
    outtextxy(1100,200,"Total Cost");
    setcolor(WHITE);
    while(read.good())
    {
        setcolor(WHITE);
        getline(read,line,',');
        if(line=="") break;
        strcpy(ip,line.c_str());
        outtextxy(62,n,ip);
        getline(read,line,',');
        getline(read,line,',');
        strcpy(ip,line.c_str());
        outtextxy(330,n,ip);
        getline(read,line,',');
        strcpy(ip,line.c_str());
        outtextxy(640,n,ip);
        getline(read,line,',');
        strcpy(ip,line.c_str());
        outtextxy(882,n,ip);
        getline(read,line,',');
        strcpy(ip,line.c_str());
        outtextxy(1155,n,ip);
        getline(read,line,'\n');
        n+=50;
    }
    read.close();
    setcolor(10);
    outtextxy(40,640," Press 0 to go to the Admin or any other key to Menu:");
    char ee=getch();
    if(ee=='0')
        Admin();
    else menu();

}
void add()
{
    char name[30],pass[30],time[30],from[30],to[30],Cost[30],seat[30];
    cleardevice();
    setcolor(14);
    settextstyle(6,0,7);
    outtextxy(45 ,40,"     TRANSPORT HELPLINE");
    setcolor(10);
    settextstyle(8,0,6);
    outtextxy(55,130,"      Please Fill Up this Form");
    settextstyle(6,0,4);
    outtextxy(155,260," Company Name        :");
    setcolor(11);
    outtextxy(90,260,"(1)");
    moveto(600,260);
    getString(name);
    ifstream read;
    read.open("excel.csv");
    int recordFound =0;
    string line;
    while(read.good())
    {
        getline(read, line,',');
        if(line=="")break;
        char ip[50];
        strcpy(ip,line.c_str());
        getline(read, line,',');
        getline(read, line,',');
        getline(read, line,',');
        getline(read, line,',');
        getline(read, line,',');
        getline(read, line,'\n');
        if(strcmp(ip,name)==0 )
        {
            recordFound=1;
            break;
        }
    }
    if(recordFound == 1)
    {
        outtextxy(40,590,"The Company is already Registered.");
        outtextxy(40,640,"Press 0 to go to the Main Menu or any other key to add again:");
        char c=getch();
        if(c=='0')menu();
        else add();
    }
    read.close();
    settextstyle(6,0,4);
    setcolor(10);
    outtextxy(155,300," Password");
    outtextxy(155,340," Arrival Time");
    outtextxy(155,380," Departure from");
    outtextxy(155,420," Arrived At");
    outtextxy(155,460," Total Cost");
    outtextxy(155,500," Total Seat");
    for(int i=300; i<=500; i+=40)
    {
        outtextxy(543,i,":");
    }
    setcolor(11);
    outtextxy(90,300,"(2)");
    outtextxy(90,340,"(3)");
    outtextxy(90,380,"(4)");
    outtextxy(90,420,"(5)");
    outtextxy(90,460,"(6)");
    outtextxy(90,500,"(7)");
    moveto(600,300);
    getString(pass);
    moveto(600,340);
    getString(time);
    moveto(600,380);
    getString(from);
    moveto(600,420);
    getString(to);
    moveto(600,460);
    getString(Cost);
    moveto(600,500);
    getString(seat);
    ofstream chk1;
    chk1.open("excel.csv",ios::app);
    chk1<<name<<",";
    chk1<<pass<<",";
    chk1<<time<<",";
    chk1<<from<<",";
    chk1<<to<<",";
    chk1<<Cost<<",";
    chk1<<seat<<"\n";
    chk1.close();
    settextstyle(6,0,4);
    setcolor(WHITE);
    outtextxy(40,580," Added Successfully :)");
    outtextxy(40,630," Press 0 to go to the Main Menu or any other key to exit:");
    char ee=getch();
    if(ee=='0')
        menu();
    else exit(0);

}
void see(char* name,char* pass)
{
    cleardevice();
    setcolor(14);
    settextstyle(6,0,7);
    outtextxy(45 ,40,"     TRANSPORT HELPLINE");
    setcolor(WHITE);
    settextstyle(8,0,5);
    outtextxy(120,125,"Available Transport list for this Company:");
    settextstyle(6,0,4);
    setcolor(10);
    settextstyle(6,0,4);
    outtextxy(100,200,"Arrival time");
    outtextxy(470,200,"From");
    outtextxy(770,200,"To");
    outtextxy(985,200," Total Cost");
    setcolor(WHITE);
    ifstream read;
    read.open("excel.csv");
    string line;
    int n=250;
    char ip[50];
    while(read.good())
    {
        getline(read,line,',');
        if(line=="") break;
        strcpy(ip,line.c_str());
        if(strcmp(ip,name)==0)
        {
            setcolor(WHITE);
            getline(read,line,',');
            getline(read,line,',');
            strcpy(ip,line.c_str());
            outtextxy(100,n,ip);
            getline(read,line,',');
            strcpy(ip,line.c_str());
            outtextxy(471,n,ip);
            getline(read,line,',');
            strcpy(ip,line.c_str());
            outtextxy(771,n,ip);
            getline(read,line,',');
            strcpy(ip,line.c_str());
            outtextxy(1065,n,ip);
            getline(read,line,'\n');
            n+=50;
        }
        else
        {
            getline(read,line,',');
            getline(read,line,',');
            getline(read,line,',');
            getline(read,line,',');
            getline(read,line,',');
            getline(read,line,'\n');
        }
    }
    read.close();
    settextstyle(6,0,4);
    setcolor(10);
    outtextxy(50,633," Press 0 to go to the Bus Company or any other key to exit:");
    char ee=getch();
    if(ee=='0')
        Bus_Company(name,pass);
    else exit(0);
}

void Bus_Company(char* name,char* pass)
{
    cleardevice();
    setcolor(14);
    settextstyle(6,0,7);
    outtextxy(45 ,40,"     TRANSPORT HELPLINE");
    setcolor(10);
    settextstyle(8,0,6);
    outtextxy(55,130,"              WELCOME              ");
    settextstyle(6,0,4);
    outtextxy(155,255," Add new route");
    //outtextxy(155,310," Remove route");
    outtextxy(155,310," See Information");
    outtextxy(155,365," Main Menu");
    settextstyle(6,0,5);
    setcolor(WHITE);
    outtextxy(70,640," Press your choice.......");
    setcolor(11);
    settextstyle(6,0,4);
    outtextxy(90,255,"(1)");
    outtextxy(90,310,"(2)");
    outtextxy(90,365,"(*)");
    //outtextxy(90,420,"(*)");
    moveto(650,645);
    char input=getch();
    if(input=='*') menu();
    if(input=='1') route(name,pass);
    if(input=='2') see(name,pass);
    else exit(0);
}
void route(char * name,char* pass)
{
    cleardevice();
    setcolor(14);
    settextstyle(6,0,7);
    outtextxy(45 ,40,"     TRANSPORT HELPLINE");
    setcolor(10);
    settextstyle(8,0,6);
    outtextxy(55,130,"      Please Fill Up this Form");
    settextstyle(6,0,4);
    outtextxy(155,260,"  Arrival Time ");
    outtextxy(155,300,"  Departure from ");
    outtextxy(155,340,"  Departure To  ");
    outtextxy(155,380,"  Total Cost ");
    outtextxy(155,420,"  Total seat");
    for(int i=260; i<=420; i+=40)
    {
        outtextxy(546,i,":");
    }
    setcolor(11);
    outtextxy(90,260,"(1)");
    outtextxy(90,300,"(2)");
    outtextxy(90,340,"(3)");
    outtextxy(90,380,"(4)");
    outtextxy(90,420,"(5)");
    char time[30],from[30],to[30],Cost[30],seat[30];
    moveto(600,260);
    getString(time);
    moveto(600,300);
    getString(from);
    moveto(600,340);
    getString(to);
    moveto(600,380);
    getString(Cost);
    moveto(600,420);
    getString(seat);
    ofstream chk;
    chk.open("excel.csv",ios::app);
    chk<<name<<",";
    chk<<pass<<",";
    chk<<time<<",";
    chk<<from<<",";
    chk<<to<<",";
    chk<<Cost<<",";
    chk<<seat<<"\n";
    chk.close();
    settextstyle(6,0,4);
    setcolor(10);
    outtextxy(40,565," Added Successfully :)");
    outtextxy(40,615," Press 0 to go to the Bus Company or any other key to exit:");
    char ee=getch();
    if(ee=='0')
        Bus_Company(name,pass);
    else exit(0);
}
void inside_city()
{
    cleardevice();
    setcolor(14);
    settextstyle(6,0,7);
    outtextxy(45 ,40,"     TRANSPORT HELPLINE");
    setcolor(10);
    settextstyle(8,0,6);
    outtextxy(55,130,"          WELCOME TO USER");
    settextstyle(6,0,4);
    outtextxy(155,260,"Input Start Point  :");
    outtextxy(155,320,"Input finish Point :");
    setcolor(WHITE);
    moveto(500,260);
    char from[50],to[50];
    getString(from);
    moveto(500,320);
    getString(to);
    ifstream read;
    read.open("excel.csv");
    string line;
    int n,chk=0;
    char ip[50];
    int num=0;
    char name[50],time[50],Cost[50];
    //setcolor(BLACK);
    setfillstyle(1,RED);
    bar(45,115,1300,560);
    a=295;
    while(read.good())
    {
        getline(read,line,',');
        strcpy(name,line.c_str());
        if(line=="")break;
        getline(read,line,',');
        getline(read,line,',');
        strcpy(time,line.c_str());
        getline(read,line,',');
        strcpy(ip,line.c_str());
        if(strcmp(ip,from)==0) chk++;
        getline(read,line,',');
        strcpy(ip,line.c_str());
        if(strcmp(ip,to)==0)chk++;
        getline(read,line,',');
        strcpy(Cost,line.c_str());
        getline(read,line,'\n');
        if(chk==2)
        {
            setcolor(10);
            settextstyle(6,0,4);
            outtextxy(55,240,"Name of the Bus");
            outtextxy(455,240,"Approximate Arrival Time");
            outtextxy(1010,240,"Total Cost");
            setcolor(WHITE);
            outtextxy(70,a,name);
            outtextxy(540,a,time);
            outtextxy(1067,a,Cost);
            a+=50;
            num=1;
        }
        chk=0;
    }
    read.close();
    settextstyle(6,0,5);
    setcolor(10);
    if(!num)
    {
        setcolor(11);
        outtextxy(70,350,"Sorry :( ");
        outtextxy(70,410,"There is no transport registered for this route");
    }
    setcolor(10);
    settextstyle(6,0,4);
    outtextxy(40,630," Press 0 to go to the Main Menu or any other key to Try Again");
    if(num)
    {
        settextstyle(6,0,5);
        setcolor(WHITE);
        outtextxy(212,150,"Available Transport list for this route:");
    }
    char ee=getch();
    if(ee=='0')
        menu();
    else inside_city();
}
void outside_city()
{
    cleardevice();
    setcolor(14);
    settextstyle(6,0,7);
    outtextxy(45 ,40,"     TRANSPORT HELPLINE");
    setcolor(10);
    settextstyle(8,0,6);
    outtextxy(55,130,"          WELCOME TO USER");
    settextstyle(6,0,4);
    outtextxy(155,260,"Input Start Point  :");
    outtextxy(155,320,"Input finish Point :");
    setcolor(WHITE);
    moveto(500,260);
    char from[50],to[50];
    getString(from);
    moveto(500,320);
    getString(to);
    ifstream read;
    read.open("excel.csv");
    string line;
    int n,chk=0,ava=0;
    char ip[50];
    char buf[50];
    string st;
    int num=0;
    char name[50],pass[50],time[50],cost[50],seat[50];
    setfillstyle(1,RED);
    bar(45,115,1300,560);
    a=295;
    while(read.good())
    {
        getline(read,line,',');
        strcpy(name,line.c_str());
        getline(read,line,',');
        getline(read,line,',');
        strcpy(time,line.c_str());
        getline(read,line,',');
        strcpy(ip,line.c_str());
        if(strcmp(ip,from)==0) chk++;
        getline(read,line,',');
        strcpy(ip,line.c_str());
        if(strcmp(ip,to)==0)chk++;
        getline(read,line,',');
        strcpy(cost,line.c_str());
        getline(read,line,'\n');
        strcpy(seat,line.c_str());
        if(chk==2)
        {
            setcolor(10);
            settextstyle(6,0,4);
            outtextxy(55,240,"Name of the Bus");
            outtextxy(473,240," Arrival Time");
            outtextxy(791,240,"Total  Seats");
            outtextxy(1110,240,"Total Cost");
            setcolor(WHITE);
            outtextxy(70,a,name);
            outtextxy(480,a,time);
            outtextxy(810,a,seat);
            outtextxy(1167,a,cost);
            a+=50;
            num=1;
        }
        chk=0;
    }
    read.close();
    settextstyle(6,0,5);
    setcolor(10);
    if(!num)
    {
        setcolor(11);
        outtextxy(70,350,"Sorry :( ");
        outtextxy(70,410,"There is no transport registered for this route");
    }
    if(num)
    {
        settextstyle(6,0,5);
        setcolor(WHITE);
        outtextxy(212,150,"Available Transport list for this route:");
        setcolor(10);
        settextstyle(6,0,4);
        outtextxy(40,500," Do you want to buy tickets?   y|n");
        moveto(40,550);
        char a[2];
        getString(a);
        if(a[0]=='y')
        {
            setfillstyle(1,RED);
            bar(35,115,1300,690);
            outtextxy(55,240,"Bus name           :");
            outtextxy(55,300,"How many tickets   :");
            setcolor(WHITE);
            moveto(465,240);
            char bus[50];
            getString(bus);
            moveto(465,300);
            char ticket[50];
            getString(ticket);
            int t;
            sscanf(ticket,"%d",&t);
            ifstream read;
            read.open("excel.csv");
            string line;
            int fina=0;
            while(read.good())
            {
                fina=0;
                getline(read,line,',');
                strcpy(name,line.c_str());
                if(strcmp(name,bus)==0) fina++;
                getline(read,line,',');
                strcpy(pass,line.c_str());
                getline(read,line,',');
                strcpy(time,line.c_str());
                getline(read,line,',');
                strcpy(ip,line.c_str());
                if(strcmp(ip,from)==0) fina++;
                getline(read,line,',');
                strcpy(ip,line.c_str());
                if(strcmp(ip,to)==0) fina++;
                getline(read,line,',');
                strcpy(cost,line.c_str());
                getline(read,line,'\n');
                strcpy(seat,line.c_str());
                if(fina==3)
                {
                    break;
                }
            }
            read.close();
            int u;
            if(fina!=3)
            {
                setcolor(11);
                outtextxy(45,570,"This Bus Company is not available in this route!!");
            }
            if(fina==3)
            {
                ava++;
                sscanf(seat,"%d",&u);
                u=u-t;
                if(u<0)
                {
                    setcolor(11);
                    outtextxy(45,570,"Sorry. There is not enough amount of seats");

                }
                else
                {
                    ava++;
                    snprintf(buf, sizeof(buf), "%d", u);
                    string st1(buf);
                    st=st1;
                    if(u>=0)
                    {
                        ofstream chk1;
                        chk1.open("excel.csv",ios::app);
                        chk1<<name<<",";
                        chk1<<pass<<",";
                        chk1<<time<<",";
                        chk1<<from<<",";
                        chk1<<to<<",";
                        chk1<<cost<<",";
                        chk1<<buf<<"\n";
                        chk1.close();
                    }
                    ifstream fin;
                    fin.open("excel.csv");
                    ofstream fout;
                    fout.open("temp.csv");
                    int i;
                    while(getline(fin,line))
                    {

                        string s="";
                        string x="";
                        string a="";
                        string b="";
                        int j=0,k=0;
                        for(i=0;; i++)
                        {
                            if(line[i]==',') break;
                            else s+=line[i];
                        }
                        j=0;
                        for(i=0; i<line.size(); i++)
                        {
                            if(j==3 && line[i]!=',') a+=line[i];
                            if(line[i]==',') j++;
                        }
                        j=0;
                        for(i=0; i<line.size(); i++)
                        {
                            if(j==4 && line[i]!=',') b+=line[i];
                            if(line[i]==',') j++;
                        }
                        k=line.size();
                        for(i=k-1;; i--)
                        {
                            if(line[i]==',') break;
                            x+=line[i];
                        }
                        reverse(x.begin(),x.end());
                        if(s!=bus ||(s==bus && x==st && a==from && b==to)|| (s==bus && a!=from && b!=to ))
                        {
                            fout<<line<<endl;
                        }
                    }

                    fin.close();
                    fout.close();
                    int result;
                    remove("excel.csv");
                    char oldname[] ="temp.csv";
                    char newname[] ="excel.csv";
                    result= rename( oldname , newname );
                }
            }
        }
    }

    settextstyle(6,0,4);
    if(ava==2)
    {
        outtextxy(45,570,"Ticket Booked successfully");
    setcolor(10);
    outtextxy(40,630," Press 0 to go to the Main Menu or any other key to Exit");

    char ee=getch();
    if(ee=='0')
        menu();
    else exit(0);
    }
    setcolor(10);
    outtextxy(40,630," Press 0 to go to the Main Menu or any other key to Try Again");

    char ee=getch();
    if(ee=='0')
        menu();
    else outside_city();
}

void user()
{
    cleardevice();
    setcolor(14);
    settextstyle(6,0,7);
    outtextxy(45 ,40,"     TRANSPORT HELPLINE");
    setcolor(10);
    settextstyle(8,0,6);
    outtextxy(55,130,"          WELCOME TO USER");
    settextstyle(6,0,4);
    outtextxy(155,270,"Inside Dhaka City  ");
    outtextxy(155,330,"Outside City ");
    settextstyle(6,0,5);
    setcolor(WHITE);
    outtextxy(70,640,"Press your choice.......");
    setcolor(11);
    settextstyle(6,0,4);
    outtextxy(90,270,"(1)");
    outtextxy(90,330,"(2)");

    char ee=getch();
    if(ee=='1')
        inside_city();
    else if (ee=='2')
        outside_city();
    else
    {
        user();
    }
}
void output()
{
    settextstyle(6,0,5);
    setcolor(WHITE);
    outtextxy(70,640,"Choose the correct option or press 0 to exit");
    char input=getch();
    if(input=='1') user();
    else if(input=='2') pass();
    else if(input=='4') password();
    else if(input=='3') add();
    else if(input=='0')exit(0);
    else
        output();
}
void menu()
{
    cleardevice();
    setcolor(14);
    settextstyle(6,0,7);
    outtextxy(45 ,40,"     TRANSPORT HELPLINE");
    setcolor(10);
    settextstyle(8,0,6);
    outtextxy(40,130,"      WELCOME TO THE MAIN MENU");
    settextstyle(6,0,4);
    outtextxy(160,255,"User");
    outtextxy(160,310,"Admin");
    outtextxy(160,365,"Add Company");
    outtextxy(160,420,"Bus Company");
    settextstyle(6,0,5);
    setcolor(WHITE);
    outtextxy(70,640,"Press your choice.......");
    setcolor(11);
    settextstyle(6,0,4);
    outtextxy(90,255,"(1)");
    outtextxy(90,310,"(2)");
    outtextxy(90,365,"(3)");
    outtextxy(90,420,"(4)");
    moveto(650,645);
    char input=getch();
    if(input=='1') user();
    else if(input=='2') pass();
    else if(input=='4') password();
    else if(input=='3') add();
    else
        output();
}

