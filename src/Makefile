FLAGS = -Wall -Wextra -Werror

all: test gcov_report

re: clean all

test: s21_math.a build_s21_math
	gcc $(FLAGS) -lcheck s21_math_test.c s21_math.a -o s21_tests
	./s21_tests

gcov_report: s21_math.c s21_math_test.c
	gcc $(FLAGS) --coverage -lcheck s21_math.c s21_math_test.c -o gcov_report
	./gcov_report
	lcov -t "./gcov_report" -o gcov_report.info --no-external -c -d .
	genhtml -o report gcov_report.info
	open ./report/index.html

s21_math.a: build_s21_math

build_s21_math:
	gcc $(FLAGS) -c s21_math.c
	ar rc s21_math.a s21_math.o
	ranlib s21_math.a

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
	rm -rf s21_tests
	rm -rf cpplint.py
	rm -rf CPPLINT.cfg

clean: clean_lib clean_test clean_obj
	rm -rf s21_math