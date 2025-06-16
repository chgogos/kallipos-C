import cffi


def demo1():
    ffi = cffi.FFI()
    ffi.cdef(
        """
            uint32_t jhash(const char *str, size_t len);
            uint32_t jhash_w(const char *str);
            """
    )
    TS = ffi.dlopen("./ch20_blackbox.so")

    txt = "Christos"
    s = ffi.new("char[]", txt.encode("ascii"))
    print(TS.jhash(s, len(txt)))
    print(TS.jhash_w(s))


def build_extension_module():
    ffibuilder = cffi.FFI()
    ffibuilder.cdef(
        """
            uint32_t jhash(const char *str, size_t len);
            uint32_t jhash_w(const char *str);
            """
    )
    ffibuilder.set_source(
        "_ch20_blackbox",
        """
                   #include "ch20_blackbox.h"
                   """,
        sources=["ch20_blackbox.c"],
        library_dirs=[],
        libraries=[],
    )
    ffibuilder.compile(verbose=True)

    # txt = "Christos"
    # s = ffi.new("char[]", txt.encode('ascii'))
    # print(TS.jhash(s, len(txt)))
    # print(TS.jhash_w(s))


def demo2():
    from _ch20_blackbox import lib

    print(lib.jhash_w(b"Christos"))


# demo1()
build_extension_module()
demo2()
