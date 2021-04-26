#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#include<assert.h>
#include<stdlib.h>
#include <process.h>

void gotoxy(int x,int y);
void load();
void encrpt_sc_msg(char str[]);
int encrpt_sc_file(char fname[]);
void encrpt_sc();
void menu();
void RSA_msg(char msg[]);
int RSA_file(char fname[]);

int gcd(int a, int h)
{
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}
void RSA_msg(char msg[])
{

    int p,q;
    int en;
    printf("enter two primes:");
    scanf("%d %d",&p,&q);
     long int n;
     n = p*q;
    long int totient = (p-1)*(q-1); 
   
 printf("enter encrpt en value:");
 scanf("%d",&en);
    while (en < totient) 

    {  

        if (gcd(en, totient)==1) 

            break; 

        else

            en++; 

    } 

int i=0;
  while(msg[i]!='\0')
{

    double c= pow(msg[i], en);  
    msg[i]=fmod(c,n);
     i++;
}

    // Encryption c = (msg ^ en) % n 

  printf("Encrypted Message :\n %s", msg);    

    	
	
}

int RSA_file(char fname[])
{
	  char  ch;
    FILE *fps, *fpt;
     int p,q;
    int en;
    printf("enter two primes:");
    scanf("%d %d",&p,&q);
     long int n;
     n = p*q;
    long int totient = (p-1)*(q-1); 
   
   printf("enter encrpt en value:");
   scanf("%d",&en);
    fps = fopen(fname, "r");
    if(fps == NULL)
	{
        return 0;
    }
    fpt = fopen("temp.txt", "w");
    if(fpt == NULL)
	{
        return 0;
    }
    ch = fgetc(fps);
    while(ch != EOF)
    {
       double c = pow(ch, en); 
       ch =fmod(c,n); 
    }
    fclose(fps);
    fclose(fpt);
    fps = fopen(fname, "w");
    if(fps == NULL)
        return 0;
    fpt = fopen("temp.txt", "r");
    if(fpt == NULL)
        return 0;
    ch = fgetc(fpt); 
    while(ch != EOF)
    {
        ch = fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
    printf("\nFile %s Encrypted Successfully!", fname);
    return 0;
	
}

void RSA()
{   
    int m;
    char msg[100],fname[100];
	printf("\n\n<-------RSA Encrption------->");
	printf("\n1.Encryption of message\n2.Encrption of file");
	printf("\nenter your choice:");
	scanf("%d",&m);
	switch(m)
	{
	  case 1:
	  	 printf("enter your message:\n");
	  	 scanf("%s",msg);
	     RSA_msg(msg);
		 break;	
	  case 2:
	    printf("enter file name:");
	    scanf("%s",fname);
	    RSA_file(fname);
	     break;
	  deault:
	     break;	
		
	}
	
}
int main()
{
  
   load();
   system("cls");
   menu();
   

}

void encrpt_sc()
{   
    int n;
    char str[200],fname[100];
	printf("\n\n<-------Encrption using specific characters------->");
	printf("\n1.Encryption of message\n2.Encrption of file");
	printf("\n Enter your choice:");
	scanf("%d",&n);
	switch(n)
	{
	  case 1:
	  	  printf("\n\nEnter your message\n\n");
	  	  scanf("%s",str);
	      encrpt_sc_msg(str);
	      break;
	  case 2:
	      printf("enter file name:");
          scanf("%s",fname);
          encrpt_sc_file(fname);
	      break;
	  default:
	     printf("no such choice");
	     break;
	   	
	}
	
}
void encrpt_sc_msg(char str[])
{ 
   int i;
   char a,b;
   int ascii;
  printf("enter two characters:");
  scanf("%c %c",&a,&b);
  for ( i = 0; i <strlen(str); i++)
  {
      ascii=str[i];
          if (ascii%2==0)
          {  
              ascii=ascii+a;
              printf("%c",ascii);
          }
          else
          {   
               ascii=ascii+b;
              printf("%c",ascii);
          }
          
      
  }
  
 
}
int encrpt_sc_file(char fname[])
{
	char  ch;
	char a,b;
	printf("enter two characters:");
	scanf("%c %c",&a,&b);
    FILE *fps, *fpt;
    fps = fopen(fname, "r");
    if(fps == NULL)
        return 0;
    fpt = fopen("temp.txt", "w");
    if(fpt == NULL)
        return 0;
    ch = fgetc(fps);
    while(ch != EOF)
    {    
         if (ch%2==0)
          { 
            ch=ch+a;
            fputc(ch, fpt);
          }
          else
          {
          	ch=ch+b;
            fputc(ch, fpt);
          }
       
        ch = fgetc(fps);
    }
    fclose(fps);
    fclose(fpt);
    fps = fopen(fname, "w");
    if(fps == NULL)
        return 0;
    fpt = fopen("temp.txt", "r");
    if(fpt == NULL)
        return 0;
    ch = fgetc(fpt);
    while(ch != EOF)
    {
        ch = fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
    printf("\nFile %s Encrypted Successfully!", fname);
    return 0;
}
/*in this encrption method every element of the message
 ascii value is increased by a key value and if this value exceeds alphabets ascii
 it is converted to alphabets by adding and substraction ascii values of a and z respectively  */
void caesar_cipher()
{
           int n;
           char message[100],ch;
	printf("\n\n<-------Caesar Cipher Encryption------->");

	printf("\n1.Encrypt a Message\n2.Encrypt a File");

  printf("\nEnter Your Choice:");

  scanf("%d",&n);

  switch(n)
{
case 1:
printf("\nEnter Your Message to be Encrypted\n");
scanf("%s",message);

int i,key;

printf("\nEnter Key:");

scanf("%d",&key);

for(i=0; message[i] !='\0' ; ++i)
{ 
     ch=message[i];

     if(ch>='a' && ch<='z')
{
     ch=ch+key;
     
              if(ch>'z')
         {
                ch=ch - 'z'+'a'- 1;
         }
 message[i] = ch; 
}

else if( ch>='A' && ch<='Z')
{
     ch = ch + key;

     if( ch>'Z')
     {
         ch = ch -'Z' + 'A' - 1;
     }
   
      message[i]=ch;
}

}
printf("Encrypted Message is:%s",message);

          break;

case 2:
	char fname[100];
	int n;
   FILE *fps, *fpt;
   printf("enter file name:");
   scanf("%s",fname);
   printf("enter key:");
   scanf("%d",&n);
    fps = fopen(fname, "r");
    if(fps == NULL)
        return ;
    fpt = fopen("temp.txt", "w");
    if(fpt == NULL)
        return ;
    ch = fgetc(fps);
    while(ch != EOF)
    {    
         if(ch>='a' && ch<='z')
{
     ch=ch+key;
     
              if(ch>'z')
         {
                ch=ch - 'z'+'a'- 1;
         }
 fputc(ch, fpt);
}

else if( ch>='A' && ch<='Z')
{
     ch = ch + key;

     if( ch>'Z')
     {
         ch = ch -'Z' + 'A' - 1;
     }
   
   fputc(ch, fpt);
}
        
        ch = fgetc(fps);
    }
    fclose(fps);
    fclose(fpt);
    fps = fopen(fname, "w");
    if(fps == NULL)
        return ;
    fpt = fopen("temp.txt", "r");
    if(fpt == NULL)
        return ;
    ch = fgetc(fpt);
    while(ch != EOF)
    {
        ch = fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
    printf("\nFile %s Encrypted Successfully!", fname);
break;

default:

printf("Invalid Input");

break;
}
		
}
void Num_encrpt()
{  
    int n;
	printf("\n\n<-------NUMBER Encrption ------->");
	printf("\n1.Encryption of message\n2.Encrption of file");
	printf("\nenter your choice:");
	scanf("%d",&n);
	switch(n)
	{
	case 1:
			int m;
			char ch;
    char msg[100];
     printf("enter a message:");
     scanf("%s",msg);	
     printf("enter a number greater than 1:");
     scanf("%d",&m);
   for(int i=0;msg[i]!='\0';i++)
   {
   	int c=msg[i];
   	msg[i]=c-m;
   	printf("%d",msg[i]);
   }
   break;
   case 2:
   	char fname[100];
   	int s;
   	printf("enter file name:");
    scanf("%s",fname);
    printf("enter a number greater than 1:");
     scanf("%d",&s);
   	FILE *fps, *fpt;
    fps = fopen(fname, "r");
    if(fps == NULL)
        return ;
    fpt = fopen("temp.txt", "w");
    if(fpt == NULL)
        return ;
    ch = fgetc(fps);
    while(ch != EOF)
    {    
         ch=ch-s;
        fputc((int)ch, fpt);
        ch = fgetc(fps);
    }
    fclose(fps);
    fclose(fpt);
    fps = fopen(fname, "w");
    if(fps == NULL)
        return ;
    fpt = fopen("temp.txt", "r");
    if(fpt == NULL)
        return ;
    ch = fgetc(fpt);
    while(ch != EOF)
    {
        ch = fputc((int)ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
    printf("\nFile %s Encrypted Successfully!", fname);
    break;
    default:
    	printf("invalid");
	}
	
}
void menu()
{ 
  int n;
  printf("<----ENCRYPTION MENU---->\n");
  printf("1.RSA\n2.NUMBER ENCRPTION\n3.CAESAR CIPHER\n4.ENCRYPTION USING SPECIAL CHARACTERS\n");
  printf("Enter your choice:");
  scanf("%d",&n);
  switch(n)
  {
  	case 1:
  		RSA();
  		break;
  	case 2:
  		Num_encrpt();
  		break;
  	case 3:
  		caesar_cipher();
  		break;
  	case 4:
  		encrpt_sc();
  		break;
  	default:
  		printf("no such choice");
  		break;
  		
  }	
}


void gotoxy(int x, int y)
{

 COORD coord;

 coord.X = x;

 coord.Y = y;

 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void load(){
    int row,col,r,c,q;
    gotoxy(94,14);
    printf("loading...\n");
    gotoxy(90,15);
    for(r=1;r<=20;r++){
    for(q=0;q<=100000000;q++);//to display the character slowly
    printf("%c",177);}
    getch();
}


