#include "Window.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Window::Window(void) {
	return ;
}

Window::Window(int const lines, int const begin)
	: _win(newwin(lines, COLS - OUTSPACE, begin, OUTSPACE)),
	_lines(lines - 1),
	_cols(COLS - OUTSPACE) {
	box(this->_win, 0, 0);
	wrefresh(this->_win);
	return ;
}

Window::Window(Window const & src) {

	*this = src;

	return ;
}

/*************************     DESTRUCTORS     ********************************/

Window::~Window(void) {
	std::cout << "Destructor called" << std::endl;
}

/*************************     OPERATORS OVERLOAD     *************************/

Window &	Window::operator=(Window const & rhs) {

	if (this != &rhs) {
		this->_lines = rhs.get_lines();
		this->_cols = rhs.get_cols();
	}
	
	return *this;
}

/*************************     GETTERS      ***********************************/

/*************************     SETTERS      ***********************************/

/*************************     PUBLIC MEMBER FUNCTIONS      *******************/

int			Window::get_lines(void) const {
	return (this->_lines);
}

int			Window::get_cols(void) const {
	return (this->_cols);
}

WINDOW		*Window::get_win(void) const {
	return (this->_win);
}

/*************************     PRIVATE MEMBER FUNCTIONS     *******************/

/*************************     NON MEMBER FUNTIONS     ************************/
/*************************     EXTERNAL OVERLOADS     *************************/

std::ostream &		operator<<(std::ostream & o, Window const & rhs) {
	o << "nombres de lignes == " << rhs.get_lines()
		<< std::endl << "nombre de colonnes == " << rhs.get_cols() << std::endl;

	return (o);
}


