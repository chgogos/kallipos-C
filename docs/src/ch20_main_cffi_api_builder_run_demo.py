import cffi

ffi = cffi.FFI()

ffi.set_source(
    "_jhash",
    '#include "ch20_blackbox.h"',
    sources=["ch20_blackbox.c"],
)
ffi.cdef('uint32_t jhash(const char *str, size_t len);')
ffi.cdef('uint32_t jhash_w(const char *str);')

ffi.cdef('''
         typedef struct
        {
            char name[21];
            uint32_t password;
            uint32_t salt;
        } user;
         ''')

library = ffi.compile(verbose=True)

# -------------------

_jhash_lib = ffi.dlopen(library)
s = ffi.new("char[]", b'test')
x = _jhash_lib.jhash_w(s)
print(x)

# -------------------

# from _jhash import lib
# s = ffi.new("char[]", b'test')
# x = lib.jhash_w(s)
# print(x)