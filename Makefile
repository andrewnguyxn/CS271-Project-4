# Target to compile the executable
mytests: mytests.o Graph.o
	g++ -std=c++11 -o mytests mytests.o Graph.o
	./mytests

# Target to compile mytests.o
mytests.o: mytests.cpp Graph.hpp customexceptions.hpp
	g++ -std=c++11 -c mytests.cpp -o mytests.o

# Target to compile Graph.o
Graph.o: Graph.cpp Graph.hpp customexceptions.hpp
	g++ -std=c++11 -c Graph.cpp -o Graph.o

# Clean target to remove object files and executable
clean:
	rm -f *.o mytests
