FLAGS = -Wall -Wextra -Werror

all: test gcov_report

re: clean all

test: sb_math.a build_sb_math
	gcc $(FLAGS) -lcheck sb_math_test.c sb_math.a -o sb_tests
	./sb_tests

gcov_report: sb_math.c sb_math_test.c
	gcc $(FLAGS) --coverage -lcheck sb_math.c sb_math_test.c -o gcov_report
	./gcov_report
	lcov -t "./gcov_report" -o gcov_report.info --no-external -c -d .
	genhtml -o report gcov_report.info
	open ./report/index.html

sb_math.a: build_sb_math

build_sb_math:
	gcc $(FLAGS) -c sb_math.c
	ar rc sb_math.a sb_math.o
	ranlib sb_math.a

check:
	cppcheck *.c
	cp ../materials/linters/cpplint.py ./
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h

clean_obj:
	rm -rf *.o

clean_lib: 
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf gcov_report
	rm -rf report
	rm -rf sb_tests
	rm -rf cpplint.py
	rm -rf CPPLINT.cfg

clean: clean_lib clean_test clean_obj
	rm -rf sb_math