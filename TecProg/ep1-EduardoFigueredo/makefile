

assembly: assembly.s
	yasm -f elf64 -g dwarf2 assembly.s -o assembly.o
	ld assembly.o -o assembly
	