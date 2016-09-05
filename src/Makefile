TARGET = libRomanNumeral.a

$(TARGET): romanNumeral.o
	ar rcs $@ $^

romanNumeral.o: romanNumeral.c romanNumeral.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)

.PHONY: test
test: $(TARGET)
