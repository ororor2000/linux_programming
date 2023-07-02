TARGET: app

dll.o:dll.c
	gcc -c dll.c -o dll.o

dll_util.o:dll_util.c
	gcc -c dll_util.c -o dll_util.o

app.o:app.c
	gcc -c app.c -o app.o

app:app.o dll.o dll_util.o
	gcc app.o dll.o dll_util.o -o app

clean:
	rm *.o
	rm app	
