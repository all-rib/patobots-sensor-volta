import serial
import tkinter as tk
import threading


portaArduinoUtilizada = '/dev/ttyUSB0' #Inserir a porta serial do Arduino

def inputSerial():
    while True:
        linha = ser.readline().decode('utf-8').strip()
        label_tempo['text'] = linha

ser = serial.Serial(portaArduinoUtilizada, 9600, timeout=1) 

app = tk.Tk()
app.title("Campeonato Seguidor")

largura_janela = 640
altura_janela = 320

app.geometry(f"{largura_janela}x{altura_janela}")
app.resizable(False, False)


frame_superior = tk.Frame(app, height=(altura_janela - 200) // 2)
frame_superior.pack(side="top", fill="both")

label_tempo = tk.Label(app, text="Tempo: N/A", font=("Arial", 30), bg="white", padx=20, pady=20)
label_tempo.pack(side="top", fill="both")

thread_serial = threading.Thread(target=inputSerial)
thread_serial.start()

def fechar():
    ser.close()
    app.destroy()

botao_fechar = tk.Button(app, text="Fechar", font=("Arial", 20), bg="red", command=fechar)
botao_fechar.pack()

app.mainloop()
