# lpc213x-7segment-driver
LPC213x 7segment driver library - mux 4 digit

features:
- Configurable pins (seglib.h)
- Configurable seven segment type [CA - CC] (seglib.h)

```c
// Config connected pin direction and level
void segConfig(void);  
```
```c
// Clear 7segment
void segClear(void);
```
```c
// Write custom digit on custom 7segment position (7segment digit)
void segWriteDigit(unsigned char digit, unsigned char pos);
```
```c
// Write full number (4digit) on 7segment
void segWrite(int num);
```
