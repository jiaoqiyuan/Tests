from tkinter import *

window = Tk()
window.title("Welcome to LikeGeeks app")
#lbl = Label(window, text="Hello", font=("Arial Bold", 50))
lbl = Label(window, text="Hello")
lbl.grid(column=0, row=0)

window.geometry('350x200')

txt = Entry(window, width=10, state='disabled')
txt.grid(column=2, row=0)
txt.focus()

def clicked():
    res = "Welcome to " + txt.get()
    lbl.configure(text = res)
btn = Button(window, text="Click Me", bg="orange", fg="red", command=clicked)
btn.grid(column=1, row=0)


window.mainloop()
