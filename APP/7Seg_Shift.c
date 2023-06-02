/*********************************************
 * Author:          Moaz Mohamed Romih
 * Creation Data:   01 June, 2023
 * Version:         v1.0
 * Compiler:        GNU ARM-GCC
 ********************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "ShiftRegister_Interface.h"


const u8 SegValues[10] = {0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};

void main(void)
{
    MRCC_voidInit();
    MRCC_voidEnablePeripheralClock(RCC_AHB1,GPIOA_ID);
    MSTK_voidInit();
    HShiftRegister_voidInit();
    while (1)
    {
        s8 main_s8OuterLoopCounter;
		s8 main_s8InnerLoopCounter;
		for(main_s8OuterLoopCounter = 9; main_s8OuterLoopCounter >= 0; main_s8OuterLoopCounter--)
		{
			HShiftRegister_voidSend1ByteDataHigh(SegValues[main_s8OuterLoopCounter]);
			for(main_s8InnerLoopCounter = 9; main_s8InnerLoopCounter >= 0; main_s8InnerLoopCounter--)
			{
				HShiftRegister_voidSend1ByteDataLow(SegValues[main_s8InnerLoopCounter]);
				MSTK_voidSetBusyWaitus(100000);
			}
		}
	}

}
