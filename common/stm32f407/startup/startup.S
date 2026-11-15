.syntax unified
.cpu cortex-m4
.thumb

.global Reset_Handler
.global Default_Handler

.extern main

/* Vector table */
.section .isr_vector, "a", %progbits
.align 9

.word _estack
.word Reset_Handler
.word Default_Handler       /* NMI */
.word Default_Handler       /* HardFault */
.word Default_Handler       /* MemManage */
.word Default_Handler       /* BusFault */
.word Default_Handler       /* UsageFault */

.rept 4
.word 0
.endr

.word Default_Handler       /* SVC */
.word Default_Handler       /* DebugMon */
.word 0
.word Default_Handler       /* PendSV */
.word Default_Handler       /* SysTick */

/* STM32F407 has 82 external interrupt vectors */
.rept 82
.word Default_Handler
.endr

/* Reset handler */
.section .text.Reset_Handler
.type Reset_Handler, %function

Reset_Handler:

    /* Copy initialized data from Flash to RAM */
    ldr r0, =_sidata
    ldr r1, =_sdata
    ldr r2, =_edata

copy_data:
    cmp r1, r2
    bcs zero_bss_start

    ldr r3, [r0], #4
    str r3, [r1], #4
    b copy_data

zero_bss_start:

    /* Clear BSS */
    ldr r1, =_sbss
    ldr r2, =_ebss
    movs r3, #0

zero_bss:
    cmp r1, r2
    bcs call_main

    str r3, [r1], #4
    b zero_bss

call_main:

    bl main

hang:
    b hang

.size Reset_Handler, .-Reset_Handler

/* Default exception handler */
.section .text.Default_Handler
.type Default_Handler, %function

Default_Handler:
    b .

.size Default_Handler, .-Default_Handler