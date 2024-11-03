OBJ=stacktest.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stacktest: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
