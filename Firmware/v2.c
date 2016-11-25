/*
 * LED_dice_t13.c
 *
 * Created: 23.11.2016. 11:05:03
 * Author : e-radionica.com
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL // 1Mhz

#include <util/delay.h>


int main(void)
{
	// define direction ports
	DDRB = (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0); 
	
	// pull-up for pushbutton
	// PORTB = (1<<PORTB4);
	
	int i = 0;
	
	//loop
    while (1) 
    {
		// set random seed
		srand(i);
		i++;
		
		// read push button
		int btn = PINB;
		
		if(btn != 0)
		{
			int x = generateNumber(6,1);
			animation();
			toogleLEDs(x);
		}
		
		// turn off all LEDs
		PORTB = (0<<PORTB0) | (0<<PORTB1) | (0<<PORTB2) | (0<<PORTB3);	
    }
}

void toogleLEDs(int broj)
{
	switch(broj)
	{
		case 1:
		PORTB = (1<<PORTB0);
		break;

		case 2:
		PORTB = (1<<PORTB2);
		break;

		case 3:
		PORTB = (1<<PORTB0) | (1<<PORTB2);
		break;

		case 4:
		PORTB = (1<<PORTB1) | (1<<PORTB2);
		break;

		case 5:
		PORTB = (1<<PORTB0) | (1<<PORTB1) | (1<<PORTB2);
		break;

		case 6:
		PORTB = (1<<PORTB1) | (1<<PORTB2) | (1<<PORTB3);
		break;
	}
	_delay_ms(4000);
}

int generateNumber(int n, int z)
{
	
	 // n - max, z - if 0 starts from 0, if 1 starts from 1
	 if( z == 0 ) n += 1;
	 
	 int r = ( rand() % n ) + z; 
	 return r;
}

void animation()
{
	int jk = 0;
	
	for(int i = 0; i < 10; i++)
	{
		
		jk = generateNumber(3,0);
		
		switch(jk)
		{
			case 0:
			PINB = (1<<PORTB0);
			break;
			
			case 1:
			PINB = (1<<PORTB1);
			break;
			
			case 2:
			PINB = (1<<PORTB2);
			break;
			
			case 3:
			PINB = (1<<PORTB3);
			break;
		}
	
		// turn off all LEDs
		_delay_ms(40);	
		PORTB = 0;	
			
	}
}
