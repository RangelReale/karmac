SET( TARGET_BASE_NAME kmpackage_test )

SET(BASE_SOURCE_PATH ".")

#-----------------------------------------------------------------------------

SET( EXE_NAME "${TARGET_BASE_NAME}" )

# Add any source files here.
SET( EXE_SRCS
)


# Add any include files here.
SET( EXE_INCS
)

#-----------------------------------------------------------------------------

SET(BASE_SRCS
		main.cpp
)
SET(BASE_INCS
)

ADD_EXECUTABLE(${TARGET_BASE_NAME} ${BASE_SRCS} ${BASE_INCS_MOC} ${EXE_SRCS} ${EXE_INCS})

TARGET_LINK_LIBRARIES ( ${EXE_NAME}
  kmpackage

  ${CMAKE_THREAD_LIBS_INIT}
  ${CMAKE_DL_LIBS}
)
