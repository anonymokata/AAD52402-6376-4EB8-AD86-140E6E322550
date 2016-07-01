TARGET = romanNumeralTests

$(TARGET): checkRomanNumeral.o
	gcc $^ -o $@ -L../src -lRomanNumeral -lcheck -lpthread -lcheck_pic -lrt -lm

checkRomanNumeral.o: checkRomanNumeral.c
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)
