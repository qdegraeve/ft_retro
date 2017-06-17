#include "Ennemy.hpp"
#include <iostream>

/*************************     CONSTRUCTORS     *******************************/

Ennemy::Ennemy(void) {

	std::cout << "Default constructor called" << std::endl;
	return ;
}

Ennemy::Ennemy(Ennemy const & src) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

/*************************     DESTRUCTORS     ********************************/

Ennemy::~Ennemy(void) {
	std::cout << "Destructor called" << std::endl;
}

/*************************     OPERATORS OVERLOAD     *************************/

Ennemy &	Ennemy::operator=(Ennemy const & rhs) {

	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs) {
		this->_pos_x = rhs.get_pos_x();
		this->_pos_x = rhs.get_pos_y();
		this->_speed = rhs.get_speed();
		this->_life = rhs.get_life();
	}
	
	return *this;
}

/*************************     GETTERS      ***********************************/

/*************************     SETTERS      ***********************************/

/*************************     PUBLIC MEMBER FUNCTIONS      *******************/

/*************************     PRIVATE MEMBER FUNCTIONS     *******************/

/*************************     NON MEMBER FUNTIONS     ************************/

/*************************     EXTERNAL OVERLOADS     *************************/
