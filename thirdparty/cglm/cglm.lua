-- BUILD CGLM 0.9.6

project "cglm"
   kind "SharedLib"
   language "C"
   cdialect "c99"
   targetdir "../../bin"
   files { "src/**.c", "include/**.h" }
   
   links { "GL", "m" }

   filter "configurations:debug"
      defines { "DEBUG" }
      --optimize "On"
      symbols "On"

   filter "configurations:release"
      defines { "NDEBUG" }
      optimize "On"

function include_cglm() 
   includedirs { "thirdparty/cglm/include" }
end
