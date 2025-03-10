-- BUILD GLFW 3.4
project "glfw"
   kind "SharedLib"
   language "C++"
   cppdialect "c++17"
   targetdir "../../bin"
   includedirs { "include" }

   files { "src/**.c", "include/**.h" }

   includedirs { "include" }

   filter { "system:linux" }
       defines { "_GLFW_X11" }
       links { "X11", "Xrandr", "Xinerama", "Xi", "m", "dl", "pthread" }

   filter "system:windows"
       defines { "_GLFW_WIN32" }
       links { "gdi32", "user32", "shell32" }
   filter "configurations:debug"
      defines { "DEBUG" }
      --optimize "On"
      symbols "On"

   filter "configurations:release"
      defines { "NDEBUG" }
      optimize "On"

   
