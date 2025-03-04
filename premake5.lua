workspace "lxengine"
   architecture "x86_64"
   configurations { "debug", "release" }

include 'thirdparty/include-deps.lua'

project "lxengine"
   kind "SharedLib"
   language "C"
   cdialect "c99"
   targetdir "bin"
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

project "lxeditor"
   kind "ConsoleApp"
   language "C"
   cdialect "c99"
   targetdir "bin"
   includedirs { "include" }
   files { "editor/**.c", "editor/**.h" }
   
   links { "lxengine", "m"}

   filter "configurations:debug"
      defines { "DEBUG" }
      --optimize "On"
      symbols "On"

   filter "configurations:release"
      defines { "NDEBUG" }
      optimize "On"
