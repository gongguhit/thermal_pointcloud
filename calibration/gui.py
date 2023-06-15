import tkinter as tk
import subprocess 

window = tk.Tk()
window.title('calibration demo')
window.geometry('500x500')
z = tk.Label(window,anchor = 'w',bg='white',
                    justify = 'center', width=500, height=500)
z.place(x = 0, y = 0)
a = tk.Label(window,anchor = 'w',text="Calibration & fusion demo",
                    fg = 'white', bg='darkblue', font=('TimesNewRoman', 30),
                    justify = 'center', width=20, height=1)
a.place(x = 50, y = 100)
 
b = tk.Label(window,anchor='nw',text="With Realsense d455 and Boson 320",
             fg='black',bg='white',font=('TimesNewRoman',12),
             justify='center',width=50,height=20)
b.place(x = 50, y = 150)

## "Start" buttons 
c = tk.Button(window, text='set1', width=10,
              height=2, command=lambda:subprocess.Popen(args=['python', r'/home/gg/Downloads/calibration/get_img_d455_boson.py']))
c.place(x = 270,y = 180)
 
p = tk.Button(window, text='set2', width=10,
              height=2, command=lambda:subprocess.Popen(args=['python', r'/home/gg/Downloads/calibration/get_img_d455_boson_2.py']))
p.place(x = 270,y = 220)


e = tk.Button(window, text='set1', width=10,
              height=2, command=lambda:subprocess.Popen(args=['python', r'/home/gg/Downloads/calibration/calib_RGB_boson.py']))
e.place(x = 270,y = 270)

q = tk.Button(window, text='set2', width=10,
              height=2, command=lambda:subprocess.Popen(args=['python', r'/home/gg/Downloads/calibration/calib_RGB_boson_2.py']))
q.place(x = 270,y = 310)

g = tk.Button(window, text='set1', width=10,
              height=2, command=lambda:subprocess.Popen(args=['python', r'/home/gg/Downloads/calibration/quick_fusion_D455_boson.py']))
g.place(x = 270,y = 350)

r = tk.Button(window, text='set2', width=10,
              height=2, command=lambda:subprocess.Popen(args=['python', r'/home/gg/Downloads/calibration/quick_fusion_D455_boson_2.py']))
r.place(x = 270,y = 390)


## Buttons description
 
d_name = tk.StringVar()
d_name.set("get image")
d = tk.Label(window,anchor='nw',textvariable=d_name,
             fg='black',bg='white',font=('TimesNewRoman',12),
             justify='center',width=20,height=2)
d.place(x = 50, y = 210)

f_name = tk.StringVar()
f_name.set("calibration")
f = tk.Label(window,anchor='nw',textvariable=f_name,
             fg='black',bg='white',font=('TimesNewRoman',12),
             justify='center',width=20,height=2)
f.place(x = 50, y = 290)

h_name = tk.StringVar()
h_name.set("fusion D455 & boson")
h = tk.Label(window,anchor='nw',textvariable=h_name,
             fg='black',bg='white',font=('TimesNewRoman',12),
             justify='center',width=20,height=2)
h.place(x = 50, y = 370)
 
window.mainloop()
