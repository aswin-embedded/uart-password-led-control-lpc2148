#include<lpc214x.h>
#include <string.h>
#include <stdio.h>
void uart0_init()
{
	PINSEL0=0X05;
	U0LCR=0X83;
	U0DLL=97;
	U0DLM=0;
	U0LCR=0X03;
}
void uart0_char_tx(char ch)
{
	while(!(U0LSR & 0X20));
	U0THR=ch;
	
}
char uart0_char_rx()
{
  while(!(U0LSR & 0X01));
	return U0RBR;
}
	
void uart0_str_tx(char str[])
{
	int i=0;
	while(str[i]!='\0')
	{
		uart0_char_tx(str[i]);
		i++;
  }
}
void uart0_rx_echo(char str[]) //echo back 
{ 
	char ch;
	int i=0;
	while(1)
	{
		ch=uart0_char_rx();
		uart0_char_tx(ch);
		if(ch=='\r')
		{ 
			break;
		}
		str[i]=ch;
		i++;
		
		
  }
	str[i]='\0';
	
}
void uart0_str_rx(char str[]) //echo back as * -> used for pass echoback
{ 
	char ch;
	int i=0;
	while(1)
	{
		ch=uart0_char_rx();
		uart0_char_tx('*');
		if(ch=='\r')
		{ 
			break;
		}
		str[i]=ch;
		i++;
		
		
  }
	str[i]='\0';
	
}
void uart0_str_cmmd_rx(char str[]) //rx without echoback
{ 
	char ch;
	int i=0;
	
	while(1)
	{
		ch=uart0_char_rx();
		if(ch=='\r')
		{ 
			break;
		}
		str[i]=ch;
		i++;
		
		
		
  }
	str[i]='\0';
	
}

int main()
{
	char pass[10]="1234";
	char try[10]; //user enetring pass
	int i,attempt=3;
	int invalid=0; //invalid try 1-crct strng pass, 0=wrong string pass
	char buffer[20];
	
	//==============
	
	char led0n[20]="LED_ON";
	char led0ff[20]="LED_OFF";
	char ledcmmd[20];//cmmd string ->to recieve the cmmd by user
	
	uart0_init();
	IODIR0 |=(1<<10);//P0.10 as output
	while(1)
	{
		uart0_str_tx("\rENTER YOUR PASS: ");
		uart0_str_rx(try); //recieve pass frm user
		invalid=0; //reset before checking 
		for(i=0;pass[i]!='\0';i++) //checking each char in pass[] with user entered try[]
		{
			if(pass[i]!=try[i])
			{
				invalid=1;
				break;
			}
			
    }
		if(pass[i]!=try[i])//checking the lenghth of both strings
		{
			invalid=1;
		}
		//==========================================================================
		//correct pass
		if(invalid==0) //if pass is crct
		{
			uart0_str_tx("\rCorrect password");
			attempt=3;
			//---------command system----------;
			while(1)
			{
			
			uart0_str_tx("\rENTER COMMAND:");
			uart0_str_tx("\rLED_ON");
			uart0_str_tx("\rLED_OFF");
			uart0_str_tx("\rEXIT");
			uart0_char_tx('\r');
			
			uart0_rx_echo(ledcmmd); //recieve command
			
			if(strcmp(led0n,ledcmmd)==0) //comapir with ledon
			{
				IOSET0=(1<<10);
				uart0_str_tx("\rLED ON");
			}
			else if(strcmp(led0ff,ledcmmd)==0)//compair with led off
			{
				IOCLR0=(1<<10);
				uart0_str_tx("\rLED OFF");
			}
			else if(strcmp(ledcmmd,"EXIT")==0) //compair withy exit
			{
				uart0_str_tx("\rLOGOUT");
				break;
			}
			else
			{
				uart0_str_tx("\rINVALID COMMAND");
			}
		  }
		}
			
		
		//=========================================================================
		//wrong pass
		else if(invalid==1)//if pass is wrong(invalid=1) with 3 attempts
		{
			attempt--; //decrement of attempt from 3
			uart0_str_tx("\rWrong pass");
			sprintf(buffer,"\r%d chances remaining",attempt); //buffer->chance remaining
			uart0_str_tx(buffer);//priniting buffer
			if(attempt==0)
			{
				while(1);//lock it on a loop after 3 continuce wrong attempt
			}
			invalid=0;
		}
  
}
}
