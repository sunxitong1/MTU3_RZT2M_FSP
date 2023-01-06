/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#include "bsp_api.h"
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (1)
#endif
/* ISR prototypes */
void mtu3_counter_overflow_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_TCIV4 ((IRQn_Type) 93) /* TCIV4 (MTU4.TCNT overflow/underflow) */
typedef enum IRQn {
	SoftwareGeneratedInt0 = -32,
	SoftwareGeneratedInt1 = -31,
	SoftwareGeneratedInt2 = -30,
	SoftwareGeneratedInt3 = -29,
	SoftwareGeneratedInt4 = -28,
	SoftwareGeneratedInt5 = -27,
	SoftwareGeneratedInt6 = -26,
	SoftwareGeneratedInt7 = -25,
	SoftwareGeneratedInt8 = -24,
	SoftwareGeneratedInt9 = -23,
	SoftwareGeneratedInt10 = -22,
	SoftwareGeneratedInt11 = -21,
	SoftwareGeneratedInt12 = -20,
	SoftwareGeneratedInt13 = -19,
	SoftwareGeneratedInt14 = -18,
	SoftwareGeneratedInt15 = -17,
	DebugCommunicationsChannelInt = -10,
	PerformanceMonitorCounterOverflowInt = -9,
	CrossTriggerInterfaceInt = -8,
	VritualCPUInterfaceMaintenanceInt = -7,
	HypervisorTimerInt = -6,
	VirtualTimerInt = -5,
	NonSecurePhysicalTimerInt = -2,
	TCIV4_IRQn = 93, /* TCIV4 (MTU4.TCNT overflow/underflow) */
	SHARED_PERIPHERAL_INTERRUPTS_MAX_ENTRIES = BSP_VECTOR_TABLE_MAX_ENTRIES
} IRQn_Type;
#endif /* VECTOR_DATA_H */
