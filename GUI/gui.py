
# This file was generated by the Tkinter Designer by Parth Jadhav
# https://github.com/ParthJadhav/Tkinter-Designer


from pathlib import Path

#from tkinter import *

from tkinter.ttk import Scale, Style, Label
# Explicit imports to satisfy Flake8
from tkinter import Tk, Canvas, Entry, Text, Button, PhotoImage, IntVar, StringVar


OUTPUT_PATH = Path(__file__).parent
#ASSETS_PATH = OUTPUT_PATH / Path(r"C:\Users\ftmar\se\Prueba_GUI\Figma3\build\assets\frame0")


#def relative_to_assets(path: str) -> Path:
#    return ASSETS_PATH / Path(path)


window = Tk()

window.geometry("1000x800")
window.configure(bg = "#272727")

color_boton = "#111111"


brillo = IntVar()
vel_ventilador = IntVar()

red = IntVar()
green = IntVar()
blue = IntVar()



s_red = Style()
s_green = Style()
s_blue = Style()

s_basico = Style()

s_basico2 = Style()


s_red.configure('sliderRed.Vertical.TScale', background = 'red')

s_green.configure('sliderGreen.Vertical.TScale', background = 'green')

s_blue.configure('sliderBlue.Vertical.TScale', background = 'blue')

s_basico.configure('sliderBasico.Horizontal.TScale', background = '#272727')


def get_slider_red():
    return int(slider_red.get())

def slider_red_changed(event):
    actualizar_color()
    canvas.itemconfig(text_red_id, text=get_slider_red())



def get_slider_green():
    return int(slider_green.get())

def slider_green_changed(event):
    actualizar_color()
    canvas.itemconfig(text_green_id, text=get_slider_green())



def get_slider_blue():
    return int(slider_blue.get())

def slider_blue_changed(event):
    actualizar_color()
    canvas.itemconfig(text_blue_id, text=get_slider_blue())



def get_slider_brillo():
    return int(slider_brillo.get())

def slider_brillo_changed(event):
    canvas.itemconfig(text_brillo_id, text=get_slider_brillo())



def get_slider_ventilador():
    return int(slider_ventilador.get())

def slider_ventilador_changed(event):
    canvas.itemconfig(text_ventilador_id, text=get_slider_ventilador())



def rgb2hex(r,g,b):
    return "#{:02x}{:02x}{:02x}".format(r,g,b)

def actualizar_color():
    color = rgb2hex(get_slider_red(), get_slider_green(), get_slider_blue())
    canvas.itemconfig(color_final_id, fill = color)


canvas = Canvas(
    window,
    bg = "#272727",
    height = 800,
    width = 1000,
    bd = 0,
    highlightthickness = 0,
    relief = "ridge"
)

canvas.place(x = 0, y = 0)
canvas.create_text(
    368.0,
    395.0,
    anchor="nw",
    text="Controles Lámpara",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 32 * -1)
)

canvas.create_rectangle(
    69.0,
    368.0,
    940.0051879882812,
    369.0,
    fill="#7F7F7F",
    outline="")

canvas.create_text(
    389.0,
    39.0,
    anchor="nw",
    text="Estado Lámpara",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 32 * -1)
)

canvas.create_rectangle(
    38.0,
    200.0,
    203.0,
    295.0,
    fill="#303030",
    outline="")

canvas.create_text(
    101.0,
    166.0,
    anchor="nw",
    text="CO2",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 20 * -1)
)

canvas.create_rectangle(
    412.0,
    200.0,
    577.0,
    295.0,
    fill="#303030",
    outline="")

canvas.create_text(
    451.0,
    164.0,
    anchor="nw",
    text="Temperatura",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 20 * -1)
)



canvas.create_rectangle(
    598.0,
    200.0,
    763.0,
    295.0,
    fill="#303030",
    outline="")

canvas.create_text(
    640.0,
    166.0,
    anchor="nw",
    text="Iluminancia",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 20 * -1)
)


canvas.create_rectangle(
    225.0,
    200.0,
    390.0,
    295.0,
    fill="#303030",
    outline="")



canvas.create_text(
    274.0,
    166.0,
    anchor="nw",
    text="Humedad",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 20 * -1)
)

canvas.create_rectangle(
    786.0,
    200.0,
    951.0,
    295.0,
    fill="#303030",
    outline="")

canvas.create_text(
    843.0,
    164.0,
    anchor="nw",
    text="Ruido",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 20 * -1)
)

canvas.create_rectangle(
    587.0,
    148.0,
    588.0,
    301.0,
    fill="#7F7F7F",
    outline="")

canvas.create_rectangle(
    773.0,
    148.0,
    774.0,
    301.0,
    fill="#7F7F7F",
    outline="")

canvas.create_rectangle(
    401.0,
    148.0,
    402.0,
    301.0,
    fill="#7F7F7F",
    outline="")

canvas.create_rectangle(
    213.0,
    148.0,
    214.0,
    301.0,
    fill="#7F7F7F",
    outline="")



canvas.create_text(
    78.0,
    227.0,
    anchor="nw",
    text="500",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 32 * -1)
)

canvas.create_text(
    140.0,
    239.0,
    anchor="nw",
    text="PPM",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 20 * -1)
)

canvas.create_text(
    279.0,
    227.0,
    anchor="nw",
    text="45%",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 32 * -1)
)

canvas.create_text(
    460.0,
    227.0,
    anchor="nw",
    text="23ºC",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 32 * -1)
)

canvas.create_text(
    654.0,
    227.0,
    anchor="nw",
    text="450",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 32 * -1)
)

canvas.create_text(
    715.0,
    237.0,
    anchor="nw",
    text="px",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 20 * -1)
)

canvas.create_text(
    827.0,
    227.0,
    anchor="nw",
    text="BAJO",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 32 * -1)
)

canvas.create_text(
    845.0,
    259.0,
    anchor="nw",
    text="(350)",
    fill="#FFFFFF",
    font=("ZCOOLXiaoWei Regular", 16 * -1)
)


button_1 = Button(
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_1 clicked"),
    relief="flat", 
    text= "Aplicar",
    background=color_boton,
    foreground= "white",
    font=('calibri', 15, 'bold')
)
button_1.place(
    x=366.0,
    y=700.0,
    width=78.0,
    height=35.0
)


button_2 = Button(
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_2 clicked"),
    relief="flat",
    text= "Aplicar",
    background=color_boton,
    foreground= "white",
    font=('calibri', 15, 'bold')
)
button_2.place(
    x=907.0,
    y=677.0,
    width=78.0,
    height=35.0
)


button_3 = Button(
    borderwidth=0,
    highlightthickness=0,
    command=lambda: print("button_3 clicked"),
    relief="flat",
    text= "Aplicar",
    background=color_boton,
    foreground= "white",
    font=('calibri', 15, 'bold')
)
button_3.place(
    x=907.0,
    y=536.0,
    width=78.0,
    height=35.0
)

canvas.create_rectangle(
    499.0,
    491.99998474121094,
    500.0,
    748.001953125,
    fill="#7F7F7F",
    outline="")




slider_red = Scale( window,           #slider Red
    from_=255,
    to=0,
    orient='vertical',
    length=144,
    style="sliderRed.Vertical.TScale",
    variable=red,
    command=slider_red_changed
    )
slider_red.place(
    x=169.0,
    y=525.0,
    width=30.0,
    height=144.0
)


slider_green = Scale( window,           #slider Green
    from_=255,
    to=0,
    orient='vertical',
    length=144,
    style="sliderGreen.Vertical.TScale",
    variable=green,
    command=slider_green_changed
    )
slider_green.place(
    x=222.0,
    y=525.0,
    width=30.0,
    height=144.0
)


slider_blue = Scale( window,           #slider Blue
    from_=255,
    to=0,
    orient='vertical',
    length=144,
    style="sliderBlue.Vertical.TScale",
    variable=blue,
    command=slider_blue_changed
    )
slider_blue.place(
    x=275.0,
    y=525.0,
    width=30.0,
    height=144.0
)

color_final_id = canvas.create_rectangle(        #Rectangulo resultado RGB
    355.0,
    548.0,
    455.0,
    648.0,
    fill="#000000",
    outline="")



canvas.create_text(                         #texto R
    177.0,
    490.0,
    anchor="nw",
    text="R",
    fill="#FFFFFF",
    font=('calibri', 18, 'bold')
)

canvas.create_text(                         #texto G
    229.0,
    490.0,
    anchor="nw",
    text="G",
    fill="#FFFFFF",
    font=('calibri', 18, 'bold')
)

canvas.create_text(                         #texto B
    284.0,
    490.0,
    anchor="nw",
    text="B",
    fill="#FFFFFF",
    font=('calibri', 18, 'bold')
)

canvas.create_text(
    48.0,
    574.0,
    anchor="nw",
    text="Color",
    fill="#FFFFFF",
    font=('calibri', 25, 'bold')
)

canvas.create_rectangle(
    531.0,
    620.0,
    946.0,
    621.0,
    fill="#7F7F7F",
    outline="")

canvas.create_text(
    532.0,
    539.0,
    anchor="nw",
    text="Brillo",
    fill="#FFFFFF",
    font=("Inter Bold", 24 * -1)
)

canvas.create_text(
    522.0,
    671.0,
    anchor="nw",
    text="Velociad\nventilador",
    fill="#FFFFFF",
    font=("Inter Bold", 20 * -1)
)

slider_brillo = Scale( window,           #slider Brillo
    from_=0,
    to=31,
    orient='horizontal',
    length=238,
    variable=brillo,
    command=slider_brillo_changed,
    style = "sliderBasico.Horizontal.TScale"
    )
slider_brillo.place(
    x=654.0,
    y=543.0,
    width=238.0,
    height=22.0
)

slider_ventilador = Scale( window,           #slider Velocidad Ventilador
    from_=0,
    to=100,
    orient='horizontal',
    length=238,
    variable= vel_ventilador,
    command=slider_ventilador_changed,
    style = "sliderBasico.Horizontal.TScale"
    )
slider_ventilador.place(
    x=654.0,
    y=684.0,
    width=238.0,
    height=22.0
)


text_red_id = canvas.create_text(                     #texto con valor slider red
    183.0,
    685.0,
    anchor="center",
    text=get_slider_red(),
    fill="#FFFFFF",
    font=('calibri', 15, 'bold')
)

text_green_id = canvas.create_text(                      #texto con valor slider green
    236.0,
    685.0,
    anchor="center",
    text= get_slider_green(),
    fill="#FFFFFF",
    font=('calibri', 15, 'bold')
)

text_blue_id = canvas.create_text(                      #texto con valor slider blue
    290.0,
    685.0,
    anchor="center",
    text=get_slider_blue(),
    fill="#FFFFFF",
    font=('calibri', 15, 'bold')
)

text_brillo_id = canvas.create_text(                      #texto con valor slider brillo
    770.0,
    515.0,
    anchor="center",
    text=get_slider_brillo(),
    fill="#FFFFFF",
    font=("Inter Bold", 25 * -1)
)

text_ventilador_id = canvas.create_text(                       #texto con valor slider velocidad ventilador
    770.0,
    656.0,
    anchor="center",
    text=get_slider_ventilador(),
    fill="#FFFFFF",
    font=("Inter Bold", 25 * -1)
)

canvas.create_rectangle(            #slider Velociad ventilador
    654.0,
    684.0,
    892.0,
    706.0,
    fill="#FF7A00",
    outline="")

window.resizable(False, False)
window.mainloop()