file(GLOB NAPI_SRC "*.cpp")

add_executable(aws-dummy ${NAPI_SRC})

target_link_libraries(aws-dummy ${LIBS} ${OUTPUT})

