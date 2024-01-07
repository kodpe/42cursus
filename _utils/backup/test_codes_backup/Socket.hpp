#ifndef SOCKETS_HEADER
#define SOCKETS_HEADER

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>



// -- N A M E S P A C E S  I R C ----------------------------------------------

namespace IRC {


	// -- S O C K E T  C L A S S ----------------------------------------------

	// this class act like shared_ptr but for socket descriptor
	// so if you copy a socket, the descriptor will be shared

	class Socket {

		public:

			// -- P U B L I C  A L I A S E S ----------------------------------

			/* descriptor type */
			typedef int Descriptor;

			/* domain type */
			typedef int Domain;

			/* type type */
			typedef int Type;

			/* protocol type */
			typedef int Protocol;

			/* size type */
			typedef std::size_t Size;


			// -- P U B L I C  C O N S T R U C T O R S ------------------------

			/* default constructor */
			Socket(void);

			/* copy constructor */
			Socket(const Socket &socket);

			/* destructor */
			~Socket(void);


			// -- P U B L I C  O P E R A T O R S ------------------------------

			/* copy assignment operator */
			Socket& operator=(const Socket& socket);

			/* bool operator */
			operator bool(void) const;

			/* not operator */
			bool operator!(void) const;

			/* equality operator */
			bool operator==(const Socket &socket) const;

			/* inequality operator */
			bool operator!=(const Socket &socket) const;



			// -- P U B L I C  M E T H O D S ----------------------------------

			/* create socket */
			void create(Domain domain, Type type, Protocol protocol);


		private:

			// -- P R I V A T E  E N U M S ------------------------------------

			/* descriptor type */
			enum { NULL_DESCRIPTOR = -1 };

			// -- P R I V A T E  M E M B E R S --------------------------------

			/* descriptor */
			mutable Descriptor _descriptor;

			/* count */
			mutable Size*      _count;


	};

}

#endif

/* prototype */
// int socket(int domain, int type, int protocol);

// DESCRIPTION socket() creates an endpoint for communication and returns a descriptor.


/* protocol */

// PF_LOCAL        Host-internal protocols, formerly called PF_UNIX,
// PF_UNIX         Host-internal protocols, deprecated, use PF_LOCAL,
// PF_INET         Internet version 4 protocols,
// PF_ROUTE        Internal Routing protocol,
// PF_KEY          Internal key-management function,
// PF_INET6        Internet version 6 protocols,
// PF_SYSTEM       System domain,
// PF_NDRV         Raw access to network device,
// PF_VSOCK        VM Sockets protocols

//struct PFLocal { static const int value = PF_LOCAL; };
//
//struct PFUnix { static const int value = PF_UNIX; };
//
//struct PFInet { static const int value = PF_INET; };
//
//struct PFRoute { static const int value = PF_ROUTE; };
//
//struct PFKey { static const int value = PF_KEY; };

/* type */

// SOCK_STREAM
// SOCK_DGRAM
// SOCK_RAW
