-- BUILD GLEW 2.2.0
project "glew"
   kind "SharedLib"
   language "C"
   cdialect "c99"
   targetdir "../../bin"
   includedirs { "include" }
   files { "src/**.c", "include/**.h" }
   
   links { "GL", "m" }

   filter "configurations:debug"
      defines { "DEBUG" }
      --optimize "On"
      symbols "On"

   filter "configurations:release"
      defines { "NDEBUG" }
      optimize "On"
