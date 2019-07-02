XCC = gcc
AS = as
LD = ld

DEBUGFLAGS = -DDEBUG
NOPT = -O0

OPT_FLAG = -O2
CFLAGS = -c -fPIC -Wall -I. -Iinclude -Iinclude/kern -Iinclude/lib -Iinclude/usr -mcpu=arm920t -msoft-float -S
# -g: include hooks for gdb
# -c: only compile
# -mcpu=arm920t: generate code for the 920t architecture
# -fpic: emit position-independent code
# -Wall: report all warnings

ASFLAGS	= -mcpu=arm920t -mapcs-32
# -mapcs: always generate a complete stack frame

LDFLAGS = -init main -Map $(OUTDIR)/kernel.map -N  -T $(SRCDIR)/orex.ld -L/u/wbcowan/gnuarm-4.0.2/lib/gcc/arm-elf/4.0.2 -Llib

BINDIR = bin
OUTDIR = build
SRCDIR = src
ASMDIR = $(SRCDIR)/asm
KERNDIR = $(SRCDIR)/kern
LIBDIR = $(SRCDIR)/lib
USRDIR = $(SRCDIR)/usr

ASMSRC = $(wildcard $(ASMDIR)/*.asm)
OBJS = first.o calibration.o cli.o dispatch.o train.o conductor.o switches.o track.o sensors.o misc.o track_data.o time.o clock.o perf.o ns.o event.o idle.o interrupts.o message.o td.o syscalls.o scheduling.o string.o kernel.o uarts.o buffers.o io.o random.o
%.s : $(SRCDIR)/%.c
	$(XCC) $(CFLAGS) $< -o $(OUTDIR)/$@

%.s : $(KERNDIR)/%.c
	$(XCC) $(CFLAGS) $< -o $(OUTDIR)/$@

%.s : $(USRDIR)/%.c
	$(XCC) $(CFLAGS) $< -o $(OUTDIR)/$@

%.s : $(LIBDIR)/%.c
	$(XCC) $(CFLAGS) $< -o $(OUTDIR)/$@

%.o : %.s
	$(AS) $(ASFLAGS) -o $(OUTDIR)/$@ $(OUTDIR)/$<

default: CFLAGS += $(OPT_FLAG)
default: all

debug: CFLAGS += $(DEBUGFLAGS)
debug: all

nopt: CFLAGS += $(NOPT)
nopt: all

all:  folders bwio kernel.s kernel.elf

kernel.s: $(SRCDIR)/main.c $(SRCDIR)/main.h
	$(XCC) $(CFLAGS) $(SRCDIR)/main.c -o $(OUTDIR)/kernel.s

kernel.o: kernel.s
	$(AS) $(ASFLAGS) -o $(OUTDIR)/kernel.o $(OUTDIR)/kernel.s $(ASMSRC)

kernel.elf: $(OBJS)
	$(LD) $(LDFLAGS) -o $(BINDIR)/$@ $(OBJS:%.o=$(OUTDIR)/%.o) -lbwio -lgcc

folders:
	mkdir -p bin/
	mkdir -p build/
	mkdir -p lib/

bwio: bw_src/Makefile
	$(MAKE) -C bw_src/

clean:
	-rm -f $(BINDIR)/kernel.elf $(OUTDIR)/*.s $(OUTDIR)/*.o $(OUTDIR)/kernel.map
	$(MAKE) -C bw_src/ clean
