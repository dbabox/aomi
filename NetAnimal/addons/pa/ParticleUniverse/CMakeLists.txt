ORZ_PRE_BUILD_EVENT(Model_Base)

INCLUDE_DIRECTORIES("include")


ADD_DEFINITIONS(-D_USRDLL)

ORZ_SET_PROJECT("FILE" include include/ .h)
ORZ_SET_PROJECT("FILE" src src/ .cpp)
ORZ_SET_PROJECT("FILE" def ./ .def)

   

ADD_LIBRARY(${LIB_NAME} SHARED ${${LIB_NAME}_FILE})


TARGET_LINK_LIBRARIES(${LIB_NAME} 
Framework_Base Toolkit_Base View_OGRE3D
)

ORZ_POST_BUILD_EVENT()

