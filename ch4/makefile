objects = main.o getop.o getch.o stack.o \

LDFLAGS = -lm

CFLAGS = -g -Wall

ch4_example.o: $(objects)
		cc $(objects) $(CFLAGS) -o ch4_example.o -lm

main.o: calc.h

getop.o: calc.h

getch.o: calc.h

stack.o: stack.c calc.h

.PHONY: clean
clean: 
	-rm ch4_example.o $(objects)