%.o:	%.c
	cc $< -c -o $@

r_drive0:	r_drive0.o rand0.o
		cc $^ -o $@

clean: 
	rm -f r_drive0 a.out *.o

