#include <avr/io.h>
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "DIO.h"


void DIO_voidSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction){
	if(Copy_u8Pin < 8){
		if (Copy_u8Direction == DIO_PIN_OUTPUT){
			switch(Copy_u8Port){
				case DIO_PORTA: DDRA = SET_BIT(DDRA,Copy_u8Pin); break;
				case DIO_PORTB: DDRB = SET_BIT(DDRB,Copy_u8Pin); break;
				case DIO_PORTC: DDRC = SET_BIT(DDRC,Copy_u8Pin); break;
				case DIO_PORTD: DDRD = SET_BIT(DDRD,Copy_u8Pin); break;
				default:	return;/*do nothing*/
			}
		}
		else if (Copy_u8Direction == DIO_PIN_INPUT){
			switch(Copy_u8Port){
				case DIO_PORTA: DDRA = CLR_BIT(DDRA,Copy_u8Pin); break;
				case DIO_PORTB: DDRB = CLR_BIT(DDRB,Copy_u8Pin); break;
				case DIO_PORTC: DDRC = CLR_BIT(DDRC,Copy_u8Pin); break;
				case DIO_PORTD: DDRD = CLR_BIT(DDRD,Copy_u8Pin); break;
				default:	return;	/*do nothing*/
			}			
		}
		else if (Copy_u8Direction == DIO_PIN_INPUT_PULLUP){
			switch(Copy_u8Port){
				case DIO_PORTA: DDRA = CLR_BIT(DDRA,Copy_u8Pin); PORTA = SET_BIT(PORTA,Copy_u8Pin);break;
				case DIO_PORTB: DDRB = CLR_BIT(DDRB,Copy_u8Pin); PORTB = SET_BIT(PORTB,Copy_u8Pin);break;
				case DIO_PORTC: DDRC = CLR_BIT(DDRC,Copy_u8Pin); PORTC = SET_BIT(PORTC,Copy_u8Pin);break;
				case DIO_PORTD: DDRD = CLR_BIT(DDRD,Copy_u8Pin); PORTD = SET_BIT(PORTD,Copy_u8Pin);break;
				default:	return;	/*do nothing*/
			}
		}

		else{
			/*do nothing*/
			return;
		}
		
	}
	else{
		/*do nothing*/
	}
}


void DIO_voidSetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value){
	if(Copy_u8Pin < 8){
		if (Copy_u8Value == DIO_HIGH){
			switch(Copy_u8Port){
				case DIO_PORTA: PORTA = SET_BIT(PORTA,Copy_u8Pin); break;
				case DIO_PORTB: PORTB = SET_BIT(PORTB,Copy_u8Pin); break;
				case DIO_PORTC: PORTC = SET_BIT(PORTC,Copy_u8Pin); break;
				case DIO_PORTD: PORTD = SET_BIT(PORTD,Copy_u8Pin); break;
				default:	return;/*do nothing*/
			}
		}
		else if (Copy_u8Value == DIO_LOW){
			switch(Copy_u8Port){
				case DIO_PORTA: PORTA = CLR_BIT(PORTA,Copy_u8Pin); break;
				case DIO_PORTB: PORTB = CLR_BIT(PORTB,Copy_u8Pin); break;
				case DIO_PORTC: PORTC = CLR_BIT(PORTC,Copy_u8Pin); break;
				case DIO_PORTD: PORTD = CLR_BIT(PORTD,Copy_u8Pin); break;
				default:	return;/*do nothing*/
			}			
		}
		else{
			/*do nothing*/
			return;
		}
		
	}
	else{
		/*do nothing*/
		return;
	}	
}

void DIO_voidTogglePinValue (u8 Copy_u8Port, u8 Copy_u8Pin){
	if(Copy_u8Pin < 8){
			switch(Copy_u8Port){
				case DIO_PORTA: PORTA = TGL_BIT(PORTA,Copy_u8Pin); break;
				case DIO_PORTB: PORTB = TGL_BIT(PORTB,Copy_u8Pin); break;
				case DIO_PORTC: PORTC = TGL_BIT(PORTC,Copy_u8Pin); break;
				case DIO_PORTD: PORTD = TGL_BIT(PORTD,Copy_u8Pin); break;
				default:	return;/*do nothing*/
			}
	}
	else{
		/*do nothing*/
		return;
	}
}
u8 DIO_u8GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin){
	if(Copy_u8Pin < 8){
		switch(Copy_u8Port){
			case DIO_PORTA: return GET_BIT(PINA,Copy_u8Pin); 
			case DIO_PORTB: return GET_BIT(PINB,Copy_u8Pin);
			case DIO_PORTC: return GET_BIT(PINC,Copy_u8Pin); 
			case DIO_PORTD: return GET_BIT(PIND,Copy_u8Pin); 
			default       :	return 0xff;              /*as a wrong entry*/						
		}
	}
	else{
		/*do nothing*/
	}	
}

void DIO_voidSetPortDirection (u8 Copy_u8Port, u8 Copy_u8DirValue){
	switch(Copy_u8Port){
		case DIO_PORTA: DDRA = Copy_u8DirValue; break;
		case DIO_PORTB: DDRB = Copy_u8DirValue; break;
		case DIO_PORTC: DDRC = Copy_u8DirValue; break;
		case DIO_PORTD: DDRD = Copy_u8DirValue; break;
		default:	return;/*do nothing*/
	}	
}

void DIO_voidSetPortValue (u8 Copy_u8Port, u8 Copy_u8Value){
	switch(Copy_u8Port){
		case DIO_PORTA: PORTA = Copy_u8Value; break;
		case DIO_PORTB: PORTB = Copy_u8Value; break;
		case DIO_PORTC: PORTC = Copy_u8Value; break;
		case DIO_PORTD: PORTD = Copy_u8Value; break;
		default:	return;/*do nothing*/
	}	
		
}
