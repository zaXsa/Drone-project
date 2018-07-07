#ifndef USARTINIT_h
#define USARTINIT_h 
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	#define FOSC 16000000 // Clock speed
	#define BAUD 9600
	#define MYUBRR FOSC/16/BAUD-1

	/* UART Buffer Defines */
	#define UART_RX_BUFFER_SIZE 32 /* 2,4,8,16,32,64,128 or 256 bytes */
	#define UART_TX_BUFFER_SIZE 32
	#define UART_RX_BUFFER_MASK (UART_RX_BUFFER_SIZE - 1)
	#if (UART_RX_BUFFER_SIZE & UART_RX_BUFFER_MASK)
	#error RX buffer size is not a power of 2
	#endif
	#define UART_TX_BUFFER_MASK (UART_TX_BUFFER_SIZE - 1)
	#if (UART_TX_BUFFER_SIZE & UART_TX_BUFFER_MASK)
	#error TX buffer size is not a power of 2
	#endif

	/* Prototypes */
	void InitUART(unsigned int ubrr_val);
	char ReceiveByte(void);
	void TransmitByte(char data);
	void ReceiveString(char *str);
	void TransmitString(char *str);
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#endif
