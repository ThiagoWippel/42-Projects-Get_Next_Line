# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twippel- <twippel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 00:00:00 by twippel-          #+#    #+#              #
#    Updated: 2025/02/06 00:00:00 by twippel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= SETTINGS ================================= #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 42

# Colors for output
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

# ================================ DIRECTORIES =============================== #

SRC_DIR = src
INC_DIR = include
EXAMPLES_DIR = examples
TESTS_DIR = tests

# Mandatory
MANDATORY_DIR = $(SRC_DIR)/mandatory
MANDATORY_INC = $(INC_DIR)

# Bonus (for future implementation)
BONUS_DIR = $(SRC_DIR)/bonus
BONUS_INC = $(INC_DIR)

# ================================== SOURCES ================================= #

# Mandatory source files
SRCS_MANDATORY = $(MANDATORY_DIR)/get_next_line.c \
                 $(MANDATORY_DIR)/get_next_line_utils.c

# Bonus source files (uncomment when implemented)
# SRCS_BONUS = $(BONUS_DIR)/get_next_line_bonus.c \
#              $(BONUS_DIR)/get_next_line_utils_bonus.c

# Object files
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
# OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# ================================ EXECUTABLES =============================== #

# Test executables
TEST_MANDATORY = test_gnl
TEST_BONUS = test_gnl_bonus

# Example source files
EXAMPLE_BASIC = $(EXAMPLES_DIR)/basic_usage.c
EXAMPLE_STDIN = $(EXAMPLES_DIR)/stdin_example.c
# EXAMPLE_MULTI_FD = $(EXAMPLES_DIR)/multiple_fd_bonus.c  # For bonus

# Test source files
TEST_SRC_MANDATORY = $(TESTS_DIR)/mandatory/test_gnl.c
# TEST_SRC_BONUS = $(TESTS_DIR)/bonus/test_gnl_bonus.c  # For bonus

# ================================== RULES =================================== #

# Compilation pattern rule
%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -I$(MANDATORY_INC) -c $< -o $@

# ================================ MAIN TARGETS ============================== #

.PHONY: all clean fclean re help

all: $(TEST_MANDATORY)
	@echo "$(GREEN)✓ Mandatory part compiled successfully!$(RESET)"

# Build mandatory test executable
$(TEST_MANDATORY): $(OBJS_MANDATORY)
	@echo "$(YELLOW)Building mandatory test executable...$(RESET)"
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -I$(MANDATORY_INC) \
		$(OBJS_MANDATORY) $(TEST_SRC_MANDATORY) -o $(TEST_MANDATORY)
	@echo "$(GREEN)✓ Test executable ready: ./$(TEST_MANDATORY)$(RESET)"

# ================================= BONUS ==================================== #

# Bonus target (uncomment when implementing bonus)
# .PHONY: bonus
# bonus: $(OBJS_BONUS)
# 	@echo "$(YELLOW)Building bonus test executable...$(RESET)"
# 	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -I$(BONUS_INC) \
# 		$(OBJS_BONUS) $(TEST_SRC_BONUS) -o $(TEST_BONUS)
# 	@echo "$(GREEN)✓ Bonus compiled successfully!$(RESET)"

# ================================= TESTING ================================== #

.PHONY: test test1 test42 test1000 test10000

# Run mandatory test with default buffer
test: $(TEST_MANDATORY)
	@echo "$(YELLOW)Running test with BUFFER_SIZE=$(BUFFER_SIZE)...$(RESET)"
	@./$(TEST_MANDATORY)

# Test with BUFFER_SIZE=1
test1: BUFFER_SIZE = 1
test1: fclean $(TEST_MANDATORY)
	@echo "$(YELLOW)Testing with BUFFER_SIZE=1...$(RESET)"
	@./$(TEST_MANDATORY)

# Test with BUFFER_SIZE=42
test42: BUFFER_SIZE = 42
test42: fclean $(TEST_MANDATORY)
	@echo "$(YELLOW)Testing with BUFFER_SIZE=42...$(RESET)"
	@./$(TEST_MANDATORY)

# Test with BUFFER_SIZE=1000
test1000: BUFFER_SIZE = 1000
test1000: fclean $(TEST_MANDATORY)
	@echo "$(YELLOW)Testing with BUFFER_SIZE=1000...$(RESET)"
	@./$(TEST_MANDATORY)

# Test with BUFFER_SIZE=10000000
test10000: BUFFER_SIZE = 10000000
test10000: fclean $(TEST_MANDATORY)
	@echo "$(YELLOW)Testing with BUFFER_SIZE=10000000...$(RESET)"
	@./$(TEST_MANDATORY)

# Run all tests with different buffer sizes
testall: test1 test42 test1000 test10000
	@echo "$(GREEN)✓ All tests completed!$(RESET)"

# ================================ EXAMPLES ================================== #

.PHONY: example_basic example_stdin

# Run basic usage example
example_basic: $(OBJS_MANDATORY)
	@echo "$(YELLOW)Compiling basic usage example...$(RESET)"
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -I$(MANDATORY_INC) \
		$(OBJS_MANDATORY) $(EXAMPLE_BASIC) -o example_basic
	@echo "$(GREEN)✓ Example ready: ./example_basic$(RESET)"
	@./example_basic

# Run stdin example
example_stdin: $(OBJS_MANDATORY)
	@echo "$(YELLOW)Compiling stdin example...$(RESET)"
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -I$(MANDATORY_INC) \
		$(OBJS_MANDATORY) $(EXAMPLE_STDIN) -o example_stdin
	@echo "$(GREEN)✓ Example ready: ./example_stdin$(RESET)"
	@./example_stdin

# ================================= CLEANUP ================================== #

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJS_MANDATORY)
	@rm -f $(MANDATORY_DIR)/*.o
	# @rm -f $(OBJS_BONUS)  # Uncomment for bonus
	# @rm -f $(BONUS_DIR)/*.o  # Uncomment for bonus
	@echo "$(GREEN)✓ Clean complete!$(RESET)"

fclean: clean
	@echo "$(RED)Removing executables...$(RESET)"
	@rm -f $(TEST_MANDATORY)
	# @rm -f $(TEST_BONUS)  # Uncomment for bonus
	@rm -f example_basic example_stdin
	@echo "$(GREEN)✓ Full clean complete!$(RESET)"

re: fclean all

# =================================== HELP =================================== #

help:
	@echo "$(GREEN)╔════════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║          Get Next Line - Makefile Commands                 ║$(RESET)"
	@echo "$(GREEN)╠════════════════════════════════════════════════════════════╣$(RESET)"
	@echo "$(YELLOW)  Building:$(RESET)"
	@echo "    make              - Build mandatory test (BUFFER_SIZE=42)"
	@echo "    make bonus        - Build bonus test (when implemented)"
	@echo ""
	@echo "$(YELLOW)  Testing:$(RESET)"
	@echo "    make test         - Run test with default buffer"
	@echo "    make test1        - Test with BUFFER_SIZE=1"
	@echo "    make test42       - Test with BUFFER_SIZE=42"
	@echo "    make test1000     - Test with BUFFER_SIZE=1000"
	@echo "    make test10000    - Test with BUFFER_SIZE=10000000"
	@echo "    make testall      - Run all buffer size tests"
	@echo ""
	@echo "$(YELLOW)  Examples:$(RESET)"
	@echo "    make example_basic  - Compile and run basic example"
	@echo "    make example_stdin  - Compile and run stdin example"
	@echo ""
	@echo "$(YELLOW)  Cleanup:$(RESET)"
	@echo "    make clean        - Remove object files"
	@echo "    make fclean       - Remove objects and executables"
	@echo "    make re           - Rebuild everything"
	@echo ""
	@echo "$(YELLOW)  Other:$(RESET)"
	@echo "    make help         - Show this help message"
	@echo "$(GREEN)╚════════════════════════════════════════════════════════════╝$(RESET)"
