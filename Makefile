# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meudier <meudier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 21:07:29 by amahla            #+#    #+#              #
#    Updated: 2022/12/19 15:03:44 by amahla           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC					:=	c++
RM					:=	rm

PROG_VECTOR			:=	vector

SRCDIR				:=	srcs_tests

INCLUDEDIR			:=	templates

OBJDIR				:=	./obj
DEBUGDIR			:=	./debugobj

SRCS				:=	$(addprefix vector/,	main.cpp	)


CCFLAGS				:=  -std=c++98 -Wall -Wextra -Werror
OPTFLAG				:=

NAME				:=	$(PROG_VECTOR)

OUTDIR				:=	$(OBJDIR)

DEBUGNAME			:=	$(addsuffix .debug,$(PROGNAME))

ifdef DEBUG
	OPTFLAG 		:=	-g
	NAME			:=	$(DEBUGNAME)
	OUTDIR			:=	$(DEBUGDIR)
endif

all					:	$(NAME)

debug				:
ifndef DEBUG
	$(MAKE) DEBUG=1
endif

$(OUTDIR)/%.o		:	$(SRCDIR)/%.cpp | $(OUTDIR)
	@mkdir -p $(dir $@)
	$(CC) -c -MMD -MP $(CCFLAGS) $(OPTFLAG) $(addprefix -I ,$(INCLUDEDIR)) $< -o $@

$(NAME)				:	$(addprefix $(OUTDIR)/,$(SRCS:.cpp=.o))
	$(CC) $(CCFLAGS) $(OPTFLAG) -o $@ $^

$(OUTDIR)			:
	mkdir -p $(OUTDIR)

clean				:
	$(RM) -rf $(OBJDIR) $(DEBUGDIR)

fclean				:	clean
	$(RM) -rf $(NAME) $(DEBUGNAME) $(CGIDIR)

re					:	fclean
	$(MAKE) $(NAME) $(NAMECGI1) $(NAMECGI2)

.PHONY				:	all clean fclean re debug mac select

-include	$(addprefix $(OUTDIR)/,$(SRCS:.cpp=.d))
