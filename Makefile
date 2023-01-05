# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 21:07:29 by amahla            #+#    #+#              #
#    Updated: 2023/01/05 17:28:33 by amahla           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC					:=	c++
RM					:=	rm

PROG				:=	exec
PROG_STD			:=	exec_std

SRCDIR				:=	tests

INCLUDEDIR			:=	ft

OBJDIR				:=	./obj
DEBUGDIR			:=	./debugobj

SRCS				:=	main.cpp

CCFLAGS				:=  -std=c++98 -Wall -Wextra -Werror
OPTFLAG				:=

NAME				:=	_test

OUTDIR				:=	$(OBJDIR)

DEBUGNAME			:=	$(addsuffix .debug,$(PROGNAME))

ifdef DEBUG
	OPTFLAG 		:=	-g
	NAME			:=	$(DEBUGNAME)
	OUTDIR			:=	$(DEBUGDIR)
endif

all					:	$(addprefix $(PROG), $(NAME))	\
						$(addprefix $(PROG_STD), $(NAME)) \
						$(DIFF)

debug				:
ifndef DEBUG
	$(MAKE) DEBUG=1
endif

$(OUTDIR)/%.o		:	$(SRCDIR)/%.cpp | $(OUTDIR)
	@mkdir -p $(dir $@)
	$(CC) -c -MMD -MP $(CCFLAGS) $(OPTFLAG) $(addprefix -I ,$(INCLUDEDIR)) $< -o $@

$(OUTDIR)/%_custom.o		:	$(SRCDIR)/%.cpp | $(OUTDIR)
	@mkdir -p $(dir $@)
	$(CC) -c -MMD -MP $(CCFLAGS) $(OPTFLAG) -DUSE_STL $(addprefix -I ,$(INCLUDEDIR)) $< -o $@

$(addprefix $(PROG_STD), $(NAME))		:	$(addprefix $(OUTDIR)/,$(SRCS:.cpp=_custom.o))
										$(CC) $(CCFLAGS) $(OPTFLAG) -o $@ $^

$(addprefix $(PROG), $(NAME))		:	$(addprefix $(OUTDIR)/,$(SRCS:.cpp=.o))
										$(CC) $(CCFLAGS) $(OPTFLAG) -o $@ $^

diff								: $(addprefix $(PROG_STD), $(NAME)) $(addprefix $(PROG), $(NAME))
									@./$(addprefix $(PROG_STD), $(NAME)) > test_custom
									@./$(addprefix $(PROG), $(NAME)) > test_stl
									@diff -s test_custom test_stl; [ $$? -eq 1 ]


$(OUTDIR)			:
	mkdir -p $(OUTDIR)

clean				:
	$(RM) -rf $(OBJDIR) $(DEBUGDIR)

fclean				:	clean
	$(RM) -rf  $(addprefix *, $(NAME)) test_custom test_stl

re					:	fclean
	$(MAKE) all

.PHONY				:	all clean fclean re debug diff

-include	$(addprefix $(OUTDIR)/,$(SRCS:.cpp=.d))
-include	$(addprefix $(OUTDIR)/,$(SRCS:.cpp=_custom.d))
