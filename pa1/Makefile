all: pptoken

# build pptoken application
pptoken: pptoken.cpp IPPTokenStream.h DebugPPTokenStream.h utf8.cpp
	g++ -g -std=gnu++11 -Wall -o pptoken pptoken.cpp

# test pptoken application
test: all
	scripts/run_all_tests.pl pptoken my
	scripts/compare_results.pl ref my

# regenerate reference test output
ref-test:
	scripts/run_all_tests.pl pptoken-ref ref

clean:
	rm -rf pptoken
	rm -rf a.out test.txt
