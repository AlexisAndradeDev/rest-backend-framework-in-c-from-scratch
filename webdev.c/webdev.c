/* webdev.c */
#include "webdev.h"
#include "birchutils.h"
#include <syslog.h>

/**
 * @brief A wrapper for `openlog` and `syslog` to
 * prevent `ident` from defaulting to NULL. Closes
 * the connection to the system logger using `closelog`.
 * 
 * @param priority
 * @param msg 
 */
void sys_log(int16 priority, int8 *msg) {
    openlog("webdev.c", 0, LOG_SYSLOG);
    syslog($i priority, "%s", msg);
    closelog();

    return;
}

int32 setup_server(int8 *ip_address, int16 port) {
    struct sockaddr_in sock;
    // We can't use an unsigned int for the file descriptor of the
    // socket, as socket() returns -1 when there's an error,
    // and the file descriptor would store a really large number
    // instead of -1, making the assert always pass (always > 0)
    int sock_fd;

    // AF_INET for IPv4, SOCK_STREAM for sequenced, two-way connection-based
    // byte streams, 0 for default protocol for AF_INET + SOCK_STREAM
    // combination, which is TCP protocol
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    assert(sock_fd > 0);
    
}

int main(int argc, char **argv) {
    int8 *str;
    str = "Server starting up...";

    info_log(str);

    return 0;
}
