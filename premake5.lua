project "header-parser"
    tool()
    executable()

    includedirs
    {
        includes["rapidjson"],
        includes["tclap"]
    }

    files
    {
        "*.h",
        "**.cc",
    }