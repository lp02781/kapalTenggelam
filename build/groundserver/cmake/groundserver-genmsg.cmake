# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "groundserver: 2 messages, 0 services")

set(MSG_I_FLAGS "-Igroundserver:/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg;-Imavros_msgs:/opt/ros/kinetic/share/mavros_msgs/cmake/../msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/kinetic/share/sensor_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Igeographic_msgs:/opt/ros/kinetic/share/geographic_msgs/cmake/../msg;-Iuuid_msgs:/opt/ros/kinetic/share/uuid_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(groundserver_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/inputRemote.msg" NAME_WE)
add_custom_target(_groundserver_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "groundserver" "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/inputRemote.msg" ""
)

get_filename_component(_filename "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/statusSub.msg" NAME_WE)
add_custom_target(_groundserver_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "groundserver" "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/statusSub.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(groundserver
  "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/statusSub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/groundserver
)
_generate_msg_cpp(groundserver
  "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/inputRemote.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/groundserver
)

### Generating Services

### Generating Module File
_generate_module_cpp(groundserver
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/groundserver
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(groundserver_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(groundserver_generate_messages groundserver_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/inputRemote.msg" NAME_WE)
add_dependencies(groundserver_generate_messages_cpp _groundserver_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/statusSub.msg" NAME_WE)
add_dependencies(groundserver_generate_messages_cpp _groundserver_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(groundserver_gencpp)
add_dependencies(groundserver_gencpp groundserver_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS groundserver_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(groundserver
  "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/statusSub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/groundserver
)
_generate_msg_eus(groundserver
  "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/inputRemote.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/groundserver
)

### Generating Services

### Generating Module File
_generate_module_eus(groundserver
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/groundserver
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(groundserver_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(groundserver_generate_messages groundserver_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/inputRemote.msg" NAME_WE)
add_dependencies(groundserver_generate_messages_eus _groundserver_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/statusSub.msg" NAME_WE)
add_dependencies(groundserver_generate_messages_eus _groundserver_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(groundserver_geneus)
add_dependencies(groundserver_geneus groundserver_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS groundserver_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(groundserver
  "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/statusSub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/groundserver
)
_generate_msg_lisp(groundserver
  "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/inputRemote.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/groundserver
)

### Generating Services

### Generating Module File
_generate_module_lisp(groundserver
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/groundserver
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(groundserver_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(groundserver_generate_messages groundserver_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/inputRemote.msg" NAME_WE)
add_dependencies(groundserver_generate_messages_lisp _groundserver_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/statusSub.msg" NAME_WE)
add_dependencies(groundserver_generate_messages_lisp _groundserver_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(groundserver_genlisp)
add_dependencies(groundserver_genlisp groundserver_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS groundserver_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(groundserver
  "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/statusSub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/groundserver
)
_generate_msg_nodejs(groundserver
  "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/inputRemote.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/groundserver
)

### Generating Services

### Generating Module File
_generate_module_nodejs(groundserver
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/groundserver
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(groundserver_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(groundserver_generate_messages groundserver_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/inputRemote.msg" NAME_WE)
add_dependencies(groundserver_generate_messages_nodejs _groundserver_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/statusSub.msg" NAME_WE)
add_dependencies(groundserver_generate_messages_nodejs _groundserver_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(groundserver_gennodejs)
add_dependencies(groundserver_gennodejs groundserver_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS groundserver_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(groundserver
  "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/statusSub.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/groundserver
)
_generate_msg_py(groundserver
  "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/inputRemote.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/groundserver
)

### Generating Services

### Generating Module File
_generate_module_py(groundserver
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/groundserver
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(groundserver_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(groundserver_generate_messages groundserver_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/inputRemote.msg" NAME_WE)
add_dependencies(groundserver_generate_messages_py _groundserver_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/mfikih15/Documents/kapalTenggelam/src/groundserver/msg/statusSub.msg" NAME_WE)
add_dependencies(groundserver_generate_messages_py _groundserver_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(groundserver_genpy)
add_dependencies(groundserver_genpy groundserver_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS groundserver_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/groundserver)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/groundserver
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET mavros_msgs_generate_messages_cpp)
  add_dependencies(groundserver_generate_messages_cpp mavros_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(groundserver_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(groundserver_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/groundserver)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/groundserver
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET mavros_msgs_generate_messages_eus)
  add_dependencies(groundserver_generate_messages_eus mavros_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(groundserver_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(groundserver_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/groundserver)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/groundserver
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET mavros_msgs_generate_messages_lisp)
  add_dependencies(groundserver_generate_messages_lisp mavros_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(groundserver_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(groundserver_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/groundserver)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/groundserver
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET mavros_msgs_generate_messages_nodejs)
  add_dependencies(groundserver_generate_messages_nodejs mavros_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(groundserver_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(groundserver_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/groundserver)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/groundserver\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/groundserver
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET mavros_msgs_generate_messages_py)
  add_dependencies(groundserver_generate_messages_py mavros_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(groundserver_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(groundserver_generate_messages_py sensor_msgs_generate_messages_py)
endif()
