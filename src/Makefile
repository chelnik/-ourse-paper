NAME	=	s21_matrix.a

SRC = otherMatrixFunctions.c mainFunctions.c
SRCALL = otherMatrixFunctions.c mainFunctions.c aditionalFunctions.c
OBJ		=	$(SRC:%.c=%.o)

CC 		= gcc -std=c11

CFLAGS	= -Wall -Wextra -Werror

TEST = main.c
FLAGS_PLATFORM = -lcheck



.PHONY: all clean test s21_matrix.a
# http://linux.yaroslavl.ru/docs/prog/gnu_make_3-79_russian_manual.html#:~:text=bar%20%3A%3D%20%24(foo%3A%25.o%3D%25.c)

all: $(NAME)

# Сборка библиотеки
# все что после двоеточия это пререквизиты
# $? означает что если пререквезиты новее чем цель то он использует только те пререквизиты которые обновились
$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) $?
	rm -f *.o

# $< берет первый пререквизит в данном случае %.c и переименовывает в $@ который обращается
# к %.o и переименовывает в %.o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test:
	@make clean
	@gcc -g $(CFLAGS) main.c $(SRCALL) && ./a.out
	@make clean

clean:
	@rm -rf *.o *.so *.gcda *.gcno *.gch rep.info *.html *.css report *.txt *.info *.dSYM *.out

fclean: clean
	@rm -f $(NAME)
	@rm -rf report

lint:
	@cp ../materials/linters/CPPLINT.cfg ./
	@python3 ./../materials/linters/cpplint.py --extensions=c *.c *.h
	@rm -f CPPLINT.cfg

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



