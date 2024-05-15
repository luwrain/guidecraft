

add_executable (gcr
  Broker.cpp
  BusClient.cpp
  Bus.cpp
  Client.cpp
  main.cpp
  Service.cpp
  test.cpp
  RwLock.cpp
  )

target_link_libraries(gcr pthread rt)
