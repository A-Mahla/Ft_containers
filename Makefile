# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 21:07:29 by amahla            #+#    #+#              #
#    Updated: 2022/12/20 20:04:02 by amahla           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC					:=	c++
RM					:=	rm

PROG_VECTOR			:=	vector
PROG_TOOLS		:=	tools

SRCDIR				:=	srcs_tests

INCLUDEDIR			:=	templates

OBJDIR				:=	./obj
DEBUGDIR			:=	./debugobj

SRCS_TOOLS			:=	$(addprefix tools/,		main.cpp	)
SRCS_VECTOR			:=	$(addprefix vector/,	main.cpp	)


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

all					:	$(addprefix $(PROG_VECTOR), $(NAME))	\
						$(addprefix $(PROG_TOOLS), $(NAME))

debug				:
ifndef DEBUG
	$(MAKE) DEBUG=1
endif

$(OUTDIR)/%.o		:	$(SRCDIR)/%.cpp | $(OUTDIR)
	@mkdir -p $(dir $@)
	$(CC) -c -MMD -MP $(CCFLAGS) $(OPTFLAG) $(addprefix -I ,$(INCLUDEDIR)) $< -o $@

$(addprefix $(PROG_TOOLS), $(NAME))		:	$(addprefix $(OUTDIR)/,$(SRCS_TOOLS:.cpp=.o))
										$(CC) $(CCFLAGS) $(OPTFLAG) -o $@ $^

$(addprefix $(PROG_VECTOR), $(NAME))		:	$(addprefix $(OUTDIR)/,$(SRCS_VECTOR:.cpp=.o))
										$(CC) $(CCFLAGS) $(OPTFLAG) -o $@ $^

$(OUTDIR)			:
	mkdir -p $(OUTDIR)

clean				:
	$(RM) -rf $(OBJDIR) $(DEBUGDIR)

fclean				:	clean
	$(RM) -rf  $(addprefix *, $(NAME))

re					:	fclean
	$(MAKE) all

.PHONY				:	all clean fclean re debug mac select

-include	$(addprefix $(OUTDIR)/,$(SRCS_VECTOR:.cpp=.d))
-include	$(addprefix $(OUTDIR)/,$(SRCS_TOOLS:.cpp=.d))
