/*
 * ts7200.h - definitions describing the ts7200 peripheral registers
 *
 * Specific to the TS-7200 ARM evaluation board
 *
 */

#define	TIMER1_BASE	0x80810000
#define	TIMER2_BASE	0x80810020
#define	TIMER3_BASE	0x80810080

#define TIMER4_LOW 0x80810060
#define TIMER4_HIGH 0x80810064 // enable bit is bit 8

#define	LDR_OFFSET	0x00000000	// 16/32 bits, RW
#define	VAL_OFFSET	0x00000004	// 16/32 bits, RO
#define CRTL_OFFSET	0x00000008	// 3 bits, RW
	#define	ENABLE_MASK	0x00000080
	#define	MODE_MASK	0x00000040
	#define	CLKSEL_MASK	0x00000008
#define CLR_OFFSET	0x0000000c	// no data, WO


#define LED_ADDRESS	0x80840020
	#define LED_NONE	0x0
	#define LED_GREEN	0x1
	#define LED_RED		0x2
	#define LED_BOTH	0x3

#define COM1	0
#define COM2	1

#define IRDA_BASE	0x808b0000
#define UART1_BASE	0x808c0000
#define UART2_BASE	0x808d0000

// All the below registers for UART1
// First nine registers (up to Ox28) for UART 2

#define UART_DATA_OFFSET	0x0	// low 8 bits
	#define DATA_MASK	0xff
#define UART_RSR_OFFSET		0x4	// low 4 bits
	#define FE_MASK		0x1
	#define PE_MASK		0x2
	#define BE_MASK		0x4
	#define OE_MASK		0x8
#define UART_LCRH_OFFSET	0x8	// low 7 bits
	#define BRK_MASK	0x1
	#define PEN_MASK	0x2	// parity enable
	#define EPS_MASK	0x4	// even parity
	#define STP2_MASK	0x8	// 2 stop bits
	#define FEN_MASK	0x10	// fifo
	#define WLEN_MASK	0x60	// word length
#define UART_LCRM_OFFSET	0xc	// low 8 bits
	#define BRDH_MASK	0xff	// MSB of baud rate divisor
#define UART_LCRL_OFFSET	0x10	// low 8 bits
	#define BRDL_MASK	0xff	// LSB of baud rate divisor
#define UART_CTRL_OFFSET	0x14	// low 8 bits
	#define UARTEN_MASK	0x1
	#define MSIEN_MASK	0x8	// modem status int
	#define RIEN_MASK	0x10	// receive int
	#define TIEN_MASK	0x20	// transmit int
	#define RTIEN_MASK	0x40	// receive timeout int
	#define LBEN_MASK	0x80	// loopback
#define UART_FLAG_OFFSET	0x18	// low 8 bits
	#define CTS_MASK	0x1
	#define DCD_MASK	0x2
	#define DSR_MASK	0x4
	#define TXBUSY_MASK	0x8
	#define RXFE_MASK	0x10	// Receive buffer empty
	#define TXFF_MASK	0x20	// Transmit buffer full
	#define RXFF_MASK	0x40	// Receive buffer full
	#define TXFE_MASK	0x80	// Transmit buffer empty
#define UART_INTR_OFFSET	0x1c // Use this to read the 4 interrupts in the UART
	#define MIS_MASK	0x1
	#define RIS_MASK	0x2
	#define TIS_MASK	0x4
	#define RTIS_MASK	0x8
#define UART_DMAR_OFFSET	0x28

// Specific to UART1

#define UART_MDMCTL_OFFSET	0x100
#define UART_MDMSTS_OFFSET	0x104
	#define MDM_DCTS_MASK	0x1
	#define MDM_DDSR_MASK	0x2
	#define MDM_TERI_MASK	0x4
	#define MDM_DDCD_MASK	0x8
	#define MDM_CTS_MASK	0x10
	#define MDM_DSR_MASK	0x20
	#define MDM_RI_MASK		0x40
	#define MDM_DCD_MASK	0x80
#define UART_HDLCCTL_OFFSET	0x20c
#define UART_HDLCAMV_OFFSET	0x210
#define UART_HDLCAM_OFFSET	0x214
#define UART_HDLCRIB_OFFSET	0x218
#define UART_HDLCSTS_OFFSET	0x21c

// INTERRUPTS

#define VIC1_BASE 0x800B0000
#define VIC2_BASE 0x800C0000

#define VIC_IRQ_STATUS_OFFSET 0x0
#define VIC_FIQ_STATUS_OFFSET 0x4
#define VIC_RAW_INTR_OFFSET 0x8
#define VIC_INT_ENABLE_OFFSET 0x10
#define VIC_INT_ENABLE_CLR_OFFSET 0x14
#define VIC_SOFT_INT_OFFSET 0x18
#define VIC_SOFT_INT_CLR_OFFSET 0x1c

// INTERUPT SOURCES
// IN VIC1

// IN VIC2
#define VICIS_64HZ_TIMER_INT_MASK 0x3
#define VICIS_1HZ_TIMER_INT_MASK 0x10
#define VICIS_TC3UI_INT_MASK 0x80000
#define VICIS_UART1_INT_MASK 0x100000
#define VICIS_UART2_INT_MASK 0x400000
