all: macro

# build posttoken application
macro: macro.cpp pptoken.cpp posttoken.cpp ctrlexpr.cpp
	g++ -g -std=gnu++11 -Wall -DPA4 -o macro macro.cpp

# test posttoken application
test: all
	scripts/run_all_tests.pl macro my
	scripts/compare_results.pl ref my

# regenerate reference test output
ref-test:
	scripts/run_all_tests.pl macro-ref ref

clean:
	rm -rf macro ctrlexpr pptoken posttoken a.out

pa1-test:
	g++ -g -std=gnu++11 -Wall -DPA1 -o pptoken pptoken.cpp
	cp pptoken ../pa1
	cd ../pa1; make test

pa2-test:
	g++ -g -std=gnu++11 -Wall -DPA2 -o posttoken posttoken.cpp
	cp posttoken ../pa2
	cd ../pa2; make test

pa3-test:
	g++ -g -std=gnu++11 -Wall -DPA3 -o ctrlexpr ctrlexpr.cpp
	cp ctrlexpr ../pa3
	cd ../pa3; make test


 
