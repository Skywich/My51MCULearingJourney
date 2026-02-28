#include <REGX52.H>
#include <intrins.h>
/**
  *@brief  延迟输入的xms毫秒 @11.0592MHz
  *@param  要延迟的xms
  *@retval 无
  */

void Delay(unsigned int xms)
{
	unsigned char data i, j;
	while(xms--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}

}
