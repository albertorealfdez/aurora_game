#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(includesLib PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/tinyxml/tinyxml2.cpp"
)

#Y donde se encuentran los .h
target_include_directories(includesLib PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/tinyxml/"
)

