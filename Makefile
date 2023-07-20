G++						=	g++
###############################################
EX0_PATH 				= 	./Ex0_Federation
EX0_SRC_PATH			=	./Ex0_Federation/src
EX0_TST_PATH			=	./Ex0_Federation/tests
EX0_INC_PATH			=	./Ex0_Federation/include
NAME_EX0				=	Ex0
# EX0_SRC					=	$(EX0_SRC_PATH)/.cpp

EX0_SRC_TEST			=	$(EX0_TST_PATH)/$(NAME_EX0)_test.cpp
TEST_NAME_EX0 			= 	test_$(NAME_EX0)

#################################################
EX1_PATH 				= 	./Ex1_Borg
EX1_SRC_PATH			=	./Ex1_Borg/src
EX1_TST_PATH			=	./Ex1_Borg/tests
EX1_INC_PATH			=	./Ex1_Borg/include
NAME_EX1				=	Ex1
# EX0_SRC					=	$(EX0_SRC_PATH)/.cpp

EX1_SRC_TEST			=	$(EX1_TST_PATH)/$(NAME_EX1)_test.cpp
TEST_NAME_EX1 			= 	test_$(NAME_EX1)

#################################################
EX2_PATH 				= 	./Ex2_Move
EX2_SRC_PATH			=	./Ex2_Move/src
EX2_TST_PATH			=	./Ex2_Move/tests
EX2_INC_PATH			=	./Ex2_Move/include
NAME_EX2				=	Ex2
# EX0_SRC					=	$(EX0_SRC_PATH)/.cpp

EX2_SRC_TEST			=	$(EX2_TST_PATH)/$(NAME_EX2)_test.cpp
TEST_NAME_EX2 			= 	test_$(NAME_EX2)

#################################################
EX3_PATH 				= 	./Ex3_War
EX3_SRC_PATH			=	./Ex3_War/src
EX3_TST_PATH			=	./Ex3_War/tests
EX3_INC_PATH			=	./Ex3_War/include
NAME_EX3				=	Ex3
# EX0_SRC					=	$(EX0_SRC_PATH)/.cpp

EX3_SRC_TEST			=	$(EX3_TST_PATH)/$(NAME_EX3)_test.cpp
TEST_NAME_EX3 			= 	test_$(NAME_EX3)

#################################################
EX4_PATH 				= 	./Ex4_Commander
EX4_SRC_PATH			=	./Ex4_Commander/src
EX4_TST_PATH			=	./Ex4_Commander/tests
EX4_INC_PATH			=	./Ex4_Commander/include
NAME_EX4				=	Ex4
# EX0_SRC					=	$(EX0_SRC_PATH)/.cpp

EX4_SRC_TEST			=	$(EX3_TST_PATH)/$(NAME_EX4)_test.cpp
TEST_NAME_EX4 			= 	test_$(NAME_EX4)

#################################################
OBJS					=	$(SRCS:.cpp=.o)
CLEAN					=	clean
FCLEAN					=	fclean
RM						=	rm -rf

clean					:	
							$(RM) $(OBJS)
							@$(MAKE) $(CLEAN) -C $(EX0_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(EX1_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(EX2_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(EX3_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(EX4_TST_PATH)

fclean					:	clean
							$(RM) $(NAME) $(TEST_NAME)
							@$(MAKE) $(FCLEAN) -C $(EX0_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX0_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX1_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX1_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX2_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX2_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX3_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX3_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX4_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(EX4_PATH)

re						: 	fclean all

Ex0 					: 	fclean
							@$(MAKE) -C $(EX0_PATH)
							$(EX0_PATH)/$(NAME_EX0)

tests_run_Ex0			:	fclean
							@$(MAKE) -C $(EX0_TST_PATH)
							$(EX0_TST_PATH)/$(TEST_NAME_EX0)

Ex1 					: 	fclean
							@$(MAKE) -C $(EX1_PATH)
							$(EX1_PATH)/$(NAME_EX1)

tests_run_Ex1			:	fclean
							@$(MAKE) -C $(EX1_TST_PATH)
							$(EX1_TST_PATH)/$(TEST_NAME_EX1)

Ex2 					: 	fclean
							@$(MAKE) -C $(EX2_PATH)
							$(EX2_PATH)/$(NAME_EX2)

tests_run_Ex2			:	fclean
							@$(MAKE) -C $(EX2_TST_PATH)
							$(EX2_TST_PATH)/$(TEST_NAME_EX2)

Ex3 					: 	fclean
							@$(MAKE) -C $(EX3_PATH)
							$(EX3_PATH)/$(NAME_EX3)

tests_run_Ex3			:	fclean
							@$(MAKE) -C $(EX3_TST_PATH)
							$(EX3_TST_PATH)/$(TEST_NAME_EX3)

Ex4 					: 	fclean
							@$(MAKE) -C $(EX4_PATH)
							$(EX4_PATH)/$(NAME_EX4)

tests_run_Ex4			:	fclean
							@$(MAKE) -C $(EX4_TST_PATH)
							$(EX4_TST_PATH)/$(TEST_NAME_EX4)

tests_run				:	fclean
							@$(MAKE) tests_run_EX0
							@$(MAKE) tests_run_EX1
							@$(MAKE) tests_run_EX2
							@$(MAKE) tests_run_EX3
							@$(MAKE) tests_run_EX4

.PHONY					: 	all clean fclean re \
							tests_run \
							Ex0 tests_run_Ex0 \
							Ex1 tests_run_Ex1 \
							Ex2 tests_run_Ex2 \
							Ex3 tests_run_Ex3 \
							Ex4 tests_run_Ex4
