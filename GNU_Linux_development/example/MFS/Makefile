.PHONY: clean
CFLAGS = -Werror -Wall
TRASH = main  a.out *.o 
CFILES = $(wildcard *.c)


main:	$(CFILES:.c=.o)

clean: 
	rm -f $(TRASH)
