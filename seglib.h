/*
 * seglib.h
 *
 *  Created on: 01/01/2023
 *  Author: Erfan Saraiy (Erfan-react-80)
 */

#include <LPC213x.h>
#include "delay.h"

/* 7Segment Type (CC or CA) */
//#define SEGCC
#define SEGCA

/* Common Pins */
#define CC1 10
#define CC2 11
#define CC3 12
#define CC4 13

/* Individual Pins */
#define DA 0
#define DB 1
#define DC 2
#define DD 3
#define DE 4
#define DF 5
#define DG 6

/* Quickly group pin define */
#define ALLDX (1 << DA) | (1 << DB) | (1 << DC) | (1 << DD) | (1 << DE) | (1 << DF) | (1 << DG) | (1 << CC1)
#define ALLCCX (1 << CC1) | (1 << CC2) | (1 << CC3) | (1 << CC4)

void segConfig(void);
void segWriteDigit(unsigned char digit, unsigned char pos);
void segClear(void);
void segWrite(int num);
