#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/VirtualTapeRobot.o \
	${OBJECTDIR}/_ext/1047471460/stdsoap2_cpp.o \
	${OBJECTDIR}/_ext/1904203475/soapC.o \
	${OBJECTDIR}/utilties.o \
	${OBJECTDIR}/VirtualTapeDrive.o \
	${OBJECTDIR}/_ext/1904203475/soapAmazonS3SoapBindingProxy.o \
	${OBJECTDIR}/VirtualTape.o \
	${OBJECTDIR}/dllmain.o \
	${OBJECTDIR}/AmazonSimpleStorageService.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libVirtualTapeDll.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libVirtualTapeDll.so: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libVirtualTapeDll.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/VirtualTapeRobot.o: VirtualTapeRobot.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/VirtualTapeRobot.o VirtualTapeRobot.cpp

${OBJECTDIR}/_ext/1047471460/stdsoap2_cpp.o: /home/eternus/gsoap-2.8/gsoap/stdsoap2_cpp.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1047471460
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1047471460/stdsoap2_cpp.o /home/eternus/gsoap-2.8/gsoap/stdsoap2_cpp.cpp

${OBJECTDIR}/_ext/1904203475/soapC.o: ../AmazonS3/soapC.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1904203475
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1904203475/soapC.o ../AmazonS3/soapC.cpp

${OBJECTDIR}/utilties.o: utilties.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/utilties.o utilties.cpp

${OBJECTDIR}/VirtualTapeDrive.o: VirtualTapeDrive.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/VirtualTapeDrive.o VirtualTapeDrive.cpp

${OBJECTDIR}/_ext/1904203475/soapAmazonS3SoapBindingProxy.o: ../AmazonS3/soapAmazonS3SoapBindingProxy.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1904203475
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1904203475/soapAmazonS3SoapBindingProxy.o ../AmazonS3/soapAmazonS3SoapBindingProxy.cpp

${OBJECTDIR}/VirtualTape.o: VirtualTape.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/VirtualTape.o VirtualTape.cpp

${OBJECTDIR}/dllmain.o: dllmain.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/dllmain.o dllmain.cpp

${OBJECTDIR}/AmazonSimpleStorageService.o: AmazonSimpleStorageService.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/AmazonSimpleStorageService.o AmazonSimpleStorageService.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libVirtualTapeDll.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
