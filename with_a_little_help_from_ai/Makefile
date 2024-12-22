CC=gcc
AS=nasm
LD=ld
OUTDIR=bin

all: example1 example2

example1: start_main.asm just_return.c
	$(AS) -f elf64 start_main.asm -o $(OUTDIR)/start.o
	$(CC) -c just_return.c -o $(OUTDIR)/main.o
	$(LD) $(OUTDIR)/start.o $(OUTDIR)/main.o -o $(OUTDIR)/$@

example2: inline_asm.c
	$(CC) -nostdlib -o $(OUTDIR)/$@ $<

clean:
	rm -rf bin/*

.PHONY: clean

