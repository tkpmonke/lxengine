-- BUILD VOLK 1.4.304

project "volk"
   kind "SharedLib"
   language "C"
   cdialect "c89"
   targetdir "../../bin"
   files { "**.c", "**.h" }
   
   filter "configurations:debug"
      defines { "DEBUG" }
      --optimize "On"
      symbols "On"

   filter "configurations:release"
      defines { "NDEBUG" }
      optimize "On"

function include_volk()
   includedirs { "thirdparty/volk" }
end
