#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

int main(void)
{
	int step,cnt,i,random,temp,c1,c2;
	
	DDRA = 0xff;
	DDRC = 0xff;
	DDRD = 0;
	DDRB = 0x1f;
	
	step=0;
	temp=cnt=c1=c2=0;
	while(step<=20)
	{
		
		random=rand()%9;
//		PORTB=0;		

		if(random==0)
			PORTA=1;
		if(random==1)
			PORTA=2;
		if(random==2)
			PORTA=4;
		if(random==3)
			PORTA=8;
		if(random==4)
			PORTA=16;
		if(random==5)
			PORTA=32;
		if(random==6)
			PORTA=64;
		if(random==7)
			PORTA=128;
		if(random==8)
		{
			PORTA=0;
			PORTB=1;
		}


		//_delay_ms(1000);
		
		for(i=0;i<=30;i++)
		{
			if(PIND==1 && random==0)
			{
				cnt++;
				break;
			}
			if(PIND==2 && random==1)
			{
				cnt++;
				break;
			}
			if(PIND==4 && random==2)
			{
				cnt++;
				break;
			}
			if(PIND==8 && random==3)
			{
				cnt++;
				break;
			}
			if(PIND==16 && random==4)
			{
				cnt++;
				break;
			}
			if(PIND==32 && random==5)
			{
				cnt++;
				break;
			}
			if(PIND==64 && random==6)
			{
				cnt++;
				break;
			}
			if(PIND==128 && random==7)
			{
				cnt++;
				break;
			}
			if(PINB==129 && random==8)
			{
				cnt++;
				break;
			}

			_delay_ms(100);

		}
		
		
		PORTC=(cnt/10)*16+(cnt%10);

		PORTB &=0;	
		_delay_ms(100);

		if(temp==cnt)
			PORTB=0x1E;
		else
			PORTB=0x0A;

		temp=cnt;
	}

		
		 	
  return 0;
  }

/*
	while(1)
	{
		q++;
		if(q%10==0)
		{
			q=0;
			p++;
		}
		PORTA = (p/10)*16+p%10;
		PORTD = (q/10)*16+q%10;


		_delay_ms(200);
	}	
*/
