GPATH = ../src

GDEFS =\
    -DGSDCC

GFLAGS =\
#--std-c89 \
#--std-c99 \

GLIBS =\
#-LMY_LIB \

GOBJS =\
    main.rel \
    GSchHybrid.rel \
    GLed.rel \
    GDelay.rel \

all: $(GOBJS)
	sdcc $(GOBJS) $(GFLAGS) $(GLIBS)
	packihx main.ihx > GProject.hex 
main.rel: $(GPATH)/main.c
	sdcc -c $(GPATH)/main.c $(GDEFS) $(GFLAGS)
GSch.rel: $(GPATH)/manager/GSch.c
	sdcc -c $(GPATH)/manager/GSch.c $(GDEFS) $(GFLAGS)
GSchHybrid.rel: $(GPATH)/manager/GSchHybrid.c
	sdcc -c $(GPATH)/manager/GSchHybrid.c $(GDEFS) $(GFLAGS)
GSeos.rel: $(GPATH)/manager/GSeos.c
	sdcc -c $(GPATH)/manager/GSeos.c $(GDEFS) $(GFLAGS)
GInterrupt.rel: $(GPATH)/manager/GInterrupt.c
	sdcc -c $(GPATH)/manager/GInterrupt.c $(GDEFS) $(GFLAGS)
GUart.rel: $(GPATH)/manager/GUart.c
	sdcc -c $(GPATH)/manager/GUart.c $(GDEFS) $(GFLAGS)
GDelay.rel: $(GPATH)/manager/GDelay.c
	sdcc -c $(GPATH)/manager/GDelay.c $(GDEFS) $(GFLAGS)
GLed.rel: $(GPATH)/manager/GLed.c
	sdcc -c $(GPATH)/manager/GLed.c $(GDEFS) $(GFLAGS)
GStateMachine.rel: $(GPATH)/manager/GStateMachine.c
	sdcc -c $(GPATH)/manager/GStateMachine.c $(GDEFS) $(GFLAGS)
clean:
	del *.rel *.lst *.rst *.hex *.ihx *.asm *.sym *.lk *.map *.mem
