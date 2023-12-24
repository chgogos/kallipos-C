import ch20_main_data
import cffi
import os
import sys

ffi = cffi.FFI()
if sys.platform.startswith("win"):
    clib = ffi.dlopen(os.path.join(os.getcwd(), "blackbox.dll"))
elif sys.platform.startswith("linux"):
    clib = ffi.dlopen(os.path.join(os.getcwd(), "libblackbox.so"))
elif sys.platform.startswith("darwin"):
    clib = ffi.dlopen(os.path.join(os.getcwd(), "libblackbox.dylib"))
else:
    print("Unknown OS")
    exit()

ffi.cdef("uint32_t jhash(const char *str, size_t len);")
ffi.cdef("uint32_t jhash_w(const char *str);")
ffi.cdef(
    """
         typedef struct
        {
            char name[21];
            uint32_t password;
            uint32_t salt;
        } user;
         """
)

users = []
for name, password_txt, salt in ch20_main_data.raw_data:
    v = ffi.new("user*")
    v.name = name.encode("ascii")
    v.salt = salt
    salted_password_txt = password_txt + str(salt)
    s = ffi.new("char[]", salted_password_txt.encode("ascii"))
    v.password = clib.jhash(s, len(salted_password_txt))
    print(
        f"user={ffi.string(v.name).decode('ascii')}, password={v.password}, salt={v.salt}"
    )
    users.append(v)

n = input("Enter user name: ")
p = input(f"Enter the password of user {n}: ")
login = False
for v in users:
    if ffi.string(v.name).decode("ascii") != n:
        continue
    sp_txt = p + str(v.salt)
    s = ffi.new("char[]", sp_txt.encode("ascii"))
    c = clib.jhash_w(s)
    if c == v.password:
        login = True
        break
print("LOGIN SUCCESS") if login else print("LOGIN FAILED")
