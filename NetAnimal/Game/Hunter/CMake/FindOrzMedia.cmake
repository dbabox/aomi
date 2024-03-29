FIND_PATH( Orz_Media_DIR 
  models/ogrehead.mesh
  PATHS 
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/..
  ${PROJECT_SOURCE_DIR}/../..
  ${PROJECT_SOURCE_DIR}/media  
  ${PROJECT_BINARY_DIR}
  ${PROJECT_BINARY_DIR}/..
  ${PROJECT_BINARY_DIR}/../..
  ${PROJECT_BINARY_DIR}/media
  ${PROJECT_SOURCE_DIR}/../media
  ${PROJECT_SOURCE_DIR}/../../media
  ${PROJECT_SOURCE_DIR}/dependencies/media
  ${PROJECT_BINARY_DIR}/media
  ${PROJECT_BINARY_DIR}/../media
  ${PROJECT_BINARY_DIR}/../../media
  ${PROJECT_BINARY_DIR}/dependencies/media
  NO_DEFAULT_PATH
)




IF(NOT Orz_Media_DIR  )
	MESSAGE(SEND_ERROR "[You have to download and Expand the dependencies.zip file into ${PROJECT_SOURCE_DIR}]")
ENDIF(NOT Orz_Media_DIR )


