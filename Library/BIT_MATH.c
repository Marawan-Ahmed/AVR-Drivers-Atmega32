#include <stdlib.h>
#include <stdio.h>
#include "BIT_MATH.h"
#include "STD_Types.h"

/*
void set_bit(u8 *var ,u8 bit){
	*var = *var | (1<<bit);
}
  
void clr_bit(u8 *var ,u8 bit){
	*var = *var & (~(1<<bit));
}

void tog_bit(u8 *var, u8 bit){
	*var = *var ^ (1<<bit);
}
*/

int main(){
	u8 x = 255, y = 0;
	y = SET_BIT(y,5);
	x = CLR_BIT(x,5);
	
	printf("X = %d, Y = %d", x, y);
	
	x = TOGGLE_BIT(x,5);

}