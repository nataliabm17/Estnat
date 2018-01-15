import tkinter as tk
from tkinter import ttk
import matplotlib
matplotlib.use("TkAgg")
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2TkAgg
from matplotlib.figure import Figure
import matplotlib.animation as animation
from matplotlib import style


LARGE_FONT = ("Verdana", 30)
style.use("ggplot")

f = Figure(figsize=(8,7), dpi=100)
a = f.add_subplot(111)

f2 = Figure(figsize=(8,7), dpi=100)
a2 = f2.add_subplot(111)

def animate(i):
    pullData = open("sampleData.txt","r").read()
    dataList = pullData.split('\n')
    xList = []
    yList = []
    for eachLine in dataList:
        if len(eachLine)>1:
            x, y = eachLine.split(',')
            xList.append(int(x))
            yList.append(int(y))

    a.clear()
    a.plot(xList,yList)

    pullData = open("pressure.txt","r").read()
    dataList = pullData.split('\n')
    xList2 = []
    yList2 = []
    for eachLine in dataList:
        if len(eachLine)>1:
            x2, y2 = eachLine.split(',')
            xList2.append(int(x2))
            yList2.append(int(y2))

    a2.clear()
    a2.plot(xList2,yList2)




class SeaofBTCapp(tk.Tk):

    def __init__(self, *args, **kwargs):

        tk.Tk.__init__(self, *args, **kwargs)

        #tk.Tk.iconbitmap(self, default="icon.ico")
        tk.Tk.wm_title(self, "U sure")

        self.geometry('1000x850')

        container = tk.Frame(self)
        container.pack(side = "top", fill = "both", expand = True)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)

        self.frames = {}

        for F in (StartPage, PageOne, PageTwo, PageThree, PageFour, PageFive):
            frame = F(container, self)
            self.frames[F] = frame
            frame.grid(row=0, column=0, sticky="nsew")

        self.show_frame(StartPage)

    def show_frame(self, cont):
        frame = self.frames[cont]
        frame.tkraise()

class StartPage(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)

        button = ttk.Button(self, text="Temperature", command=lambda: controller.show_frame(PageOne))
        button.pack()
        button.place(x=870,y=200)

        button2 = ttk.Button(self, text="Voltage", command=lambda: controller.show_frame(PageTwo))
        button2.pack()
        button2.place(x=870,y=250)

        button3 = ttk.Button(self, text="Altitude", command=lambda: controller.show_frame(PageThree))
        button3.pack()
        button3.place(x=870,y=300)

        button4 = ttk.Button(self, text="Pressure", command=lambda: controller.show_frame(PageFour))
        button4.pack()
        button4.place(x=870,y=350)

        button5 = ttk.Button(self, text="Position", command=lambda: controller.show_frame(PageFive))
        button5.pack()
        button5.place(x=870,y=400)

        label = tk.Label(self, text="Data", font = LARGE_FONT)
        label.pack()
        label.place(x=400,y=60)

class PageOne(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)


        canvas = FigureCanvasTkAgg(f, self)
        canvas.show()
        canvas.get_tk_widget().pack(side=tk.LEFT, fill=tk.NONE, expand = False)

        toolbar = NavigationToolbar2TkAgg(canvas, self)
        toolbar.update()
        canvas._tkcanvas.pack(side=tk.BOTTOM, fill=tk.NONE, expand = False)


        button1 = ttk.Button(self, text="Data", command=lambda: controller.show_frame(StartPage))
        button1.pack()
        button1.place(x=870,y=200)

        button2 = ttk.Button(self, text="Voltage", command=lambda: controller.show_frame(PageTwo))
        button2.pack()
        button2.place(x=870,y=250)

        button3 = ttk.Button(self, text="Altitude", command=lambda: controller.show_frame(PageThree))
        button3.pack()
        button3.place(x=870,y=300)

        button4 = ttk.Button(self, text="Pressure", command=lambda: controller.show_frame(PageFour))
        button4.pack()
        button4.place(x=870,y=350)

        button5 = ttk.Button(self, text="Position", command=lambda: controller.show_frame(PageFive))
        button5.pack()
        button5.place(x=870,y=400)

        label = tk.Label(self, text="Temperature", font = LARGE_FONT)
        label.pack()
        label.place(x=330,y=60)

class PageTwo(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)


        f = Figure(figsize=(8,7), dpi=100)
        a = f.add_subplot(111)
        a.plot([1,2,3,4,5,6,7,8],[2,1,1,8,8,5,4,2])

        canvas = FigureCanvasTkAgg(f, self)
        canvas.show()
        canvas.get_tk_widget().pack(side=tk.LEFT, fill=tk.NONE, expand = False)

        toolbar = NavigationToolbar2TkAgg(canvas, self)
        toolbar.update()
        canvas._tkcanvas.pack(side=tk.BOTTOM, fill=tk.NONE, expand = False)


        button = ttk.Button(self, text="Temperature", command=lambda: controller.show_frame(PageOne))
        button.pack()
        button.place(x=870,y=200)

        button1 = ttk.Button(self, text="Data", command=lambda: controller.show_frame(StartPage))
        button1.pack()
        button1.place(x=870,y=250)

        button3 = ttk.Button(self, text="Altitude", command=lambda: controller.show_frame(PageThree))
        button3.pack()
        button3.place(x=870,y=300)

        button4 = ttk.Button(self, text="Pressure", command=lambda: controller.show_frame(PageFour))
        button4.pack()
        button4.place(x=870,y=350)

        button5 = ttk.Button(self, text="Position", command=lambda: controller.show_frame(PageFive))
        button5.pack()
        button5.place(x=870,y=400)

        label = tk.Label(self, text="Voltage", font = LARGE_FONT)
        label.pack()
        label.place(x=400,y=60)



class PageThree(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)

        f = Figure(figsize=(8,7), dpi=100)
        a = f.add_subplot(111)
        a.plot([1,2,3,4,5,6,7,8],[1,9,10,8,5,7,4,2])

        canvas = FigureCanvasTkAgg(f, self)
        canvas.show()
        canvas.get_tk_widget().pack(side=tk.LEFT, fill=tk.NONE, expand = False)

        toolbar = NavigationToolbar2TkAgg(canvas, self)
        toolbar.update()
        canvas._tkcanvas.pack(side=tk.BOTTOM, fill=tk.NONE, expand = False)



        button = ttk.Button(self, text="Temperature", command=lambda: controller.show_frame(PageOne))
        button.pack()
        button.place(x=870,y=200)

        button1 = ttk.Button(self, text="Data", command=lambda: controller.show_frame(StartPage))
        button1.pack()
        button1.place(x=870,y=250)

        button2 = ttk.Button(self, text="Voltage", command=lambda: controller.show_frame(PageTwo))
        button2.pack()
        button2.place(x=870,y=300)

        button4 = ttk.Button(self, text="Pressure", command=lambda: controller.show_frame(PageFour))
        button4.pack()
        button4.place(x=870,y=350)

        button5 = ttk.Button(self, text="Position", command=lambda: controller.show_frame(PageFive))
        button5.pack()
        button5.place(x=870,y=400)

        label = tk.Label(self, text="Altitude", font = LARGE_FONT)
        label.pack()
        label.place(x=400,y=60)

class PageFour(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)


        canvas = FigureCanvasTkAgg(f2, self)
        canvas.show()
        canvas.get_tk_widget().pack(side=tk.LEFT, fill=tk.NONE, expand = False)

        toolbar = NavigationToolbar2TkAgg(canvas, self)
        toolbar.update()
        canvas._tkcanvas.pack(side=tk.BOTTOM, fill=tk.NONE, expand = False)



        button = ttk.Button(self, text="Temperature", command=lambda: controller.show_frame(PageOne))
        button.pack()
        button.place(x=870,y=200)

        button1 = ttk.Button(self, text="Data", command=lambda: controller.show_frame(StartPage))
        button1.pack()
        button1.place(x=870,y=250)

        button2 = ttk.Button(self, text="Voltage", command=lambda: controller.show_frame(PageTwo))
        button2.pack()
        button2.place(x=870,y=300)

        button3 = ttk.Button(self, text="Altitude", command=lambda: controller.show_frame(PageThree))
        button3.pack()
        button3.place(x=870,y=350)

        button5 = ttk.Button(self, text="Position", command=lambda: controller.show_frame(PageFive))
        button5.pack()
        button5.place(x=870,y=400)

        label = tk.Label(self, text="Pressure", font = LARGE_FONT)
        label.pack()
        label.place(x=400,y=60)

class PageFive(tk.Frame):

    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)


        button = ttk.Button(self, text="Temperature", command=lambda: controller.show_frame(PageOne))
        button.pack()
        button.place(x=870,y=200)

        button1 = ttk.Button(self, text="Data", command=lambda: controller.show_frame(StartPage))
        button1.pack()
        button1.place(x=870,y=250)

        button2 = ttk.Button(self, text="Voltage", command=lambda: controller.show_frame(PageTwo))
        button2.pack()
        button2.place(x=870,y=300)

        button3 = ttk.Button(self, text="Altitude", command=lambda: controller.show_frame(PageThree))
        button3.pack()
        button3.place(x=870,y=350)

        button4 = ttk.Button(self, text="Pressure", command=lambda: controller.show_frame(PageFour))
        button4.pack()
        button4.place(x=870,y=400)


        label = tk.Label(self, text="Position", font = LARGE_FONT)
        label.pack()
        label.place(x=400,y=60)

app = SeaofBTCapp()
ani = animation.FuncAnimation(f, animate, interval = 500)
ani = animation.FuncAnimation(f2, animate, interval = 500)
app.mainloop()
