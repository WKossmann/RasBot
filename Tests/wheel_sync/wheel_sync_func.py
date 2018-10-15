import random

def mudouEstado():
    a = random.randint(0,50)
    if (a>1):
        return 0
    else:
        return 1

def wheelSync_Calibracao():
    pwm = 0
    
    while(not mudouEstado()):
        print("Rise",pwm)
        pwm = pwm + 1
    return pwm

def wheelSync_Run(stepsL, stepsR):
    stepL_Cont = 0
    stepR_Cont = 0

    if(stepsL>stepsR):
        maxSteps = stepsL
        proporcao = float(stepsL)/float(stepsR)

        while(stepL_Cont < maxSteps):
            if(mudouEstado()): # Direito
                stepR_Cont = stepR_Cont + 1
            if(mudouEstado()): # Esquerdo
                stepL_Cont = stepL_Cont + 1
            
            #if(maxSide == "R"):
            if(stepL_Cont < stepR_Cont*proporcao):
                print("PARA DIREITO")
                #while(mudouEstado()): # Esquerdo
                print("ESPERANDO")
                stepL_Cont = stepL_Cont + 1
                print("CONTINUA DIREITO")
            if(stepL_Cont > stepR_Cont*proporcao):
                print("PARA ESQUERDO")
                #while(mudouEstado()): # Esquerdo
                print("ESPERANDO")
                stepR_Cont = stepR_Cont + 1
                print("CONTINUA ESQUERDO")
            print(stepL_Cont,stepR_Cont)

    else:
        maxSteps = stepsR
        proporcao = float(stepsR)/float(stepsL)

        while(stepR_Cont < maxSteps):
            if(mudouEstado()): # Direito
                stepR_Cont = stepR_Cont + 1
            if(mudouEstado()): # Esquerdo
                stepL_Cont = stepL_Cont + 1
            
            #if(maxSide == "R"):
            if(stepR_Cont > stepL_Cont*proporcao):
                print("PARA DIREITO")
                #while(mudouEstado()): # Esquerdo
                print("ESPERANDO")
                stepL_Cont = stepL_Cont + 1
                print("CONTINUA DIREITO")
            if(stepR_Cont < stepL_Cont*proporcao):
                print("PARA ESQUERDO")
                #while(mudouEstado()): # Esquerdo
                print("ESPERANDO")
                stepR_Cont = stepR_Cont + 1
                print("CONTINUA ESQUERDO")
            print(stepL_Cont,stepR_Cont)
        
                



# Testes Calibracao
# print("PWM de Partida: ", wheelSync_Calibracao())

# Testes Run
print("PWM de Partida: ", wheelSync_Run(10,40))
