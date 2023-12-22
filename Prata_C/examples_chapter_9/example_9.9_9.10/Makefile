%.o:	%.c
	cc $< -c -o $@

example_9.9:	example_9.9.o example_9.10.o
		cc $^ -o $@

clean:
	rm -f example_9.9 a.out *.o
