workspace "lxengine"

   architecture "x86_64"
   configurations { "Debug", "Release"}

function include_gl() 
   include "deps/conan_glew.premake5"
   include "deps/conan_glfw.premake5"
   include "deps/conan_opengl.premake5"
end

project "lxengine"
   include_gl()   

   kind "SharedLib"
   language "C"
   cdialect "c99"
   targetdir "bin"
   includedirs { "include" }
   files { "src/**.c", "include/**.h" }
   
   links { "GL", "m" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      optimize "On"
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
