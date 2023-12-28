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
SOURCEFILES_QUOTED_IF_SPACED=MM7150.c InitPIC.c main.c MainInterrupt.c UART_user.c servo.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/MM7150.o ${OBJECTDIR}/InitPIC.o ${OBJECTDIR}/main.o ${OBJECTDIR}/MainInterrupt.o ${OBJECTDIR}/UART_user.o ${OBJECTDIR}/servo.o
POSSIBLE_DEPFILES=${OBJECTDIR}/MM7150.o.d ${OBJECTDIR}/InitPIC.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/MainInterrupt.o.d ${OBJECTDIR}/UART_user.o.d ${OBJECTDIR}/servo.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/MM7150.o ${OBJECTDIR}/InitPIC.o ${OBJECTDIR}/main.o ${OBJECTDIR}/MainInterrupt.o ${OBJECTDIR}/UART_user.o ${OBJECTDIR}/servo.o

# Source Files
SOURCEFILES=MM7150.c InitPIC.c main.c MainInterrupt.c UART_user.c servo.c



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
${OBJECTDIR}/MM7150.o: MM7150.c  .generated_files/flags/default/cdf8bec6fe4af6aafcab3359f24a86a5d0d0966f .generated_files/flags/default/66e7c6a827ea0b0eafb9971d01f9570a50e9a598
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MM7150.o.d 
	@${RM} ${OBJECTDIR}/MM7150.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/MM7150.o.d" -o ${OBJECTDIR}/MM7150.o MM7150.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/InitPIC.o: InitPIC.c  .generated_files/flags/default/e1d34d681ac85aaae49cbd77600a6079b5152e8a .generated_files/flags/default/66e7c6a827ea0b0eafb9971d01f9570a50e9a598
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/InitPIC.o.d 
	@${RM} ${OBJECTDIR}/InitPIC.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/InitPIC.o.d" -o ${OBJECTDIR}/InitPIC.o InitPIC.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/ceede6b55cca93683cebee9dc22288649ca48286 .generated_files/flags/default/66e7c6a827ea0b0eafb9971d01f9570a50e9a598
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/MainInterrupt.o: MainInterrupt.c  .generated_files/flags/default/bfc1e368c03cab9465943003a90ca099a028ae32 .generated_files/flags/default/66e7c6a827ea0b0eafb9971d01f9570a50e9a598
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MainInterrupt.o.d 
	@${RM} ${OBJECTDIR}/MainInterrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/MainInterrupt.o.d" -o ${OBJECTDIR}/MainInterrupt.o MainInterrupt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/UART_user.o: UART_user.c  .generated_files/flags/default/4a23074870c06480a8d7d2044f764c165acf3ce9 .generated_files/flags/default/66e7c6a827ea0b0eafb9971d01f9570a50e9a598
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART_user.o.d 
	@${RM} ${OBJECTDIR}/UART_user.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/UART_user.o.d" -o ${OBJECTDIR}/UART_user.o UART_user.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/servo.o: servo.c  .generated_files/flags/default/afcf3942c5036ebbd44301977a80f88c6c3a0726 .generated_files/flags/default/66e7c6a827ea0b0eafb9971d01f9570a50e9a598
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/servo.o.d 
	@${RM} ${OBJECTDIR}/servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/servo.o.d" -o ${OBJECTDIR}/servo.o servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
else
${OBJECTDIR}/MM7150.o: MM7150.c  .generated_files/flags/default/84a8e38fe23ce6994dba2f391fa3a47542956b77 .generated_files/flags/default/66e7c6a827ea0b0eafb9971d01f9570a50e9a598
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MM7150.o.d 
	@${RM} ${OBJECTDIR}/MM7150.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/MM7150.o.d" -o ${OBJECTDIR}/MM7150.o MM7150.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/InitPIC.o: InitPIC.c  .generated_files/flags/default/de2c668cea72948d3b3cf8da14f90d5baba3bf2e .generated_files/flags/default/66e7c6a827ea0b0eafb9971d01f9570a50e9a598
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/InitPIC.o.d 
	@${RM} ${OBJECTDIR}/InitPIC.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/InitPIC.o.d" -o ${OBJECTDIR}/InitPIC.o InitPIC.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/e0a46a5977c28dbe644a3ee80d720cdd5dee161a .generated_files/flags/default/66e7c6a827ea0b0eafb9971d01f9570a50e9a598
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/MainInterrupt.o: MainInterrupt.c  .generated_files/flags/default/3da0cf903b7b831b6dd5a8a8968f4a28cf37eaaf .generated_files/flags/default/66e7c6a827ea0b0eafb9971d01f9570a50e9a598
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MainInterrupt.o.d 
	@${RM} ${OBJECTDIR}/MainInterrupt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/MainInterrupt.o.d" -o ${OBJECTDIR}/MainInterrupt.o MainInterrupt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/UART_user.o: UART_user.c  .generated_files/flags/default/c1dd99c1aeb0e87b7a61388dd7bd3ee11cfd2337 .generated_files/flags/default/66e7c6a827ea0b0eafb9971d01f9570a50e9a598
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/UART_user.o.d 
	@${RM} ${OBJECTDIR}/UART_user.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/UART_user.o.d" -o ${OBJECTDIR}/UART_user.o UART_user.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/servo.o: servo.c  .generated_files/flags/default/4c31b68bd211fa2ab367ea778cb1f5e053cfde0b .generated_files/flags/default/66e7c6a827ea0b0eafb9971d01f9570a50e9a598
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/servo.o.d 
	@${RM} ${OBJECTDIR}/servo.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/servo.o.d" -o ${OBJECTDIR}/servo.o servo.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/MM7150_newer_compiler.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	
else
${DISTDIR}/MM7150_newer_compiler.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/MM7150_newer_compiler.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
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
