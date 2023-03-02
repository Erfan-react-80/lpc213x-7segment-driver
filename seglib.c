/*
 * seglib.c
 *
 *  Created on: 01/01/2023
 *  Author: Erfan Saraiy (Erfan-react-80)
 */

#include "seglib.h"
/*
	@brief Config 7seg GPIO Pins
*/
void segConfig(void){
	#ifdef SEGCC
	IO0DIR |=  (ALLDX | ALLCCX); // Set all digit and common pin as output
	IO0CLR |= ALLDX; // Low all digit pins
	IO0SET |= ALLCCX; // Turn off (A) all common pins
	#endif
	
	#ifdef SEGCA
	IO0DIR |= (ALLDX | ALLCCX); // Set all digit and common pin as output
	IO0SET |= ALLDX; // Low all digit pins
	IO0CLR |= ALLCCX; // Turn off (A) all common pins
	#endif
}

/*
	@brief Write a  digit on selected 7segment pos(7seg digit)
	@param digit: a positive decimal digit (0-9)
	@param pos: digit position on 7segment (0-3)
*/
void segWriteDigit(unsigned char digit, unsigned char pos){
	unsigned char ccs[4] = {CC1, CC2, CC3, CC4};
	unsigned char segDigits[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

	#ifdef SEGCC
	IO0SET |= ALLCCX; // Turn Off All common Pins (CC)
	IO0CLR |= (1 << ccs[pos]); // Turn on selected digit pin
	IO0SET |= segDigits[digit]; //apply num
	#endif
	
	#ifdef SEGCA
	IO0CLR |= ALLCCX; // Turn Off All common Pins (CA)
	IO0SET |= (1 << ccs[pos]); // Turn on selected digit pin
	IO0CLR |= segDigits[digit]; //apply num
	#endif
}

/*
	@brief Clear 7segment individual pins
*/
void segClear(void){
	#ifdef SEGCC	
	IO0CLR |= ALLDX;
	#endif
	#ifdef SEGCA	
	IO0SET |= ALLDX;
	#endif
}
/*
	@brief Write a 4 digit number on 7segment
*/
void segWrite(int num){
	int i, numSpell[4] = {num/1000, num/100%10, num/10%10, (num%10)}; // Split digits
	for(i = 0; i < 4; i++){
		segWriteDigit(numSpell[i], i);
		delay(10);
		segClear();
	}
}
