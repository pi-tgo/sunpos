# Simple Makefile for sunpos v0.2
# Per-Ivar Emanuelsen - September 1998

# "stock" UNIX/X systems
CC = cc
CFLAGS =
LIBS = -lm

# linux 
# CC = gcc
 CLDFLAGS = -ffast-math
 CFLAGS = $(CLDFLAGS) -O2 -Wall 
 LDFLAGS = $(CLDFLAGS)
# LIBS = -lm

.PRECIOUS:	sunpos

OBJS =	anomaly.o eqecl.o eqhor.o gtime.o hourmin.o hrang.o julday.o \
	minsec.o nutat.o obliq.o secmin.o sun.o sunpos.o checkdate.o

all: sunpos

sunpos: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	rm -f *.o sunpos

tar:
	rm -f sunpos-0.3.tar.gz
	tar cvf sunpos-0.3.tar ./*.c ./*.h ./README ./Makefile
	gzip -9 sunpos-0.3.tar
