mytests: mytests.o Graph.o
	g++ -o mytests mytests.o Graph.o
	./mytests

mytests.o: mytests.cpp Graph.hpp customexceptions.hpp
	g++ -c mytests.cpp -o mytests.o

Graph.o: Graph.cpp Graph.hpp customexceptions.hpp
	g++ -c Graph.cpp -o Graph.o

# clean all object files and executable for re-make or data deallocation
clean:
	rm -f *.o mytests