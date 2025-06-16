bool has_ok_size(const char *pwd) {
    int size = strlen(pwd);
    if (size >= 5 && size <= 20)
    return true;
    else
    return false;
    }