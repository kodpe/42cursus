#include "Socket.hpp"


// -- P U B L I C  C O N S T R U C T O R S ------------------------------------

/* default constructor */
IRC::Socket::Socket(void)
: _descriptor(NULL_DESCRIPTOR), _count(NULL) {
	// code here...
}

/* copy constructor */
IRC::Socket::Socket(const Socket& other)
: _descriptor(other._descriptor), _count(other._count) {
	// check count validity
	if (_count) {
		// increment number of references
		++(*_count);
	}
}

/* destructor */
IRC::Socket::~Socket(void) {
	// check socket end of life
	if (_count && (--(*_count) == 0)) {
		// check descriptor validity
		if (_descriptor != NULL_DESCRIPTOR) {
			// close socket
			::close(_descriptor);
			// invalidate descriptor
			_descriptor = NULL_DESCRIPTOR;
		} // deallocate count
		delete _count;
		// invalidate count
		_count = NULL;
	}
}


// -- P U B L I C  O P E R A T O R S ------------------------------------------

/* copy assignment operator */
IRC::Socket& IRC::Socket::operator=(const Socket& socket) {
	// check self assignment
	if (this != &socket) {
		// call destructor
		this->~Socket();
		// copy descriptor
		_descriptor = socket._descriptor;
		_count      = socket._count;
		// check count validity
		if (_count) {
			// increment number of references
			++(*_count); }
	} // return self reference
	return *this;
}

/* bool operator */
IRC::Socket::operator bool(void) const {
	// check descriptor validity
	return _descriptor != NULL_DESCRIPTOR;
}

/* not operator */
bool IRC::Socket::operator!(void) const {
	// check descriptor validity
	return _descriptor == NULL_DESCRIPTOR;
}

/* equality operator */
bool IRC::Socket::operator==(const Socket& socket) const {
	// check descriptors equality
	return _descriptor == socket._descriptor;
}

/* inequality operator */
bool IRC::Socket::operator!=(const Socket& socket) const {
	// check descriptors inequality
	return (_descriptor != socket._descriptor);
}


// -- P U B L I C  M E T H O D S ----------------------------------------------

/* socket */
void IRC::Socket::create(Domain domain, Type type, Protocol protocol) {
	// call destructor
	this->~Socket();
	// create socket
	_descriptor = ::socket(AF_INET, SOCK_STREAM, 0);
	// check descriptor validity
	if (_descriptor != NULL_DESCRIPTOR) {
		// allocate count
		_count = new Size(1);
	}

	(void)domain;
	(void)type;
	(void)protocol;
}
