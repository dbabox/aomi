ORZ_PRE_BUILD_EVENT(Coding)


SET(QT_USE_QTMAIN true)

INCLUDE(${QT_USE_FILE} )

INCLUDE_DIRECTORIES("include")
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

ADD_DEFINITIONS(/Zc:wchar_t-)


ORZ_SET_PROJECT("SRCS" "Source Files" ./ .cpp )
ORZ_SET_PROJECT("UIS" "Form Files" ./ .ui )
ORZ_SET_PROJECT("HDRS" "Header Files" ./ .h )
ORZ_SET_PROJECT("QRCS" "Resource Files" ./ .qrc )




QT4_WRAP_UI(${EXE_NAME}_UIS_H ${${EXE_NAME}_UIS})
QT4_ADD_RESOURCES(${EXE_NAME}_RCCS_QRCS ${${EXE_NAME}_QRCS})
QT4_WRAP_CPP(${EXE_NAME}_MOC_SRCS ${${EXE_NAME}_HDRS})




SOURCE_GROUP("Generated Files\\ui" FILES ${${EXE_NAME}_UIS_H})
SOURCE_GROUP("Generated Files\\moc" FILES  ${${EXE_NAME}_MOC_SRCS})
SOURCE_GROUP("Generated Files\\rcc" FILES  ${${EXE_NAME}_RCCS_QRCS})





ADD_EXECUTABLE(${EXE_NAME} WIN32 ${${EXE_NAME}_SRCS} ${${EXE_NAME}_MOC_SRCS} ${${EXE_NAME}_UIS_H} ${${EXE_NAME}_HDRS} ${${EXE_NAME}_QRCS} ${${EXE_NAME}_RCCS_QRCS}


)


TARGET_LINK_LIBRARIES(${EXE_NAME}
${QT_LIBRARIES}
Toolkit_Base
Framework_Base
Toolkit_Component_Task
Framework_Component 
${QT_QTOPENGL_LIBRARY} 
)



ORZ_POST_BUILD_EVENT()