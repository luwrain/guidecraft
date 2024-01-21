

add_executable (gcr-br
  Broker.cpp
  BusClient.cpp
  Bus.cpp
  Client.cpp
  main.cpp
  Service.cpp)

target_link_libraries(gcr-br pthread rt)
