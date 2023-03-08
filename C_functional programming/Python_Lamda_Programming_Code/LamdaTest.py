debug_hex = 0x00010000

class h:
    pass

say_hello = lambda h: print("Hello World!!") if (debug_hex & debug_hex) else print("Out of range memory values.")

hello = h()
hello.sh = say_hello
hello.sh(hello)