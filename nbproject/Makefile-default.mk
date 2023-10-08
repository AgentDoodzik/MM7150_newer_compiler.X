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
FINAL_IMAGE=${DISTDIR}/MM7150_newer_compiler.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/MM7150_newer_compiler.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=MM7150.c InitPIC.c main.c MainInterrupt.c UART_user.c controllers.c mikser.c servo.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/MM7150.o ${OBJECTDIR}/InitPIC.o ${OBJECTDIR}/main.o ${OBJECTDIR}/MainInterrupt.o ${OBJECTDIR}/UART_user.o ${OBJECTDIR}/controllers.o ${OBJECTDIR}/mikser.o ${OBJECTDIR}/servo.o
POSSIBLE_DEPFILES=${OBJECTDIR}/MM7150.o.d ${OBJECTDIR}/InitPIC.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/MainInterrupt.o.d ${OBJECTDIR}/UART_user.o.d ${OBJECTDIR}/controllers.o.d ${OBJECTDIR}/mikser.o.d ${OBJECTDIR}/servo.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/MM7150.o ${OBJECTDIR}/InitPIC.o ${OBJECTDIR}/main.o ${OBJECTDIR}/MainInterrupt.o ${OBJECTDIR}/UART_user.o ${OBJECTDIR}/controllers.o ${OBJECTDIR}/mikser.o ${OBJECTDIR}/servo.o

# Source Files
SOURCEFILES=MM7150.c InitPIC.c main.c MainInterrupt.c UART_user.c controllers.c mikser.c servo.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/MM7150_newer_compiler.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ2048EFH064
MP_LINKER_FILE_OPTION=
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
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/MM7150.o: MM7150.c  .generated_files/flags/default/8b41273b08c1b06aa4995911076d28fc1c793dce .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MM7150.o.d 
	@${RM} ${OBJECTDIR}/MM7150.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/MM7150.o.d" -o ${OBJECTDIR}/MM7150.o MM7150.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/InitPIC.o: InitPIC.c  .generated_files/flags/default/c93637538ee3455c59d10bf9105b7d16966b646b .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/InitPIC.o.d 
	@${RM} ${OBJECTDIR}/InitPIC.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/InitPIC.o.d" -o ${OBJECTDIR}/InitPIC.o InitPIC.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/a55a20ce68b8b2e8ce9d75708124bb94a09d3dec .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/MainInterrupt.o: MainInterrupt.c  .generated_files/flags/default/58fd799b87e64ed5da0db6943e5d2507cda30701 .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MainInterrupt.o.d 
	@${RM} ${OBJECTDIR}/MainInterrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/MainInterrupt.o.d" -o ${OBJECTDIR}/MainInterrupt.o MainInterrupt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/UART_user.o: UART_user.c  .generated_files/flags/default/b466ff6ccf4245ec8b595305aeff7f3d6143e56b .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART_user.o.d 
	@${RM} ${OBJECTDIR}/UART_user.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/UART_user.o.d" -o ${OBJECTDIR}/UART_user.o UART_user.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/controllers.o: controllers.c  .generated_files/flags/default/ed7b4fec00642c3de04f1426753df31893e8dbe9 .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/controllers.o.d 
	@${RM} ${OBJECTDIR}/controllers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/controllers.o.d" -o ${OBJECTDIR}/controllers.o controllers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mikser.o: mikser.c  .generated_files/flags/default/4ee310798e8fb703016e295e8aac9ae635ed1114 .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mikser.o.d 
	@${RM} ${OBJECTDIR}/mikser.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mikser.o.d" -o ${OBJECTDIR}/mikser.o mikser.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/servo.o: servo.c  .generated_files/flags/default/afa9a739b2ea8e94e127e656c9b172d48d8c782 .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/servo.o.d 
	@${RM} ${OBJECTDIR}/servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/servo.o.d" -o ${OBJECTDIR}/servo.o servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/MM7150.o: MM7150.c  .generated_files/flags/default/c783fe6842e5ecff09759122acd7af5489dce03e .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MM7150.o.d 
	@${RM} ${OBJECTDIR}/MM7150.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/MM7150.o.d" -o ${OBJECTDIR}/MM7150.o MM7150.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/InitPIC.o: InitPIC.c  .generated_files/flags/default/fdb7eabe43cd3bb3863684658d589bc86f3d11a8 .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/InitPIC.o.d 
	@${RM} ${OBJECTDIR}/InitPIC.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/InitPIC.o.d" -o ${OBJECTDIR}/InitPIC.o InitPIC.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/8836e3b7282c01b8ccc8de59042b6608706f6dab .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/MainInterrupt.o: MainInterrupt.c  .generated_files/flags/default/b829fa99869f0fe32e0e221e01df7126b0c5ed0c .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MainInterrupt.o.d 
	@${RM} ${OBJECTDIR}/MainInterrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/MainInterrupt.o.d" -o ${OBJECTDIR}/MainInterrupt.o MainInterrupt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/UART_user.o: UART_user.c  .generated_files/flags/default/a8b66d1bfd79846875ae872bc9f3c6f19ee1f8df .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART_user.o.d 
	@${RM} ${OBJECTDIR}/UART_user.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/UART_user.o.d" -o ${OBJECTDIR}/UART_user.o UART_user.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/controllers.o: controllers.c  .generated_files/flags/default/7cbc34b261fb6969707823221420f9f28ed464aa .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/controllers.o.d 
	@${RM} ${OBJECTDIR}/controllers.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/controllers.o.d" -o ${OBJECTDIR}/controllers.o controllers.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/mikser.o: mikser.c  .generated_files/flags/default/51d7c98b2a8a9c804d444ae63b671db7e80c8956 .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mikser.o.d 
	@${RM} ${OBJECTDIR}/mikser.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/mikser.o.d" -o ${OBJECTDIR}/mikser.o mikser.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/servo.o: servo.c  .generated_files/flags/default/81e05a6c833dbcdaa9d844f04e2aea25d1a05586 .generated_files/flags/default/c24b72d7bee263215258d3ef55fcfe58c1441450
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/servo.o.d 
	@${RM} ${OBJECTDIR}/servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/servo.o.d" -o ${OBJECTDIR}/servo.o servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/MM7150_newer_compiler.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/MM7150_newer_compiler.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/MM7150_newer_compiler.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/MM7150_newer_compiler.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/MM7150_newer_compiler.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
