cmake_minimum_required(VERSION 3.21)
project(aup C)

set(CMAKE_C_STANDARD 99)

add_executable(socket  socket.c)
add_executable(socket_client socket_client.c)
add_executable(sem1 sem1.c)
add_executable(file file.c)
add_executable(lock lock.c)
add_executable(ipc1 ipc1.c)
add_executable(ipc2 ipc2.c)

target_link_libraries(socket ws2_32.dll)
target_link_libraries(socket_client ws2_32.dll)
