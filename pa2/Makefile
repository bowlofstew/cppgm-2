all: posttoken

# build posttoken application
posttoken: posttoken.cpp pptoken.cpp utf8.cpp utf16.cpp
	g++ -g -std=gnu++11 -Wall -o posttoken posttoken.cpp

# test posttoken application
test: all
	scripts/run_all_tests.pl posttoken my
	scripts/compare_results.pl ref my

# regenerate reference test output
ref-test:
	scripts/run_all_tests.pl posttoken-ref ref

clean:
	rm -rf posttoken pptoken a.out

pa1-test:
	g++ -g -std=gnu++11 -Wall -DPA1 -o pptoken pptoken.cpp
	cp ./pptoken ../pa1/
	cd ../pa1/; make test

pa1:
	g++ -g -std=gnu++11 -Wall -DPA1 -o pptoken pptoken.cpp
