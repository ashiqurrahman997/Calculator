/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
	calculator project by ashiq
*/
# include "iGraphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char str[100000], str2[100000],str3[100000],str4[100000],r[10000],p[1000000],p1[100000],ans[]="Ans: ",str5[100]="BIG INTEGER CALCULATOR";
char M[900][900],strm[9000],stn[100]="0";
char sc[]="(saved in memory)";
int a=0,b=430,c=700,d=430,pl,moder2,moder3,mode5=0,cnt=0,m4=0,m5=0,mt=0,ad=0,sp=0,sp1=1,sw=0;
int sd=0 ,len,sbb,mlt,dvd,my=0,lg,sq,pw,lon,rt,bm,rt1;
int mode,mode1,modes,modea,moder,moder1,mode3,mode4,modem;
int px=70,py=300,m_x=400,m_y=290,m_x1=50,m_y1=290,bx=20,by=265,tx=px-50,ty=py+35,tp=860;
int cx=0,cx1=50,cy=250,cy1=290,flag=0;
int nm=0,o=0;
char s[1000];
int top=-1;
int arr[1000];

int top1 = -1;


void drawTextBox()
{
	iSetColor(250,0,150);
	// screen boader
	iRectangle(8,py+18,884,196);
	iRectangle(12,py+22,876,188);
	iSetColor(0,220,255);

	// page boder
	//iFilledRectangle(5,5,890,590);
	iRectangle(4,5,894,590);
	// screen background 
	if(mode5==1)
	{
		iSetColor(0,150,200);
		iFilledRectangle(5,5,890,590);
	}
	if(mode5==2)
	{
		iSetColor(0,0,100);
		iFilledRectangle(5,5,890,590);
	}
	if(mode5==3)
	{
		iSetColor(255,100,100);
		iFilledRectangle(5,5,890,590);
	}
	if(mode5==4)
	{
		iSetColor(100,250,100);
		iFilledRectangle(5,5,890,590);
	}


	// keyboard boarder
	iSetColor(0,220,255);
	//iFilledRectangle(7,py-170,393,160);
	// menu
	iRectangle(500,py-60,350,40);
	iRectangle(500,py-110,350,40);
     iRectangle(500,py-160,350,40);
	 iSetColor(200,0,255);
	 iText(580,py-45, "BIG INTEGER CALCULATOR");
	 iText(605,py-95, "INFIX CALCULATOR");
	  iText(580,py-145, "CHANGE BACKGROUND COLOR");

       if(ad!=1)
	{
		iSetColor(50,250,250);
	  iFilledRectangle(503,py-56,344,33);
	}
	  if(ad==1)
	{
		iSetColor(50,250,250);
	  iFilledRectangle(503,py-106,344,33);

	}
	
	iSetColor(0,0,255);
	//input boarder
	//iRectangle(tx-5,ty-5,tp+10,40+10);
	// iSetColor(0,0,255);
	//iRectangle(tx-5,ty-5+60,tp+10,40+10);

	iRectangle(tx-5,ty-5+120,tp+10,40+10);

	iSetColor(255,255,255);
	iFilledRectangle(tx,ty,tp,40);
	iFilledRectangle(tx,ty+60,tp,40);
	iFilledRectangle(tx,ty+120,tp,40);
	//iFilledRectangle(px-10,py-100,20,30);

	//vetical line
	   iSetColor(150,150,200);
	iLine(7,py-10,m_x,m_y);	
	iLine(7,py-50,m_x,m_y-40);
	iLine(7,py-90,m_x,m_y-80);
	iLine(7,py-130,m_x,m_y-120);
	iLine(7,py-170,m_x,m_y-160);

	
	//iLine(5,py-190,898,m_y-180);
	//iLine(7,py-220,m_x,m_y-210);
	//iLine(7,py-250,m_x,m_y-240);
	//iLine(7,py-280,m_x,m_y-270);


	//horijental line
	iLine(m_x1-43,m_y1,m_x1-43,130);
	iLine(m_x1,m_y1,m_x1,130);
	iLine(m_x1+50,m_y1,m_x1+50,130+40);
//	iSetColor(0,255,0);
	iLine(m_x1+100,m_y1,m_x1+100,130+40);
		  
	iLine(m_x1+150,m_y1,m_x1+150,130+80);
	iLine(m_x1+150,130+40,m_x1+150,130);
	iLine(m_x1+200,m_y1,m_x1+200,130+40);
	iLine(m_x1+250,m_y1,m_x1+250,130);
	//iLine(m_x1+300,m_y1,m_x1+300,130);
	iLine(m_x1+350,m_y1,m_x1+350,130);
	//button
	//row1
     iSetColor(0,0,255);
	// iShowBMP(20,30, "smurf.bmp");

	iText(bx,by,"1");
	iText(bx+50,by,"2");
	iText(bx+100,by,"3");

	iSetColor(255,0,200);
	iText(bx+150,by,"+");
	iText(bx+200,by,"-");
	  iSetColor(255,0,0);
	iText(bx+245,by,"OFF");

     iText(bx+300,by,"MAXIMUM");
     iText(bx+300,by-40,"MINIMUM");
	 iText(bx+300,by-80,"AVERAGE");
	 iText(bx+300,by-110,"STANDER");
	  iText(bx+290,by-127,"DEVIATION");
	//row2
	 iSetColor(0,0,255);
	iText(bx,by-40,"4");
	iText(bx+50,by-40,"5");
	iText(bx+100,by-40,"6");

    iSetColor(255,0,255);
	iText(bx+150,by-40,"*");
	iText(bx+200,by-40,"/");
	 iSetColor(255,0,0);
	iText(bx+245,by-37,"AC");
	//iText(bx+300,by-40,"sqrt");
	//iText(bx+250,by-40,"6");

	 // row3
    iSetColor(0,0,255);
	iText(bx,by-80,"7");
	iText(bx+50,by-80,"8");
	iText(bx+100,by-80,"9");
	iSetColor(255,0,0);
   	iText(bx+146,by-78,"BackSpace");
	//iText(bx+193,by-80,"M(");
	iText(bx+232,by-78,"M+(");
 


    //   row 4
	iSetColor(0,0,255);
	iText(bx,by-120,"0");
	//iText(bx+50,by-117,".");
	iText(bx+80,by-120,"Enter");
	iText(bx+210,by-120,"Sound");
	//iText(bx+225,by-120,"Ans");
	
	//drawbutton();
	//iSetColor(0,350,300);
	//iFilledRectangle(0,py-170,150,120);
}
//m++
void Max(char a[900][900],int n)
{
    int i,k;
	char sk[100];
    int temp = atoi(a[0]);

    for(i=1;i<n;i++)
    {
        k= atoi(a[i]);
        if(temp<k)
            temp =k;
    }
    printf("The Maximum value is = %d\n",temp);
	sprintf(sk,"%d",temp);
	puts(sk);
	strcpy(str3,sk);
	mode3=1;
}
void Ave(char a[900][900] ,int n)
{
    double ave , sum=0,s;
    // s=atoi
    int i,j;
	char sk[900];

   //  puts(a[0]);
  //  puts (a[1]);

    for(i=0;i<n ;i++)
    {
       sum=sum+ atoi(a[i]);
    //   puts(a[i]);
    }

    ave=sum/n;
    printf("\nThe Average is =  %f\n",ave);
	 sprintf(sk,"%f",ave);
	puts(sk);
	strcpy(str3,sk);
	mode3=1;


}
void Min(char a[900][900],int n)
{
    int temp=atoi(a[0]);
	int i,j;
	char sk[900];
    for(i=1;i<n;i++)
    {
        if(temp>atoi(a[i]))
            temp=atoi(a[i]);
    }
    printf("The Minimum value is = %d\n",temp);
	 sprintf(sk,"%d",temp);
	puts(sk);
strcpy(str3,sk);
	mode3=1;


}
void stdv(char data[900][900], int n)
{
    float mean=0.0, sum_deviation=0.0,st;
    int i;
	char sk[9000];
    for(i=0; i<n;++i)
    {
        mean+=atoi(data[i]);
    }
    mean=mean/n;
    for(i=0; i<n;++i)
    sum_deviation+=(atoi(data[i])-mean)*(atoi(data[i])-mean);
	st= sqrt(sum_deviation/n);
   printf(" Stander division %f\n", st);    
	// return 0;
   sprintf(sk,"%f",st);
	puts(sk);
	strcpy(str3,sk);
	mode3=1;

}










 // infx funtion

void push1(int data)
{
if(top1 == -1)
{
top1 = 0;
arr[top1] = data;
return;
}

top1=top1+1;
arr[top1]=data;

}

int pop1()
{
int temp;
if(top1 == -1)
{
printf("Stack Underflow!!!");
return 0;
}
else{
temp = arr[top1];
top1 = top1-1;
return temp;
}
}


int clc( char* expression)
{

char exp[1000];
int l,q=0;
l=strlen(expression);
int i = 0;
int temp1, temp2, temp3;
for(i=0;i<l;i++) { if(expression[i]>='0' && expression[i]<= '9')
{
push1((expression[i])-'0');
}
else
{
temp1=pop1();
temp2=pop1();
switch(expression[i])
{
case '+':
temp3=temp1+temp2;
push1(temp3);
break;
case '-':
temp3=temp2-temp1;
push1(temp3);
break;
case '*':
temp3=temp2*temp1;
push1(temp3);
break;
case '/':
temp3=temp2/temp1;
push1(temp3);
break;

}
}
}
temp1 = pop1();
i=0;
printf("\nEvaluation of the given postfix expression is %d\n",temp1);
 while(1)
 {
	 if(temp1<0)
	 {
		// exp[i++]='-';
		 q=1;
		 temp1=temp1*-1;
	 }

     exp[i++]=temp1%10+'0';
     temp1=temp1/10;
     if(temp1==0)
        break;
 }
 if(q)
	 exp[i++]='-';

    exp[i]='\0';
  puts(exp);
  strcpy(str3,strrev(exp));
  mode3=1;
return 0;

}
void push(char elem)
{
    s[++top]=elem;
}

char pop()
{
    return(s[top--]);
}

int pr(char elem)
{
    switch(elem)
    {
    case '#': return 0;
  //  / case '(': return 1;
    case '+': return 2;
    case '-': return 1;
    case '*': return 5;
    case '/': return 3;
    }
}

void ixtopx( char infx[900] )
{
    char pofx[500],ch,elem;
    int i=0,k=0;

   // scanf("%s",infx);
    push('#');


    while ( ( ch= infx[i++]) != '\0')
    {
    if (isalnum(ch))
        pofx[k++]=ch;
    else
    {
        while( pr(s[top]) >= pr(ch) )
      pofx[k++]=pop();

        push(ch);
    }
    }
    while( s[top] != '#')
  pofx[k++]=pop();
    pofx[k]='\0';



    printf("\n\nGiven Infix Expn: %s  Postfix Expn: %s\n",infx,pofx);
     clc(pofx);
	 strcpy(str2,pofx);
	 mode=1;
    

}


//function
int rc( char string[100], char st[100])
{
    char sum1[100];
    int k=1,k1=1,i=0,j=1;

        if(string[0]=='-')
        {
            i=0;j=0;
        strcpy(p,string);
                   while(!p[i]=='\0')
		  {
			  p[j]=p[i+1];
			  i++;
			  j++;
			 // if(p1[i]=='\0')
				//  break;
		  }
        k=-1;
        }
        else
        strcpy(p,string);


        if(st[0]=='-')
        {
          strcpy(p1,st);
          i=0;j=0;
           while(!p1[i]=='\0')
		  {
			  p1[j]=p1[i+1];
			  i++;
			  j++;
			 // if(p1[i]=='\0')
				//  break;
		  }

        //  p1[0]='0';
        k1=-1;
        }
        else
            strcpy(p1,st);

       puts(p);
       puts(p1);
       printf("%d\n",k*k1);
       return k*k1;

}



int chrtoint(char a){
int i;
for (i = 48; i<=57; i++)
if (toascii(i)==a) return i-48;
return 0;
}

void add( char* n1,char* n2,int r){
char sum1[1000];
int rs[1000];
int c1, c2;


int i,j,k=0,m, cmax, sum;
c1 = strlen(n1);
c2 = strlen(n2);

strrev(n1);
strrev(n2);

cmax = c1;
if(c1<c2){
cmax = c2;
}

m=0;
for(i=0; i< cmax; i++){
if(c1==c2 || (i < c1 && i < c2)){
sum = m+chrtoint(n1[i])+chrtoint(n2[i]);
}else if(i >=c1){
sum = m+chrtoint(n2[i]);
}else if(i >=c2){
sum = m+chrtoint(n1[i]);
}
rs[i] = sum%10;
m = sum/10;
}

if(m){
rs[i]=m;
i++;
}

printf("\nResult: ");
for(j=0,k=0; j < i; j++){
     sum1[k++]= rs[i-j-1]+'0';
printf("%d", rs[i-j-1]);
}
sum1[k]='\0';
puts(sum1);
if(r==-1)
	{
	strcat(strrev(sum1),"-");
	strrev(sum1);
	strcpy(str3,sum1);
	mode3=1;
}
	else
		{
			strcpy(str3,sum1);
	mode3=1;
	}
}





void sub( char num1[100], char num2[1000],int r)
{
   char res[1000+1] ,temp[1000+1];

   // scanf("%s %s", num1, num2);

    int len1 = strlen(num1) ;
    int len2 = strlen(num2) ;
    int  j,flag=0;

    if( len1 == len2 ){

        if( num2[0] > num1[0] )
			flag = 1;
	
        else if( num2[0] == num1[0]){
            for( j=1; j<len1; j++){
                if( num2[j] > num1[j]){
                    flag = 1;
                    break;
                }
            }
        }
	}

    else if( len1 < len2 ){
        flag = 1;
    }

    if(flag){
        strcpy(temp,num1);
        strcpy( num1,num2);
        strcpy(num2,temp);
    }


    int dig, dig1, dig2, carry = 0;
    int i=0;
    len1 = strlen(num1) -1;
    len2 = strlen(num2)-1 ;

    while(1){

        if( len1<0 && len2<0) break;

        if(len1<0)  dig1 = 0;
        else
            dig1 = num1[len1--] - '0';

        if (len2<0){
            dig2 = carry + 0;
            carry = 0;
        }
        else{
            dig2 = num2[len2--] - '0' + carry;
            carry = 0;
        }

        if(dig1<dig2){
            dig1 +=10;
            carry =1;
        }

        dig = dig1 - dig2;
        res[i++] = dig + '0';
    }

    if(flag==1 && rt!=-1 && rt!=2)
        res[i++] = '-';

	else if(flag!=1 && rt==2)
        res[i++] = '-';
   
	else if(flag!=1 && rt==-1)
       res[i++] = '-';
	//else 
      //  if(flag==1)
      //  res[i++] = '-';


    res[i]='\0';
    strrev(res);
    puts(res);
	//r=r*-1;
 /* if(r==-1)
	{
		strcat(strrev(res),"-");
	strrev(res);
	strcpy(str3,res);
	mode3=1;
}
	else
		
			strcpy(str3,res);
	mode3=1;
//	}
    */
	strcpy(str3,res);
	mode3=1;
}



void mul(char a[100000],char b[100000],int kl)
{
     char mul[100000];
    char c[100000];
    char temp[100000];
    long long la,lb;
    int i,j,k=0,x=0,y;
    long int r=0;
    long sum = 0;
    la=strlen(a)-1;
        lb=strlen(b)-1;

        for(i=0;i<=la;i++){
                a[i] = a[i] - '0';
        }

        for(i=0;i<=lb;i++){
                b[i] = b[i] - '0';
        }

    for(i=lb;i>=0;i--){
         r=0;
         for(j=la;j>=0;j--){
             temp[k++] = (b[i]*a[j] + r)%10;
             r = (b[i]*a[j]+r)/10;
         }
         temp[k++] = r;
         x++;
         for(y = 0;y<x;y++){
             temp[k++] = 0;
         }
    }

    k=0;
    r=0;
    for(i=0;i<la+lb+2;i++){
         sum =0;
         y=0;
         for(j=1;j<=lb+1;j++){
             if(i <= la+j){
                 sum = sum + temp[y+i];
             }
             y += j + la + 1;
         }
         c[k++] = (sum+r) %10;
         r = (sum+r)/10;
    }
    c[k] = r;
    j=0;
    for(i=k-1;i>=0;i--){
         mul[j++]=c[i] + 48;
    }
    mul[j]='\0';
    puts(mul);


	if(kl==-1)
	{
	strcat(strrev(mul),"-");
	strrev(mul);
	strcpy(str3,mul);
	mode3=1;
}
	else
		{
	strcpy(str3,mul);
	mode3=1;
	}
}

void div(char a[],unsigned long b,int kl){
     char c[1000];
    int la;
    int i,k=0,flag=0;
    unsigned long temp=1;
    la=strlen(a);
	if(a[0]== '0')
      {
			strcpy(str3,"0");
	mode3=1;
	}
	
	else   if(b!=0)
	{
    for(i=0;i<=la;i++){
         a[i] = a[i] - 48;
    }

    temp = a[0];
    for(i=1;i<=la;i++){
         if(b<=temp){
             c[k++] = temp/b;
             temp = temp % b;
             temp =temp*10 + a[i];
            flag=1;

         }
         else{
             temp =temp*10 + a[i];
               if(flag==1)
                 c[k++] = 0;
         }
    }

    for(i=0;i<k;i++){
         c[i]=c[i]+48;
    }
    c[i]= '\0';
  

	if(kl==-1)
	{
	strcat(strrev(c),"-");
	strrev(c);
	strcpy(str3,c);
	mode3=1;
}
	else
		{
	strcpy(str3,c);
	mode3=1;
	}
	}
	else
		mt=1;
}


/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here

	iClear();
	//	
	drawTextBox();
	sprintf(stn,"%d",nm);
	iSetColor(250,0,0);
	strcat(stn,")");
	iText(bx+255,by-78,stn);
	if(mode == 1&& modem==0)
	{
		//strcat("Ans: ",str);
		iSetColor(0,0,250);
		iText(tx+5,ty+10+60,str2);
		iRectangle(tx-5,ty-5+60,tp+10,40+10);
		//mode=0;
	}
	if(mode1==1&& modem==0)
	{
	iSetColor(0,0,255);
	iText(tx+5,ty+10+120, str);
     }
	if(mode3==1)
	{
	iSetColor(255,0,0);
    // strcat(ans,str3);
	// strcpy(str3,ans);
	iText(tx+5,ty+10,ans);
	iText(tx+40,ty+10,str3);
	iRectangle(tx-5,ty-5,tp+10,40+10);
     }

	if(modes==1&&sd<1)
	{
	iSetColor(255,0,0);
	iText(tx+500,ty+30+120,sc);
    

     }
	if(modes==1&&sd==1)
	{
	iSetColor(255,0,0);
	iText(tx+500,ty+30+60,sc);
    

     }
	if(modes==1 && sd>=2)
	{
	iSetColor(255,0,0);
	iText(tx+570,ty+30,sc);
   
     }
	
	 if(ad==1&& modem==0)
	{
	iSetColor(0,0,255);
	iText(tx+250,ty+30+120, " Enter an Infix Expretion");
	
     }
	
  if(ad!=1 && modem==0)
	{
	iSetColor(0,0,255);
	iText(tx+250,ty+30+120, " Enter 1st number");
	
     }
	 if(moder2==1&&ad!=1&&modem==0)
	{
	iSetColor(0,0,255);
	iText(tx+250,ty+30+60, " Enter 2nd number");
	
     }
	 if(mode4==1)
	{
	iSetColor(0,0,255);
	iText(tx+250,ty+30+60, " The Postfix Expretion of the given Infix Expretion");
	iSetColor(255,0,0);
	iText(tx+260,ty+30, "The Solution of the Infix Expretion :");
	
     }
	
	  if(modem==1)
	{
	iSetColor(255,0,0);
	iText(tx+260,ty+30, strm);
	//iSetColor(0,0,255);
	iRectangle(tx-5,ty-5,tp+10,40+10);
     }

	 if(sd>=2&&ad!=1&& modem==0)
	{
	iSetColor(255,0,0);
	iText(tx+260,ty+30, "Enter an operrator :");
	//iSetColor(0,0,255);
	iRectangle(tx-5,ty-5,tp+10,40+10);
     }

	  if(mt==1&&modem==0)
	{
	iSetColor(255,0,0);
	 strcpy(str3,"Math Error !!!");
	iText(tx+40,ty+10,str3 );
	//iSetColor(0,0,255);
	iRectangle(tx-5,ty-5,tp+10,40+10);
     }
	
	  if(moder==1 && modem==0)
	{
	iSetColor(2550,0,0);
	iText(tx+500,ty+30, r);
	  // strcpy(r,"\0");
     }
	  
	 // iText(250,400+110, " << BIG INTEGER CALCULATOR >>");
		
    if(m5==0)
	{iDelayMS(20);
	a=a+2;
	if(a==700)
		m5=1;
	}
	 if(m5==1)
	 {
		 iDelayMS(20);
		 a=a-2;
		 if(a==8)
			 m5=0;
	 }
	iText(a,b+120,str5);//,GLUT_BITMAP_TIMES_ROMAN_);
	if(m4==0)
	{
	 iDelayMS(20);
	 c=c-2;
	 if(c==8)
		 m4=1;
	}
	 if( m4==1)
	 {
		 iDelayMS(20);
		c=c+2;
		if(c==700)
			m4=0;
	 }
	 iText(c,b+120,str5);//,GLUT_BITMAP_TIMES_ROMAN_24);
	
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	printf("%d# %d\n",mx,my);
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN )
	{
		if(mx >= cx && mx <=cx1 && my >= cy && my <=cy1)
		{
			iKeyboard('1');
			printf("1");
		}
		if(mx >= cx+50 && mx <=cx1+50 && my >= cy && my <=cy1 )
		{
			iKeyboard('2');
		}
	  
		if(mx >= cx+100 && mx <=cx1+100 && my >= cy && my <=cy1)
		{
			iKeyboard('3');
		}
		if(mx >= cx+150 && mx <=cx1+150 && my >= cy && my <=cy1)
		{
			iKeyboard('+');
			printf("%d\n",1);
		}
		if(mx >= cx+200 && mx <=cx1+200 && my >= cy && my <=cy1)
		{
			iKeyboard('-');
		}
		if(mx >= cx+250 && mx <=cx1+250 && my >= cy && my <=cy1)
		{
			iKeyboard('x');
		}

		if(mx >= cx+300 && mx <=cx1+350 && my >= cy && my <=cy1)
		{
			iKeyboard('i');
		}


		if(mx >=cx && mx <=cx1&& my >= cy-40 && my <=cy1-40)
		{
			iKeyboard('4');
		}
		if(mx >= cx+50 && mx <=cx1+50 && my >= cy-40 && my <=cy1-40)
		{
			iKeyboard('5');
		}
		if(mx >= cx+100 && mx <=cx1+100&& my >= cy-40 && my <=cy1-40)
		{
			iKeyboard('6');
		}
		if(mx >= cx+150 && mx <=cx1+150&& my >= cy-40 && my <=cy1-40)
		{
			iKeyboard('*');
		}
		if(mx >= cx+200 && mx <=cx1+200&& my >= cy-40 && my <=cy1-40)
		{
			iKeyboard('/');
		}
			if(mx >= cx+250 && mx <=cx1+250&& my >= cy-40 && my <=cy1-40)
		{
			iSpecialKeyboard(GLUT_KEY_END);
			
		}
        if(mx >= cx+300 && mx <=cx1+350&& my >= cy-40 && my <=cy1-40)
		{
			iKeyboard('o');
			
		}
        

		if(mx >= cx && mx <=cx1 && my >= cy-80 && my <=cy1-80)
		{
			iKeyboard('7');

		}


		if(mx >= cx+50 && mx <=cx1+50 && my >= cy-80 && my <=cy1-80)
		{
			iKeyboard('8');
		}
		if(mx >= cx+100 && mx <=cx1+100 && my >= cy-80 && my <=cy1-80)
		{
			iKeyboard('9');
		}

		if(mx >= cx+150 && mx <=cx1+200 && my >= cy-80 && my <=cy1-80)
		{
			iKeyboard('b');
		}

		if(mx >= cx+250 && mx <=cx1+250 && my >= cy-80 && my <=cy1-80)
		{
			iKeyboard('m');
		}
		if(mx >= cx+300 && mx <=cx1+350 && my >= cy-80 && my <=cy1-80)
		{
			iKeyboard('v');
		}
		
		if(mx >= cx+200 && mx <=cx1+200 && my >= cy-80 && my <=cy1-80)
		{
			iKeyboard('l');
		}


		if(mx >= cx && mx <=cx1 && my >= cy-120 && my <=cy1-120)
		{
			iKeyboard('0');
		}
		if(mx >= cx+50 && mx <=cx1+50 && my >= cy-120 && my <=cy1-120 )
		{
			//iKeyboard('.');
		}


		if(mx >= cx+50 && mx <=cx1+149 && my >= cy-120 && my <=cy1-120 )
		{
			iKeyboard('\r');
			printf("1);");
		}
		if(mx >= 200 && mx <=300 && my >= cy-120 && my <=cy1-120 )
		{
			iKeyboard('s');
			printf("1);");
		}
		
		if(mx >= cx+300 && mx <=cx1+350 && my >= cy-120 && my <=cy1-120 )
		{
			iKeyboard('t');
			printf("1);");
		}
		
      if(mx >= 500 && mx <=500+350 && my >= py-60 && my <=py-20 )
		{
			//iRectangle(500,py-60,350,40);
			iKeyboard('g');

			printf("1);");
		}
	   if(mx >= 500 && mx <=500+350 && my >= py-110 && my <=py-70 )
		{
			//iRectangle(500,py-60,350,40);
			iKeyboard('a');

			printf("1);");
		}
	    if(mx >= 500 && mx <=500+350 && my >= py-160 && my <=py-120 )
		{
			//iRectangle(500,py-60,350,40);
			// iRectangle(500,py-160,350,40);
			mode5++;
			if(mode5==5)
				mode5=0;

			printf("1);");
		}
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	int i,lk=0;
	o=0;
	mt=0;
	++cnt;
	modes=0;
	if(key=='s')
       sw++;
    
	if(sw==1)
    printf("\a");
	if(sw==2)
		sw=0;


	  if(key =='\r'&& ad==1)
		{
            ixtopx(str);
			mode4=1;
			sp1=0;
			sp=0;
		

	 }


        if(key=='a')
	   {
             iSpecialKeyboard(GLUT_KEY_END);
		   ad=1;
		   sd=0;
             strcpy(str5,"INFIX CALCULATOR");

	   }
        if(key=='g')
	   {
		    iSpecialKeyboard(GLUT_KEY_END);
		   ad=0;
		    strcpy(str5,"BIG INTEGER CALCULATOR");


	   }
      
		if(key == '\r'&&ad!=1)
		{
			      sd++;
		        mode=1;
				moder2=1;
		            len=0;	

		}


	   if(ad!=1)
	{
		
		 if( sd<=1 && key=='-'&&len==0)
		{
			//char iPlaysound(5);
			mode1=1;
			if(mode==0)
			{str[len] = key;
			len++;
			}
			else if(mode==1)
			{
                str2[len] = key;
			len++;
			}

	
		 }

		 if(key>='0'&&key<='9'&& sd<=1)
		{
			//void iPlaySound();
			mode1=1;
			if(mode==0)
			{
				str[len] = key;
			len++;
			}
			else if(mode==1)
			{
                str2[len] = key;
			len++;
			}

	
			}
		 if(key=='+'&&sd>=2)
	   {
			strcpy(r,"+");
			 rt= rc(str,str2);
            moder=1;
			rt=rt*1;
			if(rt==-1)
			{
			     if(str[0]=='-')
				   rt=-1;
				 else rt=0;
			    sub(p,p1,rt);
			}
			else if(rt==1)
			{
				if(str[0]=='-'&&str2[0]=='-')
				   rt=-1;
			  
	      add(p,p1,rt);
			}

	   }
	  if(key=='-'&&sd>=2)
	   {
		   printf("1");
		    rt= rc(str,str2);
		    strcpy(r,"-");
		   moder=1;
		  // if(rt==1)
			  // rt1=-1;
		  // rt=rt*-1;
		   if(rt==-1)
		   {
			   if(str[0]=='-')
				   rt=-1;

			   else rt=0;
			  
			   add(p,p1,rt);  
		   }
		   else if(rt==1)
		   {
		       if(str[0]=='-'&& str2[0]=='-')
				   rt=2;
			   else rt =1;
		
		   sub(p,p1,rt);
		   }
		 

	   }

	   if(key=='*'&&sd>=2)
	   {
		   printf("1");
		    rt= rc(str,str2);
		    strcpy(r,"*");
		   moder=1;
		   mul(p,p1,rt); 

	   }
      
	   if(key=='/'&&sd>=2)
	   {
		  // printf("1");
		    rt= rc(str,str2);
		    strcpy(r,"/");
		   moder=1;
		   div(p,atoi(p1),rt); 

	   }

	}


   if(ad==1)
   {
     if(key>='0'&&key<='9'&& sp1==1)
	 {
		 mode1=1;
		 str[len] = key;
			len++;
			sp=1;
			sp1=0;
			lk=1;

	 }
		if(sp==1 && sp1!=1 &&( key=='+'|| key=='/'|| key=='*'|| key=='-'))
		{
			//void iPlaySound();
			mode1=1;
			//if(mode==0)
			{
				str[len] = key;
			len++;
			}
		   sp=0;
		   sp1=1;
           lk=2;
		}

   }
     





		if(key=='x')
		{
		   exit(0);
	}

	if(key=='b'&&sd==0&&ad!=1)
		{
			
		   str[--len]=0;
		    if(len<=-1)
			   len=0;
			            
	}

	if(sd==1 && key =='b'&&ad!=1)
		{
		   str2[--len]=0;
		   if(len<=-1)
			   len=0;
			    
			  
	}
	if(key=='b'&&sd>=2&&ad!=1)
		{
		   for(i=0;i<=cnt;i++)
			   str3[i]=0;
		   moder=0;
		   mode3=0;

	}
	
	if(key=='m'&&ad!=1&&sd<1)
	{
       strcpy(M[nm++],str);
	   modes=1;
	   

	}
    if(key=='m'&& ad!=1 && sd==1)
	{
       strcpy(M[nm++],str2);
       modes=1;
	}
	if(key=='m'&&ad!=1&&sd>=2)
	{
       strcpy(M[nm++],str3);
	   modes=1;
	}

	if(key=='m'&& ad==1 && sd<=1)
	{
       strcpy(M[nm++],str3);
	   modes=1;
	   sd=2;
	}
	 if(key=='i')
	 {
		 Max(M,nm);
		 strcpy(strm,"Maximum");
		// iSpecialKeyboard(GLUT_KEY_END);
		 modem=1;
	 }
       if(key=='o')
	 {
		 Min(M,nm);
		//  iSpecialKeyboard(GLUT_KEY_END);

		  strcpy(strm,"Minimum");
		  modem=1;
	 }
      if(key=='v')
	 {
		 Ave(M,nm);
	        // iSpecialKeyboard(GLUT_KEY_END);

		  strcpy(strm,"Average");
		  modem=1;
	 }
	   if(key=='t')
	 {
		 stdv(M,nm);
		// iSpecialKeyboard(GLUT_KEY_END);

		  strcpy(strm,"Stander Deviation");
		  modem=1;
	 }

	//place your codes for other keys here
   }
  
/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:...................................
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
     mt=0;

	
	if(key == GLUT_KEY_END)
	{
		//modes=1;
		o++;
		int i;
		sd=0;	
		printf("%d",modes);

		for(i=0;i<=cnt;i++)
		{
			str2[i]=0;
			str3[i]=0;
			str[i]=0;
		}
		strcpy(str,str2);
		strcpy(str2,str);
		strcpy(str3,str2);
		modes=0;
		mode1=0;
		moder2=0;
		mode3=0;
		mode=0;
		modea=0;
		mode1=0;
		mode=0;
		moder=0;
		mode4=0;
		modem=0;
		len=0;
		if(ad==1)
			sp1=1;

		
		
	}
		if(key == GLUT_KEY_HOME)
	{
		//mode1=1;
		mode1=0;
		modea=1;
		strcpy(str,str2);
		mode=0;
		
	}
		if(o>=2)
		{
			 int i=0;

			while(nm--)
			{
		for(i=0;i<=strlen(M[nm]);i++)
		{
			M[nm][i]=0;
	
		}
			}
		nm=0;
		printf("\a");
		}

	//place your codes for other keys here.
}

int main()
{
	//place your own initialization codes here.
	len = 0;
	mode = 0;
	modes=0;
	str[0]= 0;
	

	//s=1;
	iInitialize(902,600, "                                                                                                           CALCULATOR");
	return 0;
}
 