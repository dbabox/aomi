
ORZ_PRE_BUILD_EVENT(WheelAnimal2Controller)

ADD_DEFINITIONS(-D_CONSOLE -D${LIB_NAME_TOUPPER}_EXPORTS)


IF(GAME1)
	ADD_DEFINITIONS(-D_GAME1)
ENDIF( GAME1)

INCLUDE_DIRECTORIES(
include
include/ui
${ORZ_PROJECT_INTERFACE_DIR}/
${PROJECT_SOURCE_DIR}/WheelGobal/include 
${PROJECT_SOURCE_DIR}/WheelAnimalController/include 
)


use_precompiled_header(WheelAnimal2Controller
  "${CMAKE_CURRENT_SOURCE_DIR}/include/WheelAnimalControllerStableHeaders.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/WheelAnimalControllerPrecompiledHeaders.cpp"
)


ORZ_SET_PROJECT_FILES(include include/ .h)
ORZ_SET_PROJECT_FILES(src src/ .cpp)


ORZ_SET_PROJECT_FILES(ui\\\\\\\\include include/ui/ .h)
ORZ_SET_PROJECT_FILES(ui\\\\\\\\src src/ui/ .cpp)

ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})

TARGET_LINK_LIBRARIES(${LIB_NAME} 
Framework_Base 
Toolkit_Base 
WheelGobal
debug OgreMain_d 
optimized OgreMain 
debug CEGUIBase_d 
optimized CEGUIBase

Toolkit_Component_Task
)

ORZ_POST_BUILD_EVENT()