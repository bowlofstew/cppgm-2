all: allocator_test pool_test 

# build pptoken application
allocator_test: allocator.cpp
	g++ -g -std=gnu++0x -Wall -o allocator_test allocator.cpp

pool_test: pool.cpp
	g++ -g -std=c++0x -Wall -o pool_test pool.cpp

clean:
	rm -rf allocator_test pool_test
