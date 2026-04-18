#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/COTS_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/COTS_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU/BUTTON/BUTTON.c ECU/KEYPAD/KEYPAD.c ECU/LCD/LCD.c ECU/LED/LED.c ECU/LM_35/LM_35.c ECU/MOTOR_DRIVER/MOTOR_DRIVER.c ECU/RELAY/RELAY.c ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.c ECU/ECU_init.c MCAL/ADC/ADC.c MCAL/CCP/CCP.c MCAL/DEVICE_CONFIG/DEVICE_CONFIG.c MCAL/EEPROM/EEPROM.c MCAL/EUSART/EUSART.c MCAL/GPIO/GPIO.c MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.c MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.c MCAL/SPI/SPI.c MCAL/Timers/Timer0/Timer0.c MCAL/Timers/TIMER1/Timer1.c MCAL/Timers/Timer2/Timer2.c MCAL/Timers/Timer3/Timer3.c app.c ECU/AD9833/AD9833.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU/BUTTON/BUTTON.p1 ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1 ${OBJECTDIR}/ECU/LCD/LCD.p1 ${OBJECTDIR}/ECU/LED/LED.p1 ${OBJECTDIR}/ECU/LM_35/LM_35.p1 ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1 ${OBJECTDIR}/ECU/RELAY/RELAY.p1 ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1 ${OBJECTDIR}/ECU/ECU_init.p1 ${OBJECTDIR}/MCAL/ADC/ADC.p1 ${OBJECTDIR}/MCAL/CCP/CCP.p1 ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1 ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 ${OBJECTDIR}/MCAL/EUSART/EUSART.p1 ${OBJECTDIR}/MCAL/GPIO/GPIO.p1 ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1 ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1 ${OBJECTDIR}/MCAL/SPI/SPI.p1 ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1 ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1 ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1 ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1 ${OBJECTDIR}/app.p1 ${OBJECTDIR}/ECU/AD9833/AD9833.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU/BUTTON/BUTTON.p1.d ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1.d ${OBJECTDIR}/ECU/LCD/LCD.p1.d ${OBJECTDIR}/ECU/LED/LED.p1.d ${OBJECTDIR}/ECU/LM_35/LM_35.p1.d ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1.d ${OBJECTDIR}/ECU/RELAY/RELAY.p1.d ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1.d ${OBJECTDIR}/ECU/ECU_init.p1.d ${OBJECTDIR}/MCAL/ADC/ADC.p1.d ${OBJECTDIR}/MCAL/CCP/CCP.p1.d ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1.d ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d ${OBJECTDIR}/MCAL/EUSART/EUSART.p1.d ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1.d ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1.d ${OBJECTDIR}/MCAL/SPI/SPI.p1.d ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1.d ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1.d ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1.d ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1.d ${OBJECTDIR}/app.p1.d ${OBJECTDIR}/ECU/AD9833/AD9833.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU/BUTTON/BUTTON.p1 ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1 ${OBJECTDIR}/ECU/LCD/LCD.p1 ${OBJECTDIR}/ECU/LED/LED.p1 ${OBJECTDIR}/ECU/LM_35/LM_35.p1 ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1 ${OBJECTDIR}/ECU/RELAY/RELAY.p1 ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1 ${OBJECTDIR}/ECU/ECU_init.p1 ${OBJECTDIR}/MCAL/ADC/ADC.p1 ${OBJECTDIR}/MCAL/CCP/CCP.p1 ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1 ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 ${OBJECTDIR}/MCAL/EUSART/EUSART.p1 ${OBJECTDIR}/MCAL/GPIO/GPIO.p1 ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1 ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1 ${OBJECTDIR}/MCAL/SPI/SPI.p1 ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1 ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1 ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1 ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1 ${OBJECTDIR}/app.p1 ${OBJECTDIR}/ECU/AD9833/AD9833.p1

# Source Files
SOURCEFILES=ECU/BUTTON/BUTTON.c ECU/KEYPAD/KEYPAD.c ECU/LCD/LCD.c ECU/LED/LED.c ECU/LM_35/LM_35.c ECU/MOTOR_DRIVER/MOTOR_DRIVER.c ECU/RELAY/RELAY.c ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.c ECU/ECU_init.c MCAL/ADC/ADC.c MCAL/CCP/CCP.c MCAL/DEVICE_CONFIG/DEVICE_CONFIG.c MCAL/EEPROM/EEPROM.c MCAL/EUSART/EUSART.c MCAL/GPIO/GPIO.c MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.c MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.c MCAL/SPI/SPI.c MCAL/Timers/Timer0/Timer0.c MCAL/Timers/TIMER1/Timer1.c MCAL/Timers/Timer2/Timer2.c MCAL/Timers/Timer3/Timer3.c app.c ECU/AD9833/AD9833.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/COTS_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU/BUTTON/BUTTON.p1: ECU/BUTTON/BUTTON.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU/BUTTON/BUTTON.p1.d 
	@${RM} ${OBJECTDIR}/ECU/BUTTON/BUTTON.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/BUTTON/BUTTON.p1 ECU/BUTTON/BUTTON.c 
	@-${MV} ${OBJECTDIR}/ECU/BUTTON/BUTTON.d ${OBJECTDIR}/ECU/BUTTON/BUTTON.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/BUTTON/BUTTON.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1: ECU/KEYPAD/KEYPAD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1.d 
	@${RM} ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1 ECU/KEYPAD/KEYPAD.c 
	@-${MV} ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.d ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LCD/LCD.p1: ECU/LCD/LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LCD" 
	@${RM} ${OBJECTDIR}/ECU/LCD/LCD.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LCD/LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LCD/LCD.p1 ECU/LCD/LCD.c 
	@-${MV} ${OBJECTDIR}/ECU/LCD/LCD.d ${OBJECTDIR}/ECU/LCD/LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LCD/LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LED/LED.p1: ECU/LED/LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LED" 
	@${RM} ${OBJECTDIR}/ECU/LED/LED.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LED/LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LED/LED.p1 ECU/LED/LED.c 
	@-${MV} ${OBJECTDIR}/ECU/LED/LED.d ${OBJECTDIR}/ECU/LED/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LED/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LM_35/LM_35.p1: ECU/LM_35/LM_35.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LM_35" 
	@${RM} ${OBJECTDIR}/ECU/LM_35/LM_35.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LM_35/LM_35.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LM_35/LM_35.p1 ECU/LM_35/LM_35.c 
	@-${MV} ${OBJECTDIR}/ECU/LM_35/LM_35.d ${OBJECTDIR}/ECU/LM_35/LM_35.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LM_35/LM_35.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1: ECU/MOTOR_DRIVER/MOTOR_DRIVER.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/MOTOR_DRIVER" 
	@${RM} ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1.d 
	@${RM} ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1 ECU/MOTOR_DRIVER/MOTOR_DRIVER.c 
	@-${MV} ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.d ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/RELAY/RELAY.p1: ECU/RELAY/RELAY.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/RELAY" 
	@${RM} ${OBJECTDIR}/ECU/RELAY/RELAY.p1.d 
	@${RM} ${OBJECTDIR}/ECU/RELAY/RELAY.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/RELAY/RELAY.p1 ECU/RELAY/RELAY.c 
	@-${MV} ${OBJECTDIR}/ECU/RELAY/RELAY.d ${OBJECTDIR}/ECU/RELAY/RELAY.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/RELAY/RELAY.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1: ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/SEVEN_SEGMENT" 
	@${RM} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1.d 
	@${RM} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1 ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.c 
	@-${MV} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.d ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/ECU_init.p1: ECU/ECU_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU" 
	@${RM} ${OBJECTDIR}/ECU/ECU_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU/ECU_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/ECU_init.p1 ECU/ECU_init.c 
	@-${MV} ${OBJECTDIR}/ECU/ECU_init.d ${OBJECTDIR}/ECU/ECU_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/ECU_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/ADC.p1: MCAL/ADC/ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/ADC.p1 MCAL/ADC/ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/ADC.d ${OBJECTDIR}/MCAL/ADC/ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/CCP/CCP.p1: MCAL/CCP/CCP.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/CCP" 
	@${RM} ${OBJECTDIR}/MCAL/CCP/CCP.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/CCP/CCP.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/CCP/CCP.p1 MCAL/CCP/CCP.c 
	@-${MV} ${OBJECTDIR}/MCAL/CCP/CCP.d ${OBJECTDIR}/MCAL/CCP/CCP.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/CCP/CCP.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1: MCAL/DEVICE_CONFIG/DEVICE_CONFIG.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/DEVICE_CONFIG" 
	@${RM} ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1 MCAL/DEVICE_CONFIG/DEVICE_CONFIG.c 
	@-${MV} ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.d ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1: MCAL/EEPROM/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 MCAL/EEPROM/EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.d ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EUSART/EUSART.p1: MCAL/EUSART/EUSART.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EUSART" 
	@${RM} ${OBJECTDIR}/MCAL/EUSART/EUSART.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EUSART/EUSART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EUSART/EUSART.p1 MCAL/EUSART/EUSART.c 
	@-${MV} ${OBJECTDIR}/MCAL/EUSART/EUSART.d ${OBJECTDIR}/MCAL/EUSART/EUSART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EUSART/EUSART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/GPIO.p1: MCAL/GPIO/GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/GPIO.p1 MCAL/GPIO/GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/GPIO.d ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1: MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1 MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.d ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1: MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1 MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.d ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/SPI/SPI.p1: MCAL/SPI/SPI.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/SPI" 
	@${RM} ${OBJECTDIR}/MCAL/SPI/SPI.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/SPI/SPI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/SPI/SPI.p1 MCAL/SPI/SPI.c 
	@-${MV} ${OBJECTDIR}/MCAL/SPI/SPI.d ${OBJECTDIR}/MCAL/SPI/SPI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/SPI/SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1: MCAL/Timers/Timer0/Timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1 MCAL/Timers/Timer0/Timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.d ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1: MCAL/Timers/TIMER1/Timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1 MCAL/Timers/TIMER1/Timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.d ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1: MCAL/Timers/Timer2/Timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1 MCAL/Timers/Timer2/Timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.d ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1: MCAL/Timers/Timer3/Timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1 MCAL/Timers/Timer3/Timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.d ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/app.p1: app.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app.p1.d 
	@${RM} ${OBJECTDIR}/app.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/app.p1 app.c 
	@-${MV} ${OBJECTDIR}/app.d ${OBJECTDIR}/app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/AD9833/AD9833.p1: ECU/AD9833/AD9833.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/AD9833" 
	@${RM} ${OBJECTDIR}/ECU/AD9833/AD9833.p1.d 
	@${RM} ${OBJECTDIR}/ECU/AD9833/AD9833.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/AD9833/AD9833.p1 ECU/AD9833/AD9833.c 
	@-${MV} ${OBJECTDIR}/ECU/AD9833/AD9833.d ${OBJECTDIR}/ECU/AD9833/AD9833.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/AD9833/AD9833.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU/BUTTON/BUTTON.p1: ECU/BUTTON/BUTTON.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/BUTTON" 
	@${RM} ${OBJECTDIR}/ECU/BUTTON/BUTTON.p1.d 
	@${RM} ${OBJECTDIR}/ECU/BUTTON/BUTTON.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/BUTTON/BUTTON.p1 ECU/BUTTON/BUTTON.c 
	@-${MV} ${OBJECTDIR}/ECU/BUTTON/BUTTON.d ${OBJECTDIR}/ECU/BUTTON/BUTTON.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/BUTTON/BUTTON.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1: ECU/KEYPAD/KEYPAD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/KEYPAD" 
	@${RM} ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1.d 
	@${RM} ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1 ECU/KEYPAD/KEYPAD.c 
	@-${MV} ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.d ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/KEYPAD/KEYPAD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LCD/LCD.p1: ECU/LCD/LCD.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LCD" 
	@${RM} ${OBJECTDIR}/ECU/LCD/LCD.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LCD/LCD.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LCD/LCD.p1 ECU/LCD/LCD.c 
	@-${MV} ${OBJECTDIR}/ECU/LCD/LCD.d ${OBJECTDIR}/ECU/LCD/LCD.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LCD/LCD.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LED/LED.p1: ECU/LED/LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LED" 
	@${RM} ${OBJECTDIR}/ECU/LED/LED.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LED/LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LED/LED.p1 ECU/LED/LED.c 
	@-${MV} ${OBJECTDIR}/ECU/LED/LED.d ${OBJECTDIR}/ECU/LED/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LED/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/LM_35/LM_35.p1: ECU/LM_35/LM_35.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/LM_35" 
	@${RM} ${OBJECTDIR}/ECU/LM_35/LM_35.p1.d 
	@${RM} ${OBJECTDIR}/ECU/LM_35/LM_35.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/LM_35/LM_35.p1 ECU/LM_35/LM_35.c 
	@-${MV} ${OBJECTDIR}/ECU/LM_35/LM_35.d ${OBJECTDIR}/ECU/LM_35/LM_35.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/LM_35/LM_35.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1: ECU/MOTOR_DRIVER/MOTOR_DRIVER.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/MOTOR_DRIVER" 
	@${RM} ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1.d 
	@${RM} ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1 ECU/MOTOR_DRIVER/MOTOR_DRIVER.c 
	@-${MV} ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.d ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/MOTOR_DRIVER/MOTOR_DRIVER.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/RELAY/RELAY.p1: ECU/RELAY/RELAY.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/RELAY" 
	@${RM} ${OBJECTDIR}/ECU/RELAY/RELAY.p1.d 
	@${RM} ${OBJECTDIR}/ECU/RELAY/RELAY.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/RELAY/RELAY.p1 ECU/RELAY/RELAY.c 
	@-${MV} ${OBJECTDIR}/ECU/RELAY/RELAY.d ${OBJECTDIR}/ECU/RELAY/RELAY.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/RELAY/RELAY.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1: ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/SEVEN_SEGMENT" 
	@${RM} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1.d 
	@${RM} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1 ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.c 
	@-${MV} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.d ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/SEVEN_SEGMENT/SEVEN_SEGMENT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/ECU_init.p1: ECU/ECU_init.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU" 
	@${RM} ${OBJECTDIR}/ECU/ECU_init.p1.d 
	@${RM} ${OBJECTDIR}/ECU/ECU_init.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/ECU_init.p1 ECU/ECU_init.c 
	@-${MV} ${OBJECTDIR}/ECU/ECU_init.d ${OBJECTDIR}/ECU/ECU_init.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/ECU_init.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/ADC/ADC.p1: MCAL/ADC/ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/ADC" 
	@${RM} ${OBJECTDIR}/MCAL/ADC/ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/ADC/ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/ADC/ADC.p1 MCAL/ADC/ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL/ADC/ADC.d ${OBJECTDIR}/MCAL/ADC/ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/ADC/ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/CCP/CCP.p1: MCAL/CCP/CCP.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/CCP" 
	@${RM} ${OBJECTDIR}/MCAL/CCP/CCP.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/CCP/CCP.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/CCP/CCP.p1 MCAL/CCP/CCP.c 
	@-${MV} ${OBJECTDIR}/MCAL/CCP/CCP.d ${OBJECTDIR}/MCAL/CCP/CCP.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/CCP/CCP.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1: MCAL/DEVICE_CONFIG/DEVICE_CONFIG.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/DEVICE_CONFIG" 
	@${RM} ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1 MCAL/DEVICE_CONFIG/DEVICE_CONFIG.c 
	@-${MV} ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.d ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/DEVICE_CONFIG/DEVICE_CONFIG.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1: MCAL/EEPROM/EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1 MCAL/EEPROM/EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.d ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EEPROM/EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/EUSART/EUSART.p1: MCAL/EUSART/EUSART.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/EUSART" 
	@${RM} ${OBJECTDIR}/MCAL/EUSART/EUSART.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/EUSART/EUSART.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/EUSART/EUSART.p1 MCAL/EUSART/EUSART.c 
	@-${MV} ${OBJECTDIR}/MCAL/EUSART/EUSART.d ${OBJECTDIR}/MCAL/EUSART/EUSART.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/EUSART/EUSART.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/GPIO/GPIO.p1: MCAL/GPIO/GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/GPIO/GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/GPIO/GPIO.p1 MCAL/GPIO/GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL/GPIO/GPIO.d ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/GPIO/GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1: MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1 MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.d ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/EXTERNAL_INTERRUPT/EXTERNAL_INTERRUPT.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1: MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager" 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1 MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.d ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/INTERRUPT/INTERRUPT_manager/INTERRUPT_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/SPI/SPI.p1: MCAL/SPI/SPI.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/SPI" 
	@${RM} ${OBJECTDIR}/MCAL/SPI/SPI.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/SPI/SPI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/SPI/SPI.p1 MCAL/SPI/SPI.c 
	@-${MV} ${OBJECTDIR}/MCAL/SPI/SPI.d ${OBJECTDIR}/MCAL/SPI/SPI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/SPI/SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1: MCAL/Timers/Timer0/Timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/Timer0" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1 MCAL/Timers/Timer0/Timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.d ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/Timer0/Timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1: MCAL/Timers/TIMER1/Timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/TIMER1" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1 MCAL/Timers/TIMER1/Timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.d ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/TIMER1/Timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1: MCAL/Timers/Timer2/Timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1 MCAL/Timers/Timer2/Timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.d ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/Timer2/Timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1: MCAL/Timers/Timer3/Timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL/Timers/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1 MCAL/Timers/Timer3/Timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.d ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL/Timers/Timer3/Timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/app.p1: app.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app.p1.d 
	@${RM} ${OBJECTDIR}/app.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/app.p1 app.c 
	@-${MV} ${OBJECTDIR}/app.d ${OBJECTDIR}/app.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/app.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU/AD9833/AD9833.p1: ECU/AD9833/AD9833.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU/AD9833" 
	@${RM} ${OBJECTDIR}/ECU/AD9833/AD9833.p1.d 
	@${RM} ${OBJECTDIR}/ECU/AD9833/AD9833.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU/AD9833/AD9833.p1 ECU/AD9833/AD9833.c 
	@-${MV} ${OBJECTDIR}/ECU/AD9833/AD9833.d ${OBJECTDIR}/ECU/AD9833/AD9833.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU/AD9833/AD9833.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/COTS_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/COTS_2.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/COTS_2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/COTS_2.X.${IMAGE_TYPE}.hex 
	
	
else
${DISTDIR}/COTS_2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/COTS_2.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/COTS_2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
