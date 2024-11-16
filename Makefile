TARGETS=hello stacktest
ALL: $(TARGETS)

clean:
	rm *.o $(TARGETS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stacktest: stacktest.o main.o
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.f90
	gfortran -O3 -c -o $@ $<

hello: hello.o stackcheck.o
	gfortran -o $@ $^ $(CFLAGS)
