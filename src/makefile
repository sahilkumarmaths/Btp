all: linear main
	g++ -pg ../obj/linear.o ../obj/main.o -o ../bin/a.out
	

linear:
	g++ -pg -c linear.cpp -o ../obj/linear.o
	
main:
	g++ -pg -c main.cpp -o ../obj/main.o

clean:
	rm ../obj/*.o 
	rm ../bin/a.out
