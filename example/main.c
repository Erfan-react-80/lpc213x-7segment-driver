/************************************************************************************
   Example by Erfan Saraiy | Micro2 final project | Dr Nabavi | Montazeri UN
   Author: Erfan Saraiy (Erfan-react-80)
   DESC: control 7segment value by two key (upward and backward)
************************************************************************************/


#include <LPC213x.h>
#include "delay.h"
#include "seglib.h"

typedef enum {
	increase,
	decrease
} BtnBehavior;

void buttonPressed(int* counterValue, BtnBehavior);

int main(void)
{
	BtnBehavior btn;
	int x = 2023;
	segConfig();
   while(1)
  {
		segWrite(x);
		if(!(IO1PIN & (1 << 16))){
			while(!(IO1PIN & (1 << 16)));
			buttonPressed(&x, increase);
		}
		else if(!(IO1PIN & (1 << 20))){
			while(!(IO1PIN & (1 << 20)));
			buttonPressed(&x, decrease);		
		}
	}
}

void buttonPressed(int* counterValue, BtnBehavior btn){
	if(btn == increase && *counterValue < 10000){
		*counterValue += 1;
	} else if(btn == decrease && *counterValue > 0){
		*counterValue -= 1;
	} else{
		*counterValue = 0;
	}
}
