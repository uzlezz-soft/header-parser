target("header-parser")
    tool()
    executable()

    add_includedirs(includedirs.rapidjson)

    add_files("**.cc")
    add_headerfiles('**.h')
