#ifndef  __ExternalInterrupt_
#define _ExternalInterrupt

#include <avr/io.h>
#include <stdint.h>           
#include <avr/interrupt.h>

// volatile uint8_t *pPortBhistory;     // default is high because the pull-up
// volatile uint8_t *pPortChistory;     // default is high because the pull-up
 //volatile uint8_t *pPortDhistory;     // default is high because the pull-up

 void InitExInterruptRegister0(void);
 void InitExInterruptRegister1(void);
 void InitExInterruptRegister2(void);





 uint8_t *pChangedbits;
  uint8_t *pPortBhistory;     // default is high because the pull-up
   uint8_t *pPortChistory;     // default is high because the pull-up
   uint8_t *pPortDhistory;     // default is high because the pull-up
#endif
