#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "IRC.hpp"

class Channel
{
	public:
		Channel();
		~Channel();
		Channel(const Channel &other);
		Channel &operator=(const Channel &other);

		void		setName			(std::string name);
		void		setPassword		(std::string pwd);
		void		setTopic		(std::string topic);
		void		setMaxClient	(int max_client);
		void		setEditTopic	(bool edit_topic);
		void		setIsInviteOnly	(bool is_invite_only);
		void		setOp			(int fd);
		void		unsetOp			(int fd);
		void		addClient		(int fd);
		void		delClient		(int fd);
		void		addWhiteList	(int fd);
		void		delWhiteList	(int fd);

		bool		isPassword(void);
		bool		isOp(int fd);
		bool		isInChannel(int fd);
		bool		isWhiteListed(int fd);

		void		print_channel(void);
		void		print_whitelist(void);

		std::string	getName			(void) const;
		std::string	getPassword		(void) const;
		std::string	getTopic		(void) const;
		int			getMaxClient	(void) const;
		bool		getEditTopic	(void) const;
		bool		getIsInviteOnly	(void) const;
		int			getClientNumber	(void) const;

		std::vector< int > 		get_whitelist	(void) const;
		std::map< int, bool > 	get_client		(void) const;

	private:
		std::string	_name;
		std::string	_password;
		std::string	_topic;
		int			_max_client;
		bool		_edit_topic;
		bool		_is_invite_only;

	public:
		std::vector< int > 		_whitelist;
		std::map< int, bool > 	_client;
};

#endif
