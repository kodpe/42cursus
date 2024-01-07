#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[3000];
    if (argc < 2) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[1]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    //server = gethostbyname("188.240.145.20");
    server = gethostbyname("127.0.0.1");
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
	{
        error("ERROR connecting");
	}

        /*const char * msg1 = "CAP LS\r\nPASS mdp\r\nNICK sloquet\r\nUSER sloquet sloquet 127.0.0.1 :Sylvain LOQUET\r\n";
		printf("auto send: '%s'\n", msg1);
		if (-1 == write(sockfd, msg1, strlen(msg1)))
			error("ERROR writing to socket");

		bzero(buffer, 2512);
		if (-1 ==read(sockfd, buffer, 3000))
			error("ERROR reading from socket");
		printf("=======================\n");
		printf("buffer : '%s'\n", buffer);
		printf("=======================\n");
		printf("pause..\n");

	*/
	while (1)
	{
		printf("Please enter the message: ");
		bzero(buffer, 3000);
		fgets(buffer, 3000, stdin);
        write(sockfd, buffer, strlen(buffer));
		write(sockfd, "\r\n", 2);

		bzero(buffer, 3000);
		if (-1 ==read(sockfd, buffer, 3000))
			error("ERROR reading from socket");
		printf("=======================\n");
		printf("buffer : '%s'\n", buffer);
		printf("=======================\n");
		printf("pause..\n");
        getchar();
	}

	close(sockfd);
    return 0;
}
