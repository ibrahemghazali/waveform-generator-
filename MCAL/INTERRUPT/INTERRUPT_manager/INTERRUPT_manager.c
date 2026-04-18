

#include "INTERRUPT_manager.h"
#include "../EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.h"
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE

void __interrupt() ISR_HIGH_Manager(void)
{
    #if EXTERNAL_INTERRUPT_INTX_FEATURE==INTERRUPT_FEATURE_ENABLE
    if((EXTERNAL_INTERRUPT_INT0_READ_FLAG())&&(EXTERNAL_INTERRUPT_INT0_INTERRUPT_CHECK()))
    {
        ISR_INT0();
    }
    else{/*Nothing*/}
    if((EXTERNAL_INTERRUPT_INT1_READ_FLAG())&&(EXTERNAL_INTERRUPT_INT1_INTERRUPT_CHECK())&&(EXTERNAL_INTERRUPT_INT1_PRIORITY_READ()))
    {
        ISR_INT1();
    }
    else{/*Nothing*/}
    if((EXTERNAL_INTERRUPT_INT2_READ_FLAG())&&(EXTERNAL_INTERRUPT_INT2_INTERRUPT_CHECK())&&(EXTERNAL_INTERRUPT_INT2_PRIORITY_READ()))
    {
        ISR_INT2();
    }
    else{/*Nothing*/}

#endif
#if EXTERNAL_INTERRUPT_PORTB_FEATURE==INTERRUPT_FEATURE_ENABLE
    if((EXTERNAL_INTERRUPT_RBX_READ_FLAG())&&(EXTERNAL_INTERRUPT_RBX_CHECK())&&
    (EXTERNAL_INTERRUPT_RBX_PRIORITY_CHECK())&&(PORTBbits.RB4!=RB4_state))
   {
        RB4_state=PORTBbits.RB4;
        ISR_RB4();
    }
    else{/*Nothing*/}
     if((EXTERNAL_INTERRUPT_RBX_READ_FLAG())&&(EXTERNAL_INTERRUPT_RBX_CHECK())&&
    (EXTERNAL_INTERRUPT_RBX_PRIORITY_CHECK())&&(PORTBbits.RB5!=RB5_state))
   {
        RB5_state=PORTBbits.RB5;
        ISR_RB5();
    }
    else{/*Nothing*/}
    if((EXTERNAL_INTERRUPT_RBX_READ_FLAG())&&(EXTERNAL_INTERRUPT_RBX_CHECK())&&
    (EXTERNAL_INTERRUPT_RBX_PRIORITY_CHECK())&&(PORTBbits.RB6!=RB6_state))
   {
        RB6_state=PORTBbits.RB6;
        ISR_RB6();
    }
    else{/*Nothing*/}
    if((EXTERNAL_INTERRUPT_RBX_READ_FLAG())&&(EXTERNAL_INTERRUPT_RBX_CHECK())&&
    (EXTERNAL_INTERRUPT_RBX_PRIORITY_CHECK())&&(PORTBbits.RB7!=RB7_state))
   {
        RB7_state=PORTBbits.RB7;
        ISR_RB7();
    }
    else{/*Nothing*/}
#endif 
#if ADC_CONVERTING_OPTION_METHOD==ADC_CONVERTING_BY_INTERRUPT
    if(( ADC_INTERRUPT_READ_FLAG())&&(ADC_READ_ENABLE())&&(ADC_READ_PRIORITY()))
    {
        ADC_ISR();
    }
    else{/*Nothing*/}

#endif
        
#if TIMER_0_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TIMER0_INTERRUPT_READ_FLAG())&&(TIMER0_READ_ENABLE())&&(TIMER0_READ_PRIORITY()))
    {
        TIMER0_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif 
#if TIMER_1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TIMER1_INTERRUPT_READ_FLAG())&&(TIMER1_READ_ENABLE())&&(TIMER1_READ_PRIORITY()))
    {
        TIMER1_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif 
    #if TIMER_2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TIMER2_INTERRUPT_READ_FLAG())&&(TIMER2_READ_ENABLE())&&(TIMER2_READ_PRIORITY()))
    {
        TIMER2_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif 
    
#if TIMER_3_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TIMER3_INTERRUPT_READ_FLAG())&&(TIMER3_READ_ENABLE())&&(TIMER3_READ_PRIORITY()))
    {
        TIMER3_INTERRUPT_HANDLER();
        TIMER3_INTERRUPT_CLEAR_FLAG();
    }
    else
    {
        /*nothing*/
    }
#endif 
    
#if CCP1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((CCP1_INTERRUPT_READ_FLAG())&&(CCP1_READ_ENABLE())&&(CCP1_READ_PRIORITY()))
    {
        CCP1_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif

#if CCP2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((CCP2_INTERRUPT_READ_FLAG())&&(CCP2_READ_ENABLE())&&(CCP2_READ_PRIORITY()))
    {
        CCP2_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
    
#if TX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TX_INTERRUPT_READ_FLAG())&&(TX_READ_ENABLE())&&(TX_READ_PRIORITY()))
    {
        TX_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
    
#if RX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((RX_INTERRUPT_READ_FLAG())&&(RX_READ_ENABLE())&&(RX_READ_PRIORITY()))
    {
        RX_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
    
#if SPI_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((SPI_INTERRUPT_READ_FLAG())&&(SPI_READ_ENABLE())&&(SPI_READ_PRIORITY()))
    {
        SPI_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
}

void __interrupt(low_priority) ISR_LOW_Manager(void)
{
    #if EXTERNAL_INTERRUPT_INTX_FEATURE==INTERRUPT_FEATURE_ENABLE
    if((EXTERNAL_INTERRUPT_INT0_READ_FLAG())&&(EXTERNAL_INTERRUPT_INT0_INTERRUPT_CHECK()))
    {
        ISR_INT0();
    }
    else{/*Nothing*/}
    if((EXTERNAL_INTERRUPT_INT1_READ_FLAG())&&(EXTERNAL_INTERRUPT_INT1_INTERRUPT_CHECK())&&(!EXTERNAL_INTERRUPT_INT1_PRIORITY_READ()))
    {
        ISR_INT1();
    }
    else{/*Nothing*/}
    if((EXTERNAL_INTERRUPT_INT2_READ_FLAG())&&(EXTERNAL_INTERRUPT_INT2_INTERRUPT_CHECK())&&(!EXTERNAL_INTERRUPT_INT2_PRIORITY_READ()))
    {
        ISR_INT2();
    }
    else{/*Nothing*/}
#endif
#if EXTERNAL_INTERRUPT_PORTB_FEATURE==INTERRUPT_FEATURE_ENABLE
    if((EXTERNAL_INTERRUPT_RBX_READ_FLAG())&&(EXTERNAL_INTERRUPT_RBX_CHECK())&&
    (!EXTERNAL_INTERRUPT_RBX_PRIORITY_CHECK())&&(PORTBbits.RB4!=RB4_state))
   {
        RB4_state=PORTBbits.RB4;
        ISR_RB4();
    }
    else{/*Nothing*/}
     if((EXTERNAL_INTERRUPT_RBX_READ_FLAG())&&(EXTERNAL_INTERRUPT_RBX_CHECK())&&
    (!EXTERNAL_INTERRUPT_RBX_PRIORITY_CHECK())&&(PORTBbits.RB5!=RB5_state))
   {
        RB5_state=PORTBbits.RB5;
        ISR_RB5();
    }
    else{/*Nothing*/}
    if((EXTERNAL_INTERRUPT_RBX_READ_FLAG())&&(EXTERNAL_INTERRUPT_RBX_CHECK())&&
    (!EXTERNAL_INTERRUPT_RBX_PRIORITY_CHECK())&&(PORTBbits.RB6!=RB6_state))
   {
        RB6_state=PORTBbits.RB6;
        ISR_RB6();
    }
    else{/*Nothing*/}
    if((EXTERNAL_INTERRUPT_RBX_READ_FLAG())&&(EXTERNAL_INTERRUPT_RBX_CHECK())&&
    (!EXTERNAL_INTERRUPT_RBX_PRIORITY_CHECK())&&(PORTBbits.RB7!=RB7_state))
   {
        RB7_state=PORTBbits.RB7;
        ISR_RB7();
    }
    else{/*Nothing*/}
#endif
    
    #if ADC_CONVERTING_OPTION_METHOD==ADC_CONVERTING_BY_INTERRUPT
    if(( ADC_INTERRUPT_READ_FLAG())&&(ADC_READ_ENABLE())&&(0==ADC_READ_PRIORITY()))
    {
       ADC_ISR();
    }
    else{/*Nothing*/}

#endif
    
    #if TIMER_0_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TIMER0_INTERRUPT_READ_FLAG())&&(TIMER0_READ_ENABLE())&&(!TIMER0_READ_PRIORITY()))
    {
        TIMER0_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif 
#if TIMER_1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TIMER1_INTERRUPT_READ_FLAG())&&(TIMER1_READ_ENABLE())&&(!TIMER1_READ_PRIORITY()))
    {
        TIMER1_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif 
    #if TIMER_2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TIMER2_INTERRUPT_READ_FLAG())&&(TIMER2_READ_ENABLE())&&(!TIMER2_READ_PRIORITY()))
    {
        TIMER2_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif 
    
    #if TIMER_3_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TIMER3_INTERRUPT_READ_FLAG())&&(TIMER3_READ_ENABLE())&&(!TIMER3_READ_PRIORITY()))
    {
        TIMER3_INTERRUPT_HANDLER();
        TIMER3_INTERRUPT_CLEAR_FLAG();
    }
    else
    {
        /*nothing*/
    }
#endif 
    
    
        #if CCP1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((CCP1_INTERRUPT_READ_FLAG())&&(CCP1_READ_ENABLE())&&(!CCP1_READ_PRIORITY()))
    {
        CCP1_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif

#if CCP2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((CCP2_INTERRUPT_READ_FLAG())&&(CCP2_READ_ENABLE())&&(!CCP2_READ_PRIORITY()))
    {
        CCP2_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
    
#if TX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TX_INTERRUPT_READ_FLAG())&&(TX_READ_ENABLE())&&(!TX_READ_PRIORITY()))
    {
        TX_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
    
#if RX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((RX_INTERRUPT_READ_FLAG())&&(RX_READ_ENABLE())&&(!RX_READ_PRIORITY()))
    {
        RX_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
    
#if SPI_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((SPI_INTERRUPT_READ_FLAG())&&(SPI_READ_ENABLE())&&(!SPI_READ_PRIORITY()))
    {
        SPI_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
}

#elif INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_DISABLE
void __interrupt() ISR_HIGH_Manager(void)
{
    #if EXTERNAL_INTERRUPT_INTX_FEATURE==INTERRUPT_FEATURE_ENABLE
    if((EXTERNAL_INTERRUPT_INT0_READ_FLAG())&&(EXTERNAL_INTERRUPT_INT0_INTERRUPT_CHECK()))
    {
        ISR_INT0();
    }
    else{/*Nothing*/}
    if((EXTERNAL_INTERRUPT_INT1_READ_FLAG())&&(EXTERNAL_INTERRUPT_INT1_INTERRUPT_CHECK()))
    {
        ISR_INT1();
    }
    else{/*Nothing*/}
    if((EXTERNAL_INTERRUPT_INT2_READ_FLAG())&&(EXTERNAL_INTERRUPT_INT2_INTERRUPT_CHECK()))
    {
        ISR_INT2();
    }
    else{/*Nothing*/}
#endif
#if EXTERNAL_INTERRUPT_PORTB_FEATURE==INTERRUPT_FEATURE_ENABLE
    if((EXTERNAL_INTERRUPT_RBX_READ_FLAG())&&(EXTERNAL_INTERRUPT_RBX_CHECK())&&(PORTBbits.RB4!=RB4_state))
   {
        RB4_state=PORTBbits.RB4;
        ISR_RB4();
    }
    else{/*Nothing*/}
     if((EXTERNAL_INTERRUPT_RBX_READ_FLAG())&&(EXTERNAL_INTERRUPT_RBX_CHECK())&&(PORTBbits.RB5!=RB5_state))
   {
        RB5_state=PORTBbits.RB5;
        ISR_RB5();
    }
    else{/*Nothing*/}
    if((EXTERNAL_INTERRUPT_RBX_READ_FLAG())&&(EXTERNAL_INTERRUPT_RBX_CHECK())&&(PORTBbits.RB6!=RB6_state))
   {
        RB6_state=PORTBbits.RB6;
        ISR_RB6();
    }
    else{/*Nothing*/}
    if((EXTERNAL_INTERRUPT_RBX_READ_FLAG())&&(EXTERNAL_INTERRUPT_RBX_CHECK())&&(PORTBbits.RB7!=RB7_state))
   {
        RB7_state=PORTBbits.RB7;
        ISR_RB7();
    }
    else{/*Nothing*/}
#endif
        #if ADC_CONVERTING_OPTION_METHOD==ADC_CONVERTING_BY_INTERRUPT
    if(( ADC_INTERRUPT_READ_FLAG())&&(ADC_READ_ENABLE()))
    {
      ADC_ISR();
    }
    else{/*Nothing*/}

#endif
    
    #if TIMER_0_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TIMER0_INTERRUPT_READ_FLAG())&&(TIMER0_READ_ENABLE()))
    {
        TIMER0_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
#if TIMER_1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TIMER1_INTERRUPT_READ_FLAG())&&(TIMER1_READ_ENABLE()))
    {
        TIMER1_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
#if TIMER_2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TIMER2_INTERRUPT_READ_FLAG())&&(TIMER2_READ_ENABLE()))
    {
        TIMER2_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
    
    #if TIMER_3_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TIMER3_INTERRUPT_READ_FLAG())&&(TIMER3_READ_ENABLE()))
    {
        TIMER3_INTERRUPT_HANDLER();
        TIMER3_INTERRUPT_CLEAR_FLAG();
    }
    else
    {
        /*nothing*/
    }
#endif
    
        #if CCP1_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((CCP1_INTERRUPT_READ_FLAG())&&(CCP1_READ_ENABLE()))
    {
        CCP1_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
    
#if CCP2_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((CCP2_INTERRUPT_READ_FLAG())&&(CCP2_READ_ENABLE()))
    {
        CCP2_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
    
#if TX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((TX_INTERRUPT_READ_FLAG())&&(TX_READ_ENABLE()))
    {
        TX_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
    
#if RX_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((RX_INTERRUPT_READ_FLAG())&&(RX_READ_ENABLE()))
    {
        RX_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
    
#if SPI_INTERRUPT==INTERRUPT_FEATURE_ENABLE
    if((SPI_INTERRUPT_READ_FLAG())&&(SPI_READ_ENABLE()))
    {
        SPI_INTERRUPT_HANDLER();
    }
    else
    {
        /*nothing*/
    }
#endif
}


#endif