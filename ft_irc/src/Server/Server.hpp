#ifndef SERVER_CLASS_HPP
# define SERVER_CLASS_HPP

#include "Client.hpp"
#include "Channel.hpp"
#include "ExceptionIRC.hpp"
#include "IRC.hpp"

#define IRC_MAX_EVENTS	2000

class Server
{
	public:
		Server(int port, const char *password);
		~Server();

	private:
		struct cmpchan_icase
		{
    		bool operator() (const std::string& lhs, const std::string& rhs) const
			{
        		std::string	s1(lhs);
        		std::string	s2(rhs);
        		transform(lhs.begin(), lhs.end(), s1.begin(), ::tolower);
        		transform(rhs.begin(), rhs.end(), s2.begin(), ::tolower);
        		return s1 < s2;
    		}
		};

		std::string			_servname;
		std::string			_password;
		int 				_port;
		std::string			_operator_credentials[2];

		int 				_serv_socket;
		int 				_epoll_fd;

		Client	*			_actual_client;
		std::string			_actual_cmd_name;

		struct sockaddr_in	_addr_server_struct;
		struct epoll_event	_tab_events[IRC_MAX_EVENTS];

		std::map< int, Client >									_clients;
		std::map< std::string, Channel, cmpchan_icase >			_channels;
		std::map< std::string, void(Server::*)(std::string) >	_cmdMap;

		/**************************************************************/
		/* 					src/Server/Server_init.cpp                */
		/**************************************************************/
		void 	init_addr(void);
		void 	init_epoll(void);
		void	init_commands_map(void);


		/**************************************************************/
		/* 				 	src/Server/Server_routine.cpp             */
		/**************************************************************/
		static void	sighandler(int signum);
		void		check_clients_to_delete(void);
		bool		events_errors_handler(uint32_t ev);
		void 		routine(void);

		void	switch_EPPOLOUT(void);
		void	switch_EPPOLIN(int client_socket);


		/**************************************************************/
		/* 					src/Server/Server_clients.cpp             */
		/**************************************************************/
		void	add_client(void);
		void 	del_client(int fd);
		void	welcome(void);
		int		nick_to_fd(std::string nickname) const;


		/**************************************************************/
		/* 					src/Server/Server_show.cpp                */
		/**************************************************************/
		void	show_clients(void);
		void	show_channel(Channel & chan);
		void	show_channels(void);
		void	show_specs(void);
		void	show_client_specs(int fd);

		/**************************************************************/
		/* 					src/Server/Server_commander.cpp           */
		/**************************************************************/
		void	command_executor(std::string raw);
		void	command_handler(int client_socket);

		// command reply
		void	send_cmd_reply(std::string rpl, int fd);
		void	send_cmd_reply(std::string rpl);
		void	send_error(std::string rpl);

		// numeric reply or error
		void	send_num_reply(const char *num, std::string & rpl);
		// permet d'envoyer l'action de l'utilisateur courrant a tous les autres clients d'une channel
		void	notify_clients_on_channel(std::string channel, std::string rpl);
		void	notify_clients_on_channel_nick(std::string channel, std::string rpl);

		/* update 30/06 */
		void	send_to_buffer(int fd, std::string content);
		void	sc_send(int fd);
		void	send_all_clients_buffers(void);
		///

		/**************************************************************/
		/* 						src/Commands/			              */
		/**************************************************************/
		void	NICK	(std::string args);
		void	PASS	(std::string args);
		void	README	(std::string args);
		void	USER	(std::string args);
		void	MODE	(std::string args);
		void	TOPIC	(std::string args);
		void	JOIN	(std::string args);
		void	PART	(std::string args);
		void	PRIVMSG (std::string args);
		void	NOTICE	(std::string args);
		void	INVITE	(std::string args);
		void	KICK	(std::string args);
		void	LIST	(std::string args);
		void	WHO		(std::string args);
		void	QUIT	(std::string args);
		void	PING	(std::string args);
		void	OPER	(std::string args);
		// void	NAMES	(std::string args);

		// methods created for JOIN :
		void	create_channel(std::string channel_name, std::string channel_key);
		void	join_existing_channel(std::string channel_name, std::string channel_key);
		void	join_one_channel(std::string channel_name, std::string channel_key);

		// methods created for PART :
		void	quit_one_channel(std::string channel_name);

		// other

		/**************************************************************/
		/* 						src/Commands/MODE_utils.cpp			  */
		/**************************************************************/
		bool	invalid_client(Channel & channel);
		void	mode_l	(Channel & channel, std::string opt, std::string user_limit);
		void	mode_o	(Channel & channel, std::string opt, std::string nickname);
		void	mode_k	(Channel & channel, std::string opt, std::string pwd);
		void	mode_tt	(Channel & channel, std::string opt);
		void	mode_i	(Channel & channel, std::string opt);


		/**************************************************************/
		/* 						src/Server/replies.cpp	              */
		/**************************************************************/

		void	RPL_WELCOME(void);							// 001
		void	RPL_YOURHOST(void);							// 002
		void	RPL_CREATED(void);							// 003
		void	RPL_MYINFO(void);							// 004
		void	RPL_ISUPPORT(void);							// 005

		void	RPL_LUSERCLIENT(void);						// 251
		void	RPL_LUSEROP(void);							// 252
		void	RPL_LUSERUNKNOWN(void);						// 253
		void	RPL_LUSERCHANNELS(void);					// 254

		void	RPL_ENDOFWHO(std::string str);				// 315

		void	RPL_LISTSTART(void);						// 321
		void	RPL_LIST(std::string channel_name, bool is_private);			// 322
		void	RPL_LISTEND(void);							// 323
		void	RPL_CHANNELMODEIS(std::string channel);		// 324

		void	RPL_NOTOPIC(std::string channel);			// 331
		void	RPL_TOPIC(std::string channel);				// 332

		void	RPL_WHOREPLY(int fd);						// 352
		void	RPL_NAMREPLY(std::string channel_name);		// 353

		void	RPL_ENDOFNAMES(std::string channel_name);	// 366

		void	RPL_YOUREOPER(void);						// 381

		void	ERR_NOSUCHNICK(std::string nick);			// 401

		void	ERR_NOSUCHCHANNEL(std::string channel);		// 403
		void	ERR_CANNOTSENDTOCHAN(std::string channel);	// 404
		void	ERR_TOOMANYCHANNELS(std::string channel);	// 405

		void	ERR_NORECIPIENT(void); 						// 411
		void	ERR_NOTEXTTOSEND(void);						// 412

		void	ERR_INPUTTOOLONG(void);						// 417

		void	ERR_UNKNOWNCOMMAND(void); 					// 421

		void	ERR_NONICKNAMEGIVEN(void); 					// 431
		void	ERR_ERRONEUSNICKNAME(std::string nick);		// 432
		void	ERR_NICKNAMEINUSE(std::string nick);		// 433

		void	ERR_USERNOTINCHANNEL(std::string nick);		// 441
		void	ERR_NOTONCHANNEL(std::string channel);		// 442
		void	ERR_USERONCHANNEL(std::string nick);		// 443

		void	ERR_NOTREGISTERED(void);					// 451

		void	ERR_NEEDMOREPARAMS(std::string opt);		// 461
		void	ERR_ALREADYREGISTERED(void);				// 462

		void	ERR_PASSWDMISMATCH(void);					// 464

		void	ERR_KEYSET(std::string channel);			// 467

		void	ERR_CHANNELISFULL(std::string channel);		// 471
		void	ERR_UNKNOWNMODE(std::string err_char);		// 472
		void	ERR_INVITEONLYCHAN(std::string channel);	// 473

		void	ERR_BADCHANNELKEY(std::string channel);		// 475

		void	ERR_NOPRIVILEGES(std::string reason);		// 481

		void	ERR_CHANOPRIVSNEEDED(std::string channel);	// 482

};

#endif /* SERVER_CLASS_HPP */
