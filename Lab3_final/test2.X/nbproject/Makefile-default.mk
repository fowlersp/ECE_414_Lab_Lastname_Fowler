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
FINAL_IMAGE=${DISTDIR}/test2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/test2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../test.X/main.c ../test.X/porta_in.c ../test.X/portb_out.c ../test.X/ztimer.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/792833749/main.o ${OBJECTDIR}/_ext/792833749/porta_in.o ${OBJECTDIR}/_ext/792833749/portb_out.o ${OBJECTDIR}/_ext/792833749/ztimer.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/792833749/main.o.d ${OBJECTDIR}/_ext/792833749/porta_in.o.d ${OBJECTDIR}/_ext/792833749/portb_out.o.d ${OBJECTDIR}/_ext/792833749/ztimer.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/792833749/main.o ${OBJECTDIR}/_ext/792833749/porta_in.o ${OBJECTDIR}/_ext/792833749/portb_out.o ${OBJECTDIR}/_ext/792833749/ztimer.o

# Source Files
SOURCEFILES=../test.X/main.c ../test.X/porta_in.c ../test.X/portb_out.c ../test.X/ztimer.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/test2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX250F128B
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
${OBJECTDIR}/_ext/792833749/main.o: ../test.X/main.c  .generated_files/flags/default/96a83308bad740eb35d126357ae81f8d7d4505a6 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/792833749" 
	@${RM} ${OBJECTDIR}/_ext/792833749/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/792833749/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/792833749/main.o.d" -o ${OBJECTDIR}/_ext/792833749/main.o ../test.X/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/792833749/porta_in.o: ../test.X/porta_in.c  .generated_files/flags/default/c5c26698f132ebf5235e38317704345df77d75ed .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/792833749" 
	@${RM} ${OBJECTDIR}/_ext/792833749/porta_in.o.d 
	@${RM} ${OBJECTDIR}/_ext/792833749/porta_in.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/792833749/porta_in.o.d" -o ${OBJECTDIR}/_ext/792833749/porta_in.o ../test.X/porta_in.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/792833749/portb_out.o: ../test.X/portb_out.c  .generated_files/flags/default/8934abb25a9003ec1d13226e143e87b22dd19fb2 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/792833749" 
	@${RM} ${OBJECTDIR}/_ext/792833749/portb_out.o.d 
	@${RM} ${OBJECTDIR}/_ext/792833749/portb_out.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/792833749/portb_out.o.d" -o ${OBJECTDIR}/_ext/792833749/portb_out.o ../test.X/portb_out.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/792833749/ztimer.o: ../test.X/ztimer.c  .generated_files/flags/default/f5160d4561d34ec582a05adc8634ca03a2c1e0ea .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/792833749" 
	@${RM} ${OBJECTDIR}/_ext/792833749/ztimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/792833749/ztimer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/792833749/ztimer.o.d" -o ${OBJECTDIR}/_ext/792833749/ztimer.o ../test.X/ztimer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
else
${OBJECTDIR}/_ext/792833749/main.o: ../test.X/main.c  .generated_files/flags/default/61418bed07522c46f9cf5cdc599b8e99a032a0f4 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/792833749" 
	@${RM} ${OBJECTDIR}/_ext/792833749/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/792833749/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/792833749/main.o.d" -o ${OBJECTDIR}/_ext/792833749/main.o ../test.X/main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/792833749/porta_in.o: ../test.X/porta_in.c  .generated_files/flags/default/6adcaa291a18ec3cf0f4c67569019e397e38b355 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/792833749" 
	@${RM} ${OBJECTDIR}/_ext/792833749/porta_in.o.d 
	@${RM} ${OBJECTDIR}/_ext/792833749/porta_in.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/792833749/porta_in.o.d" -o ${OBJECTDIR}/_ext/792833749/porta_in.o ../test.X/porta_in.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/792833749/portb_out.o: ../test.X/portb_out.c  .generated_files/flags/default/ca5fc5e4448a7faabda15e22640a371a6681f4ec .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/792833749" 
	@${RM} ${OBJECTDIR}/_ext/792833749/portb_out.o.d 
	@${RM} ${OBJECTDIR}/_ext/792833749/portb_out.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/792833749/portb_out.o.d" -o ${OBJECTDIR}/_ext/792833749/portb_out.o ../test.X/portb_out.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
${OBJECTDIR}/_ext/792833749/ztimer.o: ../test.X/ztimer.c  .generated_files/flags/default/54555c65b08f319fdf2f0e93fbf48e273f70073d .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/792833749" 
	@${RM} ${OBJECTDIR}/_ext/792833749/ztimer.o.d 
	@${RM} ${OBJECTDIR}/_ext/792833749/ztimer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/792833749/ztimer.o.d" -o ${OBJECTDIR}/_ext/792833749/ztimer.o ../test.X/ztimer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/test2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/test2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	
else
${DISTDIR}/test2.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/test2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/test2.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
