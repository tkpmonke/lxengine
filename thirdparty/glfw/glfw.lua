-- BUILD GLFW 3.4
project "glfw"
   kind "SharedLib"
   language "C"
   cdialect "c17"
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
