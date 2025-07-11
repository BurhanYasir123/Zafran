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
        "Zafran/vendor/GLFW/deps/glad/include",
        "Zafran/vendor/imgui/src"
    }

    links {
        "OpenGL",
        "ImGui"
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
        "Zafran/vendor/GLFW/deps/glad/include",
        "Sandbox/src",
        "Zafran/vendor/imgui/src"
    }

    links {
        "Zafran",
        "OpenGL",
        "ImGui"
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

project "OpenGL"
    location "Zafran/vendor/GLFW"
    kind "StaticLib"
    language "C"
    staticruntime "on"
    pic "On"

    files {
        "Zafran/vendor/GLFW/include/GLFW/**.h",
        "Zafran/vendor/GLFW/src/**.h",
        "Zafran/vendor/GLFW/src/**.c",
        "Zafran/vendor/GLFW/deps/glad/src/**.c",
        "Zafran/vendor/GLFW/deps/glad/include/glad/**.h"
    }

    includedirs {
        "Zafran/vendor/GLFW/include",
        "Zafran/vendor/GLFW/deps/glad/include"
    }

    filter "system:linux"
        systemversion "latest"
        defines { "_GLFW_X11" }

project "ImGui"
    location "Zafran/vendor/imgui"
    kind "StaticLib"
    language "C++"
    staticruntime "on"
    pic "On"
    
    files {
        "Zafran/vendor/imgui/src/**.cpp",
        "Zafran/vendor/imgui/src/**.h"
    }

    includedirs {
        "Zafran/vendor/imgui",
        "/usr/include/freetype2",
        "Zafran/vendor/GLFW/include",
        "Zafran/vendor/GLFW/deps/glad/include"
    }

    links {
        "freetype",
        "OpenGL"
    }

    filter "system:linux"
        systemversion "latest"
