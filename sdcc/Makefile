GPATH = ../src

GDEFS =\
    -DGSDCC

GFLAGS =\
#--std-c89 \
#--std-c99 \
#--std-c11 \ 

GOBJS =\
    main.rel \
    GSeos.rel \
    GUart.rel \
    GDelay.rel \
    GLed.rel \

all: $(GOBJS)
	sdcc $(GOBJS) $(GFLAGS)
	packihx main.ihx > GProject.hex 
main.rel: $(GPATH)/main.c
	sdcc -c $(GPATH)/main.c $(GDEFS) $(GFLAGS)
GSeos.rel: $(GPATH)/manager/GSeos.c
	sdcc -c $(GPATH)/manager/GSeos.c $(GDEFS) $(GFLAGS)
GUart.rel: $(GPATH)/manager/GUart.c
	sdcc -c $(GPATH)/manager/GUart.c $(GDEFS) $(GFLAGS)
GDelay.rel: $(GPATH)/manager/GDelay.c
	sdcc -c $(GPATH)/manager/GDelay.c $(GDEFS) $(GFLAGS)
GLed.rel: $(GPATH)/manager/GLed.c
	sdcc -c $(GPATH)/manager/GLed.c $(GDEFS) $(GFLAGS)
clean:
	del *.rel *.lst *.rst *.hex *.ihx *.asm *.sym *.lk *.map *.mem
