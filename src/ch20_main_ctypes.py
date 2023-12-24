import ch20_main_data
import ctypes
import os
import sys

if sys.platform.startswith("win"):
    clib = ctypes.CDLL(os.path.join(os.getcwd(), "blackbox.dll"))
elif sys.platform.startswith("linux"):
    clib = ctypes.CDLL(os.path.join(os.getcwd(), "libblackbox.so"))
elif sys.platform.startswith("darwin"):
    clib = ctypes.CDLL(os.path.join(os.getcwd(), "libblackbox.dylib"))
else:
    print("Unknown OS")
    exit()

# δήλωση τύπων δεδομένων για ορίσματα και τιμές επιστροφής
clib.jhash.argtypes = [ctypes.c_char_p, ctypes.c_uint32]
clib.jhash.restype = ctypes.c_uint32
clib.jhash_w.argtypes = [ctypes.c_char_p]
clib.jhash_w.restype = ctypes.c_uint32


# δήλωση τύπου δεδομένων για τη δομή User
class User(ctypes.Structure):
    _fields_ = [
        ("name", ctypes.c_char_p),
        ("password", ctypes.c_uint32),
        ("salt", ctypes.c_uint32),
    ]


users = []
for name, password_txt, salt in ch20_main_data.raw_data:
    byte_string = (password_txt + str(salt)).encode("ascii")
    password = clib.jhash(byte_string, len(byte_string))
    u = User(name.encode("ascii"), password, ctypes.c_uint32(salt))
    print(f"user={name}, password={password}, salt={salt}")
    users.append(u)

n = input("Enter user name: ")
p = input(f"Enter the password of user {n}: ")
login = False
for u in users:
    if u.name != n.encode("ascii"):
        continue
    sp_txt = p + str(u.salt)
    c = clib.jhash_w(sp_txt.encode("ascii"))
    if c == u.password:
        login = True
        break
print("LOGIN SUCCESS") if login else print("LOGIN FAILED")
