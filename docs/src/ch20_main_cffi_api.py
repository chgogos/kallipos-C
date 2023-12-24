import ch20_main_data
from _jhash import lib, ffi

users = []
for name, password_txt, salt in ch20_main_data.raw_data:
    v = ffi.new("user*")
    v.name = name.encode("ascii")
    v.salt = salt
    salted_password_txt = password_txt + str(salt)
    s = ffi.new("char[]", salted_password_txt.encode("ascii"))
    v.password = lib.jhash(s, len(salted_password_txt))
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
    c = lib.jhash_w(s)
    if c == v.password:
        login = True
        break
print("LOGIN SUCCESS") if login else print("LOGIN FAILED")
