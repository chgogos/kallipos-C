from ch20_main_data import raw_data
import ctypes
import os

clib = ctypes.CDLL(os.path.join(os.getcwd(), "libblackbox.so"))
# δήλωση τύπων δεδομένων για ορίσματα και τιμές επιστροφής
clib.jhash.argtypes = [ctypes.c_char_p, ctypes.c_uint32]
clib.jhash.restype = ctypes.c_uint32
clib.jhash_w.argtypes = [ctypes.c_char_p]
clib.jhash_w.restype = ctypes.c_uint32


class User(ctypes.Structure):
    _fields_ = [("name", ctypes.c_char_p),
                ("password", ctypes.c_uint32),
                ("salt", ctypes.c_uint32), ]


users = []
for name, password_txt, salt in raw_data:
    byte_string = (password_txt + str(salt)).encode('ascii')
    password = clib.jhash(byte_string, len(byte_string))
    u = User(name.encode('ascii'), password, ctypes.c_uint32(salt))
    users.append(u)
    print(
        f"user={name}, password={password}, salt={salt}")
    users.append(u)

n = input("Enter user name: ")
p = input(f"Enter the password of user {n}: ")
login = False
for u in users:
    if u.name != n.encode('ascii'):
        continue
    sp_txt = p + str(u.salt)
    c = clib.jhash_w(sp_txt.encode('ascii'))
    if c == u.password:
        login = True
        break
print("LOGIN SUCCESS") if login else print("LOGIN FAILED")
