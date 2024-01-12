%.o:	%.c
	cc $< -c -o $@

manydice:	manydice.o diceroll.o
		cc $^ -o $@

clean: 
	rm -f manydice a.out *.o

