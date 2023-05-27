<<<<<<< HEAD
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SEVEN_SEG_interface.h"
#include "SEVEN_SEG_private.h"
#include "SEVEN_SEG_config.h"


void SEVEN_SEG_voidInit(void)
{
	u8 Local_u8LoopCounter;
	for (Local_u8LoopCounter = LOOPSTART; Local_u8LoopCounter < LOOPEND; Local_u8LoopCounter++)
	{
		u8 Local_u8Seg2_Ports[8] = SEVEN_SEG2_PORTS;
		u8 Local_u8Seg2_Pins[8] = SEVEN_SEG2_PINS;
		MGPIO_voidSetPinMode(Local_u8Seg2_Ports[Local_u8LoopCounter],Local_u8Seg2_Pins[Local_u8LoopCounter],OUTPUT);
		MGPIO_voidSetOutputSpeed(Local_u8Seg2_Ports[Local_u8LoopCounter],Local_u8Seg2_Pins[Local_u8LoopCounter],LOW_SPEED);
		MGPIO_voidSetOutputType(Local_u8Seg2_Ports[Local_u8LoopCounter],Local_u8Seg2_Pins[Local_u8LoopCounter],PUSH_PULL);
		MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[Local_u8LoopCounter],Local_u8Seg2_Pins[Local_u8LoopCounter],LOW);
	}
	for (Local_u8LoopCounter = LOOPSTART; Local_u8LoopCounter < LOOPEND; Local_u8LoopCounter++)
	{
		u8 Local_u8Seg1_Ports[8] = SEVEN_SEG1_PORTS;
		u8 Local_u8Seg1_Pins[8] = SEVEN_SEG1_PINS;
		MGPIO_voidSetPinMode(Local_u8Seg1_Ports[Local_u8LoopCounter],Local_u8Seg1_Pins[Local_u8LoopCounter],OUTPUT);
		MGPIO_voidSetOutputSpeed(Local_u8Seg1_Ports[Local_u8LoopCounter],Local_u8Seg1_Pins[Local_u8LoopCounter],LOW_SPEED);
		MGPIO_voidSetOutputType(Local_u8Seg1_Ports[Local_u8LoopCounter],Local_u8Seg1_Pins[Local_u8LoopCounter],PUSH_PULL);
		MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[Local_u8LoopCounter],Local_u8Seg1_Pins[Local_u8LoopCounter],LOW);
	}
}

void SEVEN_SEG_voidprintNumber(u8 Copy_u8Number)
{
	if (Copy_u8Number > MAX_NUM)
	{
		/* ERROR */
	}
	else
	{
		SEVEN_SEG_voidprintNaturalNumber(SEG_2,Copy_u8Number/10);
		SEVEN_SEG_voidprintNaturalNumber(SEG_1,Copy_u8Number%10);
	}
}


static void SEVEN_SEG_voidprintNaturalNumber(u8 Copy_u8SegID,u8 Copy_u8Number)
{
	if(Copy_u8SegID == SEG_1)
	{
		u8 Local_u8Seg1_Ports[8] = SEVEN_SEG1_PORTS;
		u8 Local_u8Seg1_Pins[8] = SEVEN_SEG1_PINS;
		switch (Copy_u8Number)
		{
		case SEG_NUM_ZERO:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],LOW);
			break;
		case SEG_NUM_ONE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],LOW);
			break;
		case SEG_NUM_TWO:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_THREE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_FOUR:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_FIVE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_SIX:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_SEVEN:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],LOW);
			break;
		case SEG_NUM_EIGHT:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_NINE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		default:
			break;
		}
	}
	else if(Copy_u8SegID == SEG_2)
	{
		u8 Local_u8Seg2_Ports[8] = SEVEN_SEG2_PORTS;
		u8 Local_u8Seg2_Pins[8] = SEVEN_SEG2_PINS;
		switch (Copy_u8Number)
		{
		case SEG_NUM_ZERO:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],LOW);
			break;
		case SEG_NUM_ONE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],LOW);
			break;
		case SEG_NUM_TWO:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_THREE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_FOUR:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_FIVE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_SIX:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_SEVEN:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],LOW);
			break;
		case SEG_NUM_EIGHT:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_NINE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;

		default:
			break;
		}
	}
	else
	{
		/* ERROR */
	}
}
=======
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SEVEN_SEG_interface.h"
#include "SEVEN_SEG_private.h"
#include "SEVEN_SEG_config.h"


void SEVEN_SEG_voidInit(void)
{
	u8 Local_u8LoopCounter;
	for (Local_u8LoopCounter = LOOPSTART; Local_u8LoopCounter < LOOPEND; Local_u8LoopCounter++)
	{
		u8 Local_u8Seg2_Ports[8] = SEVEN_SEG2_PORTS;
		u8 Local_u8Seg2_Pins[8] = SEVEN_SEG2_PINS;
		MGPIO_voidSetPinMode(Local_u8Seg2_Ports[Local_u8LoopCounter],Local_u8Seg2_Pins[Local_u8LoopCounter],OUTPUT);
		MGPIO_voidSetOutputSpeed(Local_u8Seg2_Ports[Local_u8LoopCounter],Local_u8Seg2_Pins[Local_u8LoopCounter],LOW_SPEED);
		MGPIO_voidSetOutputType(Local_u8Seg2_Ports[Local_u8LoopCounter],Local_u8Seg2_Pins[Local_u8LoopCounter],PUSH_PULL);
		MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[Local_u8LoopCounter],Local_u8Seg2_Pins[Local_u8LoopCounter],LOW);
	}
	for (Local_u8LoopCounter = LOOPSTART; Local_u8LoopCounter < LOOPEND; Local_u8LoopCounter++)
	{
		u8 Local_u8Seg1_Ports[8] = SEVEN_SEG1_PORTS;
		u8 Local_u8Seg1_Pins[8] = SEVEN_SEG1_PINS;
		MGPIO_voidSetPinMode(Local_u8Seg1_Ports[Local_u8LoopCounter],Local_u8Seg1_Pins[Local_u8LoopCounter],OUTPUT);
		MGPIO_voidSetOutputSpeed(Local_u8Seg1_Ports[Local_u8LoopCounter],Local_u8Seg1_Pins[Local_u8LoopCounter],LOW_SPEED);
		MGPIO_voidSetOutputType(Local_u8Seg1_Ports[Local_u8LoopCounter],Local_u8Seg1_Pins[Local_u8LoopCounter],PUSH_PULL);
		MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[Local_u8LoopCounter],Local_u8Seg1_Pins[Local_u8LoopCounter],LOW);
	}
}

void SEVEN_SEG_voidprintNumber(u8 Copy_u8Number)
{
	if (Copy_u8Number > MAX_NUM)
	{
		/* ERROR */
	}
	else
	{
		SEVEN_SEG_voidprintNaturalNumber(SEG_2,Copy_u8Number/10);
		SEVEN_SEG_voidprintNaturalNumber(SEG_1,Copy_u8Number%10);
	}
}


static void SEVEN_SEG_voidprintNaturalNumber(u8 Copy_u8SegID,u8 Copy_u8Number)
{
	if(Copy_u8SegID == SEG_1)
	{
		u8 Local_u8Seg1_Ports[8] = SEVEN_SEG1_PORTS;
		u8 Local_u8Seg1_Pins[8] = SEVEN_SEG1_PINS;
		switch (Copy_u8Number)
		{
		case SEG_NUM_ZERO:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],LOW);
			break;
		case SEG_NUM_ONE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],LOW);
			break;
		case SEG_NUM_TWO:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_THREE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_FOUR:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_FIVE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_SIX:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_SEVEN:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],LOW);
			break;
		case SEG_NUM_EIGHT:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_NINE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_A],Local_u8Seg1_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_B],Local_u8Seg1_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_C],Local_u8Seg1_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_D],Local_u8Seg1_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_E],Local_u8Seg1_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_F],Local_u8Seg1_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg1_Ports[SEG_PIN_G],Local_u8Seg1_Pins[SEG_PIN_G],HIGH);
			break;
		default:
			break;
		}
	}
	else if(Copy_u8SegID == SEG_2)
	{
		u8 Local_u8Seg2_Ports[8] = SEVEN_SEG2_PORTS;
		u8 Local_u8Seg2_Pins[8] = SEVEN_SEG2_PINS;
		switch (Copy_u8Number)
		{
		case SEG_NUM_ZERO:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],LOW);
			break;
		case SEG_NUM_ONE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],LOW);
			break;
		case SEG_NUM_TWO:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_THREE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_FOUR:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_FIVE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_SIX:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_SEVEN:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],LOW);
			break;
		case SEG_NUM_EIGHT:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;
		case SEG_NUM_NINE:
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_A],Local_u8Seg2_Pins[SEG_PIN_A],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_B],Local_u8Seg2_Pins[SEG_PIN_B],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_C],Local_u8Seg2_Pins[SEG_PIN_C],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_D],Local_u8Seg2_Pins[SEG_PIN_D],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_E],Local_u8Seg2_Pins[SEG_PIN_E],LOW);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_F],Local_u8Seg2_Pins[SEG_PIN_F],HIGH);
			MGPIO_voidSetAtomicPinValue(Local_u8Seg2_Ports[SEG_PIN_G],Local_u8Seg2_Pins[SEG_PIN_G],HIGH);
			break;

		default:
			break;
		}
	}
	else
	{
		/* ERROR */
	}
}
>>>>>>> effefad (IR Task done.)
