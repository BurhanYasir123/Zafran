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
        "Zafran/vendor/SDL3/include",
        "Zafran/vendor/glm"
    }

    libdirs {
        "Zafran/vendor/SDL3/lib"
    }

    links {
        "SDL3"
    }

    filter "system:linux"
        systemversion "latest"
        defines { "ZAFRAN_PLATFORM_LINUX", "ZAFRAN_BUILD_DLL" }
        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ./bin/" .. outputdir .. "/Sandbox"),
            --("{COPYDIR} ./Zafran/src/Renderer/Shaders ./bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/Sandbox/Shaders")
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
        "Zafran/vendor/glm",
        "Sandbox/src",
        "Zafran/vendor/SDL3/include"
    }


    libdirs {
        "Zafran/vendor/SDL3/lib"
    }

    links {
        "Zafran",
        "SDL3"
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
