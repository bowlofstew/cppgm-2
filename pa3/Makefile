all: ctrlexpr

# build posttoken application
ctrlexpr: ctrlexpr.cpp posttoken.cpp pptoken.cpp utf8.cpp utf16.cpp
	g++ -g -std=gnu++11 -Wall -o ctrlexpr ctrlexpr.cpp

# test posttoken application
test: all
	scripts/run_all_tests.pl ctrlexpr my
	scripts/compare_results.pl ref my

# regenerate reference test output
ref-test:
	scripts/run_all_tests.pl ctrlexpr-ref ref

clean:
	rm -rf ctrlexpr pptoken posttoken a.out

pa1-test:
	g++ -g -std=gnu++11 -Wall -DPA1 -o pptoken pptoken.cpp
	cp pptoken ../pa1
	cd ../pa1; make test

pa2-test:
	g++ -g -std=gnu++11 -Wall -DPA2 -o posttoken posttoken.cpp
	cp posttoken ../pa2
	cd ../pa2; make test

   
