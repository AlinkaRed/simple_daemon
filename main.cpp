#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <syslog.h>
#include <string>

void handler(int signum) {
    syslog(LOG_INFO, "Daemon stopped with signal: %d", signum);
    closelog();
    exit(signum);
}

int main() {
    pid_t pid = fork();
    if (pid > 0) return 0;

    setsid();

    pid = fork();
    if (pid > 0) return 0;

    openlog("mydaemon", LOG_PID | LOG_CONS, LOG_USER);
    syslog(LOG_INFO, "Daemon started successfully");

    signal(SIGTERM, handler);
    signal(SIGINT, handler);

    while (true) {
        syslog(LOG_INFO, "Daemon is working...");
        sleep(5);
    }

    closelog();
    return 0;
}