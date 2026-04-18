#include "EXTERNAL_INTERRUPT.h"
#if EXTERNAL_INTERRUPT_INTX_FEATURE== INTERRUPT_FEATURE_ENABLE
static pin_config_t INT0_pin_config=
{
    .direction=GPIO_INPUT,
    .port=GPIO_PORTB,
    .pin=GPIO_PIN0,
    .logic=GPIO_LOW
};
static pin_config_t INT1_pin_config=
{
    .direction=GPIO_INPUT,
    .port=GPIO_PORTB,
    .pin=GPIO_PIN1,
    .logic=GPIO_LOW
};
static pin_config_t INT2_pin_config=
{
    .direction=GPIO_INPUT,
    .port=GPIO_PORTB,
    .pin=GPIO_PIN2,
    .logic=GPIO_LOW
};
#endif

#if EXTERNAL_INTERRUPT_PORTB_FEATURE== INTERRUPT_FEATURE_ENABLE
static pin_config_t RB4_pin_config=
{
    .direction=GPIO_INPUT,
    .port=GPIO_PORTB,
    .pin=GPIO_PIN4,
    .logic=GPIO_LOW
};
static pin_config_t RB5_pin_config=
{
    .direction=GPIO_INPUT,
    .port=GPIO_PORTB,
    .pin=GPIO_PIN5,
    .logic=GPIO_LOW
};
static pin_config_t RB6_pin_config=
{
    .direction=GPIO_INPUT,
    .port=GPIO_PORTB,
    .pin=GPIO_PIN6,
    .logic=GPIO_LOW
};
static pin_config_t RB7_pin_config=
{
    .direction=GPIO_INPUT,
    .port=GPIO_PORTB,
    .pin=GPIO_PIN7,
    .logic=GPIO_LOW
};
#endif

#if EXTERNAL_INTERRUPT_INTX_FEATURE== INTERRUPT_FEATURE_ENABLE
static STD_RETURN_TYPE INTERRUPT_INT0_init(INTERRUPT_INTx_pin_t *interrupt_pin);
static STD_RETURN_TYPE INTERRUPT_INT1_init(INTERRUPT_INTx_pin_t *interrupt_pin);
static STD_RETURN_TYPE INTERRUPT_INT2_init(INTERRUPT_INTx_pin_t *interrupt_pin);

static void (*ISR_INT0_ptr)(void)=NULL;
static void (*ISR_INT1_ptr)(void)=NULL;
static void (*ISR_INT2_ptr)(void)=NULL;
#endif

#if EXTERNAL_INTERRUPT_PORTB_FEATURE== INTERRUPT_FEATURE_ENABLE
static STD_RETURN_TYPE INTERRUPT_RB4_init(INTERRUPT_RBx_pin_t *interrupt_pin);
static STD_RETURN_TYPE INTERRUPT_RB5_init(INTERRUPT_RBx_pin_t *interrupt_pin);
static STD_RETURN_TYPE INTERRUPT_RB6_init(INTERRUPT_RBx_pin_t *interrupt_pin);
static STD_RETURN_TYPE INTERRUPT_RB7_init(INTERRUPT_RBx_pin_t *interrupt_pin);

static void (*ISR_RB4_ptr)(void)=NULL;
static void (*ISR_RB5_ptr)(void)=NULL;
static void (*ISR_RB6_ptr)(void)=NULL;
static void (*ISR_RB7_ptr)(void)=NULL;
#endif

#if EXTERNAL_INTERRUPT_INTX_FEATURE== INTERRUPT_FEATURE_ENABLE
void ISR_INT0(void); 
void ISR_INT1(void);
void ISR_INT2(void);
#endif

#if EXTERNAL_INTERRUPT_PORTB_FEATURE== INTERRUPT_FEATURE_ENABLE
void ISR_RB4(void); 
void ISR_RB5(void);
void ISR_RB6(void);
void ISR_RB7(void);
#endif

#if EXTERNAL_INTERRUPT_INTX_FEATURE== INTERRUPT_FEATURE_ENABLE
STD_RETURN_TYPE EXTERNAL_INTERRUPT_INTx_init(INTERRUPT_INTx_pin_t *interrupt_pin)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==interrupt_pin)
    {
        ret=E_NOK;
    }
    else
    {
        switch(interrupt_pin->pin_index)
        {
            case INT0_pin: ret&=INTERRUPT_INT0_init(interrupt_pin); break;
            case INT1_pin : ret&=INTERRUPT_INT1_init(interrupt_pin); break;
            case INT2_pin : ret&=INTERRUPT_INT2_init(interrupt_pin); break;
            default :ret=E_NOK;
        }
    }
    return ret;
}
#endif
#if EXTERNAL_INTERRUPT_PORTB_FEATURE==INTERRUPT_FEATURE_ENABLE
STD_RETURN_TYPE EXTERNAL_INTERRUPT_RBx_init(INTERRUPT_RBx_pin_t *interrupt_pin)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==interrupt_pin)
    {
        ret=E_NOK;
    }
    else
    {
        switch(interrupt_pin->pin_index)
        {
            case RB4_pin: INTERRUPT_RB4_init(interrupt_pin);  break;
            case RB5_pin: INTERRUPT_RB5_init(interrupt_pin);   break;
            case RB6_pin: INTERRUPT_RB6_init(interrupt_pin); break;
            case RB7_pin: INTERRUPT_RB7_init(interrupt_pin);  break;
            default: ret=E_NOK;
        }
    }
    return ret;
}
#endif
#if EXTERNAL_INTERRUPT_INTX_FEATURE== INTERRUPT_FEATURE_ENABLE
static STD_RETURN_TYPE INTERRUPT_INT0_init(INTERRUPT_INTx_pin_t *interrupt_pin)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==interrupt_pin)
    {
        ret=E_NOK;
    }
    else
    {
//enabling global and perphiral interrupt 
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_FEATURE_ENABLE();
        INTERRUPT_HIGH_PRIORITY_ENABLE();
        INTERRUPT_LOW_PRIORITY_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
#elif INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_DISABLE
INTERRUPT_PRIORITY_FEATURE_DISABLE();
INTERRUPT_GLOBAL_ENABLE();
PERIPHERAL_INTERRUPT_ENABLE();

#else 
#error "INvalid configurations"
#endif 


        //Disable interrupt before initializing it 
        EXTERNAL_INTERRUPT_INT0_INTERRUPT_DISABLE();
        //clearing flag
        EXTERNAL_INTERRUPT_INT0_CLEAR_FLAG();
        //initializing pin
        ret&=GPIO_PIN_initialize(&INT0_pin_config);
        //determining interrupt_edge
        if(FALLING_EDGE==interrupt_pin->edge)
        {
            EXTERNAL_INTERRUPT_INT0_FALLING_EDGE_ENABLE();
        }
        else if(RISING_EDGE==interrupt_pin->edge)
        {
            EXTERNAL_INTERRUPT_INT0_RISING_EDGE_ENABLE();
        }
        else
        {
         ret=E_NOK;   
        }
        //determining priority 
        
        //INT0 is high priority all time
        
        
        //sending ISR address 
        ISR_INT0_ptr=interrupt_pin->ISR_handler;
        //enabling pin to interrupt
        EXTERNAL_INTERRUPT_INT0_INTERRUPT_ENABLE();
        
    }
    return ret;
}


static STD_RETURN_TYPE INTERRUPT_INT1_init(INTERRUPT_INTx_pin_t *interrupt_pin)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==interrupt_pin)
    {
        ret=E_NOK;
    }
    else
    {
//enabling global and perphiral interrupt 
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_FEATURE_ENABLE();
        INTERRUPT_HIGH_PRIORITY_ENABLE();
        INTERRUPT_LOW_PRIORITY_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
#elif INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_DISABLE
INTERRUPT_PRIORITY_FEATURE_DISABLE();
INTERRUPT_GLOBAL_ENABLE();
PERIPHERAL_INTERRUPT_ENABLE();

#else 
#error "INvalid configurations"
#endif 


        //Disable interrupt before initializing it 
        EXTERNAL_INTERRUPT_INT1_INTERRUPT_DISABLE();
        
        
        //clearing flag
        EXTERNAL_INTERRUPT_INT1_CLEAR_FLAG();
        
        
        //initializing pin
        ret&=GPIO_PIN_initialize(&INT1_pin_config);
        
        
        //determining interrupt_edge
        if(FALLING_EDGE==interrupt_pin->edge)
        {
            EXTERNAL_INTERRUPT_INT1_FALLING_EDGE_ENABLE();
        }
        else if(RISING_EDGE==interrupt_pin->edge)
        {
            EXTERNAL_INTERRUPT_INT1_RISING_EDGE_ENABLE();
        }
        else
        {
         ret=E_NOK;   
        }
        
        
        //determining priority 
        #if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
        if(INTERRUPT_LOW_PRIORITY==interrupt_pin->priority)
        {
            EXTERNAL_INTERRUPT_INT1_LOW_PRIORITY_ENABLE();
        }
        else if(INTERRUPT_HIGH_PRIORITY==interrupt_pin->priority)
        {
            EXTERNAL_INTERRUPT_INT1_HIGH_PRIORITY_ENABLE();
        }
        else 
        {
            //nothing
        }
            
        #elif INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_DISABLE
/*nothing*/
        #else 
#error "Invalid configurations"
        #endif 

        //sending ISR address 
        ISR_INT1_ptr=interrupt_pin->ISR_handler;
        
        //enabling pin to interrupt
        EXTERNAL_INTERRUPT_INT1_INTERRUPT_ENABLE();
        
    }
    return ret;
}


static STD_RETURN_TYPE INTERRUPT_INT2_init(INTERRUPT_INTx_pin_t *interrupt_pin)
{
    STD_RETURN_TYPE ret=E_OK;
    if(NULL==interrupt_pin)
    {
        ret=E_NOK;
    }
    else
    {
//enabling global and perphiral interrupt 
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_FEATURE_ENABLE();
        INTERRUPT_HIGH_PRIORITY_ENABLE();
        INTERRUPT_LOW_PRIORITY_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
#elif INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_DISABLE
INTERRUPT_PRIORITY_FEATURE_DISABLE();
INTERRUPT_GLOBAL_ENABLE();
PERIPHERAL_INTERRUPT_ENABLE();

#else 
#error "INvalid configurations"
#endif 


        //Disable interrupt before initializing it 
        EXTERNAL_INTERRUPT_INT2_INTERRUPT_DISABLE();
        
        
        //clearing flag
        EXTERNAL_INTERRUPT_INT2_CLEAR_FLAG();
        
        
        //initializing pin
        ret&=GPIO_PIN_initialize(&INT2_pin_config);
        
        
        //determining interrupt_edge
        if(FALLING_EDGE==interrupt_pin->edge)
        {
            EXTERNAL_INTERRUPT_INT2_FALLING_EDGE_ENABLE();
        }
        else if(RISING_EDGE==interrupt_pin->edge)
        {
            EXTERNAL_INTERRUPT_INT2_RISING_EDGE_ENABLE();
        }
        else
        {
         ret=E_NOK;   
        }
        
        
        //determining priority 
        #if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
        if(INTERRUPT_LOW_PRIORITY==interrupt_pin->priority)
        {
            EXTERNAL_INTERRUPT_INT2_LOW_PRIORITY_ENABLE();
        }
        else if(INTERRUPT_HIGH_PRIORITY==interrupt_pin->priority)
        {
            EXTERNAL_INTERRUPT_INT2_HIGH_PRIORITY_ENABLE();
        }
        else 
        {
            //nothing
        }
            
        #elif INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_DISABLE
/*nothing*/
        #else 
#error "Invalid configurations"
        #endif 
        
        
        //sending ISR address 
        ISR_INT2_ptr=interrupt_pin->ISR_handler;
        
        
        //enabling pin to interrupt
        EXTERNAL_INTERRUPT_INT2_INTERRUPT_ENABLE();
        
    }
    return ret;
}
#endif

#if EXTERNAL_INTERRUPT_PORTB_FEATURE==INTERRUPT_FEATURE_ENABLE
static STD_RETURN_TYPE INTERRUPT_RB4_init(INTERRUPT_RBx_pin_t *interrupt_pin)
{
    STD_RETURN_TYPE ret=E_NOK;
    if(NULL==interrupt_pin)
    {
        ret=E_NOK;
    }
    else
    {
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_FEATURE_ENABLE();
        INTERRUPT_HIGH_PRIORITY_ENABLE();
        INTERRUPT_LOW_PRIORITY_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
#elif INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_DISABLE
INTERRUPT_PRIORITY_FEATURE_DISABLE();
INTERRUPT_GLOBAL_ENABLE();
PERIPHERAL_INTERRUPT_ENABLE();

#else 
#error "INvalid configurations"
#endif 
        /*disable the interrupt pins*/
        EXTERNAL_INTERRUPT_RBX_DISABLE();
        /*clearing the flag*/
        EXTERNAL_INTERRUPT_RBX_CLEAR_FLAG();
        /*defining the pins*/
        GPIO_PIN_initialize(&RB4_pin_config);
        /*sending ISR*/
        ISR_RB4_ptr=interrupt_pin->ISR_handler;
        /*determining priority*/
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
#if EXTRENAL_INTERRUPT_PORTB_PRIORITY==HIGH_PRIORITY
        EXTERNAL_INTERRUPT_RBX_HIGH_PRIORITY_ENABLE();
#elif   EXTRENAL_INTERRUPT_PORTB_PRIORITY==LOW_PRIORITY
        EXTERNAL_INTERRUPT_RBX_LOW_PRIORITY_ENABLE();
#else 
#error "invalid configurations"
#endif
            
#elif INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_DISABLE
     /*nothing*/   
#else 
#error "Invalid configurations"
#endif
        RB4_state=PORTBbits.RB4;
        /**enabling the interrupt*/
        EXTERNAL_INTERRUPT_RBX_ENABLE();
    }
}
static STD_RETURN_TYPE INTERRUPT_RB5_init(INTERRUPT_RBx_pin_t *interrupt_pin)
{
    STD_RETURN_TYPE ret=E_NOK;
    if(NULL==interrupt_pin)
    {
        ret=E_NOK;
    }
    else
    {
        #if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_FEATURE_ENABLE();
        INTERRUPT_HIGH_PRIORITY_ENABLE();
        INTERRUPT_LOW_PRIORITY_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
#elif INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_DISABLE
INTERRUPT_PRIORITY_FEATURE_DISABLE();
INTERRUPT_GLOBAL_ENABLE();
PERIPHERAL_INTERRUPT_ENABLE();

#else 
#error "INvalid configurations"
#endif 
        /*disable the interrupt pins*/
        EXTERNAL_INTERRUPT_RBX_DISABLE();
        /*clearing the flag*/
        EXTERNAL_INTERRUPT_RBX_CLEAR_FLAG();
        /*defining the pins*/
        GPIO_PIN_initialize(&RB5_pin_config);
        /*sending ISR*/
        ISR_RB5_ptr=interrupt_pin->ISR_handler;
        /*determining priority*/
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
#if EXTRENAL_INTERRUPT_PORTB_PRIORITY==HIGH_PRIORITY
        EXTERNAL_INTERRUPT_RBX_HIGH_PRIORITY_ENABLE();
#elif   EXTRENAL_INTERRUPT_PORTB_PRIORITY==LOW_PRIORITY
        EXTERNAL_INTERRUPT_RBX_LOW_PRIORITY_ENABLE();
#else 
#error "invalid configurations"
#endif
            
#elif INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_DISABLE
     /*nothing*/   
#else 
#error "Invalid configurations"
#endif
        RB5_state=PORTBbits.RB5;
        /**enabling the interrupt*/
        EXTERNAL_INTERRUPT_RBX_ENABLE();
    }
}
static STD_RETURN_TYPE INTERRUPT_RB6_init(INTERRUPT_RBx_pin_t *interrupt_pin)
{
    STD_RETURN_TYPE ret=E_NOK;
    if(NULL==interrupt_pin)
    {
        ret=E_NOK;
    }
    else
    {
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_FEATURE_ENABLE();
        INTERRUPT_HIGH_PRIORITY_ENABLE();
        INTERRUPT_LOW_PRIORITY_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
#elif INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_DISABLE
INTERRUPT_PRIORITY_FEATURE_DISABLE();
INTERRUPT_GLOBAL_ENABLE();
PERIPHERAL_INTERRUPT_ENABLE();

#else 
#error "INvalid configurations"
#endif 
        /*disable the interrupt pins*/
        EXTERNAL_INTERRUPT_RBX_DISABLE();
        /*clearing the flag*/
        EXTERNAL_INTERRUPT_RBX_CLEAR_FLAG();
        /*defining the pins*/
        GPIO_PIN_initialize(&RB6_pin_config);
        /*sending ISR*/
        ISR_RB6_ptr=interrupt_pin->ISR_handler;
        /*determining priority*/
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
#if EXTRENAL_INTERRUPT_PORTB_PRIORITY==HIGH_PRIORITY
        EXTERNAL_INTERRUPT_RBX_HIGH_PRIORITY_ENABLE();
#elif   EXTRENAL_INTERRUPT_PORTB_PRIORITY==LOW_PRIORITY
        EXTERNAL_INTERRUPT_RBX_LOW_PRIORITY_ENABLE();
#else 
#error "invalid configurations"
#endif
            
#elif INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_DISABLE
     /*nothing*/   
#else 
#error "Invalid configurations"
#endif
        RB6_state=PORTBbits.RB6;
        /**enabling the interrupt*/
        EXTERNAL_INTERRUPT_RBX_ENABLE();
    }
}
static STD_RETURN_TYPE INTERRUPT_RB7_init(INTERRUPT_RBx_pin_t *interrupt_pin)
{
    STD_RETURN_TYPE ret=E_NOK;
    if(NULL==interrupt_pin)
    {
        ret=E_NOK;
    }
    else
    {
#if INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_FEATURE_ENABLE();
        INTERRUPT_HIGH_PRIORITY_ENABLE();
        INTERRUPT_LOW_PRIORITY_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
#elif INTERRUPT_PRIORITY_FEATURE ==INTERRUPT_FEATURE_DISABLE
INTERRUPT_PRIORITY_FEATURE_DISABLE();
INTERRUPT_GLOBAL_ENABLE();
PERIPHERAL_INTERRUPT_ENABLE();

#else 
#error "INvalid configurations"
#endif 
        /*disable the interrupt pins*/
        EXTERNAL_INTERRUPT_RBX_DISABLE();
        /*clearing the flag*/
        EXTERNAL_INTERRUPT_RBX_CLEAR_FLAG();
        /*defining the pins*/
        GPIO_PIN_initialize(&RB7_pin_config);
        /*sending ISR*/
        ISR_RB7_ptr=interrupt_pin->ISR_handler;
        /*determining priority*/
#if INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_ENABLE
#if EXTRENAL_INTERRUPT_PORTB_PRIORITY==HIGH_PRIORITY
        EXTERNAL_INTERRUPT_RBX_HIGH_PRIORITY_ENABLE();
#elif   EXTRENAL_INTERRUPT_PORTB_PRIORITY==LOW_PRIORITY
        EXTERNAL_INTERRUPT_RBX_LOW_PRIORITY_ENABLE();
#else 
#error "invalid configurations"
#endif
            
#elif INTERRUPT_PRIORITY_FEATURE==INTERRUPT_FEATURE_DISABLE
     /*nothing*/   
#else 
#error "Invalid configurations"
#endif
        RB7_state=PORTBbits.RB7;
        /**enabling the interrupt*/
        EXTERNAL_INTERRUPT_RBX_ENABLE();
    }
}


#endif

#if EXTERNAL_INTERRUPT_INTX_FEATURE== INTERRUPT_FEATURE_ENABLE

void ISR_INT0(void)
{
    EXTERNAL_INTERRUPT_INT0_CLEAR_FLAG();
    if(ISR_INT0_ptr!=NULL)
    {
        ISR_INT0_ptr();
    }
}
void ISR_INT1(void)
{
    EXTERNAL_INTERRUPT_INT1_CLEAR_FLAG();
    if(ISR_INT1_ptr!=NULL)
    {
        ISR_INT1_ptr();
    }
}
void ISR_INT2(void)
{
    EXTERNAL_INTERRUPT_INT2_CLEAR_FLAG();
    if(ISR_INT2_ptr!=NULL)
    {
        ISR_INT2_ptr();
    }
}
#endif


#if EXTERNAL_INTERRUPT_PORTB_FEATURE==INTERRUPT_FEATURE_ENABLE
void ISR_RB4(void)
{
    EXTERNAL_INTERRUPT_RBX_CLEAR_FLAG();
    if(ISR_RB4_ptr!=NULL)
    {
        ISR_RB4_ptr();
    }
}
void ISR_RB5(void)
{
    EXTERNAL_INTERRUPT_RBX_CLEAR_FLAG();
    if(ISR_RB5_ptr!=NULL)
    {
        ISR_RB5_ptr();
    }   
}
void ISR_RB6(void)
{
    EXTERNAL_INTERRUPT_RBX_CLEAR_FLAG();
    if(ISR_RB6_ptr!=NULL)
    {
        ISR_RB6_ptr();
    }    
}
void ISR_RB7(void)
{
    EXTERNAL_INTERRUPT_RBX_CLEAR_FLAG();
    if(ISR_RB7_ptr!=NULL)
    {
        ISR_RB7_ptr();
    }    
}

#endif