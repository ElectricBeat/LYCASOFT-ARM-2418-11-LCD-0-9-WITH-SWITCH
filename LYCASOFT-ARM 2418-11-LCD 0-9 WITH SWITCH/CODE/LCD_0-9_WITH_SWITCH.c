#include <lpc214x.h>
#include "LPC2148_delay.h"
#include "LPC2148_LCD_4_BIT_HEADER_FILE.h"

#define SW 0x80000000

int Count;

int main()
{
	PINSEL0 = 0x00000000;
	IODIR0 = 0x000003F0;
	
	Lcd_Intialization();
	
	Lcd_Command(0x80);
	Lcd_String("LYCA SOFT");

	while(1)
	{
		Lcd_Command(0xC0);
		while(IOPIN0 == SW)
		{
			Lcd_Data(Count+48);
			Count++;
			
			if(Count >= 10)
			{
				Count = 0;
			}
			while(IOPIN0 == SW);
		}
	}
}