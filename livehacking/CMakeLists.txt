ADD_EXECUTABLE(dummy dummy.cpp)
TARGET_LINK_LIBRARIES(dummy Threads::Threads)

ADD_EXECUTABLE(demo demo.cpp)
TARGET_LINK_LIBRARIES(demo Threads::Threads)

ADD_EXECUTABLE(initlist-mess initlist-mess.cpp)
ADD_EXECUTABLE(structured-binding structured-binding.cpp)

ADD_EXECUTABLE(virtual-dtor virtual-dtor.cpp)
ADD_EXECUTABLE(enum enum.cpp)

ADD_SUBDIRECTORY(smartptrs)
