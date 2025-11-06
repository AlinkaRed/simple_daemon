# simple_daemon
## Запуск
- mkdir build
- cd build
- cmake ..
- make
- ./daemon
- tail -f /var/log/syslog | grep mydaemon
- ps aux | grep daemon
- pkill daemon
