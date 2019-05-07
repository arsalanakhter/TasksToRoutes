cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main src/main.cpp
                    src/Node.cpp 
                    src/Route.cpp
                    src/RoutingModel.cpp
                    src/ClarkWright.cpp
                    src/Saving.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
