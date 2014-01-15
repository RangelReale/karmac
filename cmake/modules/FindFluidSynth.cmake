FIND_PATH(FluidSynth_ROOT_DIR NAMES include/fluidsynth.h)

SET(FluidSynth_FOUND 0)

IF(FluidSynth_ROOT_DIR)
  IF(EXISTS "${FluidSynth_ROOT_DIR}/include/fluidsynth.h")
        SET(FluidSynth_INCLUDE_DIR "${FluidSynth_ROOT_DIR}/include")
        SET(FluidSynth_FOUND 1)
  ELSE()
      MESSAGE(FATAL_ERROR "FluidSynth was not found.")
  ENDIF()
  
  IF(FluidSynth_FOUND)
        FIND_LIBRARY(FluidSynth_LIBRARY_DEBUG NAMES fluidsynth_debug fluidsynth)
        FIND_LIBRARY(FluidSynth_LIBRARY_RELEASE NAMES fluidsynth)
        
        SET(FluidSynth_LIBRARY
          debug ${FluidSynth_LIBRARY_DEBUG}
          optimized ${FluidSynth_LIBRARY_RELEASE}
        )        
  ENDIF()
ENDIF()
