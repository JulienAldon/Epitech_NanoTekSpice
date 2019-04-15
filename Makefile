##
## EPITECH PROJECT, 2017
## Template
## File description:
## 
##

## tests disabled (in line all:)

NAME		:= nanotekspice
SRC		:= Circuit.cpp Command.cpp Component.cpp Parser.cpp SpecialComponents.cpp Creation.cpp Errors.cpp
TEST		:=

CC		:= gcc
CXX		:= g++
NASM		:= nasm
RM		:= rm -f

CFLAGS		:= -Wall -Wextra -Werror
CXXFLAGS	:= #-Wall -Wextra -Werror
CPPFLAGS	:= -Iinclude -g
NASMFLAGS	:= -felf
LDFLAGS		:=
LDLIBS		:=

SRCDIR		:= src
OBJDIR		:= obj
DEPDIR		:= dep
TESTDIR		:= tests

OBJ		:= $(patsubst %,$(OBJDIR)/%.o,$(basename $(SRC)))
DEP		:= $(patsubst %,$(DEPDIR)/%.d,$(basename $(SRC)))
TESTOBJ		:= $(patsubst %,$(OBJDIR)/tests/%.o,$(basename $(TEST)))
TESTDEP		:= $(patsubst %,$(DEPDIR)/tests/%.d,$(basename $(TEST)))

all: $(NAME) #$(NAME)_tests

re: fclean all

auto: re clean

run: auto
	@echo "running main binary..."
	@./$(NAME)

tests: auto
	@echo "running test binary..."
	@./$(NAME)_tests

clean:
	@-$(RM) -vf $(OBJ) $(TESTOBJ) $(DEP) $(TESTDEP) $(OBJDIR)/main.o $(DEPDIR)/main.d
	@-$(RM) -rf $(OBJDIR) $(DEPDIR)

fclean: clean
	@-$(RM) -vf $(NAME) $(NAME)_tests

$(NAME): $(OBJ) $(OBJDIR)/main.o
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(OUTPUT_OPTION) $^ $(LDFLAGS) $(LDLIBS)
	@echo "linked '$@'"

$(NAME)_tests: $(OBJ) $(TESTOBJ)
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(OUTPUT_OPTION) $^ $(LDFLAGS) $(LDLIBS) -lcriterion
	@echo "linked '$@'"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPDIR)/%.d
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(OUTPUT_OPTION) -c $<
	@echo "built '$@'"

$(DEPDIR)/%.d: $(SRCDIR)/%.c 
	@mkdir -p $(shell dirname $@)
	@$(CC) -MM -MF $@ -MT '$$(OBJDIR)/$*.o' $(CPPFLAGS) $(CFLAGS) $<
	@echo "generated '$@'"

$(OBJDIR)/%.o: %.c $(DEPDIR)/%.d 
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) $(OUTPUT_OPTION) -c $<
	@echo "built '$@'"

$(DEPDIR)/%.d: %.c 
	@mkdir -p $(shell dirname $@)
	@$(CC) -MM -MF $@ -MT '$$(OBJDIR)/$*.o' $(CPPFLAGS) $(CFLAGS) $<
	@echo "generated '$@'"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPDIR)/%.d
	@mkdir -p $(shell dirname $@)
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(OUTPUT_OPTION) -c $<
	@echo "built '$@'"

$(DEPDIR)/%.d: $(SRCDIR)/%.cpp 
	@mkdir -p $(shell dirname $@)
	@$(CXX) -MM -MF $@ -MT '$$(OBJDIR)/$*.o' $(CPPFLAGS) $(CXXFLAGS) $<
	@echo "generated '$@'"

$(OBJDIR)/%.o: %.cpp $(DEPDIR)/%.d 
	@mkdir -p $(shell dirname $@)
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(OUTPUT_OPTION) -c $<
	@echo "built '$@'"

$(DEPDIR)/%.d: %.cpp 
	@mkdir -p $(shell dirname $@)
	@$(CXX) -MM -MF $@ -MT '$$(OBJDIR)/$*.o' $(CPPFLAGS) $(CXXFLAGS) $<
	@echo "generated '$@'"

$(OBJDIR)/%.o: $(SRCDIR)/%.S $(DEPDIR)/%.d
$(OBJDIR)/%.o: $(SRCDIR)/%.asm $(DEPDIR)/%.d
$(OBJDIR)/%.o: $(SRCDIR)/%.s $(DEPDIR)/%.d
	@mkdir -p $(shell dirname $@)
	@$(NASM) $(CPPFLAGS) $(NASMFLAGS) $(OUTPUT_OPTION) $<
	@echo "built '$@'"

$(DEPDIR)/%.d: $(SRCDIR)/%.S 
$(DEPDIR)/%.d: $(SRCDIR)/%.asm 
$(DEPDIR)/%.d: $(SRCDIR)/%.s 
	@mkdir -p $(shell dirname $@)
	@$(NASM) -MM -MF $@ -MT '$$(OBJDIR)/$*.o' $(CPPFLAGS) $(NASMFLAGS) $<
	@echo "generated '$@'"

$(OBJDIR)/%.o: %.S $(DEPDIR)/%.d 
$(OBJDIR)/%.o: %.asm $(DEPDIR)/%.d 
$(OBJDIR)/%.o: %.s $(DEPDIR)/%.d 
	@mkdir -p $(shell dirname $@)
	@$(NASM) $(CPPFLAGS) $(NASMFLAGS) $(OUTPUT_OPTION) $<
	@echo "built '$@'"

$(DEPDIR)/%.d: %.S 
$(DEPDIR)/%.d: %.asm 
$(DEPDIR)/%.d: %.s 
	@mkdir -p $(shell dirname $@)
	@$(NASM) -MM -MF $@ -MT '$$(OBJDIR)/$*.o' $(CPPFLAGS) $(NASMFLAGS) $<
	@echo "generated '$@'"

.PHONY: all re auto fclean clean run tests

.PRECIOUS: $(DEPDIR)/%.d

include $(wildcard $(DEPDIR)/*.d)
