all: linear main
	g++ ../obj/linear.o ../obj/main.o -o ../bin/a.out
	

linear:
	g++ -c linear.cpp -o ../obj/linear.o
	
main:
	g++ -c main.cpp -o ../obj/main.o

clean:
	rm ../obj/*.o 
	rm ../bin/a.out
