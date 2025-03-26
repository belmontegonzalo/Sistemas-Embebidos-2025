import time

print("Hola! En este programa se le solicitaran dos numeros A y B, que deben ser numero ENTEROS.")
time.sleep(1)
print("Luego se le informara, la suma, la resta y el producto de ambos numeros ingresados.")
time.sleep(1)

A = input("Ingrese el numero A: ") # Pido al usuario el numero A
while A.isdigit() == False: # Chequeo si el numero ingresado es, en si, un numero, para evitar crasheos del programa
    print("Lo ingresado es invalido y no cumple con los parametros propuestos. Intente nuevamente.")
    time.sleep(1)
    A = input("Ingrese el numero A: ")
A = int(A)

B = input("Ingrese el numero B: ") #Pido al usuario numero B
while B.isdigit() == False: # Chequeo si el numero ingresado es, en si, un numero, para evitar crasheos del programa
    print("Lo ingresado es invalido y no cumple con los parametros propuestos. Intente nuevamente.")
    time.sleep(1)
    B = input("Ingrese el numero B: ")
B = int(B)

suma = A + B

cond = input("¿Desea recibir la resta de A-B o B-A? \n 1) A-B \n 2) B-A\n") # Ya que la resta no es indiferente su orden, pregunto en que orden lo gustaria el usuario

while not cond.isdigit() or int(cond) < 1 or int(cond) > 2: # Chequeo si lo ingresado es una de las opciones
    print("Lo ingresado es invalido y no cumple con los parametros propuestos. Intente nuevamente.")
    time.sleep(1)
    cond = input("¿Desea recibir la resta de A-B o B-A? \n 1) A-B \n 2) B-A\n")
cond = int(cond)

if cond == 1:
    resta = A - B
else:
    resta = B - A

producto = A * B

print("Procesando...")
time.sleep(2)
print("Los resultados son los siguientes: \nSuma = ", suma, "\nResta = ", resta, "\nProducto = ", producto)
time.sleep(1)
print("Gracias por usar!")