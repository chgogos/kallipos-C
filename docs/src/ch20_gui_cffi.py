import tkinter as tk
import os
import sys
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from cffi import FFI

ffi = FFI()  # δημιουργία ενός αντικειμένου FFI
if sys.platform.startswith("win"):
    clib = ffi.dlopen(os.path.join(os.getcwd(), "gui_logic.dll"))
elif sys.platform.startswith("linux"):
    clib = ffi.dlopen(os.path.join(os.getcwd(), "libgui_logic.so"))
elif sys.platform.startswith("darwin"):
    clib = ffi.dlopen(os.path.join(os.getcwd(), "libgui_logic.dylib"))
else:
    print("Unknown OS")
    exit()

ffi.cdef("int* get_values();")  # δήλωση του πρωτοτύπου της συνάρτησης C


# ανάκτηση τιμών από τη C και μετατροπή τους σε λίστα Python
def get_c_values():
    c_values = clib.get_values()
    return [c_values[i] for i in range(5)]


# ανανέωση του γραφήματος
def update_plot():
    data = get_c_values()
    ax.clear()
    ax.plot(data, marker="o")
    canvas.draw()


# δημιουργία του παραθύρου
root = tk.Tk()
root.title("CFFI Tkinter App")

# δημιουργία του γραφήματος
fig = Figure(figsize=(5, 4), dpi=100)
ax = fig.add_subplot(111)

# ενσωμάτωση του γραφήματος στο παράθυρο
canvas = FigureCanvasTkAgg(fig, master=root)
canvas_widget = canvas.get_tk_widget()
canvas_widget.pack(side=tk.TOP, fill=tk.BOTH, expand=True)

# προσθήκη κουμπιού στο παράθυρο
button = tk.Button(root, text="Get C Values", command=update_plot)
button.pack(side=tk.BOTTOM)

root.mainloop()
