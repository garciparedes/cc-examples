
file(GLOB_RECURSE files *.cc)
foreach (file ${files})
    get_filename_component(testname ${file} NAME)
    string(REPLACE ".cc" "" testname ${testname})

    add_executable(${testname} ${file})
endforeach ()