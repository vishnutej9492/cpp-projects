#
# Created by gmakemake (Ubuntu Sep  7 2011) on Sat Apr  5 23:27:25 2014
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s .S
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.S.s:
		$(CPP) -o $*.s $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		gcc
CXX =		g++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
CPP = $(CPP) $(CPPFLAGS)
########## Default flags (redefine these with a header.mak file if desired)
CXXFLAGS =	-ggdb
CFLAGS =	-ggdb
CLIBFLAGS =	-lm
CCLIBFLAGS =	
########## End of default flags


CPP_FILES =	Time.cpp WeatherStation.cpp WeatherStationWithRain.cpp WeatherStationWithWind.cpp WeatherStationWithWindAndRain.cpp weather.cpp
C_FILES =	
PS_FILES =	
S_FILES =	
H_FILES =	Time.h WeatherStation.h WeatherStationWithRain.h WeatherStationWithWind.h WeatherStationWithWindAndRain.h
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	Time.o WeatherStation.o WeatherStationWithRain.o WeatherStationWithWind.o WeatherStationWithWindAndRain.o 

#
# Main targets
#

all:	weather 

weather:	weather.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o weather weather.o $(OBJFILES) $(CCLIBFLAGS)

#
# Dependencies
#

Time.o:	Time.h
WeatherStation.o:	Time.h WeatherStation.h
WeatherStationWithRain.o:	Time.h WeatherStation.h WeatherStationWithRain.h
WeatherStationWithWind.o:	Time.h WeatherStation.h WeatherStationWithWind.h
WeatherStationWithWindAndRain.o:	Time.h WeatherStation.h WeatherStationWithRain.h WeatherStationWithWind.h WeatherStationWithWindAndRain.h
weather.o:	Time.h WeatherStation.h WeatherStationWithRain.h WeatherStationWithWind.h WeatherStationWithWindAndRain.h

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm $(OBJFILES) weather.o core 2> /dev/null

realclean:        clean
	-/bin/rm -rf weather 
