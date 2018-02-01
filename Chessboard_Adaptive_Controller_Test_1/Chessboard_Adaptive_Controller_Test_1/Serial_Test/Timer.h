#ifndef  TIMERS_H
#define TIMERS_H

#define PRE1	1
#define PRE8	8
#define PRE64	54
#define PRE256	256
#define PRE1024	1024

//Timer 0
void InitTimer0(void);
void SetTimer0Counter(int count);
void SetTimer0Prescaler(int prescaler);

//Timer 1
void InitTimer1(void);
void SetTimer1Counter(int count);
void SetTimer1Prescaler(int prescaler);

//Timer 2
void InitTimer2(void);
void SetTimer2Counter(int count);
void SetTimer2Prescaler(int prescaler);



#endif
