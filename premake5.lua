workspace "Zafran"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Zafran"
    location "Zafran"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/GLFW/include",
        "Zafran/vendor/System_h/include",
    }

    links {
        "GLFW"
    }

    filter "system:linux"
        systemversion "latest"
        defines { "ZAFRAN_PLATFORM_LINUX", "ZAFRAN_BUILD_DLL" }
        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "ZAFRAN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "ZAFRAN_RELEASE"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

    includedirs {
        "Zafran/",
        "Zafran/src",
        "Zafran/vendor/GLFW/include",
        "Zafran/vendor/System_h/include",
        "Sandbox/src"
    }

    links {
        "Zafran",
        "GLFW"
    }

    filter "system:linux"
        systemversion "latest"
        defines { "ZAFRAN_PLATFORM_LINUX" }

    filter "configurations:Debug"
        defines "SANDBOX_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SANDBOX_RELEASE"
        optimize "On"

project "GLFW"
    location "Zafran/vendor/GLFW"
    kind "StaticLib"
    language "C"
    staticruntime "on"

    files {
        "Zafran/vendor/GLFW/include/GLFW/**.h",
        "Zafran/vendor/GLFW/src/**.h",
        "Zafran/vendor/GLFW/src/**.c"
    }

    includedirs {
        "Zafran/vendor/GLFW/include"
    }

    filter "system:linux"
        systemversion "latest"
        defines { "_GLFW_X11" }

project "System_h"
    location "Zafran/vendor/System_h"
    kind "StaticLib"
    language "C++"
    staticruntime "On"

    files {
        "Zafran/vendor/System_h/**.h",
        "Zafran/vendor/System_h/**.cpp"
    }

    includedirs {
        "Zafran/vendor/System_h/include"
    }

    filter "system:linux"
        systemversion "latest"
        defines { "MACROS" }