G++				=	g++
#############################################
TEST_SRC_PATH	=	./test_src
TEST_INC_PATH	=	./test_include
TEST_BIN_PATH	=	./test_bin
TEST_SRC		=	$(TEST_SRC_PATH)/test_Federation.cpp \
					$(TEST_SRC_PATH)/test_WarpSystem.cpp \
					$(TEST_SRC_PATH)/test_Borg.cpp \
					$(TEST_SRC_PATH)/test_Admiral.cpp \
					$(TEST_SRC_PATH)/test_BorgQueen.cpp

NAME			=	test_Ex4
#############################################

INCFLAGS		+=	-I$(TEST_INC_PATH)
CRITFLAGS		+=	--coverage -lcriterion --verbose
CPPFLAGS		+=	-Wall -Wextra -Werror $(INCFLAGS) $(CRITFLAGS) -W -std=c++23 -Wfatal-errors


SRCS			=	$(TEST_BIN_PATH)/test_main.cpp \
					$(TEST_SRC)


OBJS			=	$(SRCS:.cpp=.o)
OBJS_GCDA		=	$(SRCS:.cpp=.gcda)
OBJS_GCNO		=	$(SRCS:.cpp=.gcno)


all				:	$(NAME)

$(NAME)			:	$(OBJS)
					$(G++) $(OBJS) -o $(NAME) $(CPPFLAGS)

RM				=	rm -rf

clean			:
					$(RM) $(OBJS) $(OBJS_GCDA) $(OBJS_GCNO)
					$(RM) $(TEST_SRC_PATH)$(OBJS) $(TEST_SRC_PATH)$(OBJS_GCDA) $(TEST_SRC_PATH)$(OBJS_GCNO)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re