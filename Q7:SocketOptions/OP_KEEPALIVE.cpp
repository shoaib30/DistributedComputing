#include <sys/socket.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int sockfd, sendbuff;
    socklen_t optlen;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    int res = 0;

    // Get buffer size
    optlen = sizeof(sendbuff);
    res = getsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &sendbuff, &optlen);


    //printf("send buffer size = %d\n", sendbuff);
    printf("SO_KEEPALIVE is %s\n", (sendbuff ? "ON" : "OFF"));

    // Set buffer size
    sendbuff = 1;

    printf("sets the send buffer to %d\n", sendbuff);
    res = setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &sendbuff, sizeof(sendbuff));

    // Get buffer size
    optlen = sizeof(sendbuff);
    res = getsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &sendbuff, &optlen);

    //printf("send buffer size = %d\n", sendbuff);
    printf("SO_KEEPALIVE is %s\n", (sendbuff ? "ON" : "OFF"));
    return 0;
}