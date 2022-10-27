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
FINAL_IMAGE=${DISTDIR}/Lab06.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Lab06.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../uart1.c ../ztimer4.c ../ic1.c ../oc1_plib.c pidControl.c userCommands.c ../main.c ../../Lab5/Lab05.X/tft_master.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/uart1.o ${OBJECTDIR}/_ext/1472/ztimer4.o ${OBJECTDIR}/_ext/1472/ic1.o ${OBJECTDIR}/_ext/1472/oc1_plib.o ${OBJECTDIR}/pidControl.o ${OBJECTDIR}/userCommands.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/456747157/tft_master.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/uart1.o.d ${OBJECTDIR}/_ext/1472/ztimer4.o.d ${OBJECTDIR}/_ext/1472/ic1.o.d ${OBJECTDIR}/_ext/1472/oc1_plib.o.d ${OBJECTDIR}/pidControl.o.d ${OBJECTDIR}/userCommands.o.d ${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/_ext/456747157/tft_master.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/uart1.o ${OBJECTDIR}/_ext/1472/ztimer4.o ${OBJECTDIR}/_ext/1472/ic1.o ${OBJECTDIR}/_ext/1472/oc1_plib.o ${OBJECTDIR}/pidControl.o ${OBJECTDIR}/userCommands.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/456747157/tft_master.o

# Source Files
SOURCEFILES=../uart1.c ../ztimer4.c ../ic1.c ../oc1_plib.c pidControl.c userCommands.c ../main.c ../../Lab5/Lab05.X/tft_master.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Lab06.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX150F128B
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
${OBJECTDIR}/_ext/1472/uart1.o: ../uart1.c  .generated_files/flags/default/82876074deebf8e4fa5edd3c1162bc5572337aba .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/uart1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/uart1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/uart1.o.d" -o ${OBJECTDIR}/_ext/1472/uart1.o ../uart1.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/_ext/1472/ztimer4.o: ../ztimer4.c  .generated_files/flags/default/1fac25fce66e553513d66c09f197c66eb57b8b52 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ztimer4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ztimer4.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/ztimer4.o.d" -o ${OBJECTDIR}/_ext/1472/ztimer4.o ../ztimer4.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/_ext/1472/ic1.o: ../ic1.c  .generated_files/flags/default/923309506eb4e3036cc7af17ed61f030abeacd50 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ic1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ic1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/ic1.o.d" -o ${OBJECTDIR}/_ext/1472/ic1.o ../ic1.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/_ext/1472/oc1_plib.o: ../oc1_plib.c  .generated_files/flags/default/ad2243ecc5c8d40a114fa7bc3031954242eba9f2 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/oc1_plib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/oc1_plib.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/oc1_plib.o.d" -o ${OBJECTDIR}/_ext/1472/oc1_plib.o ../oc1_plib.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/pidControl.o: pidControl.c  .generated_files/flags/default/65e02cdb4ba8ccd177e92ccac10015cefa085776 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pidControl.o.d 
	@${RM} ${OBJECTDIR}/pidControl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pidControl.o.d" -o ${OBJECTDIR}/pidControl.o pidControl.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/userCommands.o: userCommands.c  .generated_files/flags/default/10090b2dbc56cc0b9c7ba25b6d4af3a526d5d97c .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/userCommands.o.d 
	@${RM} ${OBJECTDIR}/userCommands.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/userCommands.o.d" -o ${OBJECTDIR}/userCommands.o userCommands.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  .generated_files/flags/default/5bd6f2552199cd2789f88562094778f757de2732 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/_ext/456747157/tft_master.o: ../../Lab5/Lab05.X/tft_master.c  .generated_files/flags/default/a9cacdcfb7c0e24862e8068bea61cf0abfad877e .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/456747157" 
	@${RM} ${OBJECTDIR}/_ext/456747157/tft_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/456747157/tft_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/456747157/tft_master.o.d" -o ${OBJECTDIR}/_ext/456747157/tft_master.o ../../Lab5/Lab05.X/tft_master.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
else
${OBJECTDIR}/_ext/1472/uart1.o: ../uart1.c  .generated_files/flags/default/aa50147b92b5f103d96e457d20a71c40c78a4294 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/uart1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/uart1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/uart1.o.d" -o ${OBJECTDIR}/_ext/1472/uart1.o ../uart1.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/_ext/1472/ztimer4.o: ../ztimer4.c  .generated_files/flags/default/1a2359e8d8a76b614c05fe2a8449602962ce2e12 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ztimer4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ztimer4.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/ztimer4.o.d" -o ${OBJECTDIR}/_ext/1472/ztimer4.o ../ztimer4.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/_ext/1472/ic1.o: ../ic1.c  .generated_files/flags/default/8ee21e7e28608e3e7e805fe81df43c6987f65714 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ic1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ic1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/ic1.o.d" -o ${OBJECTDIR}/_ext/1472/ic1.o ../ic1.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/_ext/1472/oc1_plib.o: ../oc1_plib.c  .generated_files/flags/default/8308516892053e4d3adb3605c76689c309e6b591 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/oc1_plib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/oc1_plib.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/oc1_plib.o.d" -o ${OBJECTDIR}/_ext/1472/oc1_plib.o ../oc1_plib.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/pidControl.o: pidControl.c  .generated_files/flags/default/78605c8af97afc8dfd5ed0daf3271111863094c3 .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/pidControl.o.d 
	@${RM} ${OBJECTDIR}/pidControl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/pidControl.o.d" -o ${OBJECTDIR}/pidControl.o pidControl.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/userCommands.o: userCommands.c  .generated_files/flags/default/b0ce3f3213ba0e08d6041fd2c7e80226087611da .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/userCommands.o.d 
	@${RM} ${OBJECTDIR}/userCommands.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/userCommands.o.d" -o ${OBJECTDIR}/userCommands.o userCommands.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  .generated_files/flags/default/f013c14949744ddf9d0033902d854806b676997d .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d" -o ${OBJECTDIR}/_ext/1472/main.o ../main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
${OBJECTDIR}/_ext/456747157/tft_master.o: ../../Lab5/Lab05.X/tft_master.c  .generated_files/flags/default/c2116fa6cf71db4cb74b35cf6743533d8ca5746c .generated_files/flags/default/fa77e48c5d6b209b0dbc904325b3870195f7a677
	@${MKDIR} "${OBJECTDIR}/_ext/456747157" 
	@${RM} ${OBJECTDIR}/_ext/456747157/tft_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/456747157/tft_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/456747157/tft_master.o.d" -o ${OBJECTDIR}/_ext/456747157/tft_master.o ../../Lab5/Lab05.X/tft_master.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -D _SUPPRESS_PLIB_WARNING   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Lab06.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab06.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  -D _SUPPRESS_PLIB_WARNING $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	
else
${DISTDIR}/Lab06.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab06.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  -D _SUPPRESS_PLIB_WARNING $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/Lab06.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
