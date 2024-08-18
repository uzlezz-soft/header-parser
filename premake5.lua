project "header-parser"
    tool()
    executable()

    includedirs
    {
        includes["rapidjson"]
    }

    files
    {
        "*.h",
        "**.cc",
    }