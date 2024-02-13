%.o: 	%.c
	cc $< -c -o $@

useheader: name_st.o useheader.o
			cc $^ -o $@

clean:
	rm -f header a.out *.o
