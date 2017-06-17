#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <string>
# include <ncurses.h>

# define OUTSPACE 4

class Window {

public:

	Window(void);
	Window(int const lines, int const begin);
	Window(Window const & src);
	~Window();

	Window &	operator=(Window const & rhs);

	int			get_lines(void) const;
	int			get_cols(void) const;
	WINDOW		*get_win(void) const;
	void		set_size();

private:

	WINDOW		*_win;
	int			_lines;
	int			_cols;

};

std::ostream &		operator<<(std::ostream & o, Window const & rhs);

#endif
