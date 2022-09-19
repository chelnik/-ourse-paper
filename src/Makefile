
OS := $(shell uname -s)
NAME	=	s21_matrix.a

SRC = createMatrix.c
SRCALL = createMatrix.c aditionalFunctions.c
OBJ		=	$(SRC:%.c=%.o)

CC 		= gcc -std=c11

CFLAGS	= -Wall -Wextra -Werror

# TEST = test_andry.c
# TEST = test_gleb.c
TEST = test_serega.c
FLAGS_PLATFORM = -lcheck

GCOVFLAGS = -fprofile-arcs -ftest-coverage
REPORT = GcovReport
# Переменная для тестов отдельно под систему мак и линукс
ifeq ($(OS), Darwin)
	FLAGS_PLATFORM = -lcheck
else
	FLAGS_PLATFORM = -lcheck -lsubunit -lrt -lm -lpthread -g
endif

.PHONY: all clean test s21_matrix.a gcov_report

all: $(NAME)

# Сборка библиотеки
$(NAME): $(OBJ) $(HEADER)
	@ar rcs $(NAME) $?
	@rm -f *.o

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

testing:
	@make clean
	@gcc -g $(CFLAGS) main.c $(SRCALL) && ./a.out
	@make clean

test:
	@gcc $(CFLAGS) $(TEST) $(SRC) $(FLAGS_PLATFORM) -o tests.out
	@./tests.out

clean:
	@rm -rf *.o *.so *.gcda *.gcno *.gch rep.info *.html *.css report *.txt *.info *.dSYM *.out

fclean: clean
	@rm -f $(NAME)
	@rm -rf report

lint:
	@cp ../materials/linters/CPPLINT.cfg ./
	@python3 ./../materials/linters/cpplint.py --extensions=c *.c *.h
	@rm -f CPPLINT.cfg

gcov_report:
	gcc $(GCOVFLAGS) $(TEST) $(SRC) $(FLAGS_PLATFORM) -o $(REPORT)
	chmod +x *
	./GcovReport
	lcov -t "$(REPORT)" -o $(REPORT).info -c -d .
	genhtml -o report $(REPORT).info
	rm -rf ./*.gcno ./*.gcda ./$(REPORT).*
	open ./report/index.html
	rm $(REPORT)
	rm -rf *.dSYM

valgrind: $(NAME)
	@echo -------------------MEMORY_LEAKS-------------------
	@echo $(CC) -g $(TEST) $(NAME) $(FLAGS_PLATFORM) -o unit.out
	@echoCK_FORK=no valgrind --leak-check=full -s ./unit.out	

check: $(NAME)
	@echo ---------------------CPPCHECK---------------------
	cppcheck *.h $(SRC)
	@echo ---------------------CPPLINT----------------------
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c $(SRC) $(TEST) *.h *.c
	rm CPPLINT.cfg
	@echo -------------------MEMORY_LEAKS-------------------
	$(CC) -g $(TEST) $(NAME) $(FLAGS_PLATFORM) -o unit.out
	CK_FORK=no leaks --atExit -- ./unit.out

# rebuild
# re: clean test


