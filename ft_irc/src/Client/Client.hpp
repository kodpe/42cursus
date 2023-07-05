#ifndef CLIENT_CLASS_HPP
# define CLIENT_CLASS_HPP

#include "IRC.hpp"

class Client
{
	public:
		Client();
		Client(int fd);
		Client(const Client &other);
   	   ~Client ();
		Client &operator=(const Client &other);

		void	set_fd(int fd);
		void	set_nick(std::string nick);
		void	set_username(std::string username);
		void	set_realname(std::string username);
		void	set_hostname(std::string hostname);
		void	set_servname(std::string servname);
		void	set_password(std::string password);
		void	set_registered(void);

		void	set_recv_buffer(std::string recv_buffer);
		void	set_send_buffer(std::string send_buffer);
		void	add_to_send_buffer(std::string content);
		int		recv_append_to_buffer(void);
		void	set_nb_chan_join(int nb_chan_join);
		void	set_serv_operator(void);
		void	set_to_delete(void);
		void	set_register_data(int data);

		int					get_fd(void) const;
		const std::string & get_nick(void) const;
		const std::string & get_username(void) const;
		const std::string & get_realname(void) const;
		const std::string & get_hostname(void) const;
		const std::string & get_servname(void) const;
		const std::string & get_password(void) const;
		bool				is_registered(void) const;
		const std::string &	get_recv_buffer(void) const;
		const std::string &	get_send_buffer(void) const;
		std::string			extract_next_command(void);
		int					get_nb_chan_join(void) const;
		bool				get_serv_operator(void) const;
		bool				get_to_delete(void) const;

	private:
		int			_fd;
		std::string	_nick;
		std::string	_username;
		std::string	_realname;
		std::string	_hostname;
		std::string	_servname;
		std::string	_password;
		bool		_registered;
		std::string	_recv_buffer;
		std::string	_send_buffer;
		int			_nb_chan_join;
		bool		_serv_operator;
		bool		_to_delete;

		typedef struct s_register {
			bool		pass;
			bool		nick;
			bool		user;
			s_register() : pass(0), nick(0), user(0) {}
		}	t_regdata;

		t_regdata		_reg;
};

#endif /* CLIENT_CLASS_HPP */
