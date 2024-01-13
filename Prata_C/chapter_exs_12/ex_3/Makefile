%.o:	%.c
	cc $< -c -o $@

main:	main.o fun.o
	cc $^ -o $@

clean:
	rm -f main a.out *.o

