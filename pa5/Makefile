all: preproc

# build posttoken application
preproc: preproc.cpp pptoken.cpp posttoken.cpp macro.cpp ctrlexpr.cpp
	g++ -g -std=gnu++11 -Wall -DPA5 -o preproc preproc.cpp

# test posttoken application
test: all
	scripts/run_all_tests.pl preproc my
	scripts/compare_results.pl ref my

# regenerate reference test output
ref-test:
	scripts/run_all_tests.pl preproc-ref ref

clean:
	rm -rf preproc macro ctrlexpr pptoken posttoken a.out

pa1-test:
	g++ -g -std=gnu++11 -Wall -DPA1 -o pptoken pptoken.cpp
	cp pptoken ../pa1
	cd ../pa1; make test

pa2-test:
	g++ -g -std=gnu++11 -Wall -DPA2 -o posttoken posttoken.cpp
	cp posttoken ../pa2
	cd ../pa2; make test

pa3-test:
	g++ -g -O2 -std=gnu++11 -Wall -DPA3 -o ctrlexpr ctrlexpr.cpp
	cp ctrlexpr ../pa3
	cd ../pa3; make test

pa4-test:
	g++ -g -std=gnu++11 -Wall -DPA4 -o macro macro.cpp
	cp macro ../pa4
	cd ../pa4; make test


