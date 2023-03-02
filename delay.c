#include "delay.h"
// danger: Approximate delay
void delay(int ms){
	unsigned long t = 1500 * ms;
	while(t--);
}
